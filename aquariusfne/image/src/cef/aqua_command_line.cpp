#include "aqua_command_line.h"
#include "utils\aqua_conv.h"
#include "include\cef_command_line.h"

using namespace AquaCef;

///
//	����һ���µ�CefCommandLineʵ����
///
AQUAENTRY(LPVOID, CreateCommandLine)(void) {
	CefRefPtr<CefCommandLine> object = CefCommandLine::CreateCommandLine();
	object->AddRef();
	return (LPVOID)object.get();
}

///
//	���ص���ȫ��CefCommandLine���� ���صĶ�����ֻ���ġ�
///
AQUAENTRY(LPVOID, GetGlobalCommandLine)(void) {
	CefRefPtr<CefCommandLine> object = CefCommandLine::GetGlobalCommandLine();
	object->AddRef();
	return (LPVOID)object.get();
}

///
//	����˶�����Ч���򷵻�true�� ����˺�������false����Ҫ�����κ�����������
///
AQUAENTRYFULL(BOOL, CommandLine, IsValid)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		BOOL result = FALSE;
		pUnit->AddRef();
		result = pUnit->IsValid();
		pUnit->Release();
		return result;
	}
	return FALSE;
}

///
//	����˶����ֵ��ֻ���ģ��򷵻�true�� һЩAPI���ܻṫ��ֻ������
///
AQUAENTRYFULL(BOOL, CommandLine, IsReadOnly)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		BOOL result = FALSE;
		pUnit->AddRef();
		result = pUnit->IsReadOnly();
		pUnit->Release();
		return result;
	}
	return FALSE;
}

///
//	���ش˶���Ŀ�д������
///
AQUAENTRYFULL(LPVOID, CommandLine, Copy)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		LPVOID result = NULL;
		pUnit->AddRef();
		CefRefPtr<CefCommandLine> newCopyer = pUnit->Copy();
		newCopyer->AddRef();
		result = newCopyer.get();
		pUnit->Release();
		return result;
	}
	return NULL;
}

///
//	��ָ����| argc |��ʼ�������� ��| argv |ֵ�� ��һ�����������ǳ�������ơ�
//	�˷������ڷ�Windowsƽ̨����֧�֡�
///
AQUAENTRYFULL(void, CommandLine, InitFromArgv)(LPVOID object, int argc, const char* const* argv) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->InitFromArgv(argc, argv);
		pUnit->Release();
		return ;
	}
	return ;
}

///
//	��ͨ������GetCommandLineA�������ص��ַ�����ʼ�������С� �˷�������Windows����֧�֡�
///
AQUAENTRYFULL(void, CommandLine, InitFromStringA)(LPVOID object, LPCSTR command_line) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto cmd = conv.from_bytes(command_line);
		pUnit->InitFromString(cmd);
		pUnit->Release();
	}
}

///
//	��ͨ������GetCommandLineA�������ص��ַ�����ʼ�������С� �˷�������Windows����֧�֡�
///
AQUAENTRYFULL(void, CommandLine, InitFromStringW)(LPVOID object, LPCWSTR command_line) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->InitFromString(command_line);
		pUnit->Release();
	}
}

///
//	����ԭʼ�������ַ�����Ϊ�ַ�����������
//	argv���飺{program��[�� - | - | /��switch [= value]] *��[ - ]��[argument] *}
///
AQUAENTRYFULL(LPVOID, CommandLine, GetArgv)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		LPVOID result = NULL;
		std::vector<CefString> *pArgvs = new std::vector<CefString>;
		pUnit->AddRef();
		pUnit->GetArgv((*pArgvs));
		pUnit->Release();
		return pArgvs;
	}
	return NULL;
}

