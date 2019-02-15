#ifndef COOKIE_H_
#define COOKIE_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtCookieManagerElemnet[]={
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

INT s_nCookieManagerCmdIndex[]={
	161,162,163,164,165,166,167,168,169,170,171,172
};

static LIB_DATA_TYPE_ELEMENT s_dtCookieElemnet[]={
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����"),
        /*m_szEgName*/          _T("name"),
        /*m_szExplain*/         _T("The cookie name."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ֵ"),
        /*m_szEgName*/          _T("value"),
        /*m_szExplain*/         _T("The cookie value."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("domain"),
        /*m_szExplain*/         _T("���| domain | �ǿյ�����cookie����������������cookie��"
								 "cookie��ǰ׺\".\"�洢��һ�� ������ɼ���������cookie���ɼ���"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��ȫ���"),
        /*m_szEgName*/          _T("secure"),
        /*m_szExplain*/         _T("���| secure | Ϊ�棬cookie��ֻ���͸�HTTPS����"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�����ڴ����"),
        /*m_szEgName*/          _T("httponly"),
        /*m_szExplain*/         _T("���| httponly |Ϊ��,���cookieֻ�ᱻ��������HTTP����"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�Ƿ����"),
        /*m_szEgName*/          _T("has_expires"),
        /*m_szExplain*/         _T("cookie�������ڽ���|has_expires|Ϊ��ʱ��Ч��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            MAKELONG(18,0),
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����ʱ��"),
        /*m_szEgName*/          _T("expires"),
        /*m_szExplain*/         _T("cookie�������ڡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtTimeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("year"),
        /*m_szExplain*/         _T("��λ�����\"2007\""),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("month"),
        /*m_szExplain*/         _T("����1���·ݣ�ֵ1 = 1�·ݵȣ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����"),
        /*m_szEgName*/          _T("day_of_week"),
        /*m_szExplain*/         _T("����0�����ڼ���0 =������ȣ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("day_of_month"),
        /*m_szExplain*/         _T("ÿ��1�գ�1-31��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ʱ"),
        /*m_szEgName*/          _T("hour"),
        /*m_szExplain*/         _T("�����Сʱ��0-23��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("minute"),
        /*m_szExplain*/         _T("��ǰСʱ�ڵķ�������0-59��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("second"),
        /*m_szExplain*/         _T("��ǰ�����ڵ�������0-59�����룬���ɴ�60�룩��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����"),
        /*m_szEgName*/          _T("millisecond"),
        /*m_szExplain*/         _T("��ǰ���ڵĺ�������0-999��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
};


#endif

#endif