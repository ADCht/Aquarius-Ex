#ifndef JSDIALOG_H_
#define JSDIALOG_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtJsDialogCallbackElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ڲ�ָ��"),
        /*m_szEgName*/          _T("InternalPointer"),
        /*m_szExplain*/         _T("��Ŷ����ָ��"),
        /*m_dwState*/           LES_HIDED,
        /*m_nDefault*/          0
    }
};

INT s_nJsDialogCallbackCmdIndex[]={
	243,244,245,246,247
};

#endif
#endif