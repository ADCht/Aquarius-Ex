#ifndef AQUA_FRAME_H_
#define AQUA_FRAME_H_
#include "utils\aqua_utils.h"

namespace AquaCef {
	
	/**
	  *	����������������б�ʾ��ܵ��ࡣ ��ʹ��ʱ
	  * ��������̿��ܻ����κ��߳��ϵ��ô���ķ���������
	  * ������������ָ���� ����Ⱦ������ʹ��ʱ
	  * �����ķ���ֻ�������߳��е��á�
	  * * * * * * * * * * * * * * * * * * * */

	///
	//	����˶���ǰ���ӵ���Ч��ܣ���Ϊ�档
	///
	AQUAENTRYFULL(BOOL, Frame, IsValid)(LPVOID object);

	///
	//	�ڴ˿����ִ�г�����
	///
	AQUAENTRYFULL(void, Frame, Undo)(LPVOID object);

	///
	//	�ڴ˿����ִ��������
	///
	AQUAENTRYFULL(void, Frame, Redo)(LPVOID object);

	///
	//	�ڴ˿����ִ�м��С�
	///
	AQUAENTRYFULL(void, Frame, Cut)(LPVOID object);

	///
	//	����������ִ�и��ơ�
	///
	AQUAENTRYFULL(void, Frame, Copy)(LPVOID object);

	///
	//	����������ִ��ճ����
	///
	AQUAENTRYFULL(void, Frame, Paste)(LPVOID object);

	///
	//	�ڴ˿���ִ��ɾ����
	///
	AQUAENTRYFULL(void, Frame, Delete)(LPVOID object);

	///
	//	ִ���ڴ˿���ѡ��ȫ����
	///
	AQUAENTRYFULL(void, Frame, SelectAll)(LPVOID object);

	///
	//	�Է��͵�ָ�������ߵ��ַ��������˿�ܵ�HTMLԴ���롣
	///
	AQUAENTRYFULL(BOOL, Frame, GetSourceA)(LPVOID object, LPVOID callback,LPVOID params,BOOL async);

	///
	//	�Է��͵�ָ�������ߵ��ַ��������˿�ܵ�HTML�ı���
	///
	AQUAENTRYFULL(BOOL, Frame, GetTextA)(LPVOID object, LPVOID callback, LPVOID params, BOOL async);

	///
	//	����ָ����| url |��
	///
	AQUAENTRYFULL(BOOL, Frame, LoadURLA)(LPVOID object, LPCSTR url);

	///
	//	����| string_val |������ ʹ��ָ��������| url |��|��ַ|
	//	Ӧ����һ����׼�ķ��������磬http�����������Ƶ���Ϊ
	//	���ӵ�����������簲ȫ���ƿ����޷���Ԥ�����С�
	///
	AQUAENTRYFULL(BOOL, Frame, LoadStringA)(LPVOID object, LPCSTR html,LPCSTR url);

	AQUAENTRYFULL(void, Frame, LoadRequest)(LPVOID object,LPVOID request);

	///
	//	�ڴ˿����ִ��һ��JavaScript���롣 | script_url |
	//	�����ǿ����ҵ�������Ľű���URL������еĻ���
	//	��Ⱦ�����ܻ������URL���򿪷���Ա��ʾ
	//	���� | start_line | ���������ڳ���Ļ��ߺ�
	//	���档
	///
	AQUAENTRYFULL(BOOL, Frame, ExecuteJavaScriptA)(LPVOID object,LPCSTR code,LPCSTR url,int line);

	///
	//	�������������������ܣ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Frame, IsMain)(LPVOID object);

	///
	//	������Ǿ۽���ܣ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, Frame, IsFocused)(LPVOID object);

	///
	//	���ش�֡�����ơ� ��������һ����������ƣ�����
	//	���磬ͨ��iframe��name���������ã�����ô��ֵ����
	//	�ء� ���򣬽����ݸÿ�ܹ���Ψһ������
	//	����νṹ�� ������������ܽ�ʼ����һ���յ�����
	//	ֵ��
	///
	AQUAENTRYFULL(int, Frame, GetNameA)(LPVOID object, LPSTR buf, int len);

	///
	//	���ش�֡��ȫ��Ψһ��ʶ��������ײ�֡�в����ڣ��򷵻�<0��
	///
	AQUAENTRYFULL(__int64, Frame, GetIdentifier)(LPVOID object);

	///
	//	���ش�֡�ĸ�Ԫ�ػ�NULL�������������������֡��
	///
	AQUAENTRYFULL(LPVOID, Frame, GetParent)(LPVOID object);

	///
	//	���ص�ǰ�ڴ˿���м��ص�URL��
	///
	AQUAENTRYFULL(int, Frame, GetURLA)(LPVOID object, LPSTR buf, int len);

	///
	//	���ش�֡�������������
	///
	AQUAENTRYFULL(LPVOID, Frame, GetBrowser)(LPVOID object);

	///
	//	ִ�б��ʽ
	///
	AQUAENTRYFULL(void,Frame,EvalA)(LPVOID object,LPCSTR code,LPCSTR url,int line,LPVOID callback,LPVOID params,BOOL async);
}

#endif