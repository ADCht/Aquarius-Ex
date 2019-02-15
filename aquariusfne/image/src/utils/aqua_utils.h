#ifndef AQUA_UTILS_H_
#define AQUA_UTILS_H_
#include <string.h>
#include <Windows.h>

#ifndef AQUAENTRY
	#ifdef AQUAINLINE
		#define AQUAENTRY(x,name)				x(__cdecl *Aqua##name)
		#define AQUAENTRYFULL(x,space,name)		x(__cdecl *Aqua##space##name)
	#else
		#define AQUAENTRY(x,name) extern "C" x __declspec(dllexport) Aqua##name
		#define AQUAENTRYFULL(x,space,name) extern "C" x _declspec(dllexport) Aqua##space##name
	#endif
#endif



class CefBaseRefCounted;

namespace AquaUtils {

	/******************************
	 *			���ü���
	 ******************************/	


	///
	//	��|object|��������һ�����ü�����
	///
	AQUAENTRY(void, AddRef)(LPVOID object);

	///
	//	��|object|�������һ�����ü�����
	///
	AQUAENTRY(bool, Release)(LPVOID object);

	///
	//	������ü���Ϊ1���򷵻�true��
	///
	AQUAENTRY(bool, HasOenRef)(LPVOID object);

	///
	//	���ص�ǰ�������汾
	///
	AQUAENTRY(LPCSTR, GetAdapter)(void);

	///
	//	�˳�ϵͳ
	///
	AQUAENTRY(void, QuitProcess)(void);


	/******************************
	*			�ַ�������
	******************************/

	///
	//	ִ�и÷����󽫻���һ��"String Vector"�ַ�����������,
	//	��η������������Կ���"StrVector"�������ṩ�ķ������ϡ�
	///
	AQUAENTRYFULL(LPVOID, StrVector, Alloc)(void);

	///
	//	ִ�и÷����󽫻���һ����|object|�����п������¸�������,
	//	���|object|���Ϸ�������һ��NULL
	///
	AQUAENTRYFULL(LPVOID, StrVector, Copy)(LPVOID object);

	///
	//	ִ�и÷�����|object|ָ���"String Vector"�ַ���������
	//	׷���ַ���|text|
	///
	AQUAENTRYFULL(void, StrVector, AppendA)(LPVOID object,LPCSTR text);

	///
	//	ִ�и÷�����|object|ָ���"String Vector"�ַ���������
	//	׷���ַ���|text|
	///
	AQUAENTRYFULL(void, StrVector, AppendW)(LPVOID object, LPCWSTR text);

	///
	//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
	//	���������ַ���ֵ
	///
	AQUAENTRYFULL(void, StrVector, ReplaceA)(LPVOID object, int index,LPCSTR text);

	///
	//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
	//	���������ַ���ֵ
	///
	AQUAENTRYFULL(void, StrVector, ReplaceW)(LPVOID object, int index, LPCWSTR text);

	///
	//	ִ�и÷��������Ƴ�|object|ָ���"String Vector"�ַ���������|index|���������ַ���ֵ
	///
	AQUAENTRYFULL(void, StrVector, Remove)(LPVOID object, int index);

	///
	//	ִ�и÷����󽫻����|object|ָ���"String Vector"�ַ��������е������ַ���ֵ
	///
	AQUAENTRYFULL(void, StrVector, Clear)(LPVOID object);

	///
	//	��������߽�
	///
	AQUAENTRYFULL(int, StrVector, GetBound)(LPVOID object);

	///
	//	��ȡ��Ա����,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ���,|index|��0��ʼ��
	///
	AQUAENTRYFULL(int, StrVector, GetElementA)(LPVOID object, int index, LPSTR buffer, int length);

	///
	//	��ȡ��Ա����,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ���,|index|��0��ʼ��
	///
	AQUAENTRYFULL(int, StrVector, GetElementW)(LPVOID object, int index, LPWSTR buffer, int length);

	///
	//	�����ַ����������
	///
	AQUAENTRYFULL(void, StrVector, Destory)(LPVOID object);


	/******************************
	*			�ַ����ֵ�
	******************************/

	///
	//	ִ�и÷��������һ���µ��ֵ����
	///
	AQUAENTRYFULL(LPVOID, StrDict, Alloc)(void);

	///
	//	ִ�и÷���������һ������|object|���¸�������
	///
	AQUAENTRYFULL(LPVOID, StrDict, Copy)(LPVOID object);

