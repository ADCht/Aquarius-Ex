#ifndef AQUA_TYPES_REFER_H_
#define AQUA_TYPES_REFER_H_
#include "utils\aqua_utils.h"

/**
  * �����ڿ������ʹ�õ������ݽṹ
  * * * * * * * * * * * * * * * */

namespace AquaTypes {

	/******************************
	*		BrowserSettings
	******************************/

	///
	//	�������ʼ�����á� ָ��NULL��0�Ի�ý���
	//	Ĭ��ֵ�� ʹ���Զ���ֵ�ĺ�����ܲ�̫��
	//	���ԡ� �����Щ����������Ҳ����ʹ�����������ã�
	//	��·���ء�
	///
	namespace BrowserSettings {

		typedef enum {
			///
			// Use the default state for the setting.
			///
			STATE_DEFAULT = 0,

			///
			// Enable or allow the setting.
			///
			STATE_ENABLED,

			///
			// Disable or disallow the setting.
			///
			STATE_DISABLED,
		} TypeBsStateType;

		///
		//	����һ��Bs����
		///
		AQUAENTRYFULL(LPVOID, TypeBs, Create)(void);

		///
		//	����һ��Bs����
		///
		AQUAENTRYFULL(LPVOID, TypeBs, Copy)(LPVOID object);

		///
		//	����һ��Bs����
		///
		AQUAENTRYFULL(void, TypeBs, Destoryed)(LPVOID object);

		///
		//	��ÿ��֡����fps����ʾCefRenderHandler :: OnPaint���������
		//	������Ϊ�޴���������� ʵ�ʵ�fps���ܻ����
		//	������޷����������������֡�� ���
		//	ֵΪ1�����ֵΪ60��Ĭ��Ϊ30���� ���ֵҲ����
		//	ͨ��CefBrowserHost :: SetWindowlessFrameRate��̬���ġ�
		///
		AQUAENTRYFULL(void, TypeBs, WindowlessFrameRate)(LPVOID conf,int value);

		//The below values map to WebPreferences settings.

		///
		// ��������.
		///
		AQUAENTRYFULL(void, TypeBs, StandardFontFamilyA)(LPVOID conf,LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, FixedFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, SerifFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, SansSerifFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, CursiveFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, FantasyFontFamilyA)(LPVOID conf, LPCSTR value);
		AQUAENTRYFULL(void, TypeBs, StandardFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, FixedFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, SerifFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, SansSerifFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, CursiveFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, FantasyFontFamilyW)(LPVOID conf, LPCWSTR value);
		AQUAENTRYFULL(void, TypeBs, DefaultFontSize)(LPVOID conf, int value);
		AQUAENTRYFULL(void, TypeBs, DefaultFixedFontFize)(LPVOID conf, int value);
		AQUAENTRYFULL(void, TypeBs, MinimumFontSize)(LPVOID conf, int value);
		AQUAENTRYFULL(void, TypeBs, MinimumLogicalFontSize)(LPVOID conf, int value);

		///
		//	Web���ݵ�Ĭ�ϱ��롣 �����ʹ�ÿյġ�ISO-8859-1���� Ҳ
		//	ʹ�á�Ĭ�ϱ��롱�����п��ؽ������á�
		///
		AQUAENTRYFULL(void, TypeBs, DefaultEncodingA)(LPVOID conf,LPCSTR value);

		///
		//	Web���ݵ�Ĭ�ϱ��롣 �����ʹ�ÿյġ�ISO-8859-1���� Ҳ
		//	ʹ�á�Ĭ�ϱ��롱�����п��ؽ������á�
		///
		AQUAENTRYFULL(void, TypeBs, DefaultEncodingW)(LPVOID conf, LPCWSTR value);

		///
		//	���ƴ�Զ��Դ�������塣 Ҳ����ʹ������
		//	��disable-remote-fonts�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, RemoteFonts)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ����ִ��JavaScript�� Ҳ����ʹ��
		//	��disable-javascript�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, JavaScript)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ����ʹ��JavaScript�رղ��ǵĴ���
		//	ͨ��JavaScript�򿪡� JavaScript��Ȼ���������ر��Ǹ�����
		//	ͨ��JavaScript�򿪻���û�к���/ǰ����ʷ��¼�� Ҳ
		//	ʹ�á�disable-javascript-close-windows�������н�������
		//	���ء�
		///
		AQUAENTRYFULL(void, TypeBs, JavaScriptCloseWindows)(LPVOID conf, TypeBsStateType value);

		///
		//	����JavaScript�Ƿ���Է��ʼ����塣 Ҳ������
		//	ʹ�á�disable-javascript-access-clipboard�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, JavascriptAccessClipboard)(LPVOID conf, TypeBsStateType value);

		///
		//	���Ʊ༭���Ƿ�֧��DOMճ��
		//	execCommand����paste������|javascript_access_clipboard|����Ҳ����
		//	�����á�Ҳ����ʹ�á�disable-javascript-dom-paste��
		//	�������л���
		///
		AQUAENTRYFULL(void, TypeBs, JavascriptDomPaste)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ�����κβ���� Ҳ����ʹ��
		//	��disable-plugins�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, Plugins)(LPVOID conf, TypeBsStateType value);

