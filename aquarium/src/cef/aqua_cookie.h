#ifndef AQUA_COOKIE_H_
#define AQUA_COOKIE_H_

#include "utils\aqua_utils.h"

/**
  * ���ڹ���Cookie���ࡣ ��������˵��������������κ��߳��ϵ��ô���ķ�����
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	����ȫ��cookie�������� 
	//	Ĭ������£����ݽ��洢��CefSettings.cache_path�У������ָ���������򽫴洢���ڴ��С� 
	//	���| callback | �ǿգ������ڹ������洢��ʼ������IO�߳����첽ִ�С� 
	//	ʹ�ô˷����൱�ڵ���CefRequestContext::GetGlobalContext����->GetDefaultCookieManager������
	///
	AQUAENTRYFULL(LPVOID, Cookie, InitFromGlobal)(void);

	///
	//	����IO�߳��ϵ�Cookie�Ӽ��� 
	//	�����������url���������������·�����й��ˡ� 
	//	���| includeHttpOnly | ����ʵ��HTTP-only cookiesҲ������ڽ���С� 
	//	���ص�cookies���·������Ȼ�����紴��������������޷�����cookie���򷵻�false��
	///
	AQUAENTRYFULL(void, Cookie, GetUrlCookies)(LPVOID object,LPCSTR url,bool includeHttponly,LPVOID callback, LPVOID params);

	///
	//	����IO�߳��ϵ�����cookie�� ���ص�Cookie�ǰ������·����Ȼ������Ĵ������ڡ�
	//	���cookieΪfalse���򷵻�false�޷����ʡ�
	///
	AQUAENTRYFULL(void, Cookie, GetAllCookies)(LPVOID object, LPVOID callback,LPVOID params);

	///
	//	����һ����Ч��URL����ʽ���û��ṩ��cookie���ԡ� 
	//	�����������ÿ�����Զ��Ǹ�ʽ���õġ� 
	//	�����鲻������ַ�������';'�ַ��ǲ������
	//	��cookieֵ�����У�������δ����cookie�������ʧ��
	//	�������ַ����ҵ��� 
	//	��� | callback | ���Ƿ�NULL������ִ����cookie�����ú���IO�߳����첽��
	//	�������ָ������Ч��URL���޷�����Cookie���򷵻�false��
	///
	AQUAENTRYFULL(bool, Cookie, SetCookie)(LPVOID object,LPCSTR name,LPCSTR value,LPCSTR url,bool secure,bool httponly,bool has_expires,LPVOID expires);

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
	AQUAENTRYFULL(bool, Cookie, DeleteCookie)(LPVOID object,LPCSTR url,LPCSTR cookie_name);

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
	AQUAENTRYFULL(void, Cookie, SetStoragePath)(LPVOID object,LPCSTR path,bool persist_session_cookies);

	///
	//	���󱸴洢������У���ϴ�����̡� ���| callback | ���Ƿ�NULL��
	//	��ˢ����ɺ���IO�߳����첽ִ�С�
	//	����޷�����Cookie���򷵻�false��
	///
	AQUAENTRYFULL(void, Cookie, FlushStore)(LPVOID object);

	///
	//	�����ض�domain�µ�����cookie�Ӽ�������HTTP��ʽ��ϳ�һ���ַ�����
	///
	AQUAENTRYFULL(void, Cookie, GetCookieMerge)(LPVOID object,LPCSTR url);

	///
	//	��һ��HTTP��ʽ��cookie�Ӽ��ַ����洢����ǰcookie��������,����domain������
	///
	AQUAENTRYFULL(void, Cookie, SetCookieMerge)(LPVOID object,LPCSTR url,LPCSTR items);


}

#endif