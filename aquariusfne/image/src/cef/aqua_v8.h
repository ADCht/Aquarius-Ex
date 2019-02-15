#ifndef V8_H_
#define V8_H_

#include "utils\aqua_utils.h"
#include <string>

namespace AquaCef {
	struct V8VALUESTRUCT {
		int type;
		int index;
		BOOL v1;
		int v2;
		double v3;
		LPSTR v4;
		void(CALLBACK *free)(V8VALUESTRUCT *p);
	};

	///
	//	����һ���µ�|V8Value|����
	///
	AQUAENTRYFULL(LPVOID, V8Value, Alloc)(void);

	///
	//	��|object|�Ͽ���һ���µ�|V8Value|����
	///
	AQUAENTRYFULL(LPVOID, V8Value, Copy)(LPVOID object);

	///
	//	����|object|����
	///
	AQUAENTRYFULL(void, V8Value, Destory)(LPVOID object);

	///
	//	��ȡ|index|��ָ��|object|�����е����ݳ�Ա���͡�
	///
	AQUAENTRYFULL(int, V8Value, GetType)(LPVOID object,int index);

	///
	//	��ȡ|object|������|index|��ֵ
	///
	AQUAENTRYFULL(LPVOID, V8Value, GetValue)(LPVOID object, int index);

	///
	//	����|object|������|index|��ֵ
	///
	AQUAENTRYFULL(void, V8Value, SetValue)(LPVOID object,LPVOID value);

	///
	//	����JS����
	///
	AQUAENTRYFULL(LPVOID, V8Spec, CreateAccessor)(LPCSTR mainName);

	///
	//	ע��JS����
	///
	AQUAENTRYFULL(BOOL, V8Spec, RegisterVar)(LPVOID object, LPCSTR childName);

	///
	//	ע��JS����
	///
	AQUAENTRYFULL(BOOL, V8Spec, RegisterFunction)(LPVOID object, LPCSTR functionName);
}

#endif