		///
		//	�����ļ�URL�Ƿ���Է�������URL�� Ҳ������
		//	ʹ�á�allow-universal-access-from-files�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, UniversalAccessFromFileUrls)(LPVOID conf, TypeBsStateType value);

		///
		//	�����ļ�URL�Ƿ���Է��������ļ�URL�� Ҳ
		//	ʹ�á�allow-access-from-files�������п��ؽ������á�
		///
		AQUAENTRYFULL(void, TypeBs, FileAccessFromFileUrls)(LPVOID conf, TypeBsStateType value);

		///
		//	�������簲ȫ���ƣ�ͬԴ���ԣ��Ƿ��
		//	ǿ��ִ�С� ���Ƽ�ʹ�ô����ã���Ϊ����������
		//	��ȫ��Ϊ�����վ��ű���XSS���� Ҳ������
		//	ʹ�á�disable-web-security�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, WebSecurity)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ���������ͼ��URL�� һ�Ż����ͼƬ
		//	�����Ҫ����Ȼ����֡� Ҳ����ʹ��
		//	��disable-image-loading�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, ImageLoading)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ���С����ͼ������Ӧҳ�档 Ҳ
		//	ʹ�á�image-shrink-standalone-to-fit�������н�������
		//	���ء�
		///
		AQUAENTRYFULL(void, TypeBs, ImageShrinkStandaloneToFit)(LPVOID conf, TypeBsStateType value);

		///
		//	�����ı������Ƿ���Ե�����С�� Ҳ����ʹ��
		//	��disable-text-area-resize�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, TextAreaResize)(LPVOID conf, TypeBsStateType value);

		///
		//	����Tab���Ƿ���Խ��������������ӡ� Ҳ������
		//	ʹ�á�disable-tab-to-links�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, TabToLinks)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ����ʹ�ñ��ش洢�� Ҳ����ʹ��
		//	��disable-local-storage�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, LocalStorage)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ����ʹ�����ݿ⡣ Ҳ����ʹ��
		//	��disable-databases�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, Databases)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ����ʹ��Ӧ�ó��򻺴档 Ҳ����ʹ������
		//	��disable-application-cache�������п��ء�
		///
		AQUAENTRYFULL(void, TypeBs, ApplicationCache)(LPVOID conf, TypeBsStateType value);

		///
		//	�����Ƿ����ʹ��WebGL�� ��ע�⣬WebGL��ҪӲ��
		//	֧�֣���ʹ���ã�Ҳ�����޷�������ϵͳ�����С� Ҳ
		//	ʹ�á�disable-webgl�������п��ؽ������á�
		///
		AQUAENTRYFULL(void, TypeBs, WebGL)(LPVOID conf, TypeBsStateType value);

		///
		//	�ڼ����ĵ�֮ǰ��֮������������ı�����ɫ
		//	û��ָ���ĵ���ɫ�� alpha������������ȫ��
		//	��͸����0xFF������ȫ͸����0x00���� ���alpha������ȫ
		//	��͸������ôRGB�����������������ɫ�� ���
		//	 alpha������ڴ��ڻ����������ȫ͸����
		//	��ʹ��CefSettings.background_colorֵ�� ���alpha������
		//	�����޴��ڣ��������������ȫ͸����Ȼ��͸��
		//	�滭�������á�
		///
		AQUAENTRYFULL(void, TypeBs, BackgroundColor)(LPVOID conf, DWORD value);

		///
		//	���ŷָ�����������Դ����б�û���κοո�
		//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
		//	ʹ��CefBrowserSettings.accept_language_listֵ�� �������ֵ����
		//	Ȼ��ʹ�á�en-US,en����
		///
		AQUAENTRYFULL(void, TypeBs, AcceptLanguageListA)(LPVOID conf, LPCSTR value);

		///
		//	���ŷָ�����������Դ����б�û���κοո�
		//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
		//	ʹ��CefBrowserSettings.accept_language_listֵ�� �������ֵ����
		//	Ȼ��ʹ�á�en-US,en����
		///
		AQUAENTRYFULL(void, TypeBs, AcceptLanguageListW)(LPVOID conf, LPCWSTR value);
	}


	/***********************************
	*		RequestContextSettings
	************************************/

	///
	//	���������ĳ�ʼ�����á� ָ��NULL��0����ȡ
	//	�Ƽ���Ĭ��ֵ��
	///
	namespace RequestContextSettings {

		///
		//	����һ��Rcs����
		///
		AQUAENTRYFULL(LPVOID, TypeRcs, Create)(void);

		///
		//	����һ��Rcs����
		///
		AQUAENTRYFULL(LPVOID, TypeRcs, Copy)(LPVOID object);

		///
		//	����һ��Rcs����
		///
		AQUAENTRYFULL(void, TypeRcs, Destoryed)(LPVOID object);

