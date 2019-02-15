#ifndef AQUA_LAUNCH_H_
#define AQUA_LAUNCH_H_
#include "utils\aqua_utils.h"

namespace AquaLaunch {
	/**
	 *	ϵͳ��ʼ����غ���
	 */

	///
	//	��ʼ���ص�����,�ڴ˷����п��Խ���һЩ��ʼ������,��������ò�������ͨ�������н�������,
	//	ʹ�ô���Initǩ���ķ������в������á�
	///
	typedef void(CALLBACK *AquaInitCallback)(LPVOID conf);

	///
	//	�������ݽ��洢�ڴ����ϵ�λ�á�����ǿյĻ�������������û������ڵġ�����ģʽ���´���
	//	���ڴ洢����û�����ݱ����浽���̡�HTML5�����ݿ� localStorageֻ���ڻ���·������
	//	������³��������ڻỰ��ָ����
	///
	AQUAENTRY(void, InitCachePathA)(LPVOID conf,LPCSTR path);

	///
	//	�������ݽ��洢�ڴ����ϵ�λ�á�����ǿյĻ�������������û������ڵġ�����ģʽ���´���
	//	���ڴ洢����û�����ݱ����浽���̡�HTML5�����ݿ� localStorageֻ���ڻ���·������
	//	������³��������ڻỰ��ָ����
	///
	AQUAENTRY(void, InitCachePathW)(LPVOID conf, LPCWSTR path);

	///
	//	ƴд����ֵ��ļ����û��������ڵ�λ�ô洢�ڴ����ϡ� ���Ϊ�գ���ΪĬ��ƽ̨�ض����û�����
	//	��ʹ��Ŀ¼��Linux�ϵ�"~/.cef_user_data"Ŀ¼��Mac OS X�ϵ�"~/Library/Application
	//	Support/CEF/User Data"Ŀ¼��Windows �ϵ�"Local Settings\Application Data\CEF
	//	\User Data"�����ļ�Ŀ¼��
	///
	AQUAENTRY(void, InitUserDataA)(LPVOID conf, LPCSTR path);

	///
	//	ƴд����ֵ��ļ����û��������ڵ�λ�ô洢�ڴ����ϡ� ���Ϊ�գ���ΪĬ��ƽ̨�ض����û�����
	//	��ʹ��Ŀ¼��Linux�ϵ�"~/.cef_user_data"Ŀ¼��Mac OS X�ϵ�"~/Library/Application
	//	Support/CEF/User Data"Ŀ¼��Windows �ϵ�"Local Settings\Application Data\CEF
	//	\User Data"�����ļ�Ŀ¼��
	///
	AQUAENTRY(void, InitUserDataW)(LPVOID conf, LPCWSTR path);

	///
	//	����ΪTRUE,�������޴��ڣ���������Ⱦ֧�֡����Ӧ�ó���ʹ���޴�����Ⱦ�����ô�ֵ
	//	�����ܻή��ĳЩϵͳ����Ⱦ���ܡ�
	///
	AQUAENTRY(void, InitWindowlessRenderingEnabled)(LPVOID conf,BOOL enabled);

	///
	//	���ֻỰcookie��û�е����ջ���Ч�ڵ�cookie�����Ĭ�������ʹ��ȫ��cookie������
	//	����ֵ����ΪTRUE,�Ựcookieͨ���Ƕ��ݵģ����Ҵ󲿷ֶ���Web���������������ǡ�
	//	��ʹ������|cache_path|Ҳ������ָ�����ô˹��ܡ�Ҳ����ʹ�á�persist-session-cookies�������п��ء�
	//	�������á�
	///
	AQUAENTRY(void, InitPersistSessionCookies)(LPVOID conf, BOOL enabled);

	///
	//	�������ΪTRUE,���û���ѡ���Ϊ����·��Ŀ¼���е�JSON�ļ�,��ʹ������|cache_path|
	//	Ҳ������ָ�����ô˹��ܡ�Ҳ����ʹ��"persist-user-preferences"�����п��ء��������á�
	///
	AQUAENTRY(void, InitPersistUserPreferences)(LPVOID conf, BOOL enabled);

	///
	//	����ΪUser-Agent HTTP��ͷ���ص�ֵ���������˽�ʹ��Ĭ�ϵ�User-Agent�ַ�����
	//	Ҳ����ʹ��"user-agent"�����п���,�������á�
	///
	AQUAENTRY(void, InitUserAgentA)(LPVOID conf, LPCSTR value);

