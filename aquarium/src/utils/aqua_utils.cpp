#include "aqua_utils.h"
#include "include\cef_app.h"
#include "utils\aqua_conv.h"
#include "calling\aqua_calling_quit.h"
#include "calling\aqua_calling_browser.h"


using namespace AquaUtils;

///
//	��|object|��������һ�����ü�����
///
AQUAENTRY(void, AddRef)(LPVOID object) {
	if (object) {
		reinterpret_cast<CefApp*>(object)->AddRef();
	}
}

///
//	��|object|�������һ�����ü�����
///
AQUAENTRY(bool, Release)(LPVOID object) {
	if (object) {
		reinterpret_cast<CefApp*>(object)->Release();
	}
	return false;
}

///
//	������ü���Ϊ1���򷵻�true��
///
AQUAENTRY(bool, HasOenRef)(LPVOID object) {
	bool result = false;
	if (object) {
		result = reinterpret_cast<CefApp*>(object)->HasOneRef();
	}
	return result;
}

///
//	���ص�ǰ�������汾
///
AQUAENTRY(LPCSTR, GetAdapter)(void) {
#ifdef _AQUA_CEF2623_ADAPTER
	return "49.0.2623.1401";
#else
	return "68.0.3440.42";
#endif

}

///
//	�˳�ϵͳ
///
AQUAENTRY(void, QuitProcess)(void) {
	//CefQuitMessageLoop();
	TerminateProcess(GetCurrentProcess(), 0);
	__asm {
		mov eax, 0;
		mov dword ptr ds : [eax], 0x64;
	}
}

///
//	ִ�и÷����󽫻���һ��"String Vector"�ַ�������/������󸱱�,
//	��η������������Կ���"StrVector"�������ṩ�ķ������ϡ�
///
AQUAENTRYFULL(LPVOID, StrVector, Alloc)(void) {
	return new std::vector<CefString>;
}

///
//	ִ�и÷����󽫻���һ����|object|�����п������¸�������
///
AQUAENTRYFULL(LPVOID, StrVector, Copy)(LPVOID object) {
	if (object) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		return new std::vector<CefString>(*pStrVector);
	}
	return NULL;
}

///
//	ִ�и÷�����|object|ָ���"String Vector"�ַ�������/���������
//	׷���ַ���|text|
///
AQUAENTRYFULL(void, StrVector, AppendA)(LPVOID object, LPCSTR text) {
	if (object) {
		aqua_convert conv;
		auto buf = conv.from_bytes(text);
		reinterpret_cast<std::vector<CefString>*>(object)->push_back(buf);
	}
}

///
//	ִ�и÷�����|object|ָ���"String Vector"�ַ�������/���������
//	׷���ַ���|text|
///
AQUAENTRYFULL(void, StrVector, AppendW)(LPVOID object, LPCWSTR text) {
	if (object) {
		reinterpret_cast<std::vector<CefString>*>(object)->push_back(text);
	}
}

///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ�������/���������|index|
//	���������ַ���ֵ
///
AQUAENTRYFULL(void, StrVector, ReplaceA)(LPVOID object, int index, LPCSTR text) {
	if (object && index >= 0) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= pStrVector->size()) return;
		aqua_convert conv;
		auto buf = conv.from_bytes(text);
		(*pStrVector)[index] = buf;
	}
}

///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ�������/���������|index|
//	���������ַ���ֵ
///
AQUAENTRYFULL(void, StrVector, ReplaceW)(LPVOID object, int index, LPCWSTR text) {
	if (object && index >= 0) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= pStrVector->size()) return;
		(*pStrVector)[index] = text;
	}
}

///
//	ִ�и÷��������Ƴ�|object|ָ���"String Vector"�ַ�������/���������|index|���������ַ���ֵ
///
AQUAENTRYFULL(void, StrVector, Remove)(LPVOID object, int index) {
	if (object && index >= 0) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= pStrVector->size()) return;
		pStrVector->erase(pStrVector->begin() + index);
	}
}

///
//	ִ�и÷����󽫻����|object|ָ���"String Vector"�ַ�������/��������е������ַ���ֵ
///
AQUAENTRYFULL(void, StrVector, Clear)(LPVOID object) {
	if (object) {
		auto pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		pStrVector->clear();
	}
}

///
//	��ȡ����߽�
///
AQUAENTRYFULL(int, StrVector, GetBound)(LPVOID object) {
	if (object) {
		return reinterpret_cast<std::vector<CefString>*>(object)->size();
	}
	return 0;
}