	///
	//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
	///
	AQUAENTRYFULL(void, StrDict, InsertA)(LPVOID object,LPCSTR key,LPCSTR val);

	///
	//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
	///
	AQUAENTRYFULL(void, StrDict, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val);

	///
	//	���ֵ���Ѱ��|key|�������ļ�ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, FindA)(LPVOID object,LPCSTR key,LPSTR buf,int len);

	///
	//	���ֵ���Ѱ��|key|�������ļ�ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, FindW)(LPVOID object, LPCWSTR key, LPWSTR buf, int len);

	///
	//	�����ֵ�߽�
	///
	AQUAENTRYFULL(int, StrDict,GetBound)(LPVOID object);

	///
	//	ִ�и÷����������ֵ�����еĴ��׸���Ա��ʼ����ĵ�����ָ��,����ֵ�Ϊ�ս��᷵��NULL
	//	,ʹ������Ҫ��Erase�����ͷ�ָ�롣
	///
	AQUAENTRYFULL(LPVOID, StrDict, GetFirst)(LPVOID object);

	///
	//	ִ�и÷����Ὣ|iter|ָ����һ����Ա,�������β�����᷵��FALSE��
	///
	AQUAENTRYFULL(BOOL, StrDict, GetNext)(LPVOID object,LPVOID iter);

	///
	//	ִ�и÷���������|iter|ָ�롣
	///
	AQUAENTRYFULL(void, StrDict, Erase)(LPVOID iter);

	///
	//	��ȡ�������е�|key|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, GetKeyA)(LPVOID iter,LPSTR buf,int len);

	///
	//	��ȡ�������е�|key|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, GetKeyW)(LPVOID iter, LPWSTR buf, int len);

	///
	//	��ȡ�������е�|value|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, GetValueA)(LPVOID iter, LPSTR buf, int len);

	///
	//	���õ������е�|value|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, SetValueA)(LPVOID iter, LPCSTR value);

	///
	//	��ȡ�������е�|value|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDict, GetValueW)(LPVOID iter, LPSTR buf, int len);

	///
	//	ɾ��|key|�������ļ�ֵ����
	///
	AQUAENTRYFULL(void, StrDict,RemoveA)(LPVOID object,LPCSTR key);

	///
	//	ɾ��|key|�������ļ�ֵ����
	///
	AQUAENTRYFULL(void, StrDict, RemoveW)(LPVOID object, LPCWSTR key);

	///
	//	����ֵ��е����м�ֵ���ݡ�
	///
	AQUAENTRYFULL(void, StrDict, Clear)(LPVOID object);

	///
	//	��ȡ|key|�ֶ�ָ�������Ԫ������,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ��ȡ�
	///
	AQUAENTRYFULL(int, StrDict, AtA)(LPVOID object,LPCSTR key,LPSTR valBuffer,int valLength);

	///
	//	��ȡ|key|�ֶ�ָ�������Ԫ������,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ��ȡ�
	///
	AQUAENTRYFULL(int, StrDict, AtW)(LPVOID object, LPCSTR key, LPSTR valBuffer, int valLength);

	///
	//	�����ַ����ֵ����
	///
	AQUAENTRYFULL(void, StrDict, Destory)(LPVOID object);

	/******************************
	*		�����ַ����ֵ�
	******************************/

