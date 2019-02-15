#include "cef\aqua_frame.h"
#include "include\cef_browser.h"
#include "calling\aqua_calling_visitor.h"
#include "include\cef_app.h"
#include "utils\aqua_conv.h"
#include "calling\aqua_calling_v8.h"
#include "env\include\cpprest\http_client.h"

#pragma comment(lib,"cpprest140_xp_2_10.lib")


using namespace AquaCef;

///
//	����˶���ǰ���ӵ���Ч��ܣ���Ϊ�档
///
AQUAENTRYFULL(BOOL, Frame, IsValid)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		result = pFrame->IsValid();
		pFrame->Release();
	}
	return result;
}

///
//	�ڴ˿����ִ�г�����
///
AQUAENTRYFULL(void, Frame, Undo)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->Undo();
		pFrame->Release();
	}
}

///
//	�ڴ˿����ִ��������
///
AQUAENTRYFULL(void, Frame, Redo)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->Redo();
		pFrame->Release();
	}
}

///
//	�ڴ˿����ִ�м��С�
///
AQUAENTRYFULL(void, Frame, Cut)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->Cut();
		pFrame->Release();
	}
}

///
//	����������ִ�и��ơ�
///
AQUAENTRYFULL(void, Frame, Copy)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->Copy();
		pFrame->Release();
	}
}

///
//	����������ִ��ճ����
///
AQUAENTRYFULL(void, Frame, Paste)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->Paste();
		pFrame->Release();
	}
}

///
//	�ڴ˿���ִ��ɾ����
///
AQUAENTRYFULL(void, Frame, Delete)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->Delete();
		pFrame->Release();
	}
}

///
//	ִ���ڴ˿���ѡ��ȫ����
///
AQUAENTRYFULL(void, Frame, SelectAll)(LPVOID object) {
	if (object) {
		auto pFrame = reinterpret_cast<CefFrame*>(object);
		pFrame->AddRef();
		pFrame->SelectAll();
		pFrame->Release();
	}
}

///
//	�Է��͵�ָ�������ߵ��ַ��������˿�ܵ�HTMLԴ���롣
///
AQUAENTRYFULL(BOOL, Frame, GetSourceA)(LPVOID object, LPVOID callback, LPVOID params, BOOL async) {
	BOOL result = FALSE;
	if (CefCurrentlyOn(TID_RENDERER) || CefCurrentlyOn(TID_UI)) {
		if (async == FALSE) {
			return FALSE;
		}
	}
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = AquaCallStringVisitor::OutputString(frame, (LPFN_STRING_OUTPUTA)callback, params,async,0);
		frame->Release();
	}
	return result;
}

///
//	�Է��͵�ָ�������ߵ��ַ��������˿�ܵ�HTML�ı���
///
AQUAENTRYFULL(BOOL, Frame, GetTextA)(LPVOID object, LPVOID callback, LPVOID params, BOOL async) {
	BOOL result = FALSE;
	if (CefCurrentlyOn(TID_RENDERER) || CefCurrentlyOn(TID_UI)) {
		if (async == FALSE) {
			return FALSE;
		}
	}
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = AquaCallStringVisitor::OutputString(frame, (LPFN_STRING_OUTPUTA)callback, params, async, 1);
		frame->Release();
	}
	return result;
}

///
//	����ָ����| url |��
///
AQUAENTRYFULL(BOOL, Frame, LoadURLA)(LPVOID object, LPCSTR url) {
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		aqua_convert conv;
		auto tempBuf = conv.from_bytes(url);
		frame->AddRef();
		frame->LoadURL(tempBuf);
		frame->Release();
	}
	return TRUE;
}