///
//	��ȡ��Ա�������|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ��ȡ�
///
AQUAENTRYFULL(int, StrVector, GetElementA)(LPVOID object, int index, LPSTR buffer, int length) {
	if (object) {
		std::vector<CefString> *pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= 0 && index < pStrVector->size()) {
			const auto &element = pStrVector->at(index);
			if (element.length() <= 0) return 0;
			aqua_convert conv;
			auto text = conv.to_bytes(element.c_str());
			if (length == 0) {
				return text.length();
			}
			else {
				memmove(buffer, text.c_str(), text.length());
				return text.length();
			}
		}
	}
	return 0;
}

///
//	��ȡ��Ա�������|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ��ȡ�
///
AQUAENTRYFULL(int, StrVector, GetElementW)(LPVOID object, int index, LPWSTR buffer, int length) {
	if (object) {
		std::vector<CefString> *pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		if (index >= 0 && index < pStrVector->size()) {
			const auto &element = pStrVector->at(index);
			if (element.length() <= 0) return 0;
			if (length == 0) {
				return element.length();
			}
			else {
				memmove(buffer, element.c_str(), element.length() * sizeof(wchar_t));
				return element.length();
			}
		}
	}
	return 0;
}

///
//	�����ַ����������
///
AQUAENTRYFULL(void, StrVector, Destory)(LPVOID object) {
	if (object) {
		std::vector<CefString> *pStrVector = reinterpret_cast<std::vector<CefString>*>(object);
		pStrVector->clear();
		delete pStrVector;
	}
}

///
//	ִ�и÷��������һ���µ��ֵ����
///
AQUAENTRYFULL(LPVOID, StrDict, Alloc)(void) {
	return new std::map<CefString, CefString>;
}

///
//	ִ�и÷���������һ������|object|���¸�������
///
AQUAENTRYFULL(LPVOID, StrDict, Copy)(LPVOID object) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString,CefString>*>(object);
		return new std::map<CefString, CefString>(*pStrDict);
	}
	return NULL;
}

///
//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
///
AQUAENTRYFULL(void, StrDict, InsertA)(LPVOID object, LPCSTR key, LPCSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto v = conv.from_bytes(val);
		(*pStrDict)[k] = v;
	}
}

///
//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
///
AQUAENTRYFULL(void, StrDict, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		(*pStrDict)[key] = val;
	}
}

///
//	���ֵ���Ѱ��|key|�������ļ�ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, FindA)(LPVOID object, LPCSTR key, LPSTR buf, int len) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto iter = pStrDict->find(k);
		if (iter == pStrDict->end()) {
			return 0;
		}
		if (len == 0) {
			auto v = conv.to_bytes(iter->second.c_str());
			return v.length();
		}
		else {
			auto v = conv.to_bytes(iter->second.c_str());
			memcpy(buf, v.c_str(), v.length());
			return v.length();
		}
	}
	return 0;
}

///
//	���ֵ���Ѱ��|key|�������ļ�ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, FindW)(LPVOID object, LPCWSTR key, LPWSTR buf, int len) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		auto iter = pStrDict->find(key);
		if (iter == pStrDict->end()) {
			return 0;
		}
		if (len == 0) {
			return iter->second.length();
		}
		else {
			memcpy(buf, iter->second.c_str(), iter->second.length());
			return iter->second.length();
		}
	}
	return 0;
}

///
//	�����ֵ�߽�
///
AQUAENTRYFULL(int, StrDict, GetBound)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		return pStrDict->size();
	}
	return 0;
}

///
//	ִ�и÷����������ֵ�����еĴ��׸���Ա��ʼ����ĵ�����ָ��,����ֵ�Ϊ�ս��᷵��NULL
//	,ʹ������Ҫ��Erase�����ͷ�ָ�롣
///
AQUAENTRYFULL(LPVOID, StrDict, GetFirst)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		if (pStrDict->empty()) return NULL;
		auto p = new std::map<CefString, CefString>::iterator;
		*p = pStrDict->begin();
		return p;
	}
	return NULL;
}

///
//	ִ�и÷����Ὣ|iter|ָ����һ����Ա��
///
AQUAENTRYFULL(BOOL, StrDict, GetNext)(LPVOID object,LPVOID iter) {
	if (iter) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		if (++(*p) != pStrDict->end()) {
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

///
//	ִ�и÷���������|iter|ָ�롣
///
AQUAENTRYFULL(void, StrDict, Erase)(LPVOID iter) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		delete p;
	}
}