	///
	//	����ΪUser-Agent HTTP��ͷ���ص�ֵ���������˽�ʹ��Ĭ�ϵ�User-Agent�ַ�����
	//	Ҳ����ʹ��"user-agent"�����п���,�������á�
	///
	AQUAENTRY(void, InitUserAgentW)(LPVOID conf, LPCWSTR value);

	///
	//	����ΪĬ�ϲ�Ʒ���ֲ����ֵUser-Agent�ַ������ַ��������Ϊ�գ���ʹ��Chromium��Ʒ�汾��
	//	���| userAgent |ָ����ֵ�������ԡ�Ҳ������"product-version"�����п��ء�
	///
	AQUAENTRY(void, InitProductVersionA)(LPVOID conf, LPCSTR value);


	///
	//	����ΪĬ�ϲ�Ʒ���ֲ����ֵUser-Agent�ַ������ַ��������Ϊ�գ���ʹ��Chromium��Ʒ�汾��
	//	���| userAgent |ָ����ֵ�������ԡ�Ҳ������"product-version"�����п��ء�
	///
	AQUAENTRY(void, InitProductVersionW)(LPVOID conf, LPCWSTR value);

	///
	//	�����ݸ�WebKit�����Ի����ַ�����������Ĭ��ֵ��ʹ�á�en-US�������Ի����� 
	//	�����Ի�����Linux�ϣ���ֵ��������ʹ������˳��ʹ�û�������������ȷ����
	//	LANGUAGE��LC_ALL��LC_MESSAGES��LANG��������ʹ��"lang"���������л���
	///
	AQUAENTRY(void, InitLocaleA)(LPVOID conf, LPCSTR value);

	///
	//	�����ݸ�WebKit�����Ի����ַ�����������Ĭ��ֵ��ʹ�á�en-US�������Ի����� 
	//	�����Ի�����Linux�ϣ���ֵ��������ʹ������˳��ʹ�û�������������ȷ����
	//	LANGUAGE��LC_ALL��LC_MESSAGES��LANG��������ʹ��"lang"���������л���
	///
	AQUAENTRY(void, InitLocaleW)(LPVOID conf, LPCWSTR value);

	///
	//	��ʼ��V8 JavaScript����ʱ��ʹ�õ��Զ����־��ʹ���Զ����־�ĺ������û��
	//	�õ��ܺõĲ��ԡ�ʹ�á�js-flags�������п��ؽ������á�
	///
	AQUAENTRY(void, InitJavascriptFlagsA)(LPVOID conf, LPCSTR value);

	///
	//	��ʼ��V8 JavaScript����ʱ��ʹ�õ��Զ����־��ʹ���Զ����־�ĺ������û��
	//	�õ��ܺõĲ��ԡ�ʹ�á�js-flags�������п��ؽ������á�
	///
	AQUAENTRY(void, InitJavascriptFlagsW)(LPVOID conf, LPCWSTR value);

	///
	//	����Ϊtrue,����Ϊ��Դ���������ü��ذ��ļ�������Ϊ���������Ⱦ�ṩ��Դ���������
	//	������ذ��ļ�����ͨ��CefApp :: GetResourceBundleHandler�������д���
	//	�����á� Ҳ����ʹ�á�disable-pack-loading���������������·�л���
	///
	AQUAENTRY(void, InitPackloadingDisabled)(LPVOID conf, BOOL enabled);

	///
	//	����Ϊ1024��65535֮���ֵ������Զ�̵���ָ���Ķ˿ڡ� ���磬���8080��ָ��ΪԶ�̵���URL
	//	����http//localhost:8080��CEF���Դ��κ�CEF����Զ�̵���Chrome��������ڡ� 
	//	Ҳ����ʹ��"remote-debugging-port"�����п��ؽ������á�
	///
	AQUAENTRY(void, InitRemoteDebuggingPort)(LPVOID conf, int value);

	///
	//	Ϊδ������쳣����Ķ�ջ����֡��������ָ��һ����ֵ������CefRenderProcessHandler::OnUncaughtException()
	//	�ص�������ָ��0��Ĭ��ֵ���� OnUncaughtException�������ᱻ���á� Ҳ����ʹ��
	//	"uncaught-exception-stack-size"�����п��ؽ������á�
	///
	AQUAENTRY(void, InitUncaughtExceptionStackSize)(LPVOID conf,int value);

