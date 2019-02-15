#ifndef AQUA_BROWSER_HOST_REFER_H_
#define AQUA_BROWSER_HOST_REFER_H_
#include "utils\aqua_utils.h"
#include "cef\aqua_window.h"

/**
  * ���ڱ�ʾ��������ڵ���������̷�����ࡣ��
  * �����ķ���ֻ��������������е��á� ���ǿ�����
  * �ڸý����е��κ��߳��ϵ��ã���������˵��
  * ע�͡�
  * * * * * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	ʹ��ָ���Ĵ��ڲ�������һ���µ����������
	//	 | windowInfo |������ֵ�����ڲ����ƣ�����ʵ�ʴ����и���
	//	����UI�߳��ϴ��������| request_context |Ϊ��
	//	��ʹ��ȫ�����������ġ�
	//	����������̲߳�����������
	///
	AQUAENTRYFULL(BOOL, BrowserHost, CreateBrowserA)(LPCSTR url, LPVOID windowInfo,LPVOID settings,LPVOID rcs);

	///
	//	ʹ��ָ���Ĵ��ڲ�������һ���µ����������
	//	 | windowInfo |������ֵ�����ڲ����ƣ�����ʵ�ʴ����и���
	//	����UI�߳��ϴ��������| request_context |Ϊ��
	//	��ʹ��ȫ�����������ġ�
	//	����������̲߳�����������
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, CreateBrowserW)(LPCWSTR url, LPVOID windowInfo, LPVOID settings, LPVOID rcs);

	///
	//	�����й����������
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, GetBrowser)(LPVOID object);

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
	AQUAENTRYFULL(void, BrowserHost, CloseBrowser)(LPVOID object,BOOL force_close);

	///
	//	�ر��������Helper�Ӷ��㴰�ڵ����������
	//	close�����������ر��ˣ����ڲ�����CloseBrowser��false��
	//	��δ���������ر�ʱ���˷�������false
	//	�ȴ����ڹر���ɺ󷵻�true�������CloseBrowser������
	//	CefLifeSpanHandler :: DoClose�����ĵ��Ի�ȡ�����÷�
	//	information������������������������UI�߳��ϵ��á�
	///
	AQUAENTRYFULL(void, BrowserHost, TryCloseBrowser)(LPVOID object);

	///
	//	����������Ƿ���뽹�㡣
	///
	AQUAENTRYFULL(void, BrowserHost, SetFocus)(LPVOID object,BOOL focus);

	///
	//	Ϊ�˼������ھ�������������������װ��
	//	һ��CefBrowserViewӦ�������������UI�ϵ����������
	//	�̣߳��������ض����������ڵľ����
	///
	AQUAENTRYFULL(HWND, BrowserHost, GetWindowHandle)(LPVOID object);

	///
	//	��ȡ��ǰ���ż���Ĭ�����ż���Ϊ0.0���˷�������
	//	ֻ����UI�߳��е��á�
	///
	AQUAENTRYFULL(double, BrowserHost, GetZoomLevel)(LPVOID object);

	///
	//	�����ż������Ϊָ��ֵ��ָ��0.0������
	//	���ż��������UI�߳��ϵ��ã����Ӧ�ø���
	//	���������򣬸��Ľ����첽Ӧ����
	//	UI�̡߳�
	///
	AQUAENTRYFULL(void, BrowserHost, SetZoomLevel)(LPVOID object,double zoomLevel);

	///
	//	ʹ��CefDownloadHandler�� | url | �����ļ���
	///
	AQUAENTRYFULL(void, BrowserHost, StartDownloadA)(LPVOID object,LPCSTR url);

	///
	//	ʹ��CefDownloadHandler�� | url | �����ļ���
	///
	AQUAENTRYFULL(void, BrowserHost, StartDownloadW)(LPVOID object, LPCSTR url);

	///
	//	��ӡ��ǰ����������ݡ�
	///
	AQUAENTRYFULL(void, BrowserHost, Print)(LPVOID object);

	///
	//	���Լ���������д򿪿������ߣ�DevTools����DevTools�����
	//	��������������������������DevTools�������
	//	�Ѿ��򿪣���ô�������۽��������������| windowInfo |��
	//	��� | inspect_element_at | ��// | client |��| settings |������������
	//	�ǿգ���ôָ����x��y��λ�õ�Ԫ�ؽ�����
	//	��顣������������| windowInfo |������������
	//	��װ��CefBrowserView�С�
	///
	AQUAENTRYFULL(void, BrowserHost, ShowDevTools)(LPVOID object,LPVOID windowInfo,LPVOID settings,int x,int y);

	///
	//	��ȷ�ر���ص�DevTools�����������еĻ�����
	///
	AQUAENTRYFULL(void, BrowserHost, CloseDevTools)(LPVOID object);

	///
	//	������������ǰ���й�����DevTools��������򷵻�true��
	//	���������������UI�߳��ϵ��á�
	///
	AQUAENTRYFULL(BOOL, BrowserHost, HasDevTools)(LPVOID object);

	///
	//	���û��������ı����á�
	///
	AQUAENTRYFULL(void, BrowserHost, SetMouseCursorChangeDisabled)(LPVOID object, bool disabled);

	///
	//	��������������ģ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, BrowserHost, IsMouseCursorChangeDisabled)(LPVOID object);

	///
	//	������ô�����Ⱦ���򷵻�true��
	///
	AQUAENTRYFULL(BOOL, BrowserHost, IsWindowRenderingDisabled)(LPVOID object);

	///
	//	֪ͨ�����С�����ѱ�������С�����������
	//	����CefRenderHandler :: GetViewRect��ȡ�µĴ�СȻ�����
	//	 CefRenderHandler :: OnPaint����������첽
	//	�������ڽ��ô�����Ⱦʱʹ�á�
	///
	AQUAENTRYFULL(void, BrowserHost, WasResized)(LPVOID object);

	///
	//	֪ͨ��������ѱ����ػ���ʾ
	//	CefRenderHandler :: OnPaint֪ͨ���������ֹͣʱֹͣ
	//	hidden���������ֻ�ڽ��ô�����Ⱦʱʹ�á�
	///
	AQUAENTRYFULL(void, BrowserHost, WasHidden)(LPVOID object, bool hidden);

	///
	//	�������������Ļ��Ϣ�Ѹ��ĵ�֪ͨ��
	//	����������CefRenderHandler :: GetScreenInfo������
	//	ʹ�������ֵ����ʾ��Ϣ����ģ���ƶ�webview
	//	��һ����ʾ���ڵ���һ����ʾ���ڣ����߸ı䴰�ڵ�����
	//	��ǰ��ʾ���÷������ڴ�����Ⱦʱʹ��
	//	���á�
	///
	AQUAENTRYFULL(void, BrowserHost, NotifyScreenInfoChanged)(LPVOID object);

	///
	//	ʹ��ͼ��Ч�������������CefRenderHandler :: OnPaint
	//	�첽���˷������ڴ��ڳ���ʱʹ��
	//	���á�
	///
	AQUAENTRYFULL(void, BrowserHost, Invalidate)(LPVOID object,int status);

	///
	//	�������¼����͵��������
	///
	AQUAENTRYFULL(void, BrowserHost, SendFocusEvent)(LPVOID object, bool setFocus);

	///
	//	����������Ͳ���ʧ�¼���
	///
	AQUAENTRYFULL(void, BrowserHost, SendCaptureLostEvent)(LPVOID object);

	///
	//	֪ͨ������й����Ĵ��ڼ������ƶ����ƶ�
	//	������С���˷���������Windows��Linux��
	///
	AQUAENTRYFULL(void, BrowserHost, NotifyMoveOrResizeStarted)(LPVOID object);

	///
	//	��ÿ��֡����fps�������������CefRenderHandler ::
	//	OnPaint�������������޴����������ʵ�ʵ�fps������
	//	���������޷����������������֡���򽵵͡�
	//	��СֵΪ1�����ֵΪ60��Ĭ��ֵΪ30��
	//	ֻ����UI�߳��е��á�
	///
	AQUAENTRYFULL(int, BrowserHost, GetWindowlessFrameRate)(LPVOID object);

	///
	//	����ÿ��֡����fps�����������CefRenderHandler ::
	//	OnPaint�������������޴����������ʵ�ʵ�fps������
	//	���������޷����������������֡���򽵵͡�
	//	��Сֵ��1�����ֵ��60��Ĭ��30����Ҳ������
	//	ͨ��CefBrowserSettings.windowless_frame_rate�����������
	///
	AQUAENTRYFULL(void, BrowserHost, SetWindowlessFrameRate)(LPVOID object, int frame_rate);

	///
	//	���ؼ��¼����͵��������
	///
	AQUAENTRYFULL(void, BrowserHost, SendKeyEvent)(LPVOID object,LPVOID event);

	///
	//	����굥���¼����͵�������� | x | ��| y | ��������ͼ�����Ͻǡ�
	///
	AQUAENTRYFULL(void, BrowserHost, SendMouseClickEvent)(LPVOID object, LPVOID event, int type, bool mouseUp, int clickCount);

	///
	//	������ƶ��¼����͵�������� | x | ��| y | �����������ͼ�����Ͻǡ�
	///
	AQUAENTRYFULL(void, BrowserHost, SendMouseMoveEvent)(LPVOID object, LPVOID event, bool mouseLeave);

	///
	//	���������¼����͵�������� | x | ��| y | ������
	//	�������ͼ�����Ͻǡ� | deltaX | �� | deltaY |
	//	ֵ�ֱ��ʾX��Y�����ϵ��˶�������
	//	Ϊ���ڽ��ô�����Ⱦ������¹����ڲ�ѡ�񵯳�����
	//	Ӧ����ȷʵ��CefRenderHandler::GetScreenPoint��
	///
	AQUAENTRYFULL(void, BrowserHost, SendMouseWheelEvent)(LPVOID object, LPVOID event, int deltaX, int deltaY);

	///
	//	�ƶ�������ڹ������е����������λ�ü���С,|parent|��ΪNULLʱ,�������ô����µ����������������
	//	���򽫵������д��ڡ�
	///
	AQUAENTRYFULL(void, Manager, MoveOrResized)(HWND parent, int x, int y, int width, int height);

	///
	//	��������ʾ�����
	///
	AQUAENTRYFULL(void, Manager, SetMainHeroine)(HWND parent,HWND child);

	///
	//	��ѯ����������|id|���й��������������,������NULLʱ����ζ���Ҳ������������Ķ���
	///
	AQUAENTRYFULL(LPVOID, Manager, QueryActor)(HWND id);

	///
	//	��ȡ�������е����������
	///
	AQUAENTRYFULL(int, Manager, GetCount)(void);

	///
	//	�ر����������
	///
	AQUAENTRYFULL(void, Manager, CloseAllBrowser)(void);

	///
	//	��ȡ������������ĻỰ�������
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, GetCookieManager)(LPVOID object);

	///
	//	����JS�Ի���
	///
	AQUAENTRYFULL(void, JSDialog, Continue)(LPVOID object,bool success, LPCSTR input);

	///
	//	�����ļ��Ի���
	///
	AQUAENTRYFULL(void, FileDialog, Continue)(LPVOID object,int selection,LPVOID file_paths);

	///
	//	�����ļ��Ի���
	///
	AQUAENTRYFULL(void, FileDialog, Cancel)(LPVOID object);

	///
	//	ȡRequest������
	///
	AQUAENTRYFULL(LPVOID, BrowserHost, GetRequestContext)(LPVOID object);
}


#endif