///
//	����| string_val |������ ʹ��ָ��������| url |��|��ַ|
//	Ӧ����һ����׼�ķ��������磬http�����������Ƶ���Ϊ
//	���ӵ�����������簲ȫ���ƿ����޷���Ԥ�����С�
///
AQUAENTRYFULL(BOOL, Frame, LoadStringA)(LPVOID object, LPCSTR html, LPCSTR url) {
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		aqua_convert conv;
		auto tempBuf = conv.from_bytes(html);
		auto tempBuf2 = conv.from_bytes(url);
		frame->AddRef();
		frame->LoadString(tempBuf, tempBuf2);
		frame->Release();
	}
	return TRUE;
}

AQUAENTRYFULL(void, Frame, LoadRequest)(LPVOID object, LPVOID request) {
	if (object && request) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		auto req = reinterpret_cast<CefRequest*>(request);
		frame->AddRef();
		req->AddRef();
		frame->LoadRequest(req);
		req->Release();
		frame->Release();
	}
}

///
//	�ڴ˿����ִ��һ��JavaScript���롣 | script_url |
//	�����ǿ����ҵ�������Ľű���URL������еĻ���
//	��Ⱦ�����ܻ������URL���򿪷���Ա��ʾ
//	���� | start_line | ���������ڳ���Ļ��ߺ�
//	���档
///
AQUAENTRYFULL(BOOL, Frame, ExecuteJavaScriptA)(LPVOID object, LPCSTR code, LPCSTR url, int line) {
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		aqua_convert conv;
		auto tempBuf = conv.from_bytes(code);
		auto tempBuf2 = conv.from_bytes(url);
		frame->AddRef();
		frame->ExecuteJavaScript(tempBuf, tempBuf2,line);
		frame->Release();
	}
	return TRUE;
}

///
//	�������������������ܣ��򷵻�true��
///
AQUAENTRYFULL(BOOL, Frame, IsMain)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = frame->IsMain();
		frame->Release();
	}
	return result;
}

///
//	������Ǿ۽���ܣ��򷵻�true��
///
AQUAENTRYFULL(BOOL, Frame, IsFocused)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = frame->IsValid();
		frame->Release();
	}
	return result;
}

///
//	���ش�֡�����ơ� ��������һ����������ƣ�����
//	���磬ͨ��iframe��name���������ã�����ô��ֵ����
//	�ء� ���򣬽����ݸÿ�ܹ���Ψһ������
//	����νṹ�� ������������ܽ�ʼ����һ���յ�����
//	ֵ��
///
AQUAENTRYFULL(int, Frame, GetNameA)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		CefString name;
		frame->AddRef();
		name = frame->GetName();
		frame->Release();
		if (name.length() <= 0) {
			return 0;
		}
		aqua_convert conv;
		auto text = conv.to_bytes(name.c_str());
		if (len <= 0) return text.length();
		memmove(buf, text.c_str(), text.length());
		return text.length();
	}
	return result;
}

///
//	���ش�֡��ȫ��Ψһ��ʶ��������ײ�֡�в����ڣ��򷵻�<0��
///
AQUAENTRYFULL(__int64, Frame, GetIdentifier)(LPVOID object) {
	__int64 result = -1;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = frame->GetIdentifier();
		frame->Release();
	}
	return result;
}

///
//	���ش�֡�ĸ�Ԫ�ػ�NULL�������������������֡��
///
AQUAENTRYFULL(LPVOID, Frame, GetParent)(LPVOID object) {
	CefRefPtr<CefFrame> result = NULL;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = frame->GetParent().get();
		frame->Release();
		if (result.get() != NULL) {
			result->AddRef();
		}
	}
	return result.get();
}

///
//	���ص�ǰ�ڴ˿���м��ص�URL��
///
AQUAENTRYFULL(int, Frame, GetURLA)(LPVOID object, LPSTR buf, int len) {
	int result = 0;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		CefString name;
		frame->AddRef();
		name = frame->GetURL();
		frame->Release();
		if (name.length() <= 0) {
			return 0;
		}
		aqua_convert conv;
		auto text = conv.to_bytes(name.c_str());
		if (len <= 0) return text.length();
		memmove(buf, text.c_str(), text.length());
		return text.length();
	}
	return result;
}

