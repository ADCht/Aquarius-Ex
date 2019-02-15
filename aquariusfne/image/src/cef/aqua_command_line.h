#ifndef AQUA_COMMAND_LINE_REFER_H_
#define AQUA_COMMAND_LINE_REFER_H_
#include "utils\aqua_utils.h"

/**
  * ���ڴ�����/����������в������ࡣ ��...������
  * ' - '��' - '����Windows�ϣ�'/'ǰ׺����Ϊ������������
  * ��ʼ����û���л�ǰ׺���κβ���֮ǰ�� ���ؿ���
  * ��ѡ�ؾ���ʹ��'='�ָ���ָ����ֵ�����磬
  * ��-switch = value������ �� - ���Ĳ�������ֹ���еĽ���������
  * �������ƣ�����ǰ׺��������Ϊ�ǿ���
  * ������ ���������Ʊ���Ϊ�����ִ�Сд�� ��������
  * �ڵ���CefInitialize����֮ǰʹ�á�
  * * * * * * * * * * * * * * * * * * * * * * * */

namespace AquaCef {

	///
	//	����һ���µ�CefCommandLineʵ����
	///
	AQUAENTRY(LPVOID, CreateCommandLine)(void);

	///
	//	���ص���ȫ��CefCommandLine���� ���صĶ�����ֻ���ġ�
	///
	AQUAENTRY(LPVOID, GetGlobalCommandLine)(void);

	///
	//	����˶�����Ч���򷵻�true�� ����˺�������false����Ҫ�����κ�����������
	///
	AQUAENTRYFULL(BOOL, CommandLine, IsValid)(LPVOID object);

	///
	//	����˶����ֵ��ֻ���ģ��򷵻�true�� һЩAPI���ܻṫ��ֻ������
	///
	AQUAENTRYFULL(BOOL, CommandLine, IsReadOnly)(LPVOID object);

	///
	//	���ش˶���Ŀ�д������
	///
	AQUAENTRYFULL(LPVOID, CommandLine, Copy)(LPVOID object);

	///
	//	��ָ����| argc |��ʼ�������� ��| argv |ֵ�� ��һ�����������ǳ�������ơ�
	//	�˷������ڷ�Windowsƽ̨����֧�֡�
	///
	AQUAENTRYFULL(void, CommandLine, InitFromArgv)(LPVOID object,int argc, const char* const* argv);

	///
	//	��ͨ������GetCommandLineA�������ص��ַ�����ʼ�������С� �˷�������Windows����֧�֡�
	///
	AQUAENTRYFULL(void, CommandLine, InitFromStringA)(LPVOID object, LPCSTR command_line);

	///
	//	��ͨ������GetCommandLineA�������ص��ַ�����ʼ�������С� �˷�������Windows����֧�֡�
	///
	AQUAENTRYFULL(void, CommandLine, InitFromStringW)(LPVOID object, LPCWSTR command_line);

	///
	//	���������п��غͲ����������ֳ���������䡣
	///
	AQUAENTRYFULL(void, CommandLine, Reset)(LPVOID object);

	///
	//	����ԭʼ�������ַ�����Ϊ�ַ�����������
	//	argv���飺{program��[�� - | - | /��switch [= value]] *��[ - ]��[argument] *}
	//	�����ַ�������,���ʷ����μ�"StrVector"�������
	///
	AQUAENTRYFULL(LPVOID, CommandLine, GetArgv)(LPVOID object);

	///
	//	���첢���ر�ʾ���������ַ����� ����ʹ�ô˷�������Ϊ������Ϊ�������
	//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
	///
	AQUAENTRYFULL(int, CommandLine, GetCommandLineStringA)(LPVOID object,LPSTR buffer,int length);

	///
	//	���첢���ر�ʾ���������ַ����� ����ʹ�ô˷�������Ϊ������Ϊ�������
	//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
	///
	AQUAENTRYFULL(int, CommandLine, GetCommandLineStringW)(LPVOID object, LPWSTR buffer, int length);