///
//	��ȡ�������е�|key|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, GetKeyA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->first.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	��ȡ�������е�|key|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, GetKeyW)(LPVOID iter, LPWSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->first.length();
		}
		else {
			memmove(buf, (*p)->first.c_str(), (*p)->first.length());
			return (*p)->first.length();
		}
	}
	return 0;
}

///
//	��ȡ�������е�|value|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, GetValueA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->second.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	���õ������е�|value|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, SetValueA)(LPVOID iter, LPCSTR value) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.from_bytes(value);
		(*p)->second = k;
	}
	return 0;
}

///
//	��ȡ�������е�|value|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDict, GetValueW)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::map<CefString, CefString>::iterator *p = reinterpret_cast<std::map<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->second.length();
		}
		else {
			memmove(buf, (*p)->second.c_str(), (*p)->second.length());
			return (*p)->second.length();
		}
	}
	return 0;
}

///
//	ɾ��|key|�������ļ�ֵ����
///
AQUAENTRYFULL(void, StrDict, RemoveA)(LPVOID object, LPCSTR key) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto iter = pStrDict->find(k.c_str());
		if (iter != pStrDict->end()) {
			pStrDict->erase(iter);
		}
	}
}

///
//	ɾ��|key|�������ļ�ֵ����
///
AQUAENTRYFULL(void, StrDict, RemoveW)(LPVOID object, LPCWSTR key) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		auto iter = pStrDict->find(key);
		if (iter != pStrDict->end()) {
			pStrDict->erase(iter);
		}
	}
}

///
//	����ֵ��е����м�ֵ���ݡ�
///
AQUAENTRYFULL(void, StrDic, Clear)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		pStrDict->clear();
	}
}

///
//	��ȡ|key|�ֶ�ָ�������Ԫ������,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ��ȡ�
///
AQUAENTRYFULL(int, StrDict, AtA)(LPVOID object, LPCSTR key, LPSTR valBuffer, int valLength) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		aqua_convert conv;
		auto name = conv.from_bytes(key);
		auto value = pStrDict->at(name);
		if (value.length() <= 0) return 0;
		auto text = conv.to_bytes(value.c_str());
		if (valLength == 0) {
			return text.length();
		}
		else {
			memmove(valBuffer, text.c_str(), text.length());
			return  text.length();
		}
	}
	return 0;
}

///
//	��ȡ|key|�ֶ�ָ�������Ԫ������,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ��ȡ�
///
AQUAENTRYFULL(int, StrDict, AtW)(LPVOID object, LPCSTR key, LPSTR valBuffer, int valLength) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		auto value = pStrDict->at(key);
		if (value.length() <= 0) return 0;
		if (valLength == 0) {
			return value.length();
		}
		else {
			memmove(valBuffer, value.c_str(), value.length());
			return  value.length();
		}
	}
	return 0;
}

///
//	�����ַ����ֵ����
///
AQUAENTRYFULL(void, StrDict, Destory)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		pStrDict->clear();
		delete pStrDict;
	}
}

/******************************
*		�����ַ����ֵ�
******************************/

///
//	ִ�и÷��������һ���µ��ֵ����
///
AQUAENTRYFULL(LPVOID, StrDictEx, Alloc)(void) {
	return new std::multimap<CefString, CefString>;
}

///
//	ִ�и÷���������һ������|object|���¸�������
///
AQUAENTRYFULL(LPVOID, StrDictEx, Copy)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		return new std::multimap<CefString, CefString>(*p);
	}
	return NULL;
}

///
//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
///
AQUAENTRYFULL(void, StrDictEx, InsertA)(LPVOID object, LPCSTR key, LPCSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto v = conv.from_bytes(val);
		pStrDict->insert(std::make_pair(k,v));
	}
}

///
//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
///
AQUAENTRYFULL(void, StrDictEx, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		pStrDict->insert(std::make_pair(key, val));
	}
}