		///
		//	�������ݽ��洢�ڴ����ϵ�λ�á� ����ǿյĻ�
		//	������������û������ڵġ�����ģʽ���´���
		//	���ڴ洢����û�����ݱ����浽���̡� HTML5�����ݿ�
		//	localStorageֻ���ڻ���·�����ڵ�����³��������ڻỰ��
		//	ָ���� ����ȫ������������������ü�
		//	��ֵƥ��CefSettings.cache_pathֵ��
		///
		AQUAENTRYFULL(void, TypeRcs, CachePathA)(LPVOID conf, LPCSTR value);

		///
		//	�������ݽ��洢�ڴ����ϵ�λ�á� ����ǿյĻ�
		//	������������û������ڵġ�����ģʽ���´���
		//	���ڴ洢����û�����ݱ����浽���̡� HTML5�����ݿ�
		//	localStorageֻ���ڻ���·�����ڵ�����³��������ڻỰ��
		//	ָ���� ����ȫ������������������ü�
		//	��ֵƥ��CefSettings.cache_pathֵ��
		///
		AQUAENTRYFULL(void, TypeRcs, CachePathW)(LPVOID conf, LPCWSTR value);

		///
		//	���ֻỰcookie��û�е����ջ���Ч�ڵ�cookie
		//	�����Ĭ�������ʹ��ȫ��cookie����������ֵ����Ϊ
		//	true��1���� �Ựcookieͨ���Ƕ��ݵģ����Ҵ󲿷ֶ���
		//	Web���������������ǡ� ������ȫ������
		//	CefSettings.persist_session_cookiesֵ�� ������ֵ��������
		//	| cache_path | �ǿյģ���������CefSettings.cache_pathֵƥ�䡣
		///
		AQUAENTRYFULL(void, TypeRcs, PersistSessionCookies)(LPVOID conf, BOOL enabled);

		///
		//	���û���ѡ���Ϊ����·��Ŀ¼���е�JSON�ļ�
		//	���ֵΪ�棨1���� ������ȫ������
		//	CefSettings.persist_user_preferencesֵ�� ������ֵ��������
		//	| cache_path | �ǿյģ���������CefSettings.cache_pathֵƥ�䡣
		///
		AQUAENTRYFULL(void, TypeRcs, PersistUserPreferences)(LPVOID conf, BOOL enabled);

		///
		//	����Ϊtrue��1����������ЧSSL֤����صĴ���
		//	���ô����ÿ��ܻᵼ��Ǳ�ڵİ�ȫ©��
		//	���м��ˡ������� ���м������ݵ�Ӧ�ó���
		//	��������Ӧ�����ô����á� ������ȫ������
		//	CefSettings.ignore_certificate_errorsֵ�� ������ֵ��������
		//	| cache_path | ƥ��CefSettings.cache_pathֵ��
		///
		AQUAENTRYFULL(void, TypeRcs, IgnoreCertificateErrors)(LPVOID conf, BOOL enabled);

		///
		//	����Ϊtrue��1����������������Ļ������ڵĵ���
		//	��ȫ��Ϣ����֤��͸������־��HSTSԤ����
		//	�͹̶���Ϣ���� ���ô�ѡ���������簲ȫ��
		//	��ʹ��CEF�������ļ�ʱ�����ܻᵼ��HTTPS����ʧ��
		//	��ȥ10�� �����https://www.certificate-transparency.org/��
		//	https://www.chromium.org/hsts�˽����顣 ������ȫ������
		//	CefSettings.enable_net_security_expirationֵ��
		///
		AQUAENTRYFULL(void, TypeRcs, EnableNetSecurityExpiration)(LPVOID conf, BOOL enabled);

		///
		//	���ŷָ�����������Դ����б�û���κοո�
		//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
		//	ʹ��CefSettings.accept_language_listֵ����per-
		//	ʹ��CefBrowserSettings.accept_language_listֵ������������� ���
		//	����ֵ���ǿյģ���ô��ʹ�á�en-US��en���� ���ֵ������
		//	���| cache_path |������ ƥ��CefSettings.cache_pathֵ��
		///
		AQUAENTRYFULL(void, TypeRcs, AcceptLanguageListA)(LPVOID conf, LPCSTR value);

		///
		//	���ŷָ�����������Դ����б�û���κοո�
		//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
		//	ʹ��CefSettings.accept_language_listֵ����per-
		//	ʹ��CefBrowserSettings.accept_language_listֵ������������� ���
		//	����ֵ���ǿյģ���ô��ʹ�á�en-US��en���� ���ֵ������
		//	���| cache_path |������ ƥ��CefSettings.cache_pathֵ��
		///
		AQUAENTRYFULL(void, TypeRcs, AcceptLanguageListW)(LPVOID conf, LPCWSTR value);
	}

	/******************************
	*		CefPopupFeatures
	******************************/
	namespace PopupFeatures {

		AQUAENTRYFULL(void,TypePf, SetFeatures)(LPVOID conf,int x,int xSet,int y,int ySet,int width,int widthSet,int height,int heightSet,
			int menuBarVisible,int statusBarVisible,int toolBarVisible,int scrollbarsVisible);
	}
}

#endif