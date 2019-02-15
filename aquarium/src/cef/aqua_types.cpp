#include "aqua_types.h"
#include "utils\aqua_conv.h"
#include "include\cef_app.h"

using namespace AquaTypes;
using namespace AquaTypes::BrowserSettings;
using namespace AquaTypes::RequestContextSettings;
using namespace AquaTypes::PopupFeatures;

///
//	����һ��Bs����
///
AQUAENTRYFULL(LPVOID, TypeBs, Create)(void) {
	return new CefBrowserSettings;
}

///
//	����һ��Bs����
///
AQUAENTRYFULL(LPVOID, TypeBs, Copy)(LPVOID object) {
	if (object) {
		auto conf = reinterpret_cast<CefBrowserSettings*>(object);
		return new CefBrowserSettings(*conf);
	}
	return NULL;
}

///
//	����һ��Bs����
///
AQUAENTRYFULL(void, TypeBs, Destoryed)(LPVOID object) {
	if (object) {
		auto conf = reinterpret_cast<CefBrowserSettings*>(object);
		delete conf;
	}
}

///
//	��ÿ��֡����fps����ʾCefRenderHandler :: OnPaint���������
//	������Ϊ�޴���������� ʵ�ʵ�fps���ܻ����
//	������޷����������������֡�� ���
//	ֵΪ1�����ֵΪ60��Ĭ��Ϊ30���� ���ֵҲ����
//	ͨ��CefBrowserHost :: SetWindowlessFrameRate��̬���ġ�
///
AQUAENTRYFULL(void, TypeBs, WindowlessFrameRate)(LPVOID conf, int value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->windowless_frame_rate = value;
	}
}

//The below values map to WebPreferences settings.

///
// ��������.
///
AQUAENTRYFULL(void, TypeBs, StandardFontFamilyA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->standard_font_family) = conv.from_bytes(value);
	}
}
AQUAENTRYFULL(void, TypeBs, FixedFontFamilyA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->fixed_font_family) = conv.from_bytes(value);
	}
}
AQUAENTRYFULL(void, TypeBs, SerifFontFamilyA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->serif_font_family) = conv.from_bytes(value);
	}
}
AQUAENTRYFULL(void, TypeBs, SansSerifFontFamilyA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->sans_serif_font_family) = conv.from_bytes(value);
	}
}
AQUAENTRYFULL(void, TypeBs, CursiveFontFamilyA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->cursive_font_family) = conv.from_bytes(value);
	}
}
AQUAENTRYFULL(void, TypeBs, FantasyFontFamilyA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->fantasy_font_family) = conv.from_bytes(value);
	}
}
AQUAENTRYFULL(void, TypeBs, StandardFontFamilyW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->standard_font_family) = value;
	}
}
AQUAENTRYFULL(void, TypeBs, FixedFontFamilyW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->fixed_font_family) = value;
	}
}
AQUAENTRYFULL(void, TypeBs, SerifFontFamilyW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->serif_font_family) = value;
	}
}
AQUAENTRYFULL(void, TypeBs, SansSerifFontFamilyW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->sans_serif_font_family) = value;
	}
}
AQUAENTRYFULL(void, TypeBs, CursiveFontFamilyW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->cursive_font_family) = value;
	}
}
AQUAENTRYFULL(void, TypeBs, FantasyFontFamilyW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->fantasy_font_family) = value;
	}
}
AQUAENTRYFULL(void, TypeBs, DefaultFontSize)(LPVOID conf, int value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->default_font_size = value;
	}
}
AQUAENTRYFULL(void, TypeBs, DefaultFixedFontFize)(LPVOID conf, int value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->default_fixed_font_size = value;
	}
}
AQUAENTRYFULL(void, TypeBs, MinimumFontSize)(LPVOID conf, int value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->minimum_font_size = value;
	}
}
AQUAENTRYFULL(void, TypeBs, MinimumLogicalFontSize)(LPVOID conf, int value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->minimum_logical_font_size = value;
	}
}

///
//	Web���ݵ�Ĭ�ϱ��롣 �����ʹ�ÿյġ�ISO-8859-1���� Ҳ
//	ʹ�á�Ĭ�ϱ��롱�����п��ؽ������á�
///
AQUAENTRYFULL(void, TypeBs, DefaultEncodingA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->default_encoding) = conv.from_bytes(value);
	}
}

///
//	Web���ݵ�Ĭ�ϱ��롣 �����ʹ�ÿյġ�ISO-8859-1���� Ҳ
//	ʹ�á�Ĭ�ϱ��롱�����п��ؽ������á�
///
AQUAENTRYFULL(void, TypeBs, DefaultEncodingW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->default_encoding) = value;
	}
}