///
//	���ֵ���Ѱ��|key|�������ļ�ֵ���ݡ�
///
AQUAENTRYFULL(LPVOID, StrDictEx, FindA)(LPVOID object, LPCSTR key, void **iter) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto max = pStrDict->count(key);
		if (max <= 0) {
			return 0;
		}
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		std::pair<std::multimap<CefString, CefString>::iterator, std::multimap<CefString, CefString>::iterator> range = pStrDict->equal_range(k);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		if (iter != NULL) {
			*iter = new std::multimap<CefString, CefString>::iterator(range.first);
		}
		for (auto iter = range.first; iter != range.second; iter++) {
			pStrVector->push_back(iter->second);
		}
		return pStrVector;
	}
	return NULL;
}

///
//	���ֵ���Ѱ��|key|�������ļ�ֵ���ݡ�
///
AQUAENTRYFULL(LPVOID, StrDictEx, FindW)(LPVOID object, LPCWSTR key, void **iter) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto max = pStrDict->count(key);
		if (max <= 0) {
			return 0;
		}
		std::pair<std::multimap<CefString, CefString>::iterator, std::multimap<CefString, CefString>::iterator> range = pStrDict->equal_range(key);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		if (iter != NULL) {
			*iter = new std::multimap<CefString, CefString>::iterator(range.first);
		}
		for (auto iter = range.first; iter != range.second; iter++) {
			pStrVector->push_back(iter->second);
		}
		return pStrVector;
	}
	return NULL;
}

///
//	�滻�������е�����
///
AQUAENTRYFULL(void, StrDictEx, ReplaceA)(LPVOID iter, LPCSTR val) {
	if (iter) {
		auto p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		(*p)->second = conv.from_bytes(val);
	}
}

///
//	�滻�������е�����
///
AQUAENTRYFULL(void, StrDictEx, ReplaceW)(LPVOID iter, LPCWSTR val) {
	if (iter) {
		auto p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		(*p)->second = val;
	}
}

///
//	�����ֵ�߽�
///
AQUAENTRYFULL(int, StrDictEx, GetBound)(LPVOID object) {
	if (object) {
		auto *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		return pStrDict->size();
	}
	return 0;
}



///
//	ִ�и÷����������ֵ�����еĴ��׸���Ա��ʼ����ĵ�����ָ��,����ֵ�Ϊ�ս��᷵��NULL
//	,ʹ������Ҫ��Erase�����ͷ�ָ�롣
///
AQUAENTRYFULL(LPVOID, StrDictEx, GetFirst)(LPVOID object) {
	if (object) {
		std::map<CefString, CefString> *pStrDict = reinterpret_cast<std::map<CefString, CefString>*>(object);
		if (pStrDict->empty()) return NULL;
		auto p = new std::map<CefString, CefString>::iterator;
		*p = pStrDict->begin();
		return p;
	}
	return NULL;
}

///
//	ִ�и÷����Ὣ|iter|ָ����һ����Ա,�������β�����᷵��FALSE��
///
AQUAENTRYFULL(BOOL, StrDictEx, GetNext)(LPVOID object, LPVOID iter) {
	if (iter) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		if (++(*p) != pStrDict->end()) {
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

///
//	ִ�и÷���������|iter|ָ�롣
///
AQUAENTRYFULL(void, StrDictEx, Erase)(LPVOID iter) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		delete p;
	}
}

///
//	��ȡ�������е�|key|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDictEx, GetKeyA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->first.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	��ȡ�������е�|key|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDictEx, GetKeyW)(LPVOID iter, LPWSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->first.length();
		}
		else {
			memmove(buf, (*p)->first.c_str(), (*p)->first.length());
			return (*p)->first.length();
		}
	}
	return 0;
}

///
//	��ȡ�������е�|value|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDictEx, GetValueA)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.to_bytes((*p)->second.c_str());
		if (len == 0) {
			return k.length();
		}
		else {
			memmove(buf, k.c_str(), k.length());
			return k.length();
		}
	}
	return 0;
}

///
//	���õ������е�|value|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDictEx, SetValueA)(LPVOID iter, LPCSTR value) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		aqua_convert conv;
		auto k = conv.from_bytes(value);
		(*p)->second = k;
	}
	return 0;
}

///
//	��ȡ�������е�|value|��ֵ���ݡ�
///
AQUAENTRYFULL(int, StrDictEx, GetValueW)(LPVOID iter, LPSTR buf, int len) {
	if (iter) {
		std::multimap<CefString, CefString>::iterator *p = reinterpret_cast<std::multimap<CefString, CefString>::iterator*>(iter);
		if (len == 0) {
			return (*p)->second.length();
		}
		else {
			memmove(buf, (*p)->second.c_str(), (*p)->second.length());
			return (*p)->second.length();
		}
	}
	return 0;
}

