#include "cef\aqua_cookie.h"
#include "include\cef_cookie.h"
#include "calling\aqua_calling_cookie.h"
#include "utils\aqua_conv.h"
#include <map>
#include <vector>
#include "cpprest\http_client.h"

using namespace AquaCef;

///
//	����ȫ��cookie�������� 
//	Ĭ������£����ݽ��洢��CefSettings.cache_path�У������ָ���������򽫴洢���ڴ��С� 
//	���| callback | �ǿգ������ڹ������洢��ʼ������IO�߳����첽ִ�С� 
//	ʹ�ô˷����൱�ڵ���CefRequestContext::GetGlobalContext����->GetDefaultCookieManager������
///
AQUAENTRYFULL(LPVOID, Cookie, InitFromGlobal)(void) {
	CefRefPtr<CefCookieManager> manager = CefCookieManager::GetGlobalManager(NULL);
	manager->AddRef();
	return (LPVOID)manager.get();
}

///
//	����IO�߳��ϵ�Cookie�Ӽ��� 
//	�����������url���������������·�����й��ˡ� 
//	���| includeHttpOnly | ����ʵ��HTTP-only cookiesҲ������ڽ���С� 
//	���ص�cookies���·������Ȼ�����紴��������������޷�����cookie���򷵻�false��
///
AQUAENTRYFULL(void, Cookie, GetUrlCookies)(LPVOID object, LPCSTR url, bool includeHttponly, LPVOID callback,LPVOID params) {
	if (object && url!=NULL && strlen(url) > 0) {
		std::vector<CefCookie> pvx;
		pplx::task_completion_event<void>  tce;
		auto calling = pplx::create_task(tce);
		auto p = reinterpret_cast<CefCookieManager*>(object);
		aqua_convert conv;
		auto fullUrl = conv.from_bytes(url);
		p->AddRef();
		p->VisitUrlCookies(fullUrl,includeHttponly,new AquaCallCookie(&pvx, &tce));
		p->Release();
		try
		{
			calling.wait();
		}
		catch (const std::exception&)
		{

		}
		
		std::string name, value, domain;
		int max = pvx.size();
		for (size_t i = 0; i < pvx.size(); i++)
		{
			const auto &v = pvx[i];
			if (v.name.length > 0) {
				name = conv.to_bytes(v.name.str);
			}
			if (v.value.length > 0) {
				value = conv.to_bytes(v.value.str);
			}
			if (v.domain.length > 0) {
				domain = conv.to_bytes(v.domain.str);
			}
			((LPFN_VISIT_COOKIE)callback)(max, name.c_str(), value.c_str(), domain.c_str(), v.secure, v.httponly, v.has_expires, (LPVOID)&v.expires, params);
		}
		pvx.clear();
	}
}

///
//	����IO�߳��ϵ�����cookie�� ���ص�Cookie�ǰ������·����Ȼ������Ĵ������ڡ�
//	���cookieΪfalse���򷵻�false�޷����ʡ�
///
AQUAENTRYFULL(void, Cookie, GetAllCookies)(LPVOID object, LPVOID callback, LPVOID params) {
	if (object) {
		std::vector<CefCookie> pvx;
		pplx::task_completion_event<void>  tce;
		auto calling = pplx::create_task(tce);
		auto p = reinterpret_cast<CefCookieManager*>(object);
		p->AddRef();
		p->VisitAllCookies(new AquaCallCookie(&pvx, &tce));
		p->Release();
		try
		{
			calling.wait();
		}
		catch (const std::exception&)
		{

		}
		
		aqua_convert conv;
		std::string name, value, domain;
		int max = pvx.size();
		for (size_t i = 0; i < pvx.size(); i++)
		{
			const auto &v = pvx[i];
			if (v.name.length > 0) {
				name = conv.to_bytes(v.name.str);
			}
			if (v.value.length > 0) {
				value = conv.to_bytes(v.value.str);
			}
			if (v.domain.length > 0) {
				domain = conv.to_bytes(v.domain.str);
			}
			((LPFN_VISIT_COOKIE)callback)(max,name.c_str(), value.c_str(), domain.c_str(), v.secure, v.httponly, v.has_expires, (LPVOID)&v.expires,params);
		}
		if (max == 0) {
			((LPFN_VISIT_COOKIE)callback)(max, NULL, NULL, NULL, false, false, false, NULL, params);
		}
		pvx.clear();
	}
}

