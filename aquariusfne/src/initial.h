#ifndef INITIAL_H_
#define INITIAL_H_
#include "lib2.h"

#ifndef __E_STATIC_LIB

static LIB_DATA_TYPE_ELEMENT s_dtInitialElemnet[]={
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����·��"),
        /*m_szEgName*/          _T("cachePath"),
        /*m_szExplain*/         _T("ָ����Ż��������ڴ����ϵĴ洢λ�á����Ϊ�յĻ��������ʹ�����û���(\"����ģʽ\"),"
									"���Ҳ�������ݱ��浽�����ϡ�HTML5 database �Լ� localStorage ��Щ����ֻ����"
									"����·�����ڵ�����³���������ָ���Ự�С�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�û�����·��"),
        /*m_szEgName*/          _T("userdata"),
        /*m_szExplain*/         _T("ָ���û�ƴд����ֵ��ļ����û������ڴ����ϵĴ洢λ�á����Ϊ��,��ʹ��(Windows�ϵ�\""
										"Local Settings\\Application Data\\CEF\\User Data\")�����ļ�Ŀ¼��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
		{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������Ⱦģʽ"),
        /*m_szEgName*/          _T("windowslessRendering"),
        /*m_szExplain*/         _T("����Ϊ��,�������޴���(����)��Ⱦ֧�֡����Ӧ�ó���ʹ���޴�����Ⱦ�����ô�ֵ���ܻή��ĳЩϵͳ����Ⱦ���ܡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ֻỰ"),
        /*m_szEgName*/          _T("persistsessioncookies"),
        /*m_szExplain*/         _T("���ֻỰcookie(û�е��ڻ���Ч��cookie���)Ĭ�������ʹ��ȫ��cookie������,����ֵ����Ϊ�档"
									"ͨ������»Ựcookie����ʱ��,���Ҵ󲿷ֵ�web�����������������ǡ���|����·��|��Ҳ������ָ������"
									"�˹��ܡ�Ҳ����ʹ��\"persist-session-cokies\"�����п��ؽ������á�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�����û���ѡ��"),
        /*m_szEgName*/          _T("persistUserPreferences"),
        /*m_szExplain*/         _T("�������ΪTRUE,���û���ѡ���Ϊ����·��Ŀ�м��е�JSON�ļ�,��ʹ������|����·��|Ҳ����"
									"��ָ�����ô˹��ܡ�Ҳ����ʹ��\"persist-user-preferences\"�����п���,�������á�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�û������ʶ��"),
        /*m_szEgName*/          _T("userAgent"),
        /*m_szExplain*/         _T("����ΪUser-Agent HTTP��ͷ�ķ��ص�ֵ���������Ϊ�ս�ʹ��Ĭ�ϵ�User-Agent�ַ���"
									"Ҳ����ʹ��\"user-agent\"�����п���,�������á�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��Ʒ��ʶ��"),
        /*m_szEgName*/          _T("productVersion"),
        /*m_szExplain*/         _T("����ΪĬ�ϲ�Ʒ���ֲ���User-Agent��ֵ�����Ϊ��,��ʹ��Chromium��Ʒ�汾��"
									"���|�û������ʶ��|��ָ�����ֵ�������ԡ�Ҳ��ʹ��\"product-version\"�����п��ؽ������á�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ػ�����"),
        /*m_szEgName*/          _T("locale"),
        /*m_szExplain*/         _T("�����ݸ�WebKit�����Ի����ַ��������Ϊ��,��ʹ��\"en-US\"�����Ի���,"
									"Ҳ��ʹ��\"lang\"�����п��ؽ������á�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("Զ�̵��Զ˿�"),
        /*m_szEgName*/          _T("remoteDebuggingPort"),
        /*m_szExplain*/         _T("����Ϊ1024��65535ֱ�ӵ�ֵ������Զ�̵��Է���,����: ���8080��ָ��ΪԶ�̵��Զ˿�"
									"����URL http://localhost:8080��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����SSL֤�����"),
        /*m_szEgName*/          _T("ignoreCertificateErrors"),
        /*m_szExplain*/         _T("����Ϊ�������SSL֤����صĴ���,���ô����ÿ��ܻᵼ��Ǳ�ڵİ�ȫ©��,��\"�м���\"����"
									",�ӻ������������ݵ�Ӧ�ó���Ӧ���ô�����,Ҳ����ʹ��\"ignore-certificate-errors\"�����п��ؽ������á�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("AcceptLanguage"),
        /*m_szEgName*/          _T("acceptLanguageList"),
        /*m_szExplain*/         _T("�ö��ŷָ������Դ����б�,û���κν���\"Accept-Language\"HTTP��ͷ��ʹ�õĿո�Ĭ��Ϊ\"en-US,en\""),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_TEXT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ӽ���·��"),
        /*m_szEgName*/          _T("SubProcessPath"),
        /*m_szExplain*/         _T("������ӽ��̳���·����Ĭ��Ϊ\".\\Pepper.exe\""),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������ģʽ"),
        /*m_szEgName*/          _T("SingleProcess"),
        /*m_szExplain*/         _T("����������Ƿ�Ϊ������ģʽ"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���߳���Ϣѭ��"),
        /*m_szEgName*/          _T("MultiThreadedMessageLoop"),
        /*m_szExplain*/         _T("����������Ƿ�Ϊ�������Ϣѭ��ģʽ"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_BOOL,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ø�DPIģʽ֧��"),
        /*m_szEgName*/          _T("HighDPISupport"),
        /*m_szExplain*/         _T("����������Ƿ�Ϊ��DPIģʽ"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
};

#endif

#endif