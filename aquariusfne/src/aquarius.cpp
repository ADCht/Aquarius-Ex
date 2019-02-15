#include "StdAfx.h"
#include <windows.h>
#include "lib2.h"
#include "lang.h"
#include "datatype.h"
#include "cmdinfo.h"
#include "func.h"


/////////////////////////////////////////////////////////////////////////////

INT g_nLastNotifyResult;
PFN_NOTIFY_SYS g_fnAquaNotifySys = NULL;

INT WINAPI AquaNotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	if (g_fnAquaNotifySys != NULL)
		return g_nLastNotifyResult = g_fnAquaNotifySys (nMsg, dwParam1, dwParam2);
	else
		return g_nLastNotifyResult = 0;
}

/////////////////////////////////////////////////////////////////////////////

INT WINAPI ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	INT nRet = NR_OK;
	switch (nMsg)
	{
	case NL_SYS_NOTIFY_FUNCTION:
		g_fnAquaNotifySys = (PFN_NOTIFY_SYS)dwParam1;
		break;
	default:
		nRet = NR_ERR;
		break;
	}

	return nRet;
}

EXTERN_C INT WINAPI aquarius_ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if(nMsg == NL_GET_CMD_FUNC_NAMES)
		return (INT) g_CmdNames;
	else if(nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME)
		return (INT) "aquarius_ProcessNotifyLib";
	else if(nMsg == NL_GET_DEPENDENT_LIBS)
		return NULL;
#endif
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}

#ifndef __E_STATIC_LIB
/////////////////////////////////////////////////////////////////////////////

//////////// �ⶨ�忪ʼ
static LIB_INFO s_LibInfo =
{
/*Lib Format Ver*/		LIB_FORMAT_VER,		// ����δ�á�

// ��֧�ֿ��GUID����
// guid: {5014D8FA-6DCA-40b6-8FA6-26D8183666EB}
#define		LI_LIB_GUID_STR	"7153EF3B37294f4993DDCE8EB90617FD"
/*guid str*/			_T (LI_LIB_GUID_STR),

/*m_nMajorVersion*/		1,
/*m_nMinorVersion*/		0,

//!!!	ע�⣺������ɾ��������������������������͡�������Ϣ�ȣ�ֻҪ�԰���
//!!! �ļ����ɻ����Ӱ�죬�����������汾�ţ�������ֻ�޸�BuildNumber��
//!!!   �Ķ����������汾��!!!
/*m_nBuildNumber*/		51,	// 1: 2.5;  2: 2.5���Ű�; 3: 3.0��;  50: 3.39; 51: 4.11
		// �����汾�ţ�����Դ˰汾�����κδ���
		//   ���汾�Ž�����������ͬ��ʽ�汾�ŵĿ⣨Ʃ������޸��˼��� BUG����
		// �κι��������û�ʹ�õİ汾��˰汾�Ŷ�Ӧ�ò�һ����
		//   ��ֵʱӦ��˳�������

/*m_nRqSysMajorVer*/		3,
/*m_nRqSysMinorVer*/		0,
/*m_nRqSysKrnlLibMajorVer*/	3,
/*m_nRqSysKrnlLibMinorVer*/	0,

/*name*/				_T ("ˮ�������֧�ֿ�"),
/*lang*/				__GBK_LANG_VER,
/*explain*/				_WT("��֧�ֿ�ʵ���˶�ˮ�������(Aquariuscef)��ܵ�֧��"),
/*dwState*/				NULL,

/*szAuthor*/	_WT("��è"),
/*szZipCode*/	_WT("518108"),
/*szAddress*/	_WT("�㶫ʡ������"),
/*szPhoto*/		_WT("00000000000"),
/*szFax*/		_WT("00000000000"),
/*szEmail*/		_WT("kirino17@hotmail.com"),
/*szHomePage*/	_WT("http://www.ps-works.cc"),
/*szOther*/		_WT("ף��һ����˳�������³ɣ�"),

/*type count*/			sizeof (s_DataType) / sizeof (s_DataType[0]),
/*PLIB_DATA_TYPE_INFO*/	s_DataType,

/*CategoryCount*/ 1,	// ���������Ӵ�ֵ��
/*category*/_WT("0000������\0"	// ���˵����ÿ��Ϊһ�ַ���,ǰ��λ���ֱ�ʾͼ��������(��1��ʼ,0��).
				"0000xxxx\0"
				"\0"),
/*CmdCount*/				sizeof (s_CmdInfo) / sizeof (s_CmdInfo [0]),
/*BeginCmd*/				s_CmdInfo,
/*m_pCmdsFunc*/             s_RunFunc,
/*pfnRunAddInFn*/			NULL,
/*szzAddInFnInfo*/			NULL,

/*pfnNotify*/				aquarius_ProcessNotifyLib,

/*pfnRunSuperTemplate*/		NULL,
/*szzSuperTemplateInfo*/	NULL,

/*nLibConstCount*/			0,//sizeof (s_ConstInfo) / sizeof (s_ConstInfo [0]),
/*pLibConst*/				NULL,//s_ConstInfo,

/*szzDependFiles*/			NULL,
};

PLIB_INFO WINAPI GetNewInf ()
{
	return &s_LibInfo;
}

#endif