///
//	���첢���ر�ʾ���������ַ����� ����ʹ�ô˷�������Ϊ������Ϊ�������
//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
///
AQUAENTRYFULL(int, CommandLine, GetCommandLineStringA)(LPVOID object, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetCommandLineString();
		auto text = conv.to_bytes(cmd.c_str());
		if (length == 0) {
			result = text.length();
		}
		else {
			memmove(buffer, text.c_str(), text.length());
			result = text.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	���첢���ر�ʾ���������ַ����� ����ʹ�ô˷�������Ϊ������Ϊ�������
//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
///
AQUAENTRYFULL(int, CommandLine, GetCommandLineStringW)(LPVOID object, LPWSTR buffer, int length) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetCommandLineString();
		if (length == 0) {
			result = cmd.length();
		}
		else {
			memmove(buffer, cmd.c_str(), cmd.length());
			result = cmd.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	��ȡ���򲿷ֵ��������ַ�������һ���
//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
///
AQUAENTRYFULL(int, CommandLine, GetProgramA)(LPVOID object, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetProgram();
		auto text = conv.to_bytes(cmd.c_str());
		if (length == 0) {
			result = text.length();
		}
		else {
			memmove(buffer, text.c_str(), text.length());
			result = text.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	��ȡ���򲿷ֵ��������ַ�������һ���
//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
///
AQUAENTRYFULL(int, CommandLine, GetProgramW)(LPVOID object, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &cmd = pUnit->GetProgram();
		if (length == 0) {
			result = cmd.length();
		}
		else {
			memmove(buffer, cmd.c_str(), cmd.length());
			result = cmd.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	�����������ַ����ĳ��򲿷֣���һ���
///
AQUAENTRYFULL(void, CommandLine, SetProgramA)(LPVOID object, LPCSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		aqua_convert conv;
		pUnit->AddRef();
		auto cmd = conv.from_bytes(value);
		pUnit->SetProgram(cmd);
		pUnit->Release();
	}
}

///
//	�����������ַ����ĳ��򲿷֣���һ���
///
AQUAENTRYFULL(void, CommandLine, SetProgramW)(LPVOID object, LPCWSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->SetProgram(value);
		pUnit->Release();
	}
}

///
//	����������п��أ��򷵻�true��
///
AQUAENTRYFULL(BOOL, CommandLine, HasSwitches)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		result = pUnit->HasSwitches();
		pUnit->Release();
	}
	return result;
}

///
//	��������а��������Ŀ��أ��򷵻�true��
///
AQUAENTRYFULL(BOOL, CommandLine, HasSwitchA)(LPVOID object,LPCSTR name) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		result = pUnit->HasSwitch(key);
		pUnit->Release();
	}
	return result;
}

///
//	��������а��������Ŀ��أ��򷵻�true��
///
AQUAENTRYFULL(BOOL, CommandLine, HasSwitchW)(LPVOID object, LPCWSTR name) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		result = pUnit->HasSwitch(name);
		pUnit->Release();
	}
	return result;
}

///
//	������������ع�����ֵ�� �������û��ֵ�򲻴��ڣ���˷������ؿ��ַ�����
//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
///
AQUAENTRYFULL(int, CommandLine, GetSwitchValueA)(LPVOID object, LPCSTR name, LPSTR buffer, int length) {
	int result = 0;
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		const auto &value = pUnit->GetSwitchValue(key);
		auto text = conv.to_bytes(value.c_str());
		if (length == 0) {
			result = text.length();
		}
		else {
			memmove(buffer, text.c_str(), text.length());
			result = text.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	������������ع�����ֵ�� �������û��ֵ�򲻴��ڣ���˷������ؿ��ַ�����
//	���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|�С�
///
AQUAENTRYFULL(int, CommandLine, GetSwitchValueW)(LPVOID object, LPCWSTR name, LPWSTR buffer, int length) {
	int result = 0;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		const auto &value = pUnit->GetSwitchValue(name);
		if (length == 0) {
			result = value.length();
		}
		else {
			memmove(buffer, value.c_str(), value.length());
			result = value.length();
		}
		pUnit->Release();
	}
	return result;
}

///
//	���ؿ������ƺ�ֵ��ӳ�䡣 ���һ������û��ֵ���򷵻�һ�����ַ�����
//	�����ַ����ֵ�,���ʷ����μ�"StrMap"�������
///
AQUAENTRYFULL(LPVOID, CommandLine, GetSwitches)(LPVOID object) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		LPVOID result = NULL;
		std::map<CefString,CefString> *pStrMap = new std::map<CefString, CefString>;
		pUnit->AddRef();
		pUnit->GetSwitches((*pStrMap));
		pUnit->Release();
		return pStrMap;
	}
	return NULL;
}

