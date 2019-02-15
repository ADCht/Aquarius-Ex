#ifndef MENUPARAMS_H_
#define MENUPARAMS_H_

#include "lib2.h"
#include "wapper.h"

extern "C"
void aquarius_menuparams_getframeurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetFrameUrl(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetFrameUrl(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getlinkurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetLinkUrl(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetLinkUrl(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getsourceurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetSourceUrl(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetSourceUrl(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getpageurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetPageUrl(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetPageUrl(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getselectiontext (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetSelectionText(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetSelectionText(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getunfilteredlinkurl (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetUnfilteredLinkUrl(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetUnfilteredLinkUrl(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getframecharset (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaContextMenuGetFrameCharset(PPTR,NULL,0);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaContextMenuGetFrameCharset(PPTR,buf,len);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menuparams_getx (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaContextMenuGetXCoord(PPTR);
}

extern "C"
void aquarius_menuparams_gety (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaContextMenuGetYCoord(PPTR);
}

extern "C"
void aquarius_menumodel_getcount (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaMenuModelGetCount(PPTR);
}

extern "C"
void aquarius_menumodel_consturct (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_menumodel_copy (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaAddRef(*pArgInf[1].m_ppCompoundData);
	*pArgInf->m_ppCompoundData = *pArgInf[1].m_ppCompoundData;
}

extern "C"
void aquarius_menumodel_free (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	AquaRelease(*pArgInf->m_ppCompoundData);
	*pArgInf->m_ppCompoundData = NULL;
}

extern "C"
void aquarius_menumodel_addseparator (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelAddSeparator(PPTR);
}

extern "C"
void aquarius_menumodel_additem (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelAddItem(PPTR,pArgInf[1].m_int,pArgInf[2].m_pText);
}

extern "C"
void aquarius_menumodel_addradioitem (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelAddRadioItem(PPTR,pArgInf[1].m_int,pArgInf[2].m_pText,pArgInf[3].m_int);
}

extern "C"
void aquarius_menumodel_addsubitem (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	CAquariusWnd *pWnd = (CAquariusWnd*)TOWNDPTR(pArgInf);
	pRetData->m_ppCompoundData = (void**)g_fnAquaNotifySys(NRS_MALLOC,sizeof(LPVOID),0);
	*pRetData->m_ppCompoundData = NULL;
	LPVOID pMi = AquaMenuModelAddSubItem(PPTR,pArgInf[1].m_int,pArgInf[2].m_pText);
	if(pMi){
		*pRetData->m_ppCompoundData = pMi;
	}
}

extern "C"
void aquarius_menumodel_addcheckitem (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelAddCheckItem(PPTR,pArgInf[1].m_int,pArgInf[2].m_pText);
}

extern "C"
void aquarius_menumodel_getlabel (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	int len = AquaMenuModelGetLabel(PPTR,NULL,0,pArgInf[1].m_int);
	if(len > 0){
		char *buf = (char*)g_fnAquaNotifySys(NRS_MALLOC,len+1,0);
		AquaMenuModelGetLabel(PPTR,buf,len,pArgInf[1].m_int);
		buf[len]=0;
		pRetData->m_pText = buf;
	}
} 

extern "C"
void aquarius_menumodel_setlabel (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelSetLabel(PPTR,pArgInf[1].m_int,pArgInf[2].m_pText);
}

extern "C"
void aquarius_menumodel_gettype (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_int = AquaMenuModelGetType(PPTR,pArgInf[1].m_int);
}

extern "C"
void aquarius_menumodel_ischecked (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelIsChecked(PPTR,pArgInf[1].m_int);
}

extern "C"
void aquarius_menumodel_isvisible (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelIsVisible(PPTR,pArgInf[1].m_int);
}

extern "C"
void aquarius_menumodel_isenabled (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelIsEnabled(PPTR,pArgInf[1].m_int);
}

extern "C"
void aquarius_menumodel_setchecked (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelSetChecked(PPTR,pArgInf[1].m_int,pArgInf[2].m_bool);
}

extern "C"
void aquarius_menumodel_setvisible (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelSetVisible(PPTR,pArgInf[1].m_int,pArgInf[2].m_bool);
}

extern "C"
void aquarius_menumodel_setenabled (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf){
	AQUA_ASSERT();
	pRetData->m_bool = AquaMenuModelSetEnabled(PPTR,pArgInf[1].m_int,pArgInf[2].m_bool);
}

#endif