#ifndef ARGINFO_H_
#define ARGINFO_H_

#include "lib2.h"

#ifndef __E_STATIC_LIB

static ARG_INFO s_ArgInfo[] = {
//****** �ı�����->��ӣ���Ա��	**	0
	{
/*name*/	_WT("����ӵ��ı�"),
/*explain*/	_WT("��Ҫ��ӵ��ı������е��ı����ݡ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı�����->�滻����Ա��/ ɾ������Ա��/ ȡ���ݣ���Ա��	**	1
	{
/*name*/	_WT("����"),
/*explain*/	_WT("���Թ����ı����ݵ�������ֵ,��0��ʼ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı�����->�滻����Ա��	**	2
	{
/*name*/	_WT("�����滻���ı�"),
/*explain*/	_WT("�����滻������������ֵָ����ı����ݡ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ����������->��ӣ���Ա��	**	3
	{
/*name*/	_WT("����ӵ���ֵ"),
/*explain*/	_WT("��Ҫ��ӵ������еĳ�����ֵ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT64,
/*default*/	0,
/*state*/	NULL,
	},
//****** ����������->�滻����Ա��/ ɾ������Ա��/ ȡ���ݣ���Ա��	**	4
	{
/*name*/	_WT("����"),
/*explain*/	_WT("���Թ������������ݵ�������ֵ,��0��ʼ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ����������->�滻����Ա��	**	5
	{
/*name*/	_WT("�����滻����ֵ"),
/*explain*/	_WT("�����滻������������ֵָ��ĳ��������ݡ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT64,
/*default*/	0,
/*state*/	NULL,
	},
//****** ������->���������	**	6
	{
/*name*/	_WT("�����·��"),
/*explain*/	_WT("ָ��ˮ�������(Aquariuscef)������ľ���·����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ�->����	**	7
	{
/*name*/	_WT("������ļ���"),
/*explain*/	_WT("����������ֵ����������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ�->����	**	8
	{
/*name*/	_WT("������ļ�ֵ"),
/*explain*/	_WT("��ֵ����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ�->����	**	9
	{
/*name*/	_WT("�����ҵļ���"),
/*explain*/	_WT("�����ż�ֵ���ݵ���������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ�->ȡ�¸���Ա	**	10
	{
/*name*/	_WT("��Աָ��"),
/*explain*/	_WT("���ڽ��е����ĳ�Աλ��ָ��,�׸�λ��ָ���ʹ�ú���\"ȡ�׸���Ա\"���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ�->ɾ��	**	11
	{
/*name*/	_WT("��ɾ���ļ���"),
/*explain*/	_WT("�����ż�ֵ���ݵ���������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->����	**	12
	{
/*name*/	_WT("������ļ���"),
/*explain*/	_WT("����������ֵ����������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->����	**	13
	{
/*name*/	_WT("������ļ�ֵ"),
/*explain*/	_WT("��ֵ����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->����	**	14		//����
	{
/*name*/	_WT("�����ҵļ���"),
/*explain*/	_WT("�����ż�ֵ���ݵ���������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->ȡ�¸���Ա	**	15
	{
/*name*/	_WT("��Աָ��"),
/*explain*/	_WT("���ڽ��е����ĳ�Աλ��ָ��,�׸�λ��ָ���ʹ�ú���\"ȡ�׸���Ա\"���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->ɾ��	**	16
	{
/*name*/	_WT("��ɾ���ļ���"),
/*explain*/	_WT("�����ż�ֵ���ݵ���������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ�Ӵ���	**	17
	{
/*name*/	_WT("�����ھ��"),
/*explain*/	_WT("��Ƕ�뵽�Ĵ���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ�Ӵ���	**	18
	{
/*name*/	_WT("���λ��"),
/*explain*/	_WT("���λ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ�Ӵ���	**	19
	{
/*name*/	_WT("����λ��"),
/*explain*/	_WT("����λ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ�Ӵ���	**	20
	{
/*name*/	_WT("���"),
/*explain*/	_WT("���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ�Ӵ���	**	21
	{
/*name*/	_WT("�߶�"),
/*explain*/	_WT("�߶�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ��������	**	22
	{
/*name*/	_WT("�����ھ��"),
/*explain*/	_WT("�����ھ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->�����������Ϊ��������	**	23
	{
/*name*/	_WT("���ڱ���"),
/*explain*/	_WT("���ڱ���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->���������ʽ	**	24
	{
/*name*/	_WT("��ʽ"),
/*explain*/	_WT("��ʽ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ��������->���������ʽ	**	25
	{
/*name*/	_WT("��չ��ʽ"),
/*explain*/	_WT("��չ��ʽ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** HTTP��������->����·��	**	26
	{
/*name*/	_WT("λ��"),
/*explain*/	_WT("���ڴ洢������������ݵ�·��λ�á�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** HTTP��������->���ֻỰ	**	27
	{
/*name*/	_WT("�Ƿ�����"),
/*explain*/	_WT("������ô����������Ϊ��,����Ϊ�١�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ������->���������	**	28
	{
/*name*/	_WT("�����·��"),
/*explain*/	_WT("ָ��ˮ�������(Aquariuscef)������ľ���·����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ������->���������	**	29
	{
/*name*/	_WT("�������"),
/*explain*/	_WT("�ṩһ���ص��ӳ����������������ɺ󱻵���,����ִ����صĳ�ʼ�����롣�ӳ���ǩ��: <�޷���ֵ> �ӳ���()"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_SUB_PTR,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ������->���������	**	30
	{
/*name*/	_WT("�����д���"),
/*explain*/	_WT("�ṩһ���ص��ӳ������������ʼ��ʱ������,���Ի�ò鿴�Լ��޸�������������Ļ��ᡣ"
				"�����ǰΪ�����������|��������|Ϊ�ա��ӳ���ǩ��: <�޷���ֵ> �ӳ���(�ı��� ��������,������ ������)"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_SUB_PTR,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ������->��ʼ����������	**	31
	{
/*name*/	_WT("��ʼ����Ϣ"),
/*explain*/	_WT(""),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(6,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ��������->��ָ���ʼ��	**	32
	{
/*name*/	_WT("Դ����"),
/*explain*/	_WT("������������Դ����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ��������->�Ƿ����ָ���� / ȡ��ֵ /����ֵ	**	33
	{
/*name*/	_WT("����"),
/*explain*/	_WT("��������������,�������������ʽ: --����=[��ֵ] ,����\"[��ֵ]\"�ɺ��Բ�д��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ��������->�Ƿ����ָ����	**	34
	{
/*name*/	_WT("ֵ"),
/*explain*/	_WT("����������������������ֵ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ��������->���ַ�����ʼ��	**	35
	{
/*name*/	_WT("�������ַ���"),
/*explain*/	_WT("���ڳ�ʼ�������ж�����ַ�����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���캽Ա->���������	**	36
	{
/*name*/	_WT("url"),
/*explain*/	_WT("�����������ɺ�Ҫ���ʵĵ�ַ(URL),Ĭ��Ϊ��ʱ��Ϊ\"about:blank\"��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���캽Ա->���������	**	37
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("�ṩ��������ڵ���ʽ��Ϣ��Ĭ��Ϊ��ʱ��Ƕ�뵽�캽Ա�Ŀͻ����С�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(7,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���캽Ա->���������	**	38
	{
/*name*/	_WT("˽�л���"),
/*explain*/	_WT("�ṩ�������HTTP�����ķ��ʻ���; Ĭ��Ϊ��ʱ��ʹ��ȫ�����á�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(8,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���캽Ա->��ѯ�����	**	39
	{
/*name*/	_WT("��������"),
/*explain*/	_WT("���ڹ��������ʵ���������ֵ��ʶ����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�������->�ӱ�ʶ��ȡ���	**	40
	{
/*name*/	_WT("��ܱ�ʶ��"),
/*explain*/	_WT("���ڹ������ʵ���������ֵ��ʶ����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT64,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�������->�ӱ�ʶ��ȡ���	**	41
	{
/*name*/	_WT("����"),
/*explain*/	_WT("���ڹ������ʵ�����������(·��������Ϣ)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->�ر������	**	42
	{
/*name*/	_WT("ǿ�ƹر�"),
/*explain*/	_WT("�Ƿ���ǿ�ƴ�ʩ���ر��������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->���ý���	**	43
	{
/*name*/	_WT("�Ƿ�ӵ�н���"),
/*explain*/	_WT("�Ƿ�ӵ�н��㡣"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->�����ű���	**	44
	{
/*name*/	_WT("����"),
/*explain*/	_WT("ҳ�����ű���,С��0ʱ����Сҳ��,����0ʱ���Ŵ�ҳ�档"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_DOUBLE,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->�����ű���	**	45
	{
/*name*/	_WT("URL"),
/*explain*/	_WT("��Ҫ���ص��ļ���ַ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->�򿪿����߹���	**	46
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("�����߹��ߵĴ�����Ϣ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(7,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->�򿪿����߹���	**	47
	{
/*name*/	_WT("Ԫ��λ��X"),
/*explain*/	_WT("�ṩһ�����꽻�ɿ����߹����Զ�λ����Ԫ�����ڵ�dom��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->�򿪿����߹���	**	48
	{
/*name*/	_WT("Ԫ��λ��Y"),
/*explain*/	_WT("�ṩһ�����꽻�ɿ����߹����Զ�λ����Ԫ�����ڵ�dom��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->��ֹ���Ĺ��	**	49
	{
/*name*/	_WT("��ֹ"),
/*explain*/	_WT("�Ƿ��ֹ��������ꡣ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->֪ͨ������ɼ�״̬������	**	50
	{
/*name*/	_WT("�Ƿ�����"),
/*explain*/	_WT("�Ƿ����ء�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->��������Ⱦˢ��Ƶ��	**	51
	{
/*name*/	_WT("ˢ��Ƶ��"),
/*explain*/	_WT("ˢ��Ƶ�ʡ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�Ǵ���->��Ϊǰ̨	**	52
	{
/*name*/	_WT("�����õ�ǰ̨�����������"),
/*explain*/	_WT("����Ϊ���ھ��(���캽Ա���),ˮ�������,ˮ�Ǵ��ڵȶ���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	_SDT_ALL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�ǿ��->ȡԴ��	**	53
	{
/*name*/	_WT("�첽ִ��"),
/*explain*/	_WT("�Ƿ����첽ģʽִ��,ִ�н�����ᷢ����\"�첽���ý��\"�¼���,Ĭ��Ϊ����ͬ��ģʽִ��,"
				"�����¼��е���ʱ���������Ϊ��ʱ,���ܻ��ִ�н����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->ȡԴ��	**	54
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е����������,���Ϊ��,�򲻴��ݸò�����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(10,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->ȡԴ��	**	55
	{
/*name*/	_WT("�Զ������1"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е��Զ��������Ϣ,���Ϊ��,�򲻴��ݸò�����"
				"ֻ��Ϊ������������(�߼���,С����,��������,������,��������,˫����С����,�ı���,�ֽڼ���,�ӳ���ָ��),"
				"�Լ���֧�ֿ��е���������(������:ˮ���캽Ա)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->ȡԴ��	**	56
	{
/*name*/	_WT("�Զ������2"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е��Զ��������Ϣ,���Ϊ��,�򲻴��ݸò�����"
				"ֻ��Ϊ������������(�߼���,С����,��������,������,��������,˫����С����,�ı���,�ֽڼ���,�ӳ���ָ��),"
				"�Լ���֧�ֿ��е���������(������:ˮ���캽Ա)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->ȡԴ��	**	57
	{
/*name*/	_WT("�Զ������3"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е��Զ��������Ϣ,���Ϊ��,�򲻴��ݸò�����"
				"ֻ��Ϊ������������(�߼���,С����,��������,������,��������,˫����С����,�ı���,�ֽڼ���,�ӳ���ָ��),"
				"�Լ���֧�ֿ��е���������(������:ˮ���캽Ա)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BIN,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->����	**	58
	{
/*name*/	_WT("��ַ"),
/*explain*/	_WT("URL��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�ǿ��->����HTML	**	59
	{
/*name*/	_WT("�������HTML����"),
/*explain*/	_WT("�������HTML���롣"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�ǿ��->����HTML	**	60
	{
/*name*/	_WT("������URL"),
/*explain*/	_WT("������ݴ����URL��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->ִ�нű�	**	61
	{
/*name*/	_WT("��ִ�еĽű�����"),
/*explain*/	_WT("��ִ�еĽű����롣"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ�ǿ��->ִ�нű�	**	62
	{
/*name*/	_WT("������URL"),
/*explain*/	_WT("���ű����ִ���ʱ���ڱ�ʾ�ô��������URL"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ�ǿ��->ִ�нű�	**	63
	{
/*name*/	_WT("�������к�"),
/*explain*/	_WT("���ű����ִ���ʱ���ڱ�ʾ�ô���������к�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	64
	{
/*name*/	_WT("���ʽ"),
/*explain*/	_WT("���ʽ���롣"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	65
	{
/*name*/	_WT("������URL"),
/*explain*/	_WT("���ű����ִ���ʱ���ڱ�ʾ�ô��������URL"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	66
	{
/*name*/	_WT("�������к�"),
/*explain*/	_WT("���ű����ִ���ʱ���ڱ�ʾ�ô���������к�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	67
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("���ű����ִ���ʱ���쳣��Ϣ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY | AS_RECEIVE_VAR,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	68
	{
/*name*/	_WT("�첽ִ��"),
/*explain*/	_WT("�Ƿ����첽ģʽִ��,ִ�н�����ᷢ����\"�첽���ý��\"�¼���,Ĭ��Ϊ����ͬ��ģʽִ��,"
				"�����¼��е���ʱ���������Ϊ��ʱ,���ܻ��ִ�н����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	69
	{
/*name*/	_WT("�����"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е����������,���Ϊ��,�򲻴��ݸò�����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(10,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	70
	{
/*name*/	_WT("�Զ������1"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е��Զ��������Ϣ,���Ϊ��,�򲻴��ݸò�����"
				"ֻ��Ϊ������������(�߼���,С����,��������,������,��������,˫����С����,�ı���,�ֽڼ���,�ӳ���ָ��),"
				"�Լ���֧�ֿ��е���������(������:ˮ���캽Ա)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	71
	{
/*name*/	_WT("�Զ������2"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е��Զ��������Ϣ,���Ϊ��,�򲻴��ݸò�����"
				"ֻ��Ϊ������������(�߼���,С����,��������,������,��������,˫����С����,�ı���,�ֽڼ���,�ӳ���ָ��),"
				"�Լ���֧�ֿ��е���������(������:ˮ���캽Ա)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** ˮ���ĵ�->ִ�б��ʽ	**	72
	{
/*name*/	_WT("�Զ������3"),
/*explain*/	_WT("�첽ģʽ�´������첽�����¼��е��Զ��������Ϣ,���Ϊ��,�򲻴��ݸò�����"
				"ֻ��Ϊ������������(�߼���,С����,��������,������,��������,˫����С����,�ı���,�ֽڼ���,�ӳ���ָ��),"
				"�Լ���֧�ֿ��е���������(������:ˮ���캽Ա)��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BIN,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->GetURLCookie	**	73
	{
/*name*/	_WT("url"),
/*explain*/	_WT("��Ҫ������URL��ַ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->GetURLCookie	**	74
	{
/*name*/	_WT("includeHttpOnly"),
/*explain*/	_WT("�Ƿ��������httponly��ǵ�cookie��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	75
	{
/*name*/	_WT("url"),
/*explain*/	_WT("����һ����Ч��URL��ַ,cookie�������ڸ�URL��ַ�¡�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookie	**	76
	{
/*name*/	_WT("name"),
/*explain*/	_WT("name"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookie	**	77
	{
/*name*/	_WT("value"),
/*explain*/	_WT("value"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookie	**	78
	{
/*name*/	_WT("secure"),
/*explain*/	_WT("secure"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	79
	{
/*name*/	_WT("httponly"),
/*explain*/	_WT("httponly"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	80
	{
/*name*/	_WT("has_expires"),
/*explain*/	_WT("has_expires"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookie	**	81
	{
/*name*/	_WT("expires"),
/*explain*/	_WT("expires"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(18 ,0),
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->DeleteCookie	**	82
	{
/*name*/	_WT("url"),
/*explain*/	_WT("����һ����Ч��URL��ַ,���Ϊ�ս���ɾ�������������е�cookie��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->DeleteCookie	**	83
	{
/*name*/	_WT("name"),
/*explain*/	_WT("cookie����,���Ϊ�ս���ɾ��url·���µ�����cookie��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->GetCookieMerge	**	84
	{
/*name*/	_WT("url"),
/*explain*/	_WT("����һ����Ч��URL��ַ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** CookieManager->SetCookieMerge	**	85
	{
/*name*/	_WT("url"),
/*explain*/	_WT("����һ����Ч��URL��ַ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** CookieManager->SetCookieMerge	**	86
	{
/*name*/	_WT("cookies"),
/*explain*/	_WT("��\"name=value; \"��ʽ�ϲ���cookie�Ӽ��ַ�����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->����	**	87
	{
/*name*/	_WT("�����ҵļ���"),
/*explain*/	_WT("�����ż�ֵ���ݵ���������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->����	**	88
	{
/*name*/	_WT("���ճ�Աָ��"),
/*explain*/	_WT("���ڽ���ƥ�䵽���׸���Աָ�롣"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY|AS_RECEIVE_VAR,
	},
//****** �ı��ֵ���ǿ��->ȡ�¸���Ա	**	89
	{
/*name*/	_WT("��Աָ��"),
/*explain*/	_WT("���ڽ��е����ĳ�Աλ��ָ��,�׸�λ��ָ���ʹ�ú���\"ȡ�׸���Ա\"���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �ı��ֵ���ǿ��->����	**	90
	{
/*name*/	_WT("�����滻�ļ�ֵ"),
/*explain*/	_WT("��ֵ����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** V8Value->ȡֵ	**	91
	{
/*name*/	_WT("����"),
/*explain*/	_WT("����,��0��ʼ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** V8Value->��ֵ	**	92
	{
/*name*/	_WT("ֵ"),
/*explain*/	_WT("�������ֵ,����Ϊ: #�߼��͡�#�����͡�#С���͡�#�ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	_SDT_ALL,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���캽Ա->ע��ű���	**	93
	{
/*name*/	_WT("����"),
/*explain*/	_WT("��ע�������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���캽Ա->ע��ű�����	**	94
	{
/*name*/	_WT("��"),
/*explain*/	_WT("��ע���������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(21,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���캽Ա->ע��ű�����	**	95
	{
/*name*/	_WT("������"),
/*explain*/	_WT("��ע��ı�����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���캽Ա->ע��ű�����	**	96
	{
/*name*/	_WT("��"),
/*explain*/	_WT("��ע�ắ������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(21,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** ˮ���캽Ա->ע��ű�����	**	97
	{
/*name*/	_WT("������"),
/*explain*/	_WT("��ע��ĺ�����"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->�ύ�ļ�	**	98
	{
/*name*/	_WT("�ļ���"),
/*explain*/	_WT("���ύ���ļ���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->�ύ�ֽڼ�	**	99
	{
/*name*/	_WT("����"),
/*explain*/	_WT("���ύ���ֽڼ����ݡ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BIN,
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->ɾ���ύ��	**	100
	{
/*name*/	_WT("��ɾ�����ύ��"),
/*explain*/	_WT("��ɾ�����ύ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(22,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** PostDataElement->�����ύ��	**	101
	{
/*name*/	_WT("��������ύ��"),
/*explain*/	_WT("��������ύ�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(22,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetURL	**	102
	{
/*name*/	_WT("Url"),
/*explain*/	_WT("Url"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetMethod	**	103
	{
/*name*/	_WT("method"),
/*explain*/	_WT("method"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetReferrer	**	104
	{
/*name*/	_WT("Url"),
/*explain*/	_WT("Url"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetReferrer	**	105
	{
/*name*/	_WT("policy"),
/*explain*/	_WT("policy"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetPostData	**	106
	{
/*name*/	_WT("Ԥ���õ�HTTP����"),
/*explain*/	_WT("postdata"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(23,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetHeaderMap	**	107
	{
/*name*/	_WT("Ԥ���õ�HTTP��ͷ"),
/*explain*/	_WT("header"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(5,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetFlag	**	108
	{
/*name*/	_WT("��־λ"),
/*explain*/	_WT("flag"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Request->SetFirstPartyForCookies	**	109
	{
/*name*/	_WT("url"),
/*explain*/	_WT("url"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Response->SetStatus	**	110
	{
/*name*/	_WT("HTTP״̬��"),
/*explain*/	_WT("statusCode"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Response->SetStatusText	**	111
	{
/*name*/	_WT("HTTP״̬�ı�"),
/*explain*/	_WT("statusText"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** Response->SetMimeType	**	112
	{
/*name*/	_WT("MIME����"),
/*explain*/	_WT("mimeType"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** JSDialogCallback->ȷ��	**	113
	{
/*name*/	_WT("OK"),
/*explain*/	_WT("���øöԻ����Ƿ���OK��ť��״̬������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** JSDialogCallback->ȷ��	**	114
	{
/*name*/	_WT("�����ı�"),
/*explain*/	_WT("���Ի�������Ϊ: prompt,ʱΪ���ṩ�����ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** FileDialogCallback->ȷ��	**	115
	{
/*name*/	_WT("����������"),
/*explain*/	_WT(" |����������| Ӧ���ǴӴ��ݸ�CefDialogHandler::OnFileDialog��accept filters������ѡ���ֵ�Ĵ�0��ʼ��������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** FileDialogCallback->ȷ��	**	116
	{
/*name*/	_WT("���յ��ļ����б�"),
/*explain*/	_WT("| ���յ��ļ����б�| Ӧ���ǵ���ֵ��ֵ�б�����ȡ���ڶԻ���ģʽ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(2,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->���Ͱ����¼�	**	117
	{
/*name*/	_WT("������Ϣ"),
/*explain*/	_WT("�����͵İ�����Ϣ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(36,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->����������¼�	**	118
	{
/*name*/	_WT("�����Ϣ"),
/*explain*/	_WT("�����͵������Ϣ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(37,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->����������¼�	**	119
	{
/*name*/	_WT("��������"),
/*explain*/	_WT("�����͵İ�������,�ο���������: #MOUSE_BUTTON_TYPE.xxx"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->����������¼�	**	120
	{
/*name*/	_WT("�Ƿ���"),
/*explain*/	_WT("�Ƿ�����갴��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->����������¼�	**	121
	{
/*name*/	_WT("�������"),
/*explain*/	_WT("�������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->��������ƶ��¼�	**	122
	{
/*name*/	_WT("�����Ϣ"),
/*explain*/	_WT("�����͵������Ϣ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(37,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->��������ƶ��¼�	**	123
	{
/*name*/	_WT("�Ƿ��뿪"),
/*explain*/	_WT("�Ƿ��뿪"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->�����������¼�	**	124
	{
/*name*/	_WT("�����Ϣ"),
/*explain*/	_WT("�����͵������Ϣ"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(37,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->�����������¼�	**	125
	{
/*name*/	_WT("X����"),
/*explain*/	_WT("����λ�õĹ�������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �������̨->�����������¼�	**	126
	{
/*name*/	_WT("Y����"),
/*explain*/	_WT("����λ�õĹ�������"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** BeforeDownloadCallback->ȷ��	**	127
	{
/*name*/	_WT("���λ��"),
/*explain*/	_WT("����Ŀ�������ļ�����ڴ����ϵ�λ�á�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	AS_DEFAULT_VALUE_IS_EMPTY,
	},
//****** BeforeDownloadCallback->ȷ��	**	128
	{
/*name*/	_WT("�����Ի���"),
/*explain*/	_WT("�Ƿ񵯳��ļ��Ի����ȡ���λ�á�"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** Frame->LoadRequest	**	129
	{
/*name*/	_WT("request"),
/*explain*/	_WT("�������request"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	MAKELONG(24,0),
/*default*/	0,
/*state*/	NULL,
	},
//****** AuthCallback->ȷ��	**	130
	{
/*name*/	_WT("�û���"),
/*explain*/	_WT("�����������¼ƾ֤"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** AuthCallback->ȷ��	**	131
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�����������¼ƾ֤"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��Ӳ˵�	**	132
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��Ӳ˵�	**	133
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�˵���ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��Ӷ�ѡ�˵�	**	134
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��Ӷ�ѡ�˵�	**	135
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�˵���ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��Ӷ�ѡ�˵�	**	136
	{
/*name*/	_WT("����ID"),
/*explain*/	_WT("group_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->����Ӳ˵�	**	137
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->����Ӳ˵�	**	138
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�˵���ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��ӵ�ѡ�˵�	**	139
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��ӵ�ѡ�˵�	**	140
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�˵���ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->ȡ����	**	141
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�ñ���	**	142
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�ñ���	**	143
	{
/*name*/	_WT("����"),
/*explain*/	_WT("�˵���ı���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->ȡ����	**	144
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�Ƿ�ѡ��	**	145
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��ѡ��	**	146
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->��ѡ��	**	147
	{
/*name*/	_WT("ѡ��"),
/*explain*/	_WT("�Ƿ�ѡ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�Ƿ����	**	148
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�ÿ���	**	149
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�ÿ���	**	150
	{
/*name*/	_WT("ѡ��"),
/*explain*/	_WT("�Ƿ�ѡ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->�Ƿ�����	**	151
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->������	**	152
	{
/*name*/	_WT("�˵�ID"),
/*explain*/	_WT("command_id"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	NULL,
	},
//****** �˵�ģ��->������	**	153
	{
/*name*/	_WT("ѡ��"),
/*explain*/	_WT("�Ƿ�ѡ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_BOOL,
/*default*/	0,
/*state*/	NULL,
	},
};

#endif
#endif