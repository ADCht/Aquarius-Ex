#include "aqua_window.h"
#include "utils\aqua_conv.h"
#include "include\cef_browser.h"

///
//	����һ���µĴ��ڶ���ʵ��
///
AQUAENTRYFULL(LPVOID, Window, Create)(void) {
	return new CefWindowInfo;
}

///
//	�����������Ϊ�Ӵ��ڡ�
///
AQUAENTRYFULL(void, Window, SetAsChild)(LPVOID object, HWND parent, int x, int y, int width, int height) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		pWindow->x = x;
		pWindow->y = y;
		pWindow->width = width;
		pWindow->height = height;
		pWindow->style = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_TABSTOP | WS_VISIBLE;
		pWindow->parent_window = parent;
	}
}

///
//	���������Ϊһ���������ڡ�
///
AQUAENTRYFULL(void, Window, SetAsPopupA)(LPVOID object, HWND parent, LPCSTR title) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		aqua_convert conv;
		auto windowName = conv.from_bytes(title);
		pWindow->SetAsPopup(parent, windowName);
	}
}

///
//	���������Ϊһ���������ڡ�
///
AQUAENTRYFULL(void, Window, SetAsPopupW)(LPVOID object, HWND parent, LPCWSTR title) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		pWindow->SetAsPopup(parent, title);
	}
}

///
//	ʹ���޴��ڣ���������Ⱦ����������� û�д���
//	��Ϊ������������������е���Ⱦ����ͨ��
//	CefRenderHandler�ӿڡ� |��| | ��ֵ��������ʶ��
//	������Ϣ���䵱�Ի��������Ĳ˵��ĸ����ڣ�
//	���| parent | û���ṩ����ô����Ļ��ʾ������ʹ��
//	������Ҫ�����ڵ�ĳЩ���ܿ����޷�����
//	��ȷ�� Ϊ�˴����޴����������
//	CefSettings.windowless_rendering_enabledֵ��������Ϊtrue��
//	͸���滭Ĭ�����ã�������ͨ�����ý���
//	CefBrowserSettings.background_colorΪ��͸��ֵ��
///
AQUAENTRYFULL(void, Window, SetAsWindowless)(LPVOID object, HWND parent) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
#ifdef _AQUA_CEF2623_ADAPTER
		pWindow->SetAsWindowless(parent,true);
#else
		pWindow->SetAsWindowless(parent);
#endif
	}
}

///
//	���Ĵ��ڵ���ʽ��Ϣ��
///
AQUAENTRYFULL(void, Window, ModifyStyle)(LPVOID object, DWORD style, DWORD styleEx) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		pWindow->style = style;
		pWindow->ex_style = styleEx;
	}
}

///
//	����һ�����ڶ���
///
AQUAENTRYFULL(void, Window, Destoryed)(LPVOID object) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		delete pWindow;
	}
}

///
//	����һ�����ڶ���
///
AQUAENTRYFULL(LPVOID, Window, Copy)(LPVOID object) {
	if (object) {
		CefWindowInfo *pWindow = reinterpret_cast<CefWindowInfo*>(object);
		CefWindowInfo *pRetVal = new CefWindowInfo(*pWindow);
		return pRetVal;
	}
	return NULL;
}