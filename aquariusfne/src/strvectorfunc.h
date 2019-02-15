#ifndef STRVECTORFUNC_H_
#define STRVECTORFUNC_H_

#include "lib2.h"
#include <windows.h>
#include "wapper.h"


///
//	StrVector ���캯��
///
extern "C"
void aquarius_strvector_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrVectorAlloc();
}

///
//	StrVector ���ƹ��캯��
///
extern "C"
void aquarius_strvector_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = AquaStrVectorCopy(*pArgInf[1].m_ppCompoundData);
}

///
//	StrVector ��������
///
extern "C"
void aquarius_strvector_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorDestory(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

///
//	ִ�и÷�����|object|ָ���"String Vector"�ַ�������/���������
//	׷���ַ���|text|
///
extern "C"
void aquarius_strvector_append (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorAppendA(*pArgInf->m_ppCompoundData,pArgInf[1].m_pText);
}

///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
//	���������ַ���ֵ
///
extern "C"
void aquarius_strvector_replace(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorReplaceA(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,pArgInf[2].m_pText);
}

///
//	ִ�и÷�������|text|�滻|object|ָ���"String Vector"�ַ���������|index|
//	���������ַ���ֵ
///
extern "C"
void aquarius_strvector_remove(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorRemove(*pArgInf->m_ppCompoundData,pArgInf[1].m_int);
}

///
//	ִ�и÷����󽫻����|object|ָ���"String Vector"�ַ��������е������ַ���ֵ
///
extern "C"
void aquarius_strvector_clear(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaStrVectorClear(*pArgInf->m_ppCompoundData);
}

///
//	��������߽�
///
extern "C"
void aquarius_strvector_get_bound(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaStrVectorGetBound(*pArgInf->m_ppCompoundData);
}

///
//	��ȡ��Ա����,���|length|Ϊ0,�򲻻Ὣ��Ա������䵽|buffer|��,�����س�Ա���ݳ���,|index|��0��ʼ��
///
extern "C"
void aquarius_strvector_get_element(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaStrVectorGetElementA(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaStrVectorGetElementA(*pArgInf->m_ppCompoundData,pArgInf[1].m_int,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
}

#endif