	///
	//	����Ϊtrue��1����������ЧSSL֤����صĴ������ô����ÿ��ܻᵼ��Ǳ�ڵİ�ȫ©��
	//	��"man in the middle"����,�ӻ������������ݵ�Ӧ�ó���Ӧ���ô����á�
	//	Ҳ����ʹ��"ignore-certificate-errors"�����п��ؽ������á�
	//	����ͨ��CefRequestContextSettings.ignore_certificate_errorsֵΪ����CefRequestContextʵ�����ǡ�
	///
	AQUAENTRY(void, InitIgnoreCertificateErrors)(LPVOID conf,BOOL enabled);

	///
	//	����Ϊtrue��1���������������簲ȫ��Ϣ����֤��͸������־��HSTSԤ���غ�������Ϣ���Ļ������ڵĵ��ڡ�
	//	���ô�ѡ���������簲ȫ�ԣ�����ʹ�ù�ȥ10���ڹ�����CEF�������ļ�ʱ���ܻᵼ��HTTPS����ʧ�ܡ�
	//	����� https://www.certificate-transparency.org/ �� https://www.chromium.org/hsts �˽����顣
	///
	AQUAENTRY(void, InitEnableNetSecurityExpiration)(LPVOID conf, BOOL enabled);

	///
	//	�����ĵ�֮ǰ�Լ�δָ���ĵ���ɫʱ����������ı�����ɫ��alpha����������ȫ��͸����0xFF������ȫ͸����0x00����
	//	���alpha������ȫ��͸������ôRGB����������������ɫ��alpha������ڴ��ڻ����������ȫ͸���ģ�Ȼ��ʹ�ò�͸����ɫ��Ĭ��ֵ��
	//	���alpha��������޴��ڣ��������������ȫ͸������͸���滭�������á�
	///
	AQUAENTRY(void, InitBackgroundColor)(LPVOID conf,int value);

	///
	//	�ö��ŷָ�����������Դ����б�û���κν��ڡ�Accept-Language��HTTP��ͷ��ʹ�õĿո�
	//	����ʹ��CefBrowserSettings.accept_language_listֵ��ÿ���������������д��
	//	�������ֵ��Ϊ�գ���ʹ�á�en-US,en����
	//	����ͨ��CefRequestContextSettings.accept_language_listֵΪ����CefRequestContextʵ�����ǡ�
	///
	AQUAENTRY(void, InitAcceptLanguageListA)(LPVOID conf, LPCSTR value);

	///
	//	�ö��ŷָ�����������Դ����б�û���κν��ڡ�Accept-Language��HTTP��ͷ��ʹ�õĿո�
	//	����ʹ��CefBrowserSettings.accept_language_listֵ��ÿ���������������д��
	//	�������ֵ��Ϊ�գ���ʹ�á�en-US,en����
	//	����ͨ��CefRequestContextSettings.accept_language_listֵΪ����CefRequestContextʵ�����ǡ�
	///
	AQUAENTRY(void, InitAcceptLanguageListW)(LPVOID conf, LPCWSTR value);

	///
	//	����������ӽ���
	///
	AQUAENTRY(void, InitChildProcessA)(LPVOID conf, LPCSTR value);

	///
	//	����������ӽ���
	///
	AQUAENTRY(void, InitChildProcessW)(LPVOID conf, LPCWSTR value);

	///
	//  ���ø�DPIģʽ(��Windows7������)
	///
	AQUAENTRY(void, EnableHighDPI)();
	
	///
	//  �����̱�ʶ��
	//	����Ϊtrue,�����Ϊ������ģʽ
	//	����Ϊfalse,�����Ϊ�����ģʽ
	///
	AQUAENTRY(void, InitSingleProcess)(LPVOID conf, BOOL enabled);

	///
	//  ���߳���Ϣѭ��
	///
	AQUAENTRY(void, InitMultiThreadedMessageLoop)(LPVOID conf, BOOL enabled);

	////////////////////////////////////////////////////////////////////////

	 ///
	 //	��ʼ������,һ����"main"�������߳�ʼ�����������ȱ�����,
	 //	��|init|�ص������п��Խ���һЩ��ʼ�����á�
	 ///
	AQUAENTRY(int, DoWinMain)(AquaInitCallback init);

	///
	//	��Ϣѭ��
	///
	AQUAENTRY(int, DoMessageLoop)(void);

	///
	//	CEF������Ϣѭ��
	///
	AQUAENTRY(void, RunMessageLoop)();

	///
	//	CEF�˳���Ϣѭ��
	///
	AQUAENTRY(void, QuitMessageLoop)();

}
#endif