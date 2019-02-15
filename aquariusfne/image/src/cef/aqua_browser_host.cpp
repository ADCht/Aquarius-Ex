#include "aqua_browser_host.h"
#include "include\cef_browser.h"
#include "calling\aqua_calling_browser.h"
#include "utils\aqua_conv.h"
#include "include\cef_jsdialog_handler.h"
#include "calling\aqua_calling_request_context_handler.h"

using namespace AquaCef;

///
//	ʹ��ָ���Ĵ��ڲ�������һ���µ����������
//	 | windowInfo |������ֵ�����ڲ����ƣ�����ʵ�ʴ����и���
//	����UI�߳��ϴ��������| request_context |Ϊ��
//	��ʹ��ȫ�����������ġ�
//	����������̲߳�����������
///
AQUAENTRYFULL(BOOL, BrowserHost, CreateBrowserA)(LPCSTR url, LPVOID windowInfo, LPVOID settings, LPVOID rcs) {
	CefWindowInfo *pWi = reinterpret_cast<CefWindowInfo*>(windowInfo);
	CefBrowserSettings *pBs = reinterpret_cast<CefBrowserSettings*>(settings);
	CefBrowserSettings initBsConf;
	CefRefPtr<CefRequestContext> pRequestConf = NULL;
	aqua_convert conv;
	std::wstring fullUrl = conv.from_bytes(url);
	if (pBs == NULL) pBs = &initBsConf;
	if (pWi) {
		CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
		if (handler.get() == NULL) {
			handler = new AquaCallBrowser();
		}
		
		if (rcs != NULL) {
			auto pRequestInitial = reinterpret_cast<CefRequestContextSettings*>(rcs);
			//CefRefPtr<CefCookieManager> manager = CefCookieManager::CreateManager(pRequestInitial->cache_path.str, true, NULL);
			//new AquaRequestContextHandler(manager.get())
			pRequestConf = CefRequestContext::CreateContext((*pRequestInitial), NULL);
		}
		
		return CefBrowserHost::CreateBrowser((*pWi), handler, fullUrl, (*pBs), pRequestConf.get());
	}
	return FALSE;
}

///
//	ʹ��ָ���Ĵ��ڲ�������һ���µ����������
//	 | windowInfo |������ֵ�����ڲ����ƣ�����ʵ�ʴ����и���
//	����UI�߳��ϴ��������| request_context |Ϊ��
//	��ʹ��ȫ�����������ġ�
//	����������̲߳�����������
///
AQUAENTRYFULL(BOOL, BrowserHost, CreateBrowserW)(LPCWSTR url, LPVOID windowInfo, LPVOID settings, LPVOID rcs) {
	CefWindowInfo *pWi = reinterpret_cast<CefWindowInfo*>(windowInfo);
	CefBrowserSettings *pBs = reinterpret_cast<CefBrowserSettings*>(settings);
	CefRefPtr<CefRequestContext> request = NULL;
	if (pWi && pBs) {
		CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
		if (handler.get() == NULL) {
			handler = new AquaCallBrowser();
		}
		if (rcs) {
			auto pRcs = reinterpret_cast<CefRequestContextSettings*>(rcs);
			request = CefRequestContext::CreateContext(*pRcs, NULL);
		}
		return CefBrowserHost::CreateBrowser((*pWi), handler, url, (*pBs), request.get());
	}
	return FALSE;
}

///
//	�����й����������
///
AQUAENTRYFULL(LPVOID, BrowserHost, GetBrowser)(LPVOID object) {
	LPVOID result = NULL;
	CefRefPtr<CefBrowser> b = NULL;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		b = pHost->GetBrowser();
		b->AddRef();
		result = b.get();
		pHost->Release();
	}
	return result;
}

///
//	����������رգ�JavaScript'onbeforeunload'�¼����ᷢ��
//	����ͣ����| force_close |Ϊfalse���¼�������������еĻ���������
//	������ʾ�û����û�����ѡ��ȡ���رա�
//	���| force_close |Ϊtrue���򲻻���ʾ��ʾ���ر�
//	������������ǣ������CefLifeSpanHandler :: DoClose����
//	�¼������������close��if | force_close |Ϊtrue
//	CefLifeSpanHandler :: DoClose�����ĵ��Ի�ȡ�����÷�
//	��Ϣ��
///
AQUAENTRYFULL(void, BrowserHost, CloseBrowser)(LPVOID object, BOOL force_close) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->CloseBrowser(force_close);
		pHost->Release();
	}
}