	///
	//	ִ�и÷��������һ���µ��ֵ����
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, Alloc)(void);

	///
	//	ִ�и÷���������һ������|object|���¸�������
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, Copy)(LPVOID object);

	///
	//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
	///
	AQUAENTRYFULL(void, StrDictEx, InsertA)(LPVOID object, LPCSTR key, LPCSTR val);

	///
	//	ִ�и÷���������һ�Լ�ֵ���ֵ��С�
	///
	AQUAENTRYFULL(void, StrDictEx, InsertW)(LPVOID object, LPCWSTR key, LPCWSTR val);

	///
	//	���ֵ���Ѱ��|key|�������ļ�ֵ����,�����ַ�����������
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, FindA)(LPVOID object, LPCSTR key,void **iter);

	///
	//	���ֵ���Ѱ��|key|�������ļ�ֵ����,�����ַ�����������
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, FindW)(LPVOID object, LPCWSTR key, void **iter);

	///
	//	�滻�������е�����
	///
	AQUAENTRYFULL(void, StrDictEx, ReplaceA)(LPVOID iter,LPCSTR val);

	///
	//	�滻�������е�����
	///
	AQUAENTRYFULL(void, StrDictEx, ReplaceW)(LPVOID iter, LPCWSTR val);

	///
	//	�����ֵ�߽�
	///
	AQUAENTRYFULL(int, StrDictEx, GetBound)(LPVOID object);

	///
	//	ִ�и÷����������ֵ�����еĴ��׸���Ա��ʼ����ĵ�����ָ��,����ֵ�Ϊ�ս��᷵��NULL
	//	,ʹ������Ҫ��Erase�����ͷ�ָ�롣
	///
	AQUAENTRYFULL(LPVOID, StrDictEx, GetFirst)(LPVOID object);

	///
	//	ִ�и÷����Ὣ|iter|ָ����һ����Ա,�������β�����᷵��FALSE��
	///
	AQUAENTRYFULL(BOOL, StrDictEx, GetNext)(LPVOID object, LPVOID iter);

	///
	//	ִ�и÷���������|iter|ָ�롣
	///
	AQUAENTRYFULL(void, StrDictEx, Erase)(LPVOID iter);

	///
	//	��ȡ�������е�|key|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDictEx, GetKeyA)(LPVOID iter, LPSTR buf, int len);

	///
	//	��ȡ�������е�|key|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDictEx, GetKeyW)(LPVOID iter, LPWSTR buf, int len);

	///
	//	��ȡ�������е�|value|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDictEx, GetValueA)(LPVOID iter, LPSTR buf, int len);

	///
	//	���õ������е�|value|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDictEx, SetValueA)(LPVOID iter, LPCSTR value);

	///
	//	��ȡ�������е�|value|��ֵ���ݡ�
	///
	AQUAENTRYFULL(int, StrDictEx, GetValueW)(LPVOID iter, LPSTR buf, int len);

	///
	//	ɾ��|key|�������ļ�ֵ����
	///
	AQUAENTRYFULL(void, StrDictEx, RemoveA)(LPVOID object, LPCSTR key);

	///
	//	ɾ��|key|�������ļ�ֵ����
	///
	AQUAENTRYFULL(void, StrDictEx, RemoveW)(LPVOID object, LPCWSTR key);

	///
	//	����ֵ��е����м�ֵ���ݡ�
	///
	AQUAENTRYFULL(void, StrDictEx, Clear)(LPVOID object);

	///
	//	�����ַ����ֵ����
	///
	AQUAENTRYFULL(void, StrDictEx, Destory)(LPVOID object);


	/******************************
	*			Int64����
	******************************/

	///
	//	ִ�и÷����󽫻���һ��"String Vector"�ַ�����������,
	//	��η������������Կ���"StrVector"�������ṩ�ķ������ϡ�
	///
	AQUAENTRYFULL(LPVOID, Int64Vector, Alloc)(void);

	///
	//	ִ�и÷����󽫻���һ����|object|�����п������¸�������,
	//	���|object|���Ϸ�������һ��NULL
	///
	AQUAENTRYFULL(LPVOID, Int64Vector, Copy)(LPVOID object);

	///
	//	ִ�и÷�����|object|ָ���"String Vector"�ַ���������
	//	׷���ַ���|text|
	///
	AQUAENTRYFULL(void, Int64Vector, Append)(LPVOID object, __int64 value);

	///
	//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
	//	���������ַ���ֵ
	///
	AQUAENTRYFULL(void, Int64Vector, Replace)(LPVOID object, int index, __int64 value);

	///
	//	ִ�и÷��������Ƴ�|object|ָ���"String Vector"�ַ���������|index|���������ַ���ֵ
	///
	AQUAENTRYFULL(void, Int64Vector, Remove)(LPVOID object, int index);

	///
	//	ִ�и÷����󽫻����|object|ָ���"String Vector"�ַ��������е������ַ���ֵ
	///
	AQUAENTRYFULL(void, Int64Vector, Clear)(LPVOID object);

	///
	//	��������߽�
	///
	AQUAENTRYFULL(int, Int64Vector, GetBound)(LPVOID object);

	///
	//	���������Ա����,|index|��0��ʼ��
	///
	AQUAENTRYFULL(__int64, Int64Vector, GetElement)(LPVOID object,int index);

	///
	//	����Int64�������
	///
	AQUAENTRYFULL(void, Int64Vector, Destory)(LPVOID object);
}


#endif