	///
	//	��ȡ���򲿷ֵ��������ַ�������һ���
	//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
	///
	AQUAENTRYFULL(int, CommandLine, GetProgramA)(LPVOID object, LPSTR buffer, int length);

	///
	//	��ȡ���򲿷ֵ��������ַ�������һ���
	//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
	///
	AQUAENTRYFULL(int, CommandLine, GetProgramW)(LPVOID object, LPSTR buffer, int length);

	///
	//	�����������ַ����ĳ��򲿷֣���һ���
	///
	AQUAENTRYFULL(void, CommandLine, SetProgramA)(LPVOID object,LPCSTR value);

	///
	//	�����������ַ����ĳ��򲿷֣���һ���
	///
	AQUAENTRYFULL(void, CommandLine, SetProgramW)(LPVOID object, LPCWSTR value);

	///
	//	����������п��أ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasSwitches)(LPVOID object);

	///
	//	��������а��������Ŀ��أ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasSwitchA)(LPVOID object,LPCSTR name);

	///
	//	��������а��������Ŀ��أ��򷵻�true��
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasSwitchW)(LPVOID object, LPCWSTR name);

	///
	//	������������ع�����ֵ�� �������û��ֵ�򲻴��ڣ���˷������ؿ��ַ�����
	//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
	///
	AQUAENTRYFULL(int, CommandLine, GetSwitchValueA)(LPVOID object,LPCSTR name, LPSTR buffer, int length);

	///
	//	������������ع�����ֵ�� �������û��ֵ�򲻴��ڣ���˷������ؿ��ַ�����
	//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
	///
	AQUAENTRYFULL(int, CommandLine, GetSwitchValueW)(LPVOID object, LPCWSTR name, LPWSTR buffer, int length);

	///
	//	���ؿ������ƺ�ֵ��ӳ�䡣 ���һ������û��ֵ���򷵻�һ�����ַ�����
	//	�����ַ����ֵ�,���ʷ����μ�"StrDict"�������
	///
	AQUAENTRYFULL(LPVOID, CommandLine, GetSwitches)(LPVOID object);

	///
	//	��һ��������ӵ������е�ĩβ�� �������û��ֵ����һ����ֵ�ַ�����
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchA)(LPVOID object,LPCSTR name);

	///
	//	��һ��������ӵ������е�ĩβ�� �������û��ֵ����һ����ֵ�ַ�����
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchW)(LPVOID object, LPCWSTR name);

	///
	//	������ָ��ֵ�Ŀ�����ӵ������е�ĩβ��
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueA)(LPVOID object, LPCSTR name,LPCSTR value);

	///
	//	������ָ��ֵ�Ŀ�����ӵ������е�ĩβ��
	///
	AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueW)(LPVOID object, LPCSTR name, LPCSTR value);

	///
	//	�����ʣ��������в�������Ϊ�档
	///
	AQUAENTRYFULL(BOOL, CommandLine, HasArguments)(LPVOID object);

	///
	//	��ȡ����������в�����
	//	�����ַ�������,���ʷ����μ�"StrVector"�������
	///
	AQUAENTRYFULL(LPVOID, CommandLine, GetArguments)(LPVOID object);

	///
	//	�������е�ĩβ���һ��������
	///
	AQUAENTRYFULL(void, CommandLine ,AppendArgumentA)(LPVOID object, LPCSTR value);

	///
	//	�������е�ĩβ���һ��������
	///
	AQUAENTRYFULL(void, CommandLine, AppendArgumentW)(LPVOID object, LPCSTR value);

	///
	//	�ڵ�ǰ����֮ǰ����һ����� ͨ�����ڵ��������硰valgrind����gdb --args����
	///
	AQUAENTRYFULL(void, CommandLine, PrependWrapperA)(LPVOID object, LPCSTR wapper);

	///
	//	�ڵ�ǰ����֮ǰ����һ����� ͨ�����ڵ��������硰valgrind����gdb --args����
	///
	AQUAENTRYFULL(void, CommandLine, PrependWrapperW)(LPVOID object, LPCSTR wapper);
}

#endif