// AquariusWnd.cpp: implementation of the CAquariusWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AquariusWnd.h"
#include "dispatch.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern PFN_NOTIFY_SYS g_fnAquaNotifySys;

BEGIN_MESSAGE_MAP(CAquariusApp, CWinApp)
//{{AFX_MSG_MAP(CHtmlViewApp)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code!
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CAquariusWnd, CWnd)
//{{AFX_MSG_MAP(CHHCtrl)
ON_WM_SETFOCUS()
ON_WM_SIZE()
ON_WM_PAINT()
ON_WM_DESTROY()
ON_WM_TIMER()
ON_MESSAGE(AQUA_MSG_INITIAL,CAquariusWnd::OnInitial)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CAquariusWnd, CWnd)

END_EVENTSINK_MAP()

namespace Local{
	CAquariusWnd *pMainWnd;
}

CAquariusApp::CAquariusApp()
{
}

#ifndef __E_STATIC_LIB

CAquariusApp theApp;

#endif

// ע��˳�򲻿ɸı�!!!
UNIT_PROPERTY g_aquariusWndProperty [] =
{
	FIXED_WIN_UNIT_PROPERTY,
	{
		/*m_szName*/			_WT("�߿�"),
		/*m_szEgName*/			_WT("border"),
		/*m_szExplain*/			_WT(""),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("�ޱ߿�\0����ʽ\0͹��ʽ\0ǳ����ʽ\0����ʽ\0���߱߿�ʽ\0"),
	},{
		/*m_szName*/			_WT("���价��"),
		/*m_szEgName*/			_WT("frame_path"),
		/*m_szExplain*/			_WT("������������价����"),
		/*m_shtType*/			UD_TEXT,
			/*m_wState*/		NULL,
			/*m_szzPickStr*/	_WT(""),
	},{
		/*m_szName*/			_WT("Ĭ�ϱ���"),
		/*m_szEgName*/			_WT("default_encoding"),
		/*m_szExplain*/			_WT("Web���ݵ�Ĭ�ϱ���,���Ϊ����ʹ��\"ISO-8859-1\""),
		/*m_shtType*/			UD_TEXT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT(""),
	},{
		/*m_szName*/			_WT("���нű�"),
		/*m_szEgName*/			_WT("javascript"),
		/*m_szExplain*/			_WT("�Ƿ�������������ز�����ҳ���еĽű���Դ��"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("Ĭ��\0����\0��ֹ\0"),
	},{
		/*m_szName*/			_WT("���ز��"),
		/*m_szEgName*/			_WT("plugins"),
		/*m_szExplain*/			_WT("�Ƿ����������������չ�����"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("Ĭ��\0����\0��ֹ\0"),
	},{
		/*m_szName*/			_WT("�������"),
		/*m_szEgName*/			_WT(""),
		/*m_szExplain*/			_WT("�Ƿ�����ر������ͬԴվ�����Ʋ�������ʵ�������֧�֡�"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("Ĭ��\0����\0��ֹ\0"),
	},{
		/*m_szName*/			_WT("��ͼģʽ"),
		/*m_szEgName*/			_WT("image_loading"),
		/*m_szExplain*/			_WT("�Ƿ�������ֹ�������Ŀ�������м���ͼ����Դ��"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("Ĭ��\0����\0�ر�\0"),
	},
	{
		/*m_szName*/			_WT("WEBGL"),
		/*m_szEgName*/			_WT("webgl"),
		/*m_szExplain*/			_WT("�����Ƿ����ʹ��WebGL,��ע��,WebGL��ҪӲ��֧��,��ʹ����,Ҳ�����޷�������ϵͳ�����С�"),
		/*m_shtType*/			UD_PICK_INT,
		/*m_wState*/			NULL,
		/*m_szzPickStr*/		_WT("Ĭ��\0����\0��ֹ\0"),
	}
};

INT g_aquariusWndPropertyCount = sizeof(g_aquariusWndProperty) / sizeof(g_aquariusWndProperty[0]);

static EVENT_ARG_INFO2 s_aquariusWndArgInfo [] = {
//****** �����ʼ��	0
	{
/*name*/	_WT("ѡ��"),
/*explain*/	_WT("�ò���ֵ���ڶ�ˮ����������г�ʼ�����á�"),
/*state*/	EAS_BY_REF,
			MAKELONG(6,0)
	},
//****** �����г�ʼ��	1
	{
/*name*/	_WT("������"),
/*explain*/	_WT("�ò���ֵ���ڲ鿴���޸���������Ϣ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(9,0)
	},
//****** ��ַ���ı�	2
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ��ַ���ı�	3
	{
/*name*/	_WT("���"),
/*explain*/	_WT("�ò���ֵָ���ܶ���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ��ַ���ı�	4
	{
/*name*/	_WT("��ַ�ı�"),
/*explain*/	_WT("�ò���ֵָ���µĵ�ַ(URL)��Ϣ��"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ��ַ���ı�	5
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ���ⱻ�ı�	6
	{
/*name*/	_WT("�����ı�"),
/*explain*/	_WT("�ò���ֵָ���µı�����Ϣ��"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ҳ��ͼ�걻�ı�	7
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ҳ��ͼ�걻�ı�	8
	{
/*name*/	_WT("ͼ���б�"),
/*explain*/	_WT("�ò���ֵָ��ҳ��ͼ��URL�б�"),
/*state*/	NULL,
			MAKELONG(2,0)
	},
//****** ��ʾģʽ���ı�	9
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ��ʾģʽ���ı�	10
	{
/*name*/	_WT("ȫ��"),
/*explain*/	_WT("�ò���ֵָʾ��ǰ�Ƿ�Ϊȫ��״̬"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** ״̬�ı����ı�	11
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ״̬�ı����ı�	12
	{
/*name*/	_WT("ֵ"),
/*explain*/	_WT("�ò���ֵָ��״̬�ı���"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ����̨	13
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ����̨	14
	{
/*name*/	_WT("��Ϣ����"),
/*explain*/	_WT("�ò���ֵ������Ϣ�����͡�"),
/*state*/	NULL,
			SDT_INT
	},
//****** ����̨	15
	{
/*name*/	_WT("��Ϣ�ı�"),
/*explain*/	_WT("��Ϣ�ı�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ����̨	16
	{
/*name*/	_WT("��ϢԴ"),
/*explain*/	_WT("��ϢԴ"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ����̨	17
	{
/*name*/	_WT("�к�"),
/*explain*/	_WT("�к�"),
/*state*/	NULL,
			SDT_INT
	},
//****** ������� 18
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �������´��� 19
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �������´��� 20
	{
/*name*/	_WT("���"),
/*explain*/	_WT("�ò���ֵָ���ܶ���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** �������´��� 21
	{
/*name*/	_WT("Ŀ���ַ"),
/*explain*/	_WT("Ŀ���ַ��"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �������´��� 22
	{
/*name*/	_WT("Ŀ��������"),
/*explain*/	_WT("Ŀ�������ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �������´��� 23
	{
/*name*/	_WT("�򿪷�ʽ"),
/*explain*/	_WT("���ӵĴ򿪷�ʽ,�볣������\"#���ڴ򿪷�ʽ����.xxx\"��ƥ�䡣"),
/*state*/	NULL,
			SDT_INT
	},
//****** �������´��� 24
	{
/*name*/	_WT("����"),
/*explain*/	_WT("���ơ�"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** �������´��� 25
	{
/*name*/	_WT("��������"),
/*explain*/	_WT("��������"),
/*state*/	NULL,
			SDT_INT
	},
//****** �������´��� 26
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("������Ϣ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(7,0)
	},
//****** �������´��� 27
	{
/*name*/	_WT("���ýű�"),
/*explain*/	_WT("���ýű���"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** ����״̬���ı� 28
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ����״̬���ı� 29
	{
/*name*/	_WT("������"),
/*explain*/	_WT("��ǰҳ���Ƿ�����������"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** ����״̬���ı� 30
	{
/*name*/	_WT("�ɷ����"),
/*explain*/	_WT("�ɷ����"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** ����״̬���ı� 31
	{
/*name*/	_WT("�ɷ�ǰ��"),
/*explain*/	_WT("�ɷ�ǰ��"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** ���뿪ʼ 32
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ���뿪ʼ 33
	{
/*name*/	_WT("���"),
/*explain*/	_WT("�ò���ֵָ���ܶ���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ���뿪ʼ 34
	{
/*name*/	_WT("Դ����"),
/*explain*/	_WT("�����ת�����͡� ��һ��Դֵ��0��������Ԥѡ����"),
/*state*/	NULL,
			SDT_INT
	},
//****** ������� 35
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ������� 36
	{
/*name*/	_WT("���"),
/*explain*/	_WT("�ò���ֵָ���ܶ���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ������� 37
	{
/*name*/	_WT("״̬��"),
/*explain*/	_WT("HTTP������Ӧ��"),
/*state*/	NULL,
			SDT_INT
	},
//****** ����ʧ�� 38
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�ò���ֵָ�����������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ����ʧ�� 39
	{
/*name*/	_WT("���"),
/*explain*/	_WT("�ò���ֵָ���ܶ���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ����ʧ�� 40
	{
/*name*/	_WT("�������"),
/*explain*/	_WT("�������"),
/*state*/	NULL,
			SDT_INT
	},
//****** ����ʧ�� 41
	{
/*name*/	_WT("�����ı�"),
/*explain*/	_WT("�����ı�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ����ʧ�� 42
	{
/*name*/	_WT("ʧ�ܵ�ַ"),
/*explain*/	_WT("ʧ�ܵ�ַ"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �첽ִ�н�� 43
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("���������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �첽ִ�н�� 44
	{
/*name*/	_WT("ִ�б��"),
/*explain*/	_WT("���ڱ�ʾ��ǰ���յ���ִ�н������˭������,Ϊ���³���֮һ: "
				"0 : #�첽�������ͳ���.ȡԴ��;  1 : #�첽�������ͳ���.ȡ�ı�;  2 : #�첽�������ͳ���.ִ�б��ʽ"),
/*state*/	NULL,
			SDT_INT
	},
//****** �첽ִ�н�� 45
	{
/*name*/	_WT("�Զ������1"),
/*explain*/	_WT("�ڵ����첽����ʱ��������Զ��������"),
/*state*/	NULL,
			SDT_INT
	},
//****** �첽ִ�н�� 46
	{
/*name*/	_WT("�Զ������2"),
/*explain*/	_WT("�ڵ����첽����ʱ��������Զ��������"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �첽ִ�н�� 47
	{
/*name*/	_WT("�Զ������3"),
/*explain*/	_WT("�ڵ����첽����ʱ��������Զ��������"),
/*state*/	NULL,
			SDT_BIN
	},
//****** �첽ִ�н�� 48
	{
/*name*/	_WT("���1"),
/*explain*/	_WT("�첽ģʽ�µĺ������ý����"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �첽ִ�н�� 49
	{
/*name*/	_WT("���2"),
/*explain*/	_WT("�첽ģʽ�µĺ������ý����"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű������Ĵ������ 50
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("���������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �ű�ע���������ֵ 51
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�����ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű�ע���������ֵ 52
	{
/*name*/	_WT("������"),
/*explain*/	_WT("�������ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű�ע���������ֵ 53
	{
/*name*/	_WT("��ֵ"),
/*explain*/	_WT("���������ֵ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** �ű�ע�������ȡֵ 54
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�����ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű�ע�������ȡֵ 55
	{
/*name*/	_WT("������"),
/*explain*/	_WT("�������ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű�ע�������ȡֵ 56
	{
/*name*/	_WT("����ֵ"),
/*explain*/	_WT("���ظ������ߵ�ֵ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** �ű�ע�ắ�������� 57
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�����ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű�ע�ắ�������� 58
	{
/*name*/	_WT("������"),
/*explain*/	_WT("�������ơ�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű�ע�ắ�������� 59
	{
/*name*/	_WT("��������"),
/*explain*/	_WT("����������"),
/*state*/	NULL,
			SDT_INT
	},
//****** �ű�ע�ắ�������� 60
	{
/*name*/	_WT("����ֵ"),
/*explain*/	_WT("����ֵ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** �ű�ע�ắ�������� 61
	{
/*name*/	_WT("����ֵ"),
/*explain*/	_WT("���ص�ֵ"),
/*state*/	EAS_BY_REF,
			MAKELONG(20,0)
	},
//****** ��Դ���뿪ʼ 62
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ��Դ���뿪ʼ 63
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ��Դ���뿪ʼ 64
	{
/*name*/	_WT("request"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** ��Դ���뿪ʼ 65
	{
/*name*/	_WT("������Դ����"),
/*explain*/	_WT("�������Ϊ��������Դ˳���������ʱ����\"��Դ�������\"�¼��е�\"��Ч�غ�\"�������ṩ����Դ�ĸ������ݡ�"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** ��Դ�ض��� 66
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ��Դ�ض��� 67
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ��Դ�ض��� 68
	{
/*name*/	_WT("HTTP����"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** ��Դ������� 69
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ��Դ������� 70
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ��Դ������� 71
	{
/*name*/	_WT("HTTP����"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** ��Դ������� 72
	{
/*name*/	_WT("HTTP��Ӧ"),
/*explain*/	_WT("response"),
/*state*/	EAS_BY_REF,
			MAKELONG(25,0)
	},
//****** ��Դ������� 73
	{
/*name*/	_WT("���ؽ��"),
/*explain*/	_WT("��ӳ��Դ�ļ������,�ο������б�:#��Դ���ؽ������.xxx"),
/*state*/	NULL,
			SDT_INT
	},
//****** ��Դ������� 74
	{
/*name*/	_WT("������Դ��С"),
/*explain*/	_WT("���յ�����Դ��С"),
/*state*/	NULL,
			SDT_INT
	},
//****** ��Դ������� 75
	{
/*name*/	_WT("��Ч�غ�"),
/*explain*/	_WT("�����Դ�Ŀ�������,��\"��Դ���뿪ʼ\"�¼��н�\"������Դ����\"��������Ϊ��ʱ,�Żᴴ����Դ�ĸ�������"),
/*state*/	EAS_BY_REF,
			SDT_BIN
	},
//****** �ű������Ի��� 76
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�������"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �ű������Ի��� 77
	{
/*name*/	_WT("Url"),
/*explain*/	_WT("Url"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű������Ի��� 78
	{
/*name*/	_WT("lang"),
/*explain*/	_WT("lang"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű������Ի��� 79
	{
/*name*/	_WT("�Ի�������"),
/*explain*/	_WT("�Ի�������,�ο���������: #J�ű��Ի�����.xxx"),
/*state*/	NULL,
			SDT_INT
	},
//****** �ű������Ի��� 80
	{
/*name*/	_WT("��ʾ�ı�"),
/*explain*/	_WT("��ʾ�ı�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű������Ի��� 81
	{
/*name*/	_WT("Ĭ���ı�"),
/*explain*/	_WT("Ĭ���ı�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ű������Ի��� 82
	{
/*name*/	_WT("��ť"),
/*explain*/	_WT("��ť"),
/*state*/	EAS_BY_REF,
			MAKELONG(33,0)
	},
//****** �ļ��Ի��򽫱��� 83
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �ļ��Ի��򽫱��� 84
	{
/*name*/	_WT("�򿪷�ʽ"),
/*explain*/	_WT("�򿪷�ʽ,�ο���������: #�ļ��Ի�����.xxx"),
/*state*/	NULL,
			SDT_INT
	},
//****** �ļ��Ի��򽫱��� 85
	{
/*name*/	_WT("�����ı�"),
/*explain*/	_WT("�����ı�"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ļ��Ի��򽫱��� 86
	{
/*name*/	_WT("��ʼĿ¼"),
/*explain*/	_WT("��ʼĿ¼"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ļ��Ի��򽫱��� 87
	{
/*name*/	_WT("�������б�"),
/*explain*/	_WT("�������б�"),
/*state*/	EAS_BY_REF,
			MAKELONG(2,0)
	},
//****** �ļ��Ի��򽫱��� 88
	{
/*name*/	_WT("ѡ��Ĺ���������"),
/*explain*/	_WT("ѡ��Ĺ���������"),
/*state*/	NULL,
			SDT_INT
	},
//****** �ļ��Ի��򽫱��� 89
	{
/*name*/	_WT("��ť"),
/*explain*/	_WT("��ť"),
/*state*/	EAS_BY_REF,
			MAKELONG(34,0)
	},
//****** �����¼� 90
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �����¼� 91
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("������Ϣ"),
/*state*/	EAS_BY_REF,
			MAKELONG(36,0)
	},
//****** �����¼� 92
	{
/*name*/	_WT("�Ƿ���Ϊ��ݼ�"),
/*explain*/	_WT("�Ƿ���Ϊ��ݼ�"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** �ļ��������� 93
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �ļ��������� 94
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("������Ϣ"),
/*state*/	EAS_BY_REF,
			MAKELONG(39,0)
	},
//****** �ļ��������� 95
	{
/*name*/	_WT("�Ƽ��ļ���"),
/*explain*/	_WT("�Ƽ��ļ���"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �ļ��������� 96
	{
/*name*/	_WT("ѡ��"),
/*explain*/	_WT("ѡ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(40,0)
	},
//****** ���ؽ��ȱ����� 97
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ���ؽ��ȱ����� 98
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("������Ϣ"),
/*state*/	EAS_BY_REF,
			MAKELONG(39,0)
	},
//****** ���ؽ��ȱ����� 99
	{
/*name*/	_WT("ѡ��"),
/*explain*/	_WT("ѡ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(41,0)
	},
//****** �Ҽ��˵��������� 100
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �Ҽ��˵��������� 101
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** �Ҽ��˵��������� 102
	{
/*name*/	_WT("����λ��"),
/*explain*/	_WT("����λ��"),
/*state*/	NULL,
			SDT_INT
	},
//****** �Ҽ��˵��������� 103
	{
/*name*/	_WT("����λ��"),
/*explain*/	_WT("����λ��"),
/*state*/	NULL,
			SDT_INT
	},
//****** ��Ȩ��֤�¼� 104
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** ��Ȩ��֤�¼� 105
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** ��Ȩ��֤�¼� 106
	{
/*name*/	_WT("�Ƿ�Ϊ���������"),
/*explain*/	_WT("�Ƿ�Ϊ���������"),
/*state*/	NULL,
			SDT_BOOL
	},
//****** ��Ȩ��֤�¼� 107
	{
/*name*/	_WT("������ַ"),
/*explain*/	_WT("������ַ"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ��Ȩ��֤�¼� 108
	{
/*name*/	_WT("�����˿�"),
/*explain*/	_WT("�����˿�"),
/*state*/	NULL,
			SDT_INT
	},
//****** ��Ȩ��֤�¼� 109
	{
/*name*/	_WT("realm"),
/*explain*/	_WT("|realm| is the realm of the challenge and may be empty."),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ��Ȩ��֤�¼� 110
	{
/*name*/	_WT("scheme"),
/*explain*/	_WT("|scheme| is the authentication scheme used such as \"basic\" or \"digest\", and will be empty if the source of the request is an FTP server."),
/*state*/	NULL,
			SDT_TEXT
	},
//****** ��Ȩ��֤�¼� 111
	{
/*name*/	_WT("��¼"),
/*explain*/	_WT("��¼"),
/*state*/	NULL,
			MAKELONG(42,0)
	},
//****** �˵������� 112
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �˵������� 113
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** �˵������� 114
	{
/*name*/	_WT("�˵�����"),
/*explain*/	_WT("�˵�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(43,0)
	},
//****** �˵������� 115
	{
/*name*/	_WT("�˵�ģ��"),
/*explain*/	_WT("�˵�ģ��"),
/*state*/	EAS_BY_REF,
			MAKELONG(44,0)
	},
//****** �˵���ѡ�� 116
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �˵���ѡ�� 117
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** �˵���ѡ�� 118
	{
/*name*/	_WT("�˵�����"),
/*explain*/	_WT("�˵�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(43,0)
	},
//****** �˵���ѡ�� 119
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("�˵�ID"),
/*state*/	NULL,
			SDT_INT
	},
//****** �����������ת 120
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �����������ת 121
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*state*/	EAS_BY_REF,
			MAKELONG(12,0)
	},
//****** �����������ת 122
	{
/*name*/	_WT("HTTP����"),
/*explain*/	_WT("request"),
/*state*/	EAS_BY_REF,
			MAKELONG(24,0)
	},
//****** �����������ת 123
	{
/*name*/	_WT("is_redirect"),
/*explain*/	_WT("is_redirect"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
//****** �������������Э�� 124
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�����"),
/*state*/	EAS_BY_REF,
			MAKELONG(10,0)
	},
//****** �������������Э�� 125
	{
/*name*/	_WT("URL"),
/*explain*/	_WT("URL"),
/*state*/	NULL,
			SDT_TEXT
	},
//****** �������������Э�� 126
	{
/*name*/	_WT("allow_os_execution"),
/*explain*/	_WT("allow_os_execution"),
/*state*/	EAS_BY_REF,
			SDT_BOOL
	},
};

EVENT_INFO2 g_aquariusWndEvent [] = {
	{
			_WT("�����ʼ��"),
			_WT("�������������ɺ󱻵���,�ڴ��¼��п���ִ����صĳ�ʼ�����롣"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[0],
			_SDT_NULL
	},
	{
			_WT("�����г�ʼ��"),
			_WT("���������ʼ��ʱ������,�ڴ��¼��л�ò鿴�Լ��޸�������������Ļ��ᡣ"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[1],
			_SDT_NULL
	},
	{
			_WT("��ʼ�����"),
			_WT("���������ʼ����ʼ����Ϻ󱻵���,�ڴ��¼��п���ִ�г������س�ʼ�����롣"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			0,
			/*m_pBeginArgInfo*/		NULL,
			_SDT_NULL
	},
	{
			_WT("��ַ���ı�"),
			_WT("����ַ�����仯ʱ���ø��¼���"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[2],
			_SDT_NULL
	},
	{
			_WT("���ⱻ�ı�"),
			_WT("��ҳ�����ı�ʱ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[5],
			_SDT_NULL
	},
	{
			_WT("ҳ��ͼ�걻�ı�"),
			_WT("��ҳ��ͼ�귢���仯ʱ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[7],
			_SDT_NULL
	},
	{
			_WT("��ʾģʽ���ı�"),
			_WT("��ҳ���е���ҳ�����л�Ϊȫ��ģʽʱ���á�"
				"���|ȫ��| �����ݽ��Զ�������С������������������"
				"���|ȫ��| �Ǵ�������ݽ��Զ����ص���ԭʼ��С��λ�á� �����Ҫ���ͻ��˸������������Ĵ�С��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[9],
			_SDT_NULL
	},
	{
			_WT("״̬�ı����ı�"),
			_WT("��������յ�״̬��Ϣʱ���á�|ֵ| ��������״̬��Ϣ����ʾ���ı���"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			2,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[11],
			_SDT_NULL
	},
	{
			_WT("����̨"),
			_WT("��������ʾ����̨��Ϣ�� ����true��ֹͣ����Ϣ���������̨��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			5,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[13],
			SDT_BOOL
	},
	{
			_WT("�������"),
			_WT("��������ʾ����̨��Ϣ�� ����true��ֹͣ����Ϣ���������̨��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[18],
			_SDT_NULL
	},
	{
			_WT("�������´���"),
			_WT("�ڴ����µĵ���ʽ�����֮ǰ����UI�̡߳�"
				"��|�����|��| ��� |ֵ�������������Դ��"
				"| Ŀ���ַ |��| Ŀ������ |ֵ��ʾ������λ��"
				"�����Ӧ�õ��������δ������һ��ָ���������Ϊ�ա�"
				"| Ŀ��λ�� |ֵ��ʾ�û�����򿪵�λ��"
				"�������ڣ����統ǰ��ǩ���±�ǩ�ȣ��� | ���� |��ֵ��"
				"���ͨ����ȷ���û����ƴ��˵���ʽ����"
				"�����磬����\"����\"�����������ʽ�����Զ��򿪣�����ͨ��DomContentLoaded�¼�����"
				"����������ĵ������ڵ���Ϣ���������������������ѡ���޸�| ������Ϣ |��"
				"��| no_javascript_access |������false��ȡ�����������������������true��"
				"�ͻ���|��|����|ֵ��Ĭ��ΪԴ�������ֵ�����| no_javascript_access |ֵ����Ϊ"
				"���µ���������ᱻ��д�ű������ҿ��ܲ��ᱻ�й���Դ�������ͬ����Ⱦ�����̡�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			9,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[19],
			SDT_BOOL
	},
	{
			_WT("�ɷ񱻹ر�"),
			_WT("��������յ��ر�����ʱ���á�"
				"����ܻᵼ��ֱ�Ӵӵ���CefBrowserHost::*CloseBrowser()"
				"���������Ϊ��CEF���û������Ķ������ڵĸ������Թرոô��ڣ����磬ͨ��������X��������"
				"��'onunload'�¼�������DoClose���������ᱻ���ñ���͡�"
				"Ӧ�ó���Ӧ��ͨ���������������ߴ��ڹر�֪ͨ����CefBrowserHost :: TryCloseBrowser������"
				"CefBrowserHost :: CloseBrowser��false�������������ڹر�"
				"����������������ӣ��� �����CEFһ������"
				"����'onbeforeunload'�¼�����ѡ���ȡ���ر�DoClose���������á�"
				"�����ô�����Ⱦʱ��CEF�����ڲ��������ڻ�鿴�й�������� ����������£���DoClose��������false���ᷢ��"
				"��������Ķ��������߷��ͱ�׼�ر�֪ͨ"
				"���ڣ�����Windows�ϵ�WM_CLOSE��ִ�йرգ���OS X�ϣ���delete_event������"
				"����ͼ��Linux��CefWindowDelegate :: CanClose�����ص����� ���"
				"�������������/��ͼ�Ѿ������٣�ͨ����ͼ��νṹ"
				"�����ж������ôDoClose���������ᱻ�������������Ϊ���ٿ���ȡ���ر�����"
				"��������Ⱦ������ʱ������DoClose��������false��������������������١�"
				"���������Ķ��������ߴ�����Ҫ�Ǳ�׼�ر�֪ͨȻ���DoClose�������͸�֪ͨ������true��"
				"CefLifeSpanHandler :: OnBeforeClose()��������֮�����DoClose()(�������DoClose())�����������֮ǰ�����ƻ���"
				"Ӧ�ó���ֻӦ��OnBeforeClose()���˳��ѱ�����������������á�"
				"����������������ڹرմ���ʱӦ�÷���ʲô���������Ӧ�ó����ṩ�Ķ��㴰�����ɵġ�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[18],
			SDT_BOOL
	},
	{
			_WT("����������"),
			_WT("�������������֮ǰ���á�"
				"�ͷ����е�������������󣬲��Ҳ�Ҫ�������������ִ���κη����˻ص����غ�Ķ���"
				"����ص��������һ��֪ͨ����|�����|�� �����DoClose()�ĵ������ʹ����Ϣ��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[18],
			_SDT_NULL
	},
	{
			_WT("����״̬���ı�"),
			_WT("����״̬�����仯ʱ���á� "
				"�˻ص�����ִ������ - �Ա�̷�ʽ�����û���������ʱ�ж���һ����������ɶ���ֹʱ��ȡ����ʧ�ܡ�"
				"�������κε���OnLoadStart֮ǰ���ã��Ͼ�����OnLoadError��/��OnLoadEnd��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[28],
			_SDT_NULL
	},
	{
			_WT("���뿪ʼ"),
			_WT("���ύ����֮�����������ʼ֮ǰ�����ڿ���м������ݡ�"
				"����IsMain����������������frame�Ƿ���mainframe��"
				"| transition_type| �ṩ���ڵ���Դ����Ϣ����׼ȷ��ֵ��������������п��á�"
				"��frame����ͬʱ�����ء���frame���ܻῪʼ�����������ܼ��ؽ�������ء�����������ᱻ����"
				" Ϊ��ͬ��ҳ�浼����Ƭ�Σ���ʷ״̬�ȣ���for����ʧ�ܻ����ύ֮ǰȡ���� ֪ͨ"
				"�������������״̬��Ϊʹ��OnLoadingStateChange��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[32],
			_SDT_NULL
	},
	{
			_WT("�������"),
			_WT("���������ɼ���֡ʱ���á� |���| ��ֵ��"
				"��Զ��Ϊ�� - ����IsMain����������������֡�Ƿ�Ϊ��"
				"����ܡ� ���frame����ͬʱ���ء� ��frame����"
				"��mainframe���ؽ�����������������ء� ���ַ���"
				"�����ᱻ������ͬ��ҳ�浼����Ƭ�Σ���ʷ״̬���ȵȣ��򵼺�ʧ�ܻ��ύǰ��ȡ���� ����"
				"�������������״̬֪ͨʹ��OnLoadingStateChange���档"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[35],
			_SDT_NULL
	},
	{
			_WT("����ʧ��"),
			_WT("������ʧ�ܻ�ȡ��ʱ���á� ���ַ������ܻᱻ����"
				"����������ύ֮ǰ����OnLoadStart / OnLoadEnd���ʹ�õĻ�"
				"�ύ��|��errorCode|�Ǵ�������,|errorText| �Ǹ�"
				"�����ı���| failedUrl|��δ�ܼ��ص���ַ��"
				"�йش�����������˵������μ�net\\base\\net_error_list.h��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			5,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[38],
			_SDT_NULL
	},
	{
			_WT("�첽���ý��"),
			_WT("���¼����ڽ����첽ģʽ�µĺ������ý����"
				"֧���첽ģʽ�ĺ�����: \"ˮ�ǿ��.ȡԴ��()\",\"ˮ�ǿ��.ȡ�ı�()\",\"ˮ�ǿ��.ִ�б��ʽ()\","
				"���¼��е�����Щ������ʱ,����ʹ���첽ģʽ,�����޷���ý����"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[43],
			_SDT_NULL
	},
	{
			_WT("�첽������"),
			_WT("���¼����ڽ����첽ģʽ�µĺ������ý����"
				"֧���첽ģʽ�ĺ�����: \"ˮ�ǿ��.ȡԴ��()\",\"ˮ�ǿ��.ȡ�ı�()\",\"ˮ���ĵ�.ִ�б��ʽ()\","
				"���¼��е�����Щ������ʱ,����ʹ���첽ģʽ,�����޷���ý����"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[43],
			_SDT_NULL
	},
	{
			_WT("�ű������Ĵ������"),
			_WT("�ڴ�����ɿ���е�V8������ִ�л�������ø��¼���"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[50],
			_SDT_NULL
	},
	{
			_WT("�ű������Ľ�������"),
			_WT("�ڿ���е�V8������ִ�л�������������ǰ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			1,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[50],
			_SDT_NULL
	},
	{
			_WT("ע�������Ա���ֵ"),
			_WT("��ע���ڽű������Ļ����еı�������ֵʱ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[51],
			SDT_BOOL
	},
	{
			_WT("ע�������Ա�ȡֵ"),
			_WT("��ע���ڽű������Ļ����еı�����ȡֵʱ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[54],
			SDT_BOOL
	},
	{
			_WT("ע���෽��������"),
			_WT("��ע���ڽű������Ļ����еĺ���������ʱ��Ӧ���¼���"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			5,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[57],
			SDT_BOOL
	},
	{
			_WT("��Դ���뿪ʼ"),
			_WT("�ڼ�������ҳ����Դǰ���ø��¼�,������ؼ���ֹ����Դ�ļ���,Ĭ������·�����,�����������Դ��"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[62],
			SDT_BOOL
	},
	{
			_WT("��Դ�ض���"),
			_WT("�Ƿ���Ҫ���¶�����Դ�ļ���URL,����\"\"��ʾ�������ض���,�ǿ�ʱ�ṩ��Ҫ���¶��򵽵���URL��ַ�� "),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[66],
			SDT_TEXT
	},
	{
			_WT("��Դ�������"),
			_WT("��ҳ����Դ������ɺ���ø��¼�."),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[69],
			_SDT_NULL
	},
	{
			_WT("�ű������Ի���"),
			_WT("���ű������Ի���ʱ���ø��¼�,��������潫��ֹ�Ի���ĵ�����"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[76],
			SDT_BOOL
	},
	{
			_WT("�ļ��Ի��򽫱���"),
			_WT("���ļ��Ի��򱻷���ʱ���ø��¼�,��������潫��ֹ�Ի���ĵ�����"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			7,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[83],
			SDT_BOOL
	},
	{
			_WT("�����¼�"),
			_WT("����������в��������¼�ʱ���ø��¼�,��������潫��ֹ���¼���������Ⱦ����"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[90],
			SDT_BOOL
	},
	{
			_WT("��Դ�ļ���������"),
			_WT("�����ؿ�ʼ֮ǰ���á�| suggested_name| �������ļ��Ľ������ơ� "
				"Ĭ������£����ؽ���ȡ���� ִ��|�ص�| �첽���Դ˷����������أ������Ҫ���� "
				"��Ҫ������| download_item |������ �����ַ���֮�⡣"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[93],
			_SDT_NULL
	},
	{
			_WT("���ؽ��ȱ�����"),
			_WT("�����ص�״̬�������Ϣ�Ѹ���ʱ���á�"
					"�������OnBeforeDownload����֮ǰ��֮���ε��á�"
					"ִ��|�ص�| Ҫô�첽��Ҫô�ڴ˷�����ȡ��"
					"�����Ҫ���ء� ��Ҫ������| download_item |������ ���������ַ�����"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[97],
			_SDT_NULL
	},
	{
			_WT("�Ҽ��˵���������"),
			_WT("�����������Զ�����ʾ�����Ĳ˵���"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[100],
			SDT_BOOL
	},
	{
			_WT("������֤"),
			_WT("���������Ҫ�����û���ƾ��ʱ���ø��¼�,�����������֤,���ؼ�ȡ����֤,Ĭ�Ϸ��ؼ١�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			8,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[104],
			SDT_BOOL
	},
	{
			_WT("�˵�������"),
			_WT("����������˵�ǰ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[112],
			_SDT_NULL
	},
	{
			_WT("�˵���ѡ��"),
			_WT("�û�ѡ��˵���ʱ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[116],
			_SDT_NULL
	},
	{
			_WT("������ת"),
			_WT("�����������תʱ���á�"),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			4,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[120],
			SDT_BOOL
	},
	{
			_WT("����ִ��Э��"),
			_WT("�������������Э��ʱ����"
				   "���������ڡ�������ת�������"
				   "���Դ������Э��"
			),
			/*m_dwState*/			EV_IS_VER2,
			/*m_nArgCount*/			3,
			/*m_pBeginArgInfo*/		&s_aquariusWndArgInfo[124],
			_SDT_NULL
	},
};

INT g_nAquariusWndEventCount = sizeof(g_aquariusWndEvent) / sizeof(g_aquariusWndEvent[0]);
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAquariusWnd::CAquariusWnd()
{
	Local::pMainWnd=this;
}

CAquariusWnd::~CAquariusWnd()
{
	Local::pMainWnd=NULL;
}

BOOL CAquariusWnd::Create (HWND hParentWnd, DWORD dwStyle, UINT nID,
			 INT x, INT y, INT cx, INT cy){
	if (!CWnd::CreateEx (NULL, AfxRegisterWndClass (CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
		::LoadCursor (NULL, IDC_ARROW), HBRUSH (::GetStockObject (WHITE_BRUSH))),
		_T(""), dwStyle, x, y, cx, cy, hParentWnd, (HMENU)nID, NULL))
		return FALSE;
	
	AfxEnableControlContainer();
	return TRUE;
}

void CAquariusWnd::ChangeBroder(void){
	DWORD dwStyle = NULL, dwExStyle = NULL;
	switch (m_info.m_nBorderStyle)
	{
	case 0:		// �ޱ߿�
		break;
	case 1:		// ����ʽ
		dwExStyle = WS_EX_CLIENTEDGE;
		break;
	case 2:		// ͹��ʽ
		dwExStyle = WS_EX_DLGMODALFRAME;
		break;
	case 3:		// ǳ����ʽ
		dwExStyle = WS_EX_STATICEDGE;
		break;
	case 4:		// ����ʽ
		dwExStyle = WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME;
		break;
	case 5:
		dwStyle = WS_BORDER;
		break;
	}
	this->ModifyStyleEx (WS_EX_STATICEDGE | WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME,
		dwExStyle, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
		SWP_FRAMECHANGED | SWP_DRAWFRAME);
	this->ModifyStyle (WS_BORDER, dwStyle,
		SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE |
			SWP_FRAMECHANGED | SWP_DRAWFRAME);
}

BOOL CAquariusWnd::OnWndMsg(UINT message,WPARAM wParam,LPARAM lParam,LRESULT *pResult){
	if(message == WM_CREATE){
		if(m_blInDesignMode == FALSE){
			
		}
	}
	else if(message == AQUA_MSG_INITIAL){
		return this->OnInitial(0,0);
	}
	else if(message == WM_EXITSIZEMOVE){
	}
	else if(message == WM_CLOSE){
	}
	return CWnd::OnWndMsg(message,wParam,lParam,pResult);
}

void CAquariusWnd::OnClose(){
	CWnd::OnClose();
	return;
}

LRESULT CAquariusWnd::OnInitial(WPARAM wParam,LPARAM lParam){
	if(m_info.m_package.GetLength()>0){
		dispEventer::OnInitial(this,m_info.m_package);
	}
	return TRUE;
}


void CAquariusWnd::OnDestroy()
{
	CWnd::OnDestroy();
}

void CAquariusWnd::PostNcDestroy()
{
	CWnd::PostNcDestroy();
	g_fnAquaNotifySys (NRS_UNIT_DESTROIED, m_dwWinFormID, m_dwUnitID);
	delete this;
}

void CAquariusWnd::OnSize(UINT nType, int cx, int cy){
	CWnd::OnSize(nType,cx,cy);
	if(m_blInDesignMode == FALSE){
		dispEventer::OnResized(this);
	}
}

void CAquariusWnd::OnPaint()
{
	Default();
}

void CAquariusWnd::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);
}

afx_msg void CAquariusWnd::OnTimer(UINT nIDEvent){
	if(nIDEvent == AQUA_TIMER_INITIAL){
		KillTimer(AQUA_TIMER_INITIAL);
		PostMessage(AQUA_MSG_INITIAL);
		return;
	}
	CWnd::OnTimer(nIDEvent);
}

CAquariusWnd* CAquariusWnd::GetMainWnd(void){
	return Local::pMainWnd;
}