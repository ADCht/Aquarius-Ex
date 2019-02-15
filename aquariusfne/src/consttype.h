#ifndef CONSTTYPE_H_
#define CONSTTYPE_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

///////////////////////////////////

//*** ����������Ϣ:

// !!! ע�ⳣ��ֵ�����Ѿ����õ������У����Ծ��Բ��ܸĶ���
// ˳��ֵ���ܸĶ�

// LIB_CONST_INFO s_ConstInfo [] =
// {
// 	{	_WT("ȡԴ��"),		_WT("ˮ���첽"),	NULL,	LVL_SIMPLE,	CT_NUM,	NULL,	0,	},
// 	{	_WT("ȡ�ı�"),		_WT("ˮ���첽"),	NULL,	LVL_SIMPLE,	CT_NUM,	NULL,	1,	},
// 	{	_WT("ִ�б��ʽ"),	_WT("ˮ���첽"),	NULL,	LVL_SIMPLE,	CT_NUM,	NULL,	2,	},
// 
// };

static LIB_DATA_TYPE_ELEMENT s_dtAquaAsyncElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ȡԴ��"),
        /*m_szEgName*/          _T("GetSource"),
        /*m_szExplain*/         _T("��ȡ����е�HTMLԴ����"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ȡ�ı�"),
        /*m_szEgName*/          _T("GetSource"),
        /*m_szExplain*/         _T("��ȡ����е�HTML�ı�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ִ�б��ʽ"),
        /*m_szEgName*/          _T("Eval"),
        /*m_szExplain*/         _T("�ڿ����ִ�б��ʽ��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaWodElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("δ֪��"),
        /*m_szEgName*/          _T("WOD_UNKNOWN"),
        /*m_szExplain*/         _T("WOD_UNKNOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ڵ�ǰ��ǩ���ڴ�"),
        /*m_szEgName*/          _T("WOD_CURRENT_TAB"),
        /*m_szExplain*/         _T("WOD_CURRENT_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���µı�ǩ���ڴ�"),
        /*m_szEgName*/          _T("WOD_SINGLETON_TAB"),
        /*m_szExplain*/         _T("WOD_SINGLETON_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��ǰһ����ǩ���ڴ�"),
        /*m_szEgName*/          _T("WOD_NEW_FOREGROUND_TAB"),
        /*m_szExplain*/         _T("WOD_NEW_FOREGROUND_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ں�һ����ǩ���ڴ�"),
        /*m_szEgName*/          _T("WOD_NEW_BACKGROUND_TAB"),
        /*m_szExplain*/         _T("WOD_NEW_BACKGROUND_TAB"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          4
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���µĶԻ��򴰿ڴ�"),
        /*m_szEgName*/          _T("WOD_NEW_POPUP"),
        /*m_szExplain*/         _T("WOD_NEW_POPUP"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          5
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���µĶ��㴰�ڴ�"),
        /*m_szEgName*/          _T("WOD_NEW_WINDOW"),
        /*m_szExplain*/         _T("WOD_NEW_WINDOW"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          6
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���浽����"),
        /*m_szEgName*/          _T("WOD_SAVE_TO_DISK"),
        /*m_szExplain*/         _T("WOD_SAVE_TO_DISK"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          7
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�رռ�¼"),
        /*m_szEgName*/          _T("WOD_OFF_THE_RECORD"),
        /*m_szExplain*/         _T("WOD_OFF_THE_RECORD"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          8
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���Զ���"),
        /*m_szEgName*/          _T("WOD_IGNORE_ACTION"),
        /*m_szExplain*/         _T("WOD_IGNORE_ACTION"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          9
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaURLRequestFlagsElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("Ĭ������"),
        /*m_szEgName*/          _T("UR_FLAG_NONE"),
        /*m_szExplain*/         _T("Ĭ����Ϊ��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��������"),
        /*m_szEgName*/          _T("UR_FLAG_SKIP_CACHE"),
        /*m_szExplain*/         _T("������ã����ڴ�������ʱ���������档"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����������Ϣ"),
        /*m_szEgName*/          _T("UR_FLAG_ALLOW_CACHED_CREDENTIALS"),
        /*m_szExplain*/         _T("��������û����������cookie����������һ���ͣ�����Դ���Ӧ�б���cookie��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�����ϴ��¼����Ȼص�"),
        /*m_szEgName*/          _T("UR_FLAG_REPORT_UPLOAD_PROGRESS"),
        /*m_szExplain*/         _T("��������ϴ������¼����������������ʱ���ɡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ر����ػص�"),
        /*m_szEgName*/          _T("UR_FLAG_NO_DOWNLOAD_DATA"),
        /*m_szExplain*/         _T("������ã��򲻻����CefURLRequestClient :: OnDownloadData������"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 6
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����5XX����"),
        /*m_szEgName*/          _T("UR_FLAG_NO_RETRY_ON_5XX"),
        /*m_szExplain*/         _T("�������5XX�ض�����󽫴������۲��߶������Զ����³��ԡ� �⵱ǰ��������Դ����������̵�����"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 7
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaPostTypeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ֶ�"),
        /*m_szEgName*/          _T("PDE_TYPE_EMPTY"),
        /*m_szExplain*/         _T("��ֵ��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ֽڼ��ֶ�"),
        /*m_szEgName*/          _T("PDE_TYPE_BYTES"),
        /*m_szExplain*/         _T("�ֽڼ�ֵ��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ļ��ֶ�"),
        /*m_szEgName*/          _T("PDE_TYPE_FILE"),
        /*m_szExplain*/         _T("�ļ�ֵ��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaUrlRequestStatusElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("δ֪״̬"),
        /*m_szEgName*/          _T("UR_UNKNOWN"),
        /*m_szExplain*/         _T("δ֪״̬��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���سɹ�"),
        /*m_szEgName*/          _T("UR_SUCCESS"),
        /*m_szExplain*/         _T("���سɹ�!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ڼ�����"),
        /*m_szEgName*/          _T("UR_IO_PENDING"),
        /*m_szExplain*/         _T("��Դ���ڼ�����!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ѱ�ȡ��"),
        /*m_szEgName*/          _T("UR_CANCELED"),
        /*m_szExplain*/         _T("�ѱ�ȡ��!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����ʧ��"),
        /*m_szEgName*/          _T("UR_FAILED"),
        /*m_szExplain*/         _T("����ĳ��ԭ������ʧ��!"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          4
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaResourceTypeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�������Դ"),
        /*m_szEgName*/          _T("RT_MAIN_FRAME"),
        /*m_szExplain*/         _T("Top level page."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ӿ����Դ"),
        /*m_szEgName*/          _T("RT_SUB_FRAME"),
        /*m_szExplain*/         _T("Frame or iframe."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�����ʽ����Դ"),
        /*m_szEgName*/          _T("RT_STYLESHEET"),
        /*m_szExplain*/         _T("CSS stylesheet."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ű���Դ"),
        /*m_szEgName*/          _T("RT_SCRIPT"),
        /*m_szExplain*/         _T("External script."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ͼ����Դ"),
        /*m_szEgName*/          _T("RT_IMAGE"),
        /*m_szExplain*/         _T("Image (jpg/gif/png/etc)."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          4
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������Դ"),
        /*m_szEgName*/          _T("RT_FONT_RESOURCE"),
        /*m_szExplain*/         _T("Font."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          5
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������Դ"),
        /*m_szEgName*/          _T("RT_SUB_RESOURCE"),
        /*m_szExplain*/         _T("Some other subresource. This is the default type if the actual type is unknown."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          6
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�����Դ"),
        /*m_szEgName*/          _T("RT_OBJECT"),
        /*m_szExplain*/         _T("Object (or embed) tag for a plugin, or a resource that a plugin requested."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          7
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��ý����Դ"),
        /*m_szEgName*/          _T("RT_MEDIA"),
        /*m_szExplain*/         _T("Media resource."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          8
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��Ҫ������Դ"),
        /*m_szEgName*/          _T("RT_WORKER"),
        /*m_szExplain*/         _T("Main resource of a dedicated worker.."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          9
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��������Դ"),
        /*m_szEgName*/          _T("RT_SHARED_WORKER"),
        /*m_szExplain*/         _T("Main resource of a shared worker."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          10
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("Ԥ������Դ"),
        /*m_szEgName*/          _T("RT_PREFETCH"),
        /*m_szExplain*/         _T("Explicitly requested prefetch."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          11
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("FAVICON��Դ"),
        /*m_szEgName*/          _T("RT_FAVICON"),
        /*m_szExplain*/         _T("Favicon."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          12
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("XHR��Դ"),
        /*m_szEgName*/          _T("RT_XHR"),
        /*m_szExplain*/         _T("XMLHttpRequest."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          13
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("PING��Դ"),
        /*m_szEgName*/          _T("RT_PING"),
        /*m_szExplain*/         _T("A request for a <ping>."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          14
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��������Դ"),
        /*m_szEgName*/          _T("RT_SERVICE_WORKER"),
        /*m_szExplain*/         _T("Main resource of a service worker."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          15
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CSP��Դ"),
        /*m_szEgName*/          _T("RT_CSP_REPORT"),
        /*m_szExplain*/         _T("A report of Content Security Policy violations."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          16
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���������Դ"),
        /*m_szEgName*/          _T("RT_PLUGIN_RESOURCE"),
        /*m_szExplain*/         _T("A resource that a plugin requested."),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          17
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaKeyEventTypeElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ԭʼ������"),
        /*m_szEgName*/          _T("RAWKEYDOWN"),
        /*m_szExplain*/         _T("֪ͨ����\"����\"ת��Ϊ\"����\"��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������"),
        /*m_szEgName*/          _T("KEYDOWN"),
        /*m_szExplain*/         _T("���°�����֪ͨ�� �ⲻһ����Ӧȡ���ڼ������Ե��ַ��� ʹ��KEYEVENT_CHAR�ַ����롣"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������"),
        /*m_szEgName*/          _T("KEYUP"),
        /*m_szExplain*/         _T("֪ͨ�������ͷš�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�ַ�����"),
        /*m_szEgName*/          _T("CHAR"),
        /*m_szExplain*/         _T("�����ַ���֪ͨ�� �����ı����롣 ��down�¼����ܻ����0,1�����ַ��¼�����Կ���������úͲ���ϵͳ�ϡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaMouseButtonElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("������"),
        /*m_szEgName*/          _T("MBT_LEFT"),
        /*m_szExplain*/         _T("������"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����м�"),
        /*m_szEgName*/          _T("MBT_MIDDLE"),
        /*m_szExplain*/         _T("����м�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����Ҽ�"),
        /*m_szEgName*/          _T("MBT_RIGHT"),
        /*m_szExplain*/         _T("����Ҽ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaJsDialogElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ALERT"),
        /*m_szEgName*/          _T("ALERT"),
        /*m_szExplain*/         _T("ALERT"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CONFIRM"),
        /*m_szEgName*/          _T("CONFIRM"),
        /*m_szExplain*/         _T("CONFIRM"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("PROMPT"),
        /*m_szEgName*/          _T("PROMPT"),
        /*m_szExplain*/         _T("PROMPT"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
};

static LIB_DATA_TYPE_ELEMENT s_dtAquaFileDialogCallbackElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ļ�"),
        /*m_szEgName*/          _T("FILE_DIALOG_OPEN"),
        /*m_szExplain*/         _T("�������û�ѡ���ļ�֮ǰ��Ҫ���ļ����ڡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ļ��ɶ�ѡ"),
        /*m_szEgName*/          _T("FILE_DIALOG_OPEN_MULTIPLE"),
        /*m_szExplain*/         _T("��Openһ����������ѡ��򿪶���ļ���"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("���ļ���"),
        /*m_szEgName*/          _T("FILE_DIALOG_OPEN_FOLDER"),
        /*m_szExplain*/         _T("��Openһ������ѡ��Ҫ�򿪵��ļ��С�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�����ļ�"),
        /*m_szEgName*/          _T("FILE_DIALOG_SAVE"),
        /*m_szExplain*/         _T("����ѡ�񲻴��ڵ��ļ�������ʾ�����ļ��Ƿ��Ѵ��ڡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�Ի������ͱ�־λ"),
        /*m_szEgName*/          _T("FILE_DIALOG_TYPE_MASK"),
        /*m_szExplain*/         _T("������������ֵ��λ��ͨ�����롣"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0xFF
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�Ƿ���Ҫ������ʾ"),
        /*m_szEgName*/          _T("FILE_DIALOG_OVERWRITEPROMPT_FLAG"),
        /*m_szExplain*/         _T("����û�ʹ�á����桱�Ի���ѡ�������ļ�������ʾ���ǡ�"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0x01000000
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����ʾֻ���ļ�"),
        /*m_szEgName*/          _T("FILE_DIALOG_HIDEREADONLY_FLAG"),
        /*m_szExplain*/         _T("����ʾֻ���ļ���"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0x02000000
    },

};

static LIB_DATA_TYPE_ELEMENT s_dtAquaEventFlagsElemnet[]={
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("��"),
        /*m_szEgName*/          _T("NONE"),
        /*m_szExplain*/         _T("NONE��"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CAPS_LOCK���Ѱ���"),
        /*m_szEgName*/          _T("CAPS_LOCK_ON"),
        /*m_szExplain*/         _T("CAPS_LOCK_ON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 0
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("SHIFT���Ѱ���"),
        /*m_szEgName*/          _T("SHIFT_DOWN"),
        /*m_szExplain*/         _T("SHIFT_DOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 1
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("CTRL���Ѱ���"),
        /*m_szEgName*/          _T("CONTROL_DOWN"),
        /*m_szExplain*/         _T("CONTROL_DOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 2
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("ALT���Ѱ���"),
        /*m_szEgName*/          _T("ALT_DOWN"),
        /*m_szExplain*/         _T("ALT_DOWN"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 3
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("�������Ѱ���"),
        /*m_szEgName*/          _T("LEFT_MOUSE_BUTTON"),
        /*m_szExplain*/         _T("LEFT_MOUSE_BUTTON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 4
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����м��Ѱ���"),
        /*m_szEgName*/          _T("MIDDLE_MOUSE_BUTTON"),
        /*m_szExplain*/         _T("MIDDLE_MOUSE_BUTTON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 5
    },
	{
		/*m_dtType*/            SDT_INT,
        /*m_pArySpec*/          NULL,
        /*m_szName*/            _T("����Ҽ��Ѱ���"),
        /*m_szEgName*/          _T("RIGHT_MOUSE_BUTTON"),
        /*m_szExplain*/         _T("RIGHT_MOUSE_BUTTON"),
        /*m_dwState*/           NULL,
        /*m_nDefault*/          1 << 6
    },
};

#endif

#endif