///
//	�ر��������Helper�Ӷ��㴰�ڵ����������
//	close�����������ر��ˣ����ڲ�����CloseBrowser��false��
//	��δ���������ر�ʱ���˷�������false
//	�ȴ����ڹر���ɺ󷵻�true�������CloseBrowser������
//	CefLifeSpanHandler :: DoClose�����ĵ��Ի�ȡ�����÷�
//	information������������������������UI�߳��ϵ��á�
///
AQUAENTRYFULL(void, BrowserHost, TryCloseBrowser)(LPVOID object) {
#ifndef _AQUA_CEF2623_ADAPTER
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->TryCloseBrowser();
		pHost->Release();
	}
#endif
}

///
//	����������Ƿ���뽹�㡣
///
AQUAENTRYFULL(void, BrowserHost, SetFocus)(LPVOID object, BOOL focus) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetFocus(focus);
		pHost->Release();
	}
}

///
//	Ϊ�˼������ھ�������������������װ��
//	һ��CefBrowserViewӦ�������������UI�ϵ����������
//	�̣߳��������ض����������ڵľ����
///
AQUAENTRYFULL(HWND, BrowserHost, GetWindowHandle)(LPVOID object) {
	HWND result = NULL;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->GetWindowHandle();
		pHost->Release();
	}
	return result;
}

///
//	��ȡ��ǰ���ż���Ĭ�����ż���Ϊ0.0���˷�������
//	ֻ����UI�߳��е��á�
///
AQUAENTRYFULL(double, BrowserHost, GetZoomLevel)(LPVOID object) {
	double zoom = 0.0f;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		zoom = pHost->GetZoomLevel();
		pHost->Release();
	}
	return zoom;
}

///
//	�����ż������Ϊָ��ֵ��ָ��0.0������
//	���ż��������UI�߳��ϵ��ã����Ӧ�ø���
//	���������򣬸��Ľ����첽Ӧ����
//	UI�̡߳�
///
AQUAENTRYFULL(void, BrowserHost, SetZoomLevel)(LPVOID object, double zoomLevel) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetZoomLevel(zoomLevel);
		pHost->Release();
	}
}

///
//	ʹ��CefDownloadHandler�� | url | �����ļ���
///
AQUAENTRYFULL(void, BrowserHost, StartDownloadA)(LPVOID object, LPCSTR url) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		aqua_convert conv;
		auto addr = conv.from_bytes(url);
		pHost->StartDownload(addr);
		pHost->Release();
	}
}

///
//	ʹ��CefDownloadHandler�� | url | �����ļ���
///
AQUAENTRYFULL(void, BrowserHost, StartDownloadW)(LPVOID object, LPCSTR url) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->StartDownload(url);
		pHost->Release();
	}
}

///
//	��ӡ��ǰ����������ݡ�
///
AQUAENTRYFULL(void, BrowserHost, Print)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->Print();
		pHost->Release();
	}
}

///
//	���Լ���������д򿪿������ߣ�DevTools����DevTools�����
//	��������������������������DevTools�������
//	�Ѿ��򿪣���ô�������۽��������������| windowInfo |��
//	��� | inspect_element_at | ��// | client |��| settings |������������
//	�ǿգ���ôָ����x��y��λ�õ�Ԫ�ؽ�����
//	��顣������������| windowInfo |������������
//	��װ��CefBrowserView�С�
///
AQUAENTRYFULL(void, BrowserHost, ShowDevTools)(LPVOID object, LPVOID windowInfo, LPVOID settings, int x, int y) {
	if (object && windowInfo && settings) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		auto pWi = reinterpret_cast<CefWindowInfo*>(windowInfo);
		auto pBs = reinterpret_cast<CefBrowserSettings*>(settings);
		CefPoint pt(x, y);
		pHost->AddRef();
		pHost->ShowDevTools((*pWi),AquaCallBrowser::GetInterface(), (*pBs),pt);
		pHost->Release();
	}
}