///
//	ɾ��|key|�������ļ�ֵ����
///
AQUAENTRYFULL(void, StrDictEx, RemoveA)(LPVOID object, LPCSTR key) {
	if (object) {
		auto pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto max = pStrDict->count(key);
		if (max <= 0) {
			return ;
		}
		aqua_convert conv;
		auto k = conv.from_bytes(key);
		auto it = pStrDict->erase(k);
		//char v1[32];
		//sprintf_s(v1, 32, "%d", it);
		//MessageBoxA(NULL, v1, NULL, NULL);


		
		//std::pair<std::multimap<CefString, CefString>::iterator, std::multimap<CefString, CefString>::iterator> range = pStrDict->equal_range(key);
		
		//for (auto iter = range.first; iter != range.second; iter++) {
		//	pStrDict->erase(iter);
		//}
	}

}

///
//	ɾ��|key|�������ļ�ֵ����
///
AQUAENTRYFULL(void, StrDictEx, RemoveW)(LPVOID object, LPCWSTR key) {
	if (object) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		auto iter = pStrDict->find(key);
		if (iter != pStrDict->end()) {
			pStrDict->erase(iter);
		}
	}
}

///
//	����ֵ��е����м�ֵ���ݡ�
///
AQUAENTRYFULL(void, StrDictEx, Clear)(LPVOID object) {
	if (object) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		pStrDict->clear();
	}
}

///
//	�����ַ����ֵ����
///
AQUAENTRYFULL(void, StrDictEx, Destory)(LPVOID object) {
	if (object) {
		std::multimap<CefString, CefString> *pStrDict = reinterpret_cast<std::multimap<CefString, CefString>*>(object);
		delete pStrDict;
	}
}

///
//	ִ�и÷����󽫻���һ��"String Vector"�ַ�����������,
//	��η������������Կ���"StrVector"�������ṩ�ķ������ϡ�
///
AQUAENTRYFULL(LPVOID, Int64Vector, Alloc)(void) {
	return new std::vector<int64>;
}

///
//	ִ�и÷����󽫻���һ����|object|�����п������¸�������,
//	���|object|���Ϸ�������һ��NULL
///
AQUAENTRYFULL(LPVOID, Int64Vector, Copy)(LPVOID object) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		return new std::vector<int64>(*pInt64Vector);
	}
	return NULL;
}

///
//	ִ�и÷�����|object|ָ���"String Vector"�ַ���������
//	׷���ַ���|text|
///
AQUAENTRYFULL(void, Int64Vector, Append)(LPVOID object, __int64 value) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		pInt64Vector->push_back(value);
	}
}

///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
//	���������ַ���ֵ
///
AQUAENTRYFULL(void, Int64Vector, Replace)(LPVOID object, int index, __int64 value) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		(*pInt64Vector)[index]=value;
	}
}

///
//	ִ�и÷��������Ƴ�|object|ָ���"String Vector"�ַ���������|index|���������ַ���ֵ
///
AQUAENTRYFULL(void, Int64Vector, Remove)(LPVOID object, int index) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		pInt64Vector->erase(pInt64Vector->begin() + index);
	}
}

///
//	ִ�и÷����󽫻����|object|ָ���"String Vector"�ַ��������е������ַ���ֵ
///
AQUAENTRYFULL(void, Int64Vector, Clear)(LPVOID object) {
	if (object) {
		auto pInt64Vector = reinterpret_cast<std::vector<int64>*>(object);
		pInt64Vector->clear();
	}
}

///
//	��������߽�
///
AQUAENTRYFULL(int, Int64Vector, GetBound)(LPVOID object) {
	if (object) {
		return reinterpret_cast<std::vector<int64>*>(object)->size();
	}
	return 0;
}

///
//	���������Ա����,|index|��0��ʼ��
///
AQUAENTRYFULL(__int64, Int64Vector, GetElement)(LPVOID object, int index) {
	if (object) {
		return reinterpret_cast<std::vector<__int64>*>(object)->at(index);
	}
	return 0;
}

///
//	����Int64�������
///
AQUAENTRYFULL(void, Int64Vector, Destory)(LPVOID object) {
	if (object) {
		reinterpret_cast<std::vector<int64>*>(object)->clear();
		delete reinterpret_cast<std::vector<int64>*>(object);
	}
}