///
//	����һ����Ч��URL����ʽ���û��ṩ��cookie���ԡ� 
//	�����������ÿ�����Զ��Ǹ�ʽ���õġ� 
//	�����鲻������ַ�������';'�ַ��ǲ������
//	��cookieֵ�����У�������δ����cookie�������ʧ��
//	�������ַ����ҵ��� 
//	��� | callback | ���Ƿ�NULL������ִ����cookie�����ú���IO�߳����첽��
//	�������ָ������Ч��URL���޷�����Cookie���򷵻�false��
///
AQUAENTRYFULL(bool, Cookie, SetCookie)(LPVOID object, LPCSTR name, LPCSTR value, LPCSTR url, bool secure, bool httponly, bool has_expires, LPVOID expires) {
	bool result = false;
	if (object) {
		auto p = reinterpret_cast<CefCookieManager*>(object);
		aqua_convert conv;
		CefCookie cookie;
		CefString(&cookie.name) = name;
		CefString(&cookie.value) = value;
		cookie.secure = secure;
		cookie.httponly = httponly;
		cookie.has_expires = has_expires;
		memcpy(&cookie.expires, expires, sizeof(cef_time_t));
		p->AddRef();
		result = p->SetCookie(url, cookie, NULL);
		p->Release();
	}
	return result;
}

///
//	ɾ��������ָ������ƥ���cookie�� 
//	���| url | ��| cookie_name | ֵ��ָ��Ϊ��������������cookieƥ��
//	���߶�����ɾ���� ���ֻ�� | url | ��ָ����������cookie��������
//	����cookie����������·������ɾ���� ��� | url | ȫ���ǿյ�
//	����������������cookies����ɾ���� ��� | callback | ��
//	�ǿ�������IO�߳�֮���첽ִ��
//	Cookie�ѱ�ɾ���� ����ǿյ���ЧURL�ǣ��򷵻�false
//	ָ�����޷�����Cookie�� ������Խ���ʹ��
//	ʹ��Visit * Cookies��������ɾ����
///
AQUAENTRYFULL(bool, Cookie, DeleteCookie)(LPVOID object, LPCSTR url, LPCSTR cookie_name) {
	bool result = false;
	if (object) {
		auto p = reinterpret_cast<CefCookieManager*>(object);
		aqua_convert conv;
		p->AddRef();
		if (url != NULL && cookie_name != NULL) {
			result = p->DeleteCookies(url, cookie_name, NULL);
		}
		else if (url != NULL) {
			result = p->DeleteCookies(url, TEXT(""), NULL);
		}
		else {
			result = p->DeleteCookies(TEXT(""), TEXT(""), NULL);
		}
		p->Release();
	}
	return result;
}

///
//	���ý����ڴ洢Cookie���ݵ�Ŀ¼·���� ���
//	| ·�� | �ǿյ����ݽ�ֻ�洢���ڴ��С� �������ݽ���
//	�洢��ָ���� | ·�� | �ϡ� ��ֻỰcookie��û��cookies
//	��Ч���޻���Ч���ޣ�set | persist_session_cookies | Ϊ�档
//	�Ựcookieͨ��ּ����ʱ�ʹ����Web
//	��������������ǡ� ��� | callback | ���Ƿ�NULL������ִ��
//	�ھ���Ĵ洢�Ѿ����֮����IO�߳����첽
//	��ʼ���� ����޷�����Cookie���򷵻�false��
///
AQUAENTRYFULL(void, Cookie, SetStoragePath)(LPVOID object, LPCSTR path, bool persist_session_cookies) {

}

///
//	���󱸴洢������У���ϴ�����̡� ���| callback | ���Ƿ�NULL��
//	��ˢ����ɺ���IO�߳����첽ִ�С�
//	����޷�����Cookie���򷵻�false��
///
AQUAENTRYFULL(void, Cookie, FlushStore)(LPVOID object) {
	
	if (object) {
		auto p = reinterpret_cast<CefCookieManager*>(object);
		p->AddRef();
		p->FlushStore(NULL);
		p->Release();
	}
}

///
//	�����ض�domain�µ�����cookie�Ӽ�������HTTP��ʽ��ϳ�һ���ַ�����
///
AQUAENTRYFULL(void, Cookie, GetCookieMerge)(LPVOID object, LPCSTR url) {

}

///
//	��һ��HTTP��ʽ��cookie�Ӽ��ַ����洢����ǰcookie��������,����domain������
///
AQUAENTRYFULL(void, Cookie, SetCookieMerge)(LPVOID object, LPCSTR url, LPCSTR items) {

}