///
//	��ȷ�ر���ص�DevTools�����������еĻ�����
///
AQUAENTRYFULL(void, BrowserHost, CloseDevTools)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->CloseDevTools();
		pHost->Release();
	}
}

///
//	������������ǰ���й�����DevTools��������򷵻�true��
//	���������������UI�߳��ϵ��á�
///
AQUAENTRYFULL(BOOL, BrowserHost, HasDevTools)(LPVOID object) {
	BOOL result = FALSE;
#ifndef _AQUA_CEF2623_ADAPTER
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->HasDevTools();
		pHost->Release();
	}
#endif
	return result;
}

///
//	���û��������ı����á�
///
AQUAENTRYFULL(void, BrowserHost, SetMouseCursorChangeDisabled)(LPVOID object, bool disabled) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetMouseCursorChangeDisabled(disabled);
		pHost->Release();
	}
}

///
//	��������������ģ��򷵻�true��
///
AQUAENTRYFULL(BOOL, BrowserHost, IsMouseCursorChangeDisabled)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->IsMouseCursorChangeDisabled();
		pHost->Release();
	}
	return result;
}

///
//	������ô�����Ⱦ���򷵻�true��
///
AQUAENTRYFULL(BOOL, BrowserHost, IsWindowRenderingDisabled)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->IsWindowRenderingDisabled();
		pHost->Release();
	}
	return result;
}

///
//	֪ͨ�����С�����ѱ�������С�����������
//	����CefRenderHandler :: GetViewRect��ȡ�µĴ�СȻ�����
//	 CefRenderHandler :: OnPaint����������첽
//	�������ڽ��ô�����Ⱦʱʹ�á�
///
AQUAENTRYFULL(void, BrowserHost, WasResized)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->WasResized();
		pHost->Release();
	}
}

///
//	֪ͨ��������ѱ����ػ���ʾ
//	CefRenderHandler :: OnPaint֪ͨ���������ֹͣʱֹͣ
//	hidden���������ֻ�ڽ��ô�����Ⱦʱʹ�á�
///
AQUAENTRYFULL(void, BrowserHost, WasHidden)(LPVOID object, bool hidden) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->WasHidden(hidden);
		pHost->Release();
	}
}

///
//	�������������Ļ��Ϣ�Ѹ��ĵ�֪ͨ��
//	����������CefRenderHandler :: GetScreenInfo������
//	ʹ�������ֵ����ʾ��Ϣ����ģ���ƶ�webview
//	��һ����ʾ���ڵ���һ����ʾ���ڣ����߸ı䴰�ڵ�����
//	��ǰ��ʾ���÷������ڴ�����Ⱦʱʹ��
//	���á�
///
AQUAENTRYFULL(void, BrowserHost, NotifyScreenInfoChanged)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->NotifyScreenInfoChanged();
		pHost->Release();
	}
}

///
//	ʹ��ͼ��Ч�������������CefRenderHandler :: OnPaint
//	�첽���˷������ڴ��ڳ���ʱʹ��
//	���á�
///
AQUAENTRYFULL(void, BrowserHost, Invalidate)(LPVOID object, int status) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->Invalidate((CefBrowserHost::PaintElementType)status);
		pHost->Release();
	}
}

///
//	�������¼����͵��������
///
AQUAENTRYFULL(void, BrowserHost, SendFocusEvent)(LPVOID object, bool setFocus) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SendFocusEvent(setFocus);
		pHost->Release();
	}
}

///
//	����������Ͳ���ʧ�¼���
///
AQUAENTRYFULL(void, BrowserHost, SendCaptureLostEvent)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SendCaptureLostEvent();
		pHost->Release();
	}
}

///
//	֪ͨ������й����Ĵ��ڼ������ƶ����ƶ�
//	������С���˷���������Windows��Linux��
///
AQUAENTRYFULL(void, BrowserHost, NotifyMoveOrResizeStarted)(LPVOID object) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->NotifyMoveOrResizeStarted();
		pHost->Release();
	}
}

