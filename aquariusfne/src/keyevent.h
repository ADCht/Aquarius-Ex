#ifndef KEYEVENT_H_
#define KEYEVENT_H_
#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtKeyEventElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����"),
        /*m_szEgName*/          _T("type"),
        /*m_szExplain*/         _T("�����¼�������,�ο���������: #KEYEVENT.xxx"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��־λ"),
        /*m_szEgName*/          _T("modifiers"),
        /*m_szExplain*/         _T("�����κΰ��µ��޸ļ���λ��־�� �й�ֵ������ĳ�������: #EVENTFLAG.xxx ��"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������"),
        /*m_szEgName*/          _T("windows_key_code"),
        /*m_szExplain*/         _T("���¼���Windows�����롣DOM�淶ʹ�ô�ֵ����ʱ��ֱ�������¼�������Windows�ϣ�����ʱ����ʹ��ӳ�亯��ȷ��"
									"�ġ��й�ֵ�б�,�����WebCore/platform/chromium/KeyboardCodes.h"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ʵ�ʼ�����"),
        /*m_szEgName*/          _T("native_key_code"),
        /*m_szExplain*/         _T("��ƽ̨���ɵ�ʵ�ʼ����롣"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�Ƿ�Ϊϵͳ��"),
        /*m_szEgName*/          _T("is_system_key"),
        /*m_szExplain*/         _T("ָʾ�¼��Ƿ���Ϊ��ϵͳ�����¼��й���ϸ��Ϣ�������http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx����"
									"��ֵ�ڷǷ���Զ��false -Windowsƽ̨��"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ַ���"),
        /*m_szEgName*/          _T("character"),
        /*m_szExplain*/         _T("�����������ַ���"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ԭʼ�ַ���"),
        /*m_szEgName*/          _T("unmodified_character"),
        /*m_szExplain*/         _T("��|character|��ͬ �����ᱻ�κβ������ֵ����η��޸ģ�����shift���� ����ڼ����ݼ������á�"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�Ƿ�λ�ڽ���Ԫ��"),
        /*m_szEgName*/          _T("focus_on_editable_field"),
        /*m_szExplain*/         _T("������㵱ǰλ��ҳ���ϵĿɱ༭�ֶΣ���ΪTrue�� �����ȷ���Ƿ�Ӧ��ȡ��׼���¼������á�"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtMouseElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("x"),
        /*m_szEgName*/          _T("x"),
        /*m_szExplain*/         _T("�������ͼ����X���ꡣ"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("y"),
        /*m_szEgName*/          _T("y"),
        /*m_szExplain*/         _T("�������ͼ����Y���ꡣ"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��־λ"),
        /*m_szEgName*/          _T("modifiers"),
        /*m_szExplain*/         _T("�����κΰ��µ��޸ļ���λ��־�� �й�ֵ������ĳ�������: #EVENTFLAG.xxx ��"),
		/*m_dwState*/           NULL,
		/*m_nDefault*/          0
    },
};

#endif

#endif