///
//	���ƴ�Զ��Դ�������塣 Ҳ����ʹ������
//	��disable-remote-fonts�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, RemoteFonts)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->remote_fonts = value;
	}
}

///
//	�����Ƿ����ִ��JavaScript�� Ҳ����ʹ��
//	��disable-javascript�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, JavaScript)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->javascript = value;
		data->javascript_access_clipboard = value;
		data->javascript_close_windows = value;
		data->javascript_dom_paste = value;
#ifdef _AQUA_CEF2623_ADAPTER
		data->javascript_open_windows = value;
#endif
	}
}

///
//	�����Ƿ����ʹ��JavaScript�رղ��ǵĴ���
//	ͨ��JavaScript�򿪡� JavaScript��Ȼ���������ر��Ǹ�����
//	ͨ��JavaScript�򿪻���û�к���/ǰ����ʷ��¼�� Ҳ
//	ʹ�á�disable-javascript-close-windows�������н�������
//	���ء�
///
AQUAENTRYFULL(void, TypeBs, JavaScriptCloseWindows)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->javascript_close_windows = value;
	}
}

///
//	����JavaScript�Ƿ���Է��ʼ����塣 Ҳ������
//	ʹ�á�disable-javascript-access-clipboard�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, JavascriptAccessClipboard)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->javascript_access_clipboard = value;
	}
}

///
//	���Ʊ༭���Ƿ�֧��DOMճ��
//	execCommand����paste������|javascript_access_clipboard|����Ҳ����
//	�����á�Ҳ����ʹ�á�disable-javascript-dom-paste��
//	�������л���
///
AQUAENTRYFULL(void, TypeBs, JavascriptDomPaste)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->javascript_dom_paste = value;
	}
}

///
//	�����Ƿ�����κβ���� Ҳ����ʹ��
//	��disable-plugins�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, Plugins)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->plugins = value;
	}
}

///
//	�����ļ�URL�Ƿ���Է�������URL�� Ҳ������
//	ʹ�á�allow-universal-access-from-files�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, UniversalAccessFromFileUrls)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->universal_access_from_file_urls = value;
	}
}

///
//	�����ļ�URL�Ƿ���Է��������ļ�URL�� Ҳ
//	ʹ�á�allow-access-from-files�������п��ؽ������á�
///
AQUAENTRYFULL(void, TypeBs, FileAccessFromFileUrls)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->file_access_from_file_urls = value;
	}
}

///
//	�������簲ȫ���ƣ�ͬԴ���ԣ��Ƿ��
//	ǿ��ִ�С� ���Ƽ�ʹ�ô����ã���Ϊ����������
//	��ȫ��Ϊ�����վ��ű���XSS���� Ҳ������
//	ʹ�á�disable-web-security�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, WebSecurity)(LPVOID conf, cef_state_t value) {
	if (conf) {
		//��Ӧ����ģʽ
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		if (value == cef_state_t::STATE_ENABLED) {
			data->web_security = cef_state_t::STATE_DISABLED;
		}
		else if(cef_state_t::STATE_DISABLED) {
			data->web_security = cef_state_t::STATE_ENABLED;
		}
		data->universal_access_from_file_urls = value;
		data->file_access_from_file_urls = value;
	}
}

///
//	�����Ƿ���������ͼ��URL�� һ�Ż����ͼƬ
//	�����Ҫ����Ȼ����֡� Ҳ����ʹ��
//	��disable-image-loading�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, ImageLoading)(LPVOID conf, cef_state_t value) {
	TCHAR buf[64];
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);

		//��Ӧ��ͼģʽ����
		if (value == cef_state_t::STATE_ENABLED) {
			value = cef_state_t::STATE_DISABLED;
		}
		else if(value == cef_state_t::STATE_DISABLED) {
			value = cef_state_t::STATE_ENABLED;
		}

		data->image_loading = value;
	}
}

///
//	�����Ƿ���С����ͼ������Ӧҳ�档 Ҳ
//	ʹ�á�image-shrink-standalone-to-fit�������н�������
//	���ء�
///
AQUAENTRYFULL(void, TypeBs, ImageShrinkStandaloneToFit)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->image_shrink_standalone_to_fit = value;
	}
}

///
//	�����ı������Ƿ���Ե�����С�� Ҳ����ʹ��
//	��disable-text-area-resize�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, TextAreaResize)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->text_area_resize = value;
	}
}

///
//	����Tab���Ƿ���Խ��������������ӡ� Ҳ������
//	ʹ�á�disable-tab-to-links�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, TabToLinks)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->tab_to_links = value;
	}
}