///
//	��ÿ��֡����fps�������������CefRenderHandler ::
//	OnPaint�������������޴����������ʵ�ʵ�fps������
//	���������޷����������������֡���򽵵͡�
//	��СֵΪ1�����ֵΪ60��Ĭ��ֵΪ30��
//	ֻ����UI�߳��е��á�
///
AQUAENTRYFULL(int, BrowserHost, GetWindowlessFrameRate)(LPVOID object) {
	int result = 0;
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		result = pHost->GetWindowlessFrameRate();
		pHost->Release();
	}
	return result;
}

///
//	���ؼ��¼����͵��������
///
AQUAENTRYFULL(void, BrowserHost, SendKeyEvent)(LPVOID object, LPVOID event) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_key_event_t*>(event);
		CefKeyEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendKeyEvent(key);
		p->Release();
	}
}

///
//	����굥���¼����͵�������� | x | ��| y | ��������ͼ�����Ͻǡ�
///
AQUAENTRYFULL(void, BrowserHost, SendMouseClickEvent)(LPVOID object, LPVOID event, int type, bool mouseUp, int clickCount) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_mouse_event_t*>(event);
		CefMouseEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendMouseClickEvent(key, (cef_mouse_button_type_t)type, mouseUp, clickCount);
		p->Release();
	}
}

///
//	������ƶ��¼����͵�������� | x | ��| y | �����������ͼ�����Ͻǡ�
///
AQUAENTRYFULL(void, BrowserHost, SendMouseMoveEvent)(LPVOID object, LPVOID event, bool mouseLeave) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_mouse_event_t*>(event);
		CefMouseEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendMouseMoveEvent(key, mouseLeave);
		p->Release();
	}
}

///
//	���������¼����͵�������� | x | ��| y | ������
//	�������ͼ�����Ͻǡ� | deltaX | �� | deltaY |
//	ֵ�ֱ��ʾX��Y�����ϵ��˶�������
//	Ϊ���ڽ��ô�����Ⱦ������¹����ڲ�ѡ�񵯳�����
//	Ӧ����ȷʵ��CefRenderHandler::GetScreenPoint��
///
AQUAENTRYFULL(void, BrowserHost, SendMouseWheelEvent)(LPVOID object, LPVOID event, int deltaX, int deltaY) {
	if (object && event) {
		auto p = reinterpret_cast<CefBrowserHost*>(object);
		auto v = reinterpret_cast<_cef_mouse_event_t*>(event);
		CefMouseEvent key;
		key.Set((*v), true);
		p->AddRef();
		p->SendMouseWheelEvent(key,deltaX,deltaY);
		p->Release();
	}
}

///
//	����ÿ��֡����fps�����������CefRenderHandler ::
//	OnPaint�������������޴����������ʵ�ʵ�fps������
//	���������޷����������������֡���򽵵͡�
//	��Сֵ��1�����ֵ��60��Ĭ��30����Ҳ������
//	ͨ��CefBrowserSettings.windowless_frame_rate�����������
///
AQUAENTRYFULL(void, BrowserHost, SetWindowlessFrameRate)(LPVOID object, int frame_rate) {
	if (object) {
		auto pHost = reinterpret_cast<CefBrowserHost*>(object);
		pHost->AddRef();
		pHost->SetWindowlessFrameRate(frame_rate);
		pHost->Release();
	}
}

///
//	�ƶ�������ڹ������е����������λ�ü���С,|parent|��ΪNULLʱ,�������ô����µ����������������
//	���򽫵������д��ڡ�
///
AQUAENTRYFULL(void, Manager, MoveOrResized)(HWND parent, int x, int y, int width, int height) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get()) {
		auto mgr = handler->GetManager();
		int max = mgr->size();
		CefRefPtr<CefBrowserHost> host;
		HWND child = NULL;
		for (size_t i = 0; i < max; i++)
		{
			host = mgr->at(i)->GetHost();
			child = host->GetWindowHandle();
			if (parent != NULL) {
				if (GetParent(child) == parent) {
					SetWindowPos(child, NULL, x, y, width, height, SWP_NOACTIVATE | SWP_NOZORDER);
					host->NotifyMoveOrResizeStarted();
					host->NotifyScreenInfoChanged();
				}
			}
			else {
				host->NotifyMoveOrResizeStarted();
				host->NotifyScreenInfoChanged();
				SetWindowPos(child, NULL, x, y, width, height, SWP_NOACTIVATE | SWP_NOZORDER);
			}
		}
	}
}

