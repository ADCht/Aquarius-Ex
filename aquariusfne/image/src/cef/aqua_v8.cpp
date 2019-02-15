#include "aqua_v8.h"
#include "calling\aqua_calling_renderer.h"
#include "include\cef_v8.h"
#include "utils\aqua_conv.h"
#include "calling\aqua_calling_renderer.h"
#include "calling\aqua_calling_v8.h"

using namespace AquaCef;

void CALLBACK OnV8Free(V8VALUESTRUCT *p) {
	if (p) {
		if (p->v4) delete[]p->v4;
		delete p;
	}
}

///
//	����һ���µ�|V8Value|����
///
AQUAENTRYFULL(LPVOID, V8Value, Alloc)(void) {
	return new CefV8ValueList;
}

///
//	��|object|�Ͽ���һ���µ�|V8Value|����
///
AQUAENTRYFULL(LPVOID, V8Value, Copy)(LPVOID object) {
	if (object) {
		return new CefV8ValueList(*reinterpret_cast<CefV8ValueList*>(object));
	}
	return NULL;
}

///
//	����|object|����
///
AQUAENTRYFULL(void, V8Value, Destory)(LPVOID object) {
	if (object) {
		delete reinterpret_cast<CefV8ValueList*>(object);
	}
}

///
//	��ȡ|index|��ָ��|object|�����е����ݳ�Ա���͡�
///
AQUAENTRYFULL(int, V8Value, GetType)(LPVOID object, int index) {
	if (object) {
		auto p = reinterpret_cast<CefV8ValueList*>(object);
		if (index >= 0 && index < p->size()) {
			const auto &element = (*p)[index];
			if (element->IsBool()) {
				return 0;
			}
			else if (element->IsInt()) {
				return 1;
			}
			else if (element->IsDouble()) {
				return 2;
			}
			else if (element->IsString()) {
				return 3;
			}
		}
	}
	return -1;
}

///
//	��ȡ|object|������|index|��ֵ
///
AQUAENTRYFULL(LPVOID, V8Value, GetValue)(LPVOID object, int index) {
	if (object) {
		auto p = reinterpret_cast<CefV8ValueList*>(object);
		if (index >= 0 && index < p->size()) {
			V8VALUESTRUCT *v8 = new V8VALUESTRUCT;
			v8->free = OnV8Free;
			v8->v4 = NULL;
			const auto &element = (*p)[index];
			if (element->IsBool()) {
				v8->index = index;
				v8->type = 0;
				v8->v1 = element->GetBoolValue();
				return v8;
			}
			else if (element->IsInt()) {
				v8->index = index;
				v8->type = 1;
				v8->v2 = element->GetIntValue();
				return v8;
			}
			else if (element->IsDouble()) {
				v8->index = index;
				v8->type = 2;
				v8->v3 = element->GetDoubleValue();
				return v8;
			}
			else if (element->IsString()) {
				v8->index = index;
				v8->type = 3;
				aqua_convert conv;
				CefString vx = element->GetStringValue();
				if (vx.length() > 0) {
					v8->v4 = new char[vx.length() + 1];
					auto bv4 = conv.to_bytes(vx.c_str());
					memcpy(v8->v4, bv4.c_str(), vx.length());
					v8->v4[bv4.length()] = '\0';
				}
				return v8;
			}
		}
	}
	return NULL;
}

///
//	����|object|������|index|��ֵ
///
AQUAENTRYFULL(void, V8Value, SetValue)(LPVOID object, LPVOID value) {
	if (object && value) {
		auto p = reinterpret_cast<CefV8ValueList*>(object);
		auto v = reinterpret_cast<V8VALUESTRUCT*>(value);
		CefRefPtr<CefV8Value> retval;
		if (v->type == 0) {
			retval = CefV8Value::CreateBool(v->v1);
			p->push_back(retval);
		}
		else if (v->type == 1) {
			retval = CefV8Value::CreateInt(v->v2);
			p->push_back(retval);
		}
		else if (v->type == 2) {
			retval = CefV8Value::CreateDouble(v->v3);
			p->push_back(retval);
		}
		else if (v->type == 3) {
			aqua_convert conv;
			if (v->v4 == NULL) {
				retval = CefV8Value::CreateString(TEXT(""));
				p->push_back(retval);
			}
			else {
				auto k = conv.from_bytes(v->v4);
				retval = CefV8Value::CreateString(k);
				p->push_back(retval);
			}
		}
	}
}

///
//	����JS����
///
AQUAENTRYFULL(LPVOID, V8Spec, CreateAccessor)(LPCSTR mainName) {
	if (mainName == NULL) return FALSE;
	CefRefPtr<CefV8Context> v8 = NULL;
	CefRefPtr<AquaCallRenderer> calling = AquaCallRenderer::GetInterface();
	if (calling.get() == NULL) return FALSE;
	v8 = calling->GetV8();
	if (v8.get() == NULL) return FALSE;
	CefRefPtr<CefV8Value> window = v8->GetGlobal();
#ifdef _AQUA_CEF2623_ADAPTER
	CefRefPtr<CefV8Value> accessor = CefV8Value::CreateObject(new AquaCallV8Accessor);
#else
	CefRefPtr<CefV8Value> accessor = CefV8Value::CreateObject(new AquaCallV8Accessor,NULL);
#endif
	accessor->SetValue(TEXT("__v8_spec_"), CefV8Value::CreateString(mainName), V8_PROPERTY_ATTRIBUTE_NONE);
	window->SetValue(mainName, accessor, V8_PROPERTY_ATTRIBUTE_NONE);
	accessor->AddRef();
	return accessor.get();
}

///
//	ע��JS����
///
AQUAENTRYFULL(BOOL, V8Spec, RegisterVar)(LPVOID object, LPCSTR childName) {
	if (object==NULL || childName == NULL) return FALSE;
	//CefRefPtr<CefV8Context> v8 = NULL;
	//CefRefPtr<AquaCallRenderer> calling = AquaCallRenderer::GetInterface();
	//if (calling.get() == NULL) return FALSE;
	//v8 = calling->GetV8();
	//if (v8.get() == NULL) return FALSE;
	//CefRefPtr<CefV8Value> window = v8->GetGlobal();
	aqua_convert conv;
	CefV8Value *pAccessor = reinterpret_cast<CefV8Value*>(object);
	pAccessor->AddRef();
	pAccessor->SetValue(childName, V8_ACCESS_CONTROL_DEFAULT, V8_PROPERTY_ATTRIBUTE_NONE);
	//window->SetValue(pAccessor->GetValue(TEXT("__v8_spec_"))->GetStringValue(), pAccessor, V8_PROPERTY_ATTRIBUTE_NONE);
	pAccessor->Release();
	return TRUE;
}

///
//	ע��JS����
///
AQUAENTRYFULL(BOOL, V8Spec, RegisterFunction)(LPVOID object, LPCSTR functionName) {
	if (object == NULL || functionName == NULL) return FALSE;
	aqua_convert conv;
	CefV8Value *pAccessor = reinterpret_cast<CefV8Value*>(object);
	CefRefPtr<CefV8Value> func = CefV8Value::CreateFunction(functionName, new AquaCallV8Handler);
	pAccessor->AddRef();
	pAccessor->SetValue(functionName, func, V8_PROPERTY_ATTRIBUTE_NONE);
	pAccessor->Release();
	return TRUE;
}