///
//	�����Ƿ����ʹ�ñ��ش洢�� Ҳ����ʹ��
//	��disable-local-storage�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, LocalStorage)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->local_storage = value;
	}
}

///
//	�����Ƿ����ʹ�����ݿ⡣ Ҳ����ʹ��
//	��disable-databases�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, Databases)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->databases = value;
	}
}

///
//	�����Ƿ����ʹ��Ӧ�ó��򻺴档 Ҳ����ʹ������
//	��disable-application-cache�������п��ء�
///
AQUAENTRYFULL(void, TypeBs, ApplicationCache)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->application_cache = value;
	}
}

///
//	�����Ƿ����ʹ��WebGL�� ��ע�⣬WebGL��ҪӲ��
//	֧�֣���ʹ���ã�Ҳ�����޷�������ϵͳ�����С� Ҳ
//	ʹ�á�disable-webgl�������п��ؽ������á�
///
AQUAENTRYFULL(void, TypeBs, WebGL)(LPVOID conf, cef_state_t value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->webgl = value;
	}
}

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
AQUAENTRYFULL(void, TypeBs, BackgroundColor)(LPVOID conf, DWORD value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		data->background_color = value;
	}
}

///
//	���ŷָ�����������Դ����б�û���κοո�
//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
//	ʹ��CefBrowserSettings.accept_language_listֵ�� �������ֵ����
//	Ȼ��ʹ�á�en-US,en����
///
AQUAENTRYFULL(void, TypeBs, AcceptLanguageListA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->accept_language_list) = conv.from_bytes(value);
	}
}

///
//	���ŷָ�����������Դ����б�û���κοո�
//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
//	ʹ��CefBrowserSettings.accept_language_listֵ�� �������ֵ����
//	Ȼ��ʹ�á�en-US,en����
///
AQUAENTRYFULL(void, TypeBs, AcceptLanguageListW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->accept_language_list) = value;
	}
}

///
//	����һ��Rcs����
///
AQUAENTRYFULL(LPVOID, TypeRcs, Create)(void) {
	return new CefRequestContextSettings;
}

///
//	����һ��Rcs����
///
AQUAENTRYFULL(LPVOID, TypeRcs, Copy)(LPVOID object) {
	if (object) {
		auto conf = reinterpret_cast<CefRequestContextSettings*>(object);
		return new CefRequestContextSettings(*conf);
	}
	return NULL;
}

///
//	����һ��Rcs����
///
AQUAENTRYFULL(void, TypeRcs, Destoryed)(LPVOID object) {
	if (object) {
		auto conf = reinterpret_cast<CefRequestContextSettings*>(object);
		delete conf;
	}
}

///
//	�������ݽ��洢�ڴ����ϵ�λ�á� ����ǿյĻ�
//	������������û������ڵġ�����ģʽ���´���
//	���ڴ洢����û�����ݱ����浽���̡� HTML5�����ݿ�
//	localStorageֻ���ڻ���·�����ڵ�����³��������ڻỰ��
//	ָ���� ����ȫ������������������ü�
//	��ֵƥ��CefSettings.cache_pathֵ��
///
AQUAENTRYFULL(void, TypeRcs, CachePathA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefRequestContextSettings*>(conf);
		aqua_convert conv;
		CefString(&data->cache_path) = conv.from_bytes(value);
	}
}

///
//	�������ݽ��洢�ڴ����ϵ�λ�á� ����ǿյĻ�
//	������������û������ڵġ�����ģʽ���´���
//	���ڴ洢����û�����ݱ����浽���̡� HTML5�����ݿ�
//	localStorageֻ���ڻ���·�����ڵ�����³��������ڻỰ��
//	ָ���� ����ȫ������������������ü�
//	��ֵƥ��CefSettings.cache_pathֵ��
///
AQUAENTRYFULL(void, TypeRcs, CachePathW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefRequestContextSettings*>(conf);
		CefString(&data->cache_path) = value;
	}
}

///
//	���ֻỰcookie��û�е����ջ���Ч�ڵ�cookie
//	�����Ĭ�������ʹ��ȫ��cookie����������ֵ����Ϊ
//	true��1���� �Ựcookieͨ���Ƕ��ݵģ����Ҵ󲿷ֶ���
//	Web���������������ǡ� ������ȫ������
//	CefSettings.persist_session_cookiesֵ�� ������ֵ��������
//	| cache_path | �ǿյģ���������CefSettings.cache_pathֵƥ�䡣
///
AQUAENTRYFULL(void, TypeRcs, PersistSessionCookies)(LPVOID conf, BOOL enabled) {
	if (conf) {
		auto data = reinterpret_cast<CefRequestContextSettings*>(conf);
		data->persist_session_cookies = enabled;
	}
}