///
//	��������ʾ�����
///
AQUAENTRYFULL(void, Manager, SetMainHeroine)(HWND parent, HWND child) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get() && IsWindow(child)) {
		auto mgr = handler->GetManager();
		int max = mgr->size();
		CefRefPtr<CefBrowserHost> host;
		HWND manaChild = NULL;
		for (size_t i = 0; i < max; i++)
		{
			host = mgr->at(i)->GetHost();
			manaChild = host->GetWindowHandle();
			if (GetParent(manaChild) == parent) {
				if (manaChild == child) {
					ShowWindow(manaChild, SW_SHOW);
				}
				else {
					ShowWindow(manaChild, SW_HIDE);
				}
			}
		}
	}
}

///
//	��ѯ����������|id|���й��������������,������NULLʱ����ζ���Ҳ������������Ķ���
///
AQUAENTRYFULL(LPVOID, Manager, QueryActor)(HWND id) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get() && IsWindow(id)) {
		auto mgr = handler->GetManager();
		int max = mgr->size();
		CefRefPtr<CefBrowserHost> host;
		HWND manaChild = NULL;
		for (size_t i = 0; i < max; i++)
		{
			host = mgr->at(i)->GetHost();
			manaChild = host->GetWindowHandle();
			if (manaChild == id) {
				CefBrowser *actor = mgr->at(i);
				actor->AddRef();
				return actor;
			}
		}
	}
	return NULL;
}

///
//	��ȡ�������е����������
///
AQUAENTRYFULL(int, Manager, GetCount)(void) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get()) {
		return handler->GetManager()->size();
	}
	return 0;
}

///
//	�ر����������
///
AQUAENTRYFULL(void, Manager, CloseAllBrowser)(void) {
	CefRefPtr<AquaCallBrowser> handler = AquaCallBrowser::GetInterface();
	if (handler.get()) {
		handler->CloseAllBrowser();
	}
}

///
//	��ȡ������������ĻỰ�������
///
AQUAENTRYFULL(LPVOID, BrowserHost, GetCookieManager)(LPVOID object) {
	CefRefPtr<CefCookieManager> manager = NULL;
	if (object) {
		CefBrowserHost *host = reinterpret_cast<CefBrowserHost*>(object);
		host->AddRef();
		manager = host->GetRequestContext()->GetDefaultCookieManager(NULL);
		if (manager.get()) {
			manager->AddRef();
		}
		host->Release();
	}
	return manager.get();
}

///
//	����JS�Ի���
///
AQUAENTRYFULL(void, JSDialog, Continue)(LPVOID object, bool success, LPCSTR input) {
	if (object) {
		auto p = reinterpret_cast<CefJSDialogCallback*>(object);
		std::wstring v;
		if (input != NULL && strlen(input) > 0) {
			aqua_convert conv;
			v = conv.from_bytes(input);
		}
		p->AddRef();
		p->Continue(success, v);
		p->Release();
	}
}

///
//	�����ļ��Ի���
///
AQUAENTRYFULL(void, FileDialog, Continue)(LPVOID object, int selection, LPVOID file_paths) {
	if (object && file_paths) {
		auto p = reinterpret_cast<CefFileDialogCallback*>(object);
		auto v = reinterpret_cast<std::vector<CefString>*>(file_paths);
		p->AddRef();
		p->Continue(selection, (*v));
		p->Release();
	}
}

///
//	�����ļ��Ի���
///
AQUAENTRYFULL(void, FileDialog, Cancel)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefFileDialogCallback*>(object);
		p->AddRef();
		p->Cancel();
		p->Release();
	}
}

///
//	ȡRequest������
///
AQUAENTRYFULL(LPVOID, BrowserHost, GetRequestContext)(LPVOID object) {
	//CefRefPtr<CefBrowserHost> context = NULL;
	//if (object) {
	//	CefBrowserHost *host = reinterpret_cast<CefBrowserHost*>(object);
	//	host->AddRef();
	//	context = host->GetRequestContext();
	//	if (context.get()) {
	//		context->AddRef();
	//	}
	//	host->Release();
	//}
	//return context.get();
	return NULL;
}