#include "aqua_browser.h"
#include "utils\aqua_conv.h"
#include "include\cef_browser.h"

using namespace AquaCef;

///
//	����������������� �˷���ֻ��������������е��á�
///
AQUAENTRYFULL(LPVOID, Browser, GetHost)(LPVOID object) {
	LPVOID result = NULL;
	char buf[100];
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefBrowserHost> host = pUnit->GetHost();
		if (host.get()) {
			host->AddRef();
			result = host.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	��������������󵼺����򷵻�true��
///
AQUAENTRYFULL(BOOL, Browser, CanGoBack)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->CanGoBack();
		pUnit->Release();
	}
	return result;
}

///
//	��󵼺���
///
AQUAENTRYFULL(void, Browser, GoBack)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->GoBack();
		pUnit->Release();
	}
}

///
//	��������������ǰ�������򷵻�true��
///
AQUAENTRYFULL(BOOL, Browser, CanGoForward)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->CanGoForward();
		pUnit->Release();
	}
	return result;
}

///
//	��ǰ������
///
AQUAENTRYFULL(void, Browser, GoForward)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->GoForward();
		pUnit->Release();
	}
}

///
//	�����������ڼ��أ��򷵻�true��
///
AQUAENTRYFULL(BOOL, Browser, IsLoading)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->IsLoading();
		pUnit->Release();
	}
	return result;
}

///
//	���¼��ص�ǰҳ�档
///
AQUAENTRYFULL(void, Browser, Reload)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->Reload();
		pUnit->Release();
	}
}

///
//	���¼��ص�ǰҳ�棬�����κλ�������ݡ�
///
AQUAENTRYFULL(void, Browser, ReloadIgnoreCache)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->ReloadIgnoreCache();
		pUnit->Release();
	}
}

///
//	ֹͣ����ҳ�档
///
AQUAENTRYFULL(void, Browser, StopLoad)(LPVOID object) {
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		pUnit->StopLoad();
		pUnit->Release();
	}
}

///
//	���ش��������ȫ��Ψһ��ʶ���� ��ֵҲ������չAPI��tabId��
///
AQUAENTRYFULL(int, Browser, GetIdentifier)(LPVOID object) {
	int result = 0;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->GetIdentifier();
		pUnit->Release();
	}
	return result;
}

///
//	����˶���ָ����| that |��ͬ�ľ�����򷵻�true Ŀ�ġ�
///
AQUAENTRYFULL(BOOL, Browser, IsSame)(LPVOID object, LPVOID that) {
	BOOL result = FALSE;
	if (object && that) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		CefBrowser *pThat = reinterpret_cast<CefBrowser*>(that);
		pUnit->AddRef();
		pThat->AddRef();
		result = pUnit->IsSame(pThat);
		pUnit->Release();
		pThat->Release();
	}
	return result;
}

///
//	���������һ���������ڣ��򷵻�true��
///
AQUAENTRYFULL(BOOL, Browser, IsPopup)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->IsPopup();
		pUnit->Release();
	}
	return result;
}

///
//	����ĵ��ѱ����ص�������У��򷵻�true��
///
AQUAENTRYFULL(BOOL, Browser, HasDocument)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->HasDocument();
		pUnit->Release();
	}
	return result;
}

///
//	������������ڵ�������������ܡ�
///
AQUAENTRYFULL(LPVOID, Browser, GetMainFrame)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetMainFrame();
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	������������ڵĽ����
///
AQUAENTRYFULL(LPVOID, Browser, GetFocusedFrame)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFocusedFrame();
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	���ؾ���ָ����ʶ����Frame�����δ�ҵ����򷵻�NULL��
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameFromId)(LPVOID object, int64 identify) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFrame(identify);
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	���ؾ���ָ�����Ƶ�Frame�����δ�ҵ����򷵻�NULL��
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameA)(LPVOID object, LPCSTR name) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		aqua_convert conv;
		auto key = conv.from_bytes(name);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFrame(key);
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	���ؾ���ָ�����Ƶ�Frame�����δ�ҵ����򷵻�NULL��
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameW)(LPVOID object, LPCWSTR name) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		CefRefPtr<CefFrame> frame = pUnit->GetFrame(name);
		if (frame.get()) {
			frame->AddRef();
			result = frame.get();
		}
		pUnit->Release();
	}
	return result;
}

///
//	���ص�ǰ���ڵ�֡����
///
AQUAENTRYFULL(int, Browser, GetFrameCount)(LPVOID object) {
	int result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		pUnit->AddRef();
		result = pUnit->GetFrameCount();
		pUnit->Release();
	}
	return result;
}

///
//	������������Frame�ı�ʶ����
//	����Int64����,���ʷ����μ�"Int64Vector"�������
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameIdentifiers)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		std::vector<int64> *pInt64Vector = new std::vector<int64>;
		pUnit->AddRef();
		pUnit->GetFrameIdentifiers((*pInt64Vector));
		pUnit->Release();
		result = pInt64Vector;
	}
	return result;
}

///
//	������������Frame�����ơ�
//	�����ַ�������,���ʷ����μ�"StrVector"�������
///
AQUAENTRYFULL(LPVOID, Browser, GetFrameNames)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		pUnit->AddRef();
		pUnit->GetFrameNames((*pStrVector));
		pUnit->Release();
		result = pStrVector;
	}
	return result;
}

///
//	������Ϣ��ָ����| target_process |�� �����Ϣ�ѳɹ����ͣ��򷵻�true��
///
AQUAENTRYFULL(BOOL, Browser, SendProcessMessageA)(LPVOID object, int target_process, LPCSTR message, char *payload, int length) {
	BOOL result = FALSE;
	if (object) {
		CefBrowser *pUnit = reinterpret_cast<CefBrowser*>(object);
		aqua_convert conv;
		auto name = conv.from_bytes(message);
		pUnit->AddRef();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create(name);
		CefRefPtr<CefListValue> argument = msg->GetArgumentList();
		CefRefPtr<CefBinaryValue> binary = CefBinaryValue::Create(payload, length);
		argument->SetSize(1);
		argument->SetBinary(0, binary);
		result = pUnit->SendProcessMessage((CefProcessId)target_process, msg);
		pUnit->Release();
	}
	return result;
}