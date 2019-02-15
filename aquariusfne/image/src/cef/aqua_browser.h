#ifndef AQUA_BROWSER_REFER_H_
#define AQUA_BROWSER_REFER_H_
#include "utils\aqua_utils.h"

/**
  * ���ڱ�ʾ��������ڵ��ࡣ �������������ʹ��ʱ
  * ��������˵��������������κ��߳��ϵ��ô���ķ���
  * ��������ָ���� ����Ⱦ������ʹ�õķ���
  * �����ֻ�������߳��е��á�
  * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	����������������� �˷���ֻ��������������е��á�
	///
	AQUAENTRYFULL(LPVOID, Browser, GetHost)(LPVOID object);

	///
	//	��������������󵼺����򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Browser, CanGoBack)(LPVOID object);

	///
	//	��󵼺���
	///
	AQUAENTRYFULL(void, Browser, GoBack)(LPVOID object);

	///
	//	��������������ǰ�������򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Browser, CanGoForward)(LPVOID object);

	///
	//	��ǰ������
	///
	AQUAENTRYFULL(void, Browser, GoForward)(LPVOID object);

	///
	//	�����������ڼ��أ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Browser, IsLoading)(LPVOID object);

	///
	//	���¼��ص�ǰҳ�档
	///
	AQUAENTRYFULL(void, Browser, Reload)(LPVOID object);

	///
	//	���¼��ص�ǰҳ�棬�����κλ�������ݡ�
	///
	AQUAENTRYFULL(void, Browser, ReloadIgnoreCache)(LPVOID object);

	///
	//	ֹͣ����ҳ�档
	///
	AQUAENTRYFULL(void, Browser, StopLoad)(LPVOID object);

	///
	//	���ش��������ȫ��Ψһ��ʶ���� ��ֵҲ������չAPI��tabId��
	///
	AQUAENTRYFULL(int, Browser, GetIdentifier)(LPVOID object);

	///
	//	����˶���ָ����| that |��ͬ�ľ�����򷵻�true Ŀ�ġ�
	///
	AQUAENTRYFULL(BOOL, Browser, IsSame)(LPVOID object,LPVOID that);

	///
	//	���������һ���������ڣ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Browser, IsPopup)(LPVOID object);

	///
	//	����ĵ��ѱ����ص�������У��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Browser, HasDocument)(LPVOID object);

	///
	//	������������ڵ�������������ܡ�
	///
	AQUAENTRYFULL(LPVOID, Browser, GetMainFrame)(LPVOID object);

	///
	//	������������ڵĽ����
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFocusedFrame)(LPVOID object);

	///
	//	���ؾ���ָ����ʶ����Frame�����δ�ҵ����򷵻�NULL��
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameFromId)(LPVOID object,__int64 identify);

	///
	//	���ؾ���ָ�����Ƶ�Frame�����δ�ҵ����򷵻�NULL��
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameA)(LPVOID object, LPCSTR name);

	///
	//	���ؾ���ָ�����Ƶ�Frame�����δ�ҵ����򷵻�NULL��
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameFromNameW)(LPVOID object, LPCWSTR name);

	///
	//	���ص�ǰ���ڵ�֡����
	///
	AQUAENTRYFULL(int, Browser, GetFrameCount)(LPVOID object);

	///
	//	������������Frame�ı�ʶ����
	//	����Int64����,���ʷ����μ�"Int64Vector"�������
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameIdentifiers)(LPVOID object);

	///
	//	������������Frame�����ơ�
	//	�����ַ�������,���ʷ����μ�"StrVector"�������
	///
	AQUAENTRYFULL(LPVOID, Browser, GetFrameNames)(LPVOID object);

	///
	//	������Ϣ��ָ����| target_process |�� �����Ϣ�ѳɹ����ͣ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Browser, SendProcessMessageA)(LPVOID object, int target_process,LPCSTR message,char *payload,int length);

}


#endif