///
//	���ش�֡�������������
///
AQUAENTRYFULL(LPVOID, Frame, GetBrowser)(LPVOID object) {
	CefRefPtr<CefBrowser> result = NULL;
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		frame->AddRef();
		result = frame->GetBrowser().get();
		frame->Release();
		if (result.get() != NULL) {
			result->AddRef();
		}
	}
	return result.get();
}

///
//	ִ�б��ʽ
///
AQUAENTRYFULL(void, Frame, EvalA)(LPVOID object, LPCSTR code, LPCSTR url, int line, LPVOID callback, LPVOID params,BOOL async) {
	if (object) {
		auto frame = reinterpret_cast<CefFrame*>(object);
		CefRefPtr<CefBrowser> browser = NULL;
		aqua_convert conv;
		frame->AddRef();
		browser = frame->GetBrowser();
		CefRefPtr<CefProcessMessage> message = CefProcessMessage::Create(TEXT("EVAL"));
		CefRefPtr<CefListValue> arg = message->GetArgumentList();
		pplx::task_completion_event<CefRefPtr<CefListValue>> *result = new pplx::task_completion_event<CefRefPtr<CefListValue>>;
		arg->SetSize(5);
		auto buf = conv.from_bytes(code);
		auto vUrl = conv.from_bytes(url);
		arg->SetString(0, frame->GetName());
		arg->SetString(1, buf);
		arg->SetString(2, vUrl);
		arg->SetInt(3, line);
		arg->SetInt(4, (int)result);

		static auto exec = [](CefRefPtr<CefListValue> retval, LPVOID callback, LPVOID params) {
			aqua_convert conv;
			LPFN_V8_EVAL cb = (LPFN_V8_EVAL)callback;
			if (retval.get() == NULL) {
				cb(0, NULL, false, NULL, NULL, params, NULL);
			}
			else {
				int type = retval->GetInt(0);
				if (type == -1) {
					CefString exp = retval->GetString(1);
					auto v1 = conv.to_bytes(exp.c_str());
					((LPFN_V8_EVAL)callback)(type, NULL, false, NULL, NULL, params, v1.c_str());
					
				}
				else if (type == 0) {
					((LPFN_V8_EVAL)callback)(type, NULL, false, NULL, NULL, params, NULL);
				}
				else if (type == 1) {
					((LPFN_V8_EVAL)callback)(type, NULL, retval->GetBool(1), NULL, NULL, params, NULL);
				}
				else if (type == 2) {
					((LPFN_V8_EVAL)callback)(type, NULL, false, retval->GetInt(1), NULL, params, NULL);
				}
				else if (type == 3) {
					((LPFN_V8_EVAL)callback)(type, NULL, false, NULL, retval->GetDouble(1), params, NULL);
				}
				else if (type == 4) {
					CefString v1 = retval->GetString(1);
					std::string v2 = conv.to_bytes(v1.c_str());
					((LPFN_V8_EVAL)callback)(type, v2.c_str(), false, NULL, NULL, params, NULL);

				}
				else {
					((LPFN_V8_EVAL)callback)(type, NULL, false, NULL, NULL, params, NULL);
				}
			}
		};
		browser->SendProcessMessage(PID_RENDERER, message);
		if (async == FALSE) {
			try {
				exec(pplx::create_task(*result).get(), callback, params);
				delete result;
			}
			catch (const std::exception&) {
				exec(NULL, callback, params);
				delete result;
			}
		}
		else {
			pplx::create_task(*result).then([callback, params,result](CefRefPtr<CefListValue> retval) {
				exec(retval, callback, params);
			}).then([callback, params,result](pplx::task<void> t) {
				try
				{
					t.get();
					delete result;
				}
				catch (const std::exception&)
				{
					exec(NULL, callback, params);
					delete result;
				}
			});
		}
		

	}
}