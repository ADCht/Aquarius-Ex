#ifndef INT64VECTORFUNC_H_
#define INT64VECTORFUNC_H_
#include "wapper.h"

#include "lib2.h"


extern "C"
void aquarius_int64vector_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaInt64VectorAlloc();
}

extern "C"
void aquarius_int64vector_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaInt64VectorCopy(*pArgInf[1].m_ppCompoundData);
}

extern "C"
void aquarius_int64vector_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_int64vector_append (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorAppend(*pArgInf->m_ppCompoundData,pArgInf[1].m_int64);
}


///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
//	���������ַ���ֵ
///
extern "C"
void aquarius_int64vector_replace(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorReplace(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,pArgInf[2].m_int64);
}

///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
//	���������ַ���ֵ
///
extern "C"
void aquarius_int64vector_remove(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorRemove(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
}

///
//	ִ�и÷����󽫻����|object|ָ���"String Vector"�ַ��������е������ַ���ֵ
///
extern "C"
void aquarius_int64vector_clear(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaInt64VectorClear(*pArgInf->m_ppCompoundData);
}

///
//	��������߽�
///
extern "C"
void aquarius_int64vector_get_bound(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaInt64VectorGetBound(*pArgInf->m_ppCompoundData);
}

///
//	��ȡ��Ա����,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ���,|index|��0��ʼ��
///
extern "C"
void aquarius_int64vector_get_element(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int64 = AquaInt64VectorGetElement(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
}

#endif