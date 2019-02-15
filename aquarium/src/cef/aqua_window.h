#ifndef AQUA_WINDOW_REFER_H_
#define AQUA_WINDOW_REFER_H_
#include "utils\aqua_utils.h"


/**
  * ��ʾ������Ϣ���ࡣ
  * * * * * * * * */

namespace AquaWindow {

	///
	//	����һ���µĴ��ڶ���ʵ��
	///
	AQUAENTRYFULL(LPVOID, Window, Create)(void);

	///
	//	����һ�����ڶ���
	///
	AQUAENTRYFULL(LPVOID, Window, Copy)(LPVOID object);

	///
	//	�����������Ϊ�Ӵ��ڡ�
	///
	AQUAENTRYFULL(void, Window, SetAsChild)(LPVOID object,HWND parent, int x, int y, int width, int height);

	///
	//	���������Ϊһ���������ڡ�
	///
	AQUAENTRYFULL(void, Window, SetAsPopupA)(LPVOID object, HWND parent,LPCSTR title);

	///
	//	���������Ϊһ���������ڡ�
	///
	AQUAENTRYFULL(void, Window, SetAsPopupW)(LPVOID object, HWND parent, LPCWSTR title);

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
	AQUAENTRYFULL(void, Window, SetAsWindowless)(LPVOID object, HWND parent);

	///
	//	���Ĵ��ڵ���ʽ��Ϣ��
	///
	AQUAENTRYFULL(void, Window, ModifyStyle)(LPVOID object,DWORD style,DWORD styleEx);


	///
	//	����һ�����ڶ���
	///
	AQUAENTRYFULL(void, Window, Destoryed)(LPVOID object);
}

#endif