///
//	��һ��������ӵ������е�ĩβ�� �������û��ֵ����һ����ֵ�ַ�����
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchA)(LPVOID object, LPCSTR name) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		pUnit->AppendSwitch(key);
		pUnit->Release();
	}
}

///
//	��һ��������ӵ������е�ĩβ�� �������û��ֵ����һ����ֵ�ַ�����
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchW)(LPVOID object, LPCWSTR name) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendSwitch(name);
		pUnit->Release();
	}
}

///
//	������ָ��ֵ�Ŀ�����ӵ������е�ĩβ��
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueA)(LPVOID object, LPCSTR name, LPCSTR value) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto key = conv.from_bytes(name);
		auto text = conv.from_bytes(value);
		pUnit->AppendSwitchWithValue(key,text);
		pUnit->Release();
	}
}

///
//	������ָ��ֵ�Ŀ�����ӵ������е�ĩβ��
///
AQUAENTRYFULL(void, CommandLine, AppendSwitchWithValueW)(LPVOID object, LPCSTR name, LPCSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendSwitchWithValue(name, value);
		pUnit->Release();
	}
}

///
//	�����ʣ��������в�������Ϊ�档
///
AQUAENTRYFULL(BOOL, CommandLine, HasArguments)(LPVOID object) {
	BOOL result = FALSE;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		result = pUnit->HasArguments();
		pUnit->Release();
	}
	return result;
}

///
//	��ȡ����������в�����
//	�����ַ�������,���ʷ����μ�"StrVector"�������
///
AQUAENTRYFULL(LPVOID, CommandLine, GetArguments)(LPVOID object) {
	LPVOID result = NULL;
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		std::vector<CefString> *pStrVector = new std::vector<CefString>;
		pUnit->AddRef();
		pUnit->GetArguments((*pStrVector));
		pUnit->Release();
		result = pStrVector;
	}
	return result;
}

///
//	�������е�ĩβ���һ��������
///
AQUAENTRYFULL(void, CommandLine, AppendArgumentA)(LPVOID object, LPCSTR value) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto text = conv.from_bytes(value);
		pUnit->AppendArgument(text);
		pUnit->Release();
	}
}

///
//	�������е�ĩβ���һ��������
///
AQUAENTRYFULL(void, CommandLine, AppendArgumentW)(LPVOID object, LPCSTR value) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendArgument(value);
		pUnit->Release();
	}
}

///
//	�ڵ�ǰ����֮ǰ����һ����� ͨ�����ڵ��������硰valgrind����gdb --args����
///
AQUAENTRYFULL(void, CommandLine, PrependWrapperA)(LPVOID object, LPCSTR wapper) {
	if (object) {
		aqua_convert conv;
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		auto text = conv.from_bytes(wapper);
		pUnit->PrependWrapper(text);
		pUnit->Release();
	}
}

///
//	�ڵ�ǰ����֮ǰ����һ����� ͨ�����ڵ��������硰valgrind����gdb --args����
///
AQUAENTRYFULL(void, CommandLine, PrependWrapperW)(LPVOID object, LPCSTR wapper) {
	if (object) {
		CefCommandLine *pUnit = reinterpret_cast<CefCommandLine*>(object);
		pUnit->AddRef();
		pUnit->AppendArgument(wapper);
		pUnit->Release();
	}
}