///
//	���û���ѡ���Ϊ����·��Ŀ¼���е�JSON�ļ�
//	���ֵΪ�棨1���� ������ȫ������
//	CefSettings.persist_user_preferencesֵ�� ������ֵ��������
//	| cache_path | �ǿյģ���������CefSettings.cache_pathֵƥ�䡣
///
AQUAENTRYFULL(void, TypeRcs, PersistUserPreferences)(LPVOID conf, BOOL enabled) {
	if (conf) {
		auto data = reinterpret_cast<CefRequestContextSettings*>(conf);
		data->persist_user_preferences = enabled;
	}
}

///
//	����Ϊtrue��1����������ЧSSL֤����صĴ���
//	���ô����ÿ��ܻᵼ��Ǳ�ڵİ�ȫ©��
//	���м��ˡ������� ���м������ݵ�Ӧ�ó���
//	��������Ӧ�����ô����á� ������ȫ������
//	CefSettings.ignore_certificate_errorsֵ�� ������ֵ��������
//	| cache_path | ƥ��CefSettings.cache_pathֵ��
///
AQUAENTRYFULL(void, TypeRcs, IgnoreCertificateErrors)(LPVOID conf, BOOL enabled) {
	if (conf) {
		auto data = reinterpret_cast<CefRequestContextSettings*>(conf);
		data->ignore_certificate_errors = enabled;
	}
}


///
//	����Ϊtrue��1����������������Ļ������ڵĵ���
//	��ȫ��Ϣ����֤��͸������־��HSTSԤ����
//	�͹̶���Ϣ���� ���ô�ѡ���������簲ȫ��
//	��ʹ��CEF�������ļ�ʱ�����ܻᵼ��HTTPS����ʧ��
//	��ȥ10�� �����https://www.certificate-transparency.org/��
//	https://www.chromium.org/hsts�˽����顣 ������ȫ������
//	CefSettings.enable_net_security_expirationֵ��
///
AQUAENTRYFULL(void, TypeRcs, EnableNetSecurityExpiration)(LPVOID conf, BOOL enabled) {
#ifndef _AQUA_CEF2623_ADAPTER
	if (conf) {
		auto data = reinterpret_cast<CefRequestContextSettings*>(conf);
		data->enable_net_security_expiration = enabled;
	}
#endif
}



///
//	���ŷָ�����������Դ����б�û���κοո�
//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
//	ʹ��CefSettings.accept_language_listֵ����per-
//	ʹ��CefBrowserSettings.accept_language_listֵ������������� ���
//	����ֵ���ǿյģ���ô��ʹ�á�en-US��en���� ���ֵ������
//	���| cache_path |������ ƥ��CefSettings.cache_pathֵ��
///
AQUAENTRYFULL(void, TypeRcs, AcceptLanguageListA)(LPVOID conf, LPCSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		aqua_convert conv;
		CefString(&data->accept_language_list) = conv.from_bytes(value);
	}
}

///
//	���ŷָ�����������Դ����б�û���κοո�
//	�����ڡ�Accept-Language��HTTP��ͷ�С� ������ȫ������
//	ʹ��CefSettings.accept_language_listֵ����per-
//	ʹ��CefBrowserSettings.accept_language_listֵ������������� ���
//	����ֵ���ǿյģ���ô��ʹ�á�en-US��en���� ���ֵ������
//	���| cache_path |������ ƥ��CefSettings.cache_pathֵ��
///
AQUAENTRYFULL(void, TypeRcs, AcceptLanguageListW)(LPVOID conf, LPCWSTR value) {
	if (conf) {
		auto data = reinterpret_cast<CefBrowserSettings*>(conf);
		CefString(&data->accept_language_list) = value;
	}
}

AQUAENTRYFULL(void, TypePf, SetFeatures)(LPVOID conf, int x, int xSet, int y, int ySet, int width, int widthSet, int height, int heightSet,
	int menuBarVisible, int statusBarVisible, int toolBarVisible, int scrollbarsVisible) {
	if (conf) {
		auto data = reinterpret_cast<CefPopupFeatures*>(conf);
		data->x = x;
		data->y = y;
		data->xSet = xSet;
		data->ySet = ySet;
		data->height = height;
		data->width = width;
		data->widthSet = widthSet;
		data->heightSet = heightSet;
		data->menuBarVisible = menuBarVisible;
		data->statusBarVisible = statusBarVisible;
		data->toolBarVisible = toolBarVisible;
		data->scrollbarsVisible = scrollbarsVisible;
	}
}