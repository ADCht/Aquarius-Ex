#ifndef FUNC_H_
#define FUNC_H_

#include "strvectorfunc.h"
#include "int64vectorfunc.h"
#include "strdictfunc.h"
#include "strdictexfunc.h"
#include "windowinfofunc.h"
#include "requestcontextfunc.h"
#include "initialfunc.h"
#include "commandlinefunc.h"
#include "browserfunc.h"
#include "AquariusWnd.h"
#include "hostfunc.h"
#include "aquariusfunc.h"
#include "framefunc.h"
#include "documentfunc.h"
#include "cookiefunc.h"
#include "v8func.h"
#include "postdatafunc.h"
#include "requestfunc.h"
#include "responsefunc.h"
#include "jsdialogfunc.h"
#include "filedialogcallbackfunc.h"
#include "downloadfunc.h"
#include "callbackfunc.h"
#include "menufunc.h"

#include "wapper.h"

#ifndef __E_STATIC_LIB

PFN_EXECUTE_CMD s_RunFunc [] =	// 索引应与s_CmdInfo中的命令定义顺序对应
{
	aquarius_strvector_consturct,
	aquarius_strvector_free,
	aquarius_strvector_copy,
	aquarius_strvector_append,
	aquarius_strvector_replace,
	aquarius_strvector_remove,
	aquarius_strvector_clear,
	aquarius_strvector_get_bound,
	aquarius_strvector_get_element,
	aquarius_int64vector_consturct,
	aquarius_int64vector_free,
	aquarius_int64vector_copy,
	aquarius_int64vector_append,
	aquarius_int64vector_replace,
	aquarius_int64vector_remove,
	aquarius_int64vector_clear,
	aquarius_int64vector_get_bound,
	aquarius_int64vector_get_element,
	aquarius_browser_quitprocess,
	aquarius_strdict_consturct,
	aquarius_strdict_free,
	aquarius_strdict_copy,
	aquarius_strdict_insert,
	aquarius_strdict_find,
	aquarius_strdict_getbound,
	aquarius_strdict_getfirst,
	aquarius_strdict_getnext,
	aquarius_strdict_erase,
	aquarius_strdict_getkey,
	aquarius_strdict_getvalue,
	aquarius_strdict_remove,
	aquarius_strdict_clear,
	aquarius_strdictex_consturct,
	aquarius_strdictex_free,
	aquarius_strdictex_copy,
	aquarius_strdictex_insert,
	aquarius_strdictex_find,
	aquarius_strdictex_getbound,
	aquarius_strdictex_getfirst,
	aquarius_strdictex_getnext,
	aquarius_strdictex_erase,
	aquarius_strdictex_getkey,
	aquarius_strdictex_getvalue,
	aquarius_strdictex_remove,
	aquarius_strdictex_clear,
	aquarius_window_consturct,
	aquarius_window_free,
	aquarius_window_copy,
	aquarius_window_setaschild,
	aquarius_window_setaspopup,
	aquarius_window_setaswindowless,
	aquarius_window_modifystyle,
	aquarius_typercs_consturct,
	aquarius_typercs_free,
	aquarius_typercs_copy,
	aquarius_typercs_cachepath,
	aquarius_typercs_persistsessioncookies,
	aquarius_typercs_persistuserpreferences,
	aquarius_typercs_ignorecertificateerrors,
	aquarius_initial_initsettings,
	aquarius_commandline_consturct,
	aquarius_commandline_free,
	aquarius_commandline_copy,
	aquarius_commandline_attach,
	aquarius_commandline_isvalid,
	aquarius_commandline_isreadonly,
	aquarius_commandline_hasswitches,
	aquarius_commandline_hasSwitcha,
	aquarius_commandline_getswitchvaluea,
	aquarius_commandline_getswitches,
	aquarius_commandline_appendswitcha,
	aquarius_commandline_appendswitchwithvaluea,
	aquarius_commandline_getcommandlinestringa,
	aquarius_commandline_getglobalcommandline,
	aquarius_commandline_initfromstringa,
	aquarius_browser_createbrowser,
	aquarius_browser_querybrowser,
	aquarius_browser_consturct,
	aquarius_browser_free,
	aquarius_browser_copy,
	aquarius_browser_isvalid,
	aquarius_browser_gethost,
	aquarius_browser_cangoback,
	aquarius_browser_goback,
	aquarius_browser_cangoforward,
	aquarius_browser_goforward,
	aquarius_browser_isready,
	aquarius_browser_reload,
	aquarius_browser_reloadignorecache,
	aquarius_browser_stopload,
	aquarius_browser_gettabid,
	aquarius_browser_ispopup,
	aquarius_browser_hasdocument,
	aquarius_browser_getmainframe,
	aquarius_browser_getfocusframe,
	aquarius_browser_getframefromid,
	aquarius_browser_getframefromnamea,
	aquarius_browser_getframecount,
	aquarius_browser_getframeidentifiers,
	aquarius_browser_getframenames,
	aquarius_host_consturct,
	aquarius_host_free,
	aquarius_host_copy,
	aquarius_host_isvalid,
	aquarius_host_getbrowser,
	aquarius_host_closebrowser,
	aquarius_host_tryclosebrowser,
	aquarius_host_setfocus,
	aquarius_host_getwindowhandle,
	aquarius_host_getzoomlevel,
	aquarius_host_setzoomlevel,
	aquarius_host_startdownloada,
	aquarius_host_print,
	aquarius_host_showdevtools,
	aquarius_host_closedevtools,
	aquarius_host_hasdevtools,
	aquarius_host_setmousecursorchangedisabled,
	aquarius_host_ismousecursorchangedisabled,
	aquarius_host_iswindowrenderingdisabled,
	aquarius_host_wasresized,
	aquarius_host_washidden,
	aquarius_host_notifyscreeninfochanged,
	aquarius_host_sendfocusevent,
	aquarius_host_sendcapturelostevent,
	aquarius_host_notifymoveorresizestarted,
	aquarius_host_getwindowlessframerate,
	aquarius_host_setwindowlessframerate,
	aquarius_browser_setmainheroine,
	aquarius_frame_consturct,
	aquarius_frame_free,
	aquarius_frame_copy,
	aquarius_frame_isvalid,
	aquarius_frame_undo,
	aquarius_frame_redo,
	aquarius_frame_cut,
	aquarius_frame_copytext,
	aquarius_frame_paste,
	aquarius_frame_delete,
	aquarius_frame_selectall,
	aquarius_frame_getsource,
	aquarius_frame_gettext,
	aquarius_frame_loadurl,
	aquarius_frame_loadstring,
	aquarius_frame_executejavascript,
	aquarius_frame_ismain,
	aquarius_frame_isfocused,
	aquarius_frame_getname,
	aquarius_frame_getid,
	aquarius_frame_parent,
	aquarius_frame_geturl,
	aquarius_frame_getbrowser,
	aquarius_document_consturct,
	aquarius_document_free,
	aquarius_document_copy,
	aquarius_document_isvalid,
	aquarius_document_eval,
	aquarius_frame_getdocument,
	aquarius_browser_getcount,
	aquarius_browser_closeallbrowser,
	aquarius_browser_getadapter,
	aquarius_host_getcookiemanager,
	aquarius_cookiemanager_consturct,
	aquarius_cookiemanager_free,
	aquarius_cookiemanager_copy,
	aquarius_cookiemanager_isvalid,
	aquarius_cookiemanager_initfromglobal,
	aquarius_cookiemanager_getallcookies,
	aquarius_cookiemanager_geturlcookies,
	aquarius_cookiemanager_setcookie,
	aquarius_cookiemanager_deletecookie,
	aquarius_cookiemanager_flushstore,
	aquarius_cookiemanager_getcookiemerge,
	aquarius_cookiemanager_setcookiemerge,
	aquarius_strdict_setvalue,
	aquarius_strdictex_setvalue,
	aquarius_v8_consturct,
	aquarius_v8_copy,
	aquarius_v8_free,
	aquarius_v8_isvalid,
	aquarius_v8_gettype,
	aquarius_v8_getvalue,
	aquarius_v8_setvalue,
	aquarius_browser_regv8accessor,
	aquarius_browser_regv8var,
	aquarius_browser_regv8function,
	aquarius_document_getframe,
	aquarius_postdataelement_consturct,
	aquarius_postdataelement_free,
	aquarius_postdataelement_copy,
	aquarius_postdataelement_isvalid,
	aquarius_postdataelement_isreadnoly,
	aquarius_postdataelement_settoempty,
	aquarius_postdataelement_settofile,
	aquarius_postdataelement_settobytes,
	aquarius_postdataelement_gettype,
	aquarius_postdataelement_getfile,
	aquarius_postdataelement_getbytes,
	aquarius_postdata_consturct,
	aquarius_postdata_free,
	aquarius_postdata_copy,
	aquarius_postdata_isvalid,
	aquarius_postdata_isreadnoly,
	aquarius_postdata_hasexcludedelements,
	aquarius_postdata_getelementcount,
	aquarius_postdata_getelements,
	aquarius_postdata_removeelement,
	aquarius_postdata_addelement,
	aquarius_postdata_removeelements,
	aquarius_request_consturct,
	aquarius_request_free,
	aquarius_request_copy,
	aquarius_request_isvalid,
	aquarius_request_isreadyonly,
	aquarius_request_geturl,
	aquarius_request_seturl,
	aquarius_request_getmethod,
	aquarius_request_setmethod,
	aquarius_request_setreferrerurl,
	aquarius_request_getreferrer,
	aquarius_request_getreferrerpolicy,
	aquarius_request_getpostdata,
	aquarius_request_setpostdata,
	aquarius_request_getheadermap,
	aquarius_request_setheadermap,
	aquarius_request_getflags,
	aquarius_request_setflags,
	aquarius_request_getfirstpartyforcookies,
	aquarius_request_setfirstpartyforcookies,
	aquarius_request_getresourcetype,
	aquarius_response_consturct,
	aquarius_response_free,
	aquarius_response_copy,
	aquarius_response_isvalid,
	aquarius_response_isreadyonly,
	aquarius_response_getstatus,
	aquarius_response_setstatus,
	aquarius_response_getstatustext,
	aquarius_response_setstatustext,
	aquarius_response_getmimetype,
	aquarius_response_setmimetype,
	aquarius_response_getheadermap,
	aquarius_response_setheadermap,
	aquarius_frame_loadrequest,
	aquarius_jsdialogcallback_consturct,
	aquarius_jsdialogcallback_copy,
	aquarius_jsdialogcallback_free,
	aquarius_jsdialogcallback_isvalid,
	aquarius_jsdialogcallback_continue,
	aquarius_filedialogcallback_consturct,
	aquarius_filedialogcallback_copy,
	aquarius_filedialogcallback_free,
	aquarius_filedialogcallback_isvalid,
	aquarius_filedialogcallback_continue,
	aquarius_filedialogcallback_cancel,
	aquarius_host_sendkeyevent,
	aquarius_host_sendmouseclickevent,
	aquarius_host_sendmousemoveevent,
	aquarius_host_sendmousewheelevent,
	aquarius_downloaditem_consturct,
	aquarius_downloaditem_free,
	aquarius_downloaditem_copy,
	aquarius_downloaditem_isvalid,
	aquarius_downloaditem_isinprogress,
	aquarius_downloaditem_iscomplete,
	aquarius_downloaditem_iscanceled,
	aquarius_downloaditem_getcurrentspeed,
	aquarius_downloaditem_getpercentcomplete,
	aquarius_downloaditem_gettotalbytes,
	aquarius_downloaditem_getreceivebytes,
	aquarius_downloaditem_getstarttime,
	aquarius_downloaditem_getendtime,
	aquarius_downloaditem_getfullpath,
	aquarius_downloaditem_getid,
	aquarius_downloaditem_geturl,
	aquarius_downloaditem_getoriginalurl,
	aquarius_downloaditem_getsuggestedfilename,
	aquarius_downloaditem_getcontentdisposition,
	aquarius_downloaditem_getmimetype,
	aquarius_beforedownloadcallback_consturct,
	aquarius_beforedownloadcallback_free,
	aquarius_beforedownloadcallback_copy,
	aquarius_beforedownloadcallback_isvalid,
	aquarius_beforedownloadcallback_continue,
	aquarius_downloaditemcallback_consturct,
	aquarius_downloaditemcallback_free,
	aquarius_downloaditemcallback_copy,
	aquarius_downloaditemcallback_isvalid,
	aquarius_downloaditemcallback_cancel,
	aquarius_downloaditemcallback_pause,
	aquarius_downloaditemcallback_resume,
	aquarius_authcallback_consturct,
	aquarius_authcallback_copy,
	aquarius_authcallback_free,
	aquarius_authcallback_isvalid,
	aquarius_authcallback_continue,
	aquarius_authcallback_cancel,
	aquarius_initial_initsettings,
	NULL,
	NULL,
	NULL,
	NULL,
	aquarius_menuparams_getframeurl,
	aquarius_menuparams_getlinkurl,
	aquarius_menuparams_getsourceurl,
	aquarius_menuparams_getpageurl,
	aquarius_menuparams_getselectiontext,
	aquarius_menuparams_getunfilteredlinkurl,
	aquarius_menuparams_getframecharset,
	aquarius_menuparams_getx,
	aquarius_menuparams_gety,
	aquarius_menumodel_getcount,
	aquarius_menumodel_addseparator,
	aquarius_menumodel_additem,
	aquarius_menumodel_addradioitem,
	aquarius_menumodel_addsubitem,
	aquarius_menumodel_addcheckitem,
	aquarius_menumodel_getlabel,
	aquarius_menumodel_setlabel,
	aquarius_menumodel_gettype,
	aquarius_menumodel_ischecked,
	aquarius_menumodel_setchecked,
	aquarius_menumodel_isvisible,
	aquarius_menumodel_setvisible,
	aquarius_menumodel_isenabled,
	aquarius_menumodel_setenabled,
	aquarius_menumodel_consturct,
	aquarius_menumodel_free,
	aquarius_menumodel_copy,
	aquarius_run_message_loop,
	aquarius_quit_message_loop
};

static const char* const g_CmdNames[] = 
{
	"aquarius_strvector_consturct",
	"aquarius_strvector_free",
	"aquarius_strvector_copy",
	"aquarius_strvector_append",
	"aquarius_strvector_replace",
	"aquarius_strvector_remove",
	"aquarius_strvector_clear",
	"aquarius_strvector_get_bound",
	"aquarius_strvector_get_element",
	"aquarius_int64vector_consturct",
	"aquarius_int64vector_free",
	"aquarius_int64vector_copy",
	"aquarius_int64vector_append",
	"aquarius_int64vector_replace",
	"aquarius_int64vector_remove",
	"aquarius_int64vector_clear",
	"aquarius_int64vector_get_bound",
	"aquarius_int64vector_get_element",
	"aquarius_browser_quitprocess",
	"aquarius_strdict_consturct",
	"aquarius_strdict_free",
	"aquarius_strdict_copy",
	"aquarius_strdict_insert",
	"aquarius_strdict_find",
	"aquarius_strdict_getbound",
	"aquarius_strdict_getfirst",
	"aquarius_strdict_getnext",
	"aquarius_strdict_erase",
	"aquarius_strdict_getkey",
	"aquarius_strdict_getvalue",
	"aquarius_strdict_remove",
	"aquarius_strdict_clear",
	"aquarius_strdictex_consturct",
	"aquarius_strdictex_free",
	"aquarius_strdictex_copy",
	"aquarius_strdictex_insert",
	"aquarius_strdictex_find",
	"aquarius_strdictex_getbound",
	"aquarius_strdictex_getfirst",
	"aquarius_strdictex_getnext",
	"aquarius_strdictex_erase",
	"aquarius_strdictex_getkey",
	"aquarius_strdictex_getvalue",
	"aquarius_strdictex_remove",
	"aquarius_strdictex_clear",
	"aquarius_window_consturct",
	"aquarius_window_free",
	"aquarius_window_copy",
	"aquarius_window_setaschild",
	"aquarius_window_setaspopup",
	"aquarius_window_setaswindowless",
	"aquarius_window_modifystyle",
	"aquarius_typercs_consturct",
	"aquarius_typercs_free",
	"aquarius_typercs_copy",
	"aquarius_typercs_cachepath",
	"aquarius_typercs_persistsessioncookies",
	"aquarius_typercs_persistuserpreferences",
	"aquarius_typercs_ignorecertificateerrors",
	"aquarius_initial_initsettings",
	"aquarius_commandline_consturct",
	"aquarius_commandline_free",
	"aquarius_commandline_copy",
	"aquarius_commandline_attach",
	"aquarius_commandline_isvalid",
	"aquarius_commandline_isreadonly",
	"aquarius_commandline_hasswitches",
	"aquarius_commandline_hasSwitcha",
	"aquarius_commandline_getswitchvaluea",
	"aquarius_commandline_getswitches",
	"aquarius_commandline_appendswitcha",
	"aquarius_commandline_appendswitchwithvaluea",
	"aquarius_commandline_getcommandlinestringa",
	"aquarius_commandline_getglobalcommandline",
	"aquarius_commandline_initfromstringa",
	"aquarius_browser_createbrowser",
	"aquarius_browser_querybrowser",
	"aquarius_browser_consturct",
	"aquarius_browser_free",
	"aquarius_browser_copy",
	"aquarius_browser_isvalid",
	"aquarius_browser_gethost",
	"aquarius_browser_cangoback",
	"aquarius_browser_goback",
	"aquarius_browser_cangoforward",
	"aquarius_browser_goforward",
	"aquarius_browser_isready",
	"aquarius_browser_reload",
	"aquarius_browser_reloadignorecache",
	"aquarius_browser_stopload",
	"aquarius_browser_gettabid",
	"aquarius_browser_ispopup",
	"aquarius_browser_hasdocument",
	"aquarius_browser_getmainframe",
	"aquarius_browser_getfocusframe",
	"aquarius_browser_getframefromid",
	"aquarius_browser_getframefromnamea",
	"aquarius_browser_getframecount",
	"aquarius_browser_getframeidentifiers",
	"aquarius_browser_getframenames",
	"aquarius_host_consturct",
	"aquarius_host_free",
	"aquarius_host_copy",
	"aquarius_host_isvalid",
	"aquarius_host_getbrowser",
	"aquarius_host_closebrowser",
	"aquarius_host_tryclosebrowser",
	"aquarius_host_setfocus",
	"aquarius_host_getwindowhandle",
	"aquarius_host_getzoomlevel",
	"aquarius_host_setzoomlevel",
	"aquarius_host_startdownloada",
	"aquarius_host_print",
	"aquarius_host_showdevtools",
	"aquarius_host_closedevtools",
	"aquarius_host_hasdevtools",
	"aquarius_host_setmousecursorchangedisabled",
	"aquarius_host_ismousecursorchangedisabled",
	"aquarius_host_iswindowrenderingdisabled",
	"aquarius_host_wasresized",
	"aquarius_host_washidden",
	"aquarius_host_notifyscreeninfochanged",
	"aquarius_host_sendfocusevent",
	"aquarius_host_sendcapturelostevent",
	"aquarius_host_notifymoveorresizestarted",
	"aquarius_host_getwindowlessframerate",
	"aquarius_host_setwindowlessframerate",
	"aquarius_browser_setmainheroine",
	"aquarius_frame_consturct",
	"aquarius_frame_free",
	"aquarius_frame_copy",
	"aquarius_frame_isvalid",
	"aquarius_frame_undo",
	"aquarius_frame_redo",
	"aquarius_frame_cut",
	"aquarius_frame_copytext",
	"aquarius_frame_paste",
	"aquarius_frame_delete",
	"aquarius_frame_selectall",
	"aquarius_frame_getsource",
	"aquarius_frame_gettext",
	"aquarius_frame_loadurl",
	"aquarius_frame_loadstring",
	"aquarius_frame_executejavascript",
	"aquarius_frame_ismain",
	"aquarius_frame_isfocused",
	"aquarius_frame_getname",
	"aquarius_frame_getid",
	"aquarius_frame_parent",
	"aquarius_frame_geturl",
	"aquarius_frame_getbrowser",
	"aquarius_document_consturct",
	"aquarius_document_free",
	"aquarius_document_copy",
	"aquarius_document_isvalid",
	"aquarius_document_eval",
	"aquarius_frame_getdocument",
	"aquarius_browser_getcount",
	"aquarius_browser_closeallbrowser",
	"aquarius_browser_getadapter",
	"aquarius_host_getcookiemanager",
	"aquarius_cookiemanager_consturct",
	"aquarius_cookiemanager_free",
	"aquarius_cookiemanager_copy",
	"aquarius_cookiemanager_isvalid",
	"aquarius_cookiemanager_initfromglobal",
	"aquarius_cookiemanager_getallcookies",
	"aquarius_cookiemanager_geturlcookies",
	"aquarius_cookiemanager_setcookie",
	"aquarius_cookiemanager_deletecookie",
	"aquarius_cookiemanager_flushstore",
	"aquarius_cookiemanager_getcookiemerge",
	"aquarius_cookiemanager_setcookiemerge",
	"aquarius_strdict_setvalue",
	"aquarius_strdictex_setvalue",
	"aquarius_v8_consturct",
	"aquarius_v8_copy",
	"aquarius_v8_free",
	"aquarius_v8_isvalid",
	"aquarius_v8_gettype",
	"aquarius_v8_getvalue",
	"aquarius_v8_setvalue",
	"aquarius_browser_regv8accessor",
	"aquarius_browser_regv8var",
	"aquarius_browser_regv8function",
	"aquarius_document_getframe",
	"aquarius_postdataelement_consturct",
	"aquarius_postdataelement_free",
	"aquarius_postdataelement_copy",
	"aquarius_postdataelement_isvalid",
	"aquarius_postdataelement_isreadnoly",
	"aquarius_postdataelement_settoempty",
	"aquarius_postdataelement_settofile",
	"aquarius_postdataelement_settobytes",
	"aquarius_postdataelement_gettype",
	"aquarius_postdataelement_getfile",
	"aquarius_postdataelement_getbytes",
	"aquarius_postdata_consturct",
	"aquarius_postdata_free",
	"aquarius_postdata_copy",
	"aquarius_postdata_isvalid",
	"aquarius_postdata_isreadnoly",
	"aquarius_postdata_hasexcludedelements",
	"aquarius_postdata_getelementcount",
	"aquarius_postdata_getelements",
	"aquarius_postdata_removeelement",
	"aquarius_postdata_addelement",
	"aquarius_postdata_removeelements",
	"aquarius_request_consturct",
	"aquarius_request_free",
	"aquarius_request_copy",
	"aquarius_request_isvalid",
	"aquarius_request_isreadyonly",
	"aquarius_request_geturl",
	"aquarius_request_seturl",
	"aquarius_request_getmethod",
	"aquarius_request_setmethod",
	"aquarius_request_setreferrerurl",
	"aquarius_request_getreferrer",
	"aquarius_request_getreferrerpolicy",
	"aquarius_request_getpostdata",
	"aquarius_request_setpostdata",
	"aquarius_request_getheadermap",
	"aquarius_request_setheadermap",
	"aquarius_request_getflags",
	"aquarius_request_setflags",
	"aquarius_request_getfirstpartyforcookies",
	"aquarius_request_setfirstpartyforcookies",
	"aquarius_request_getresourcetype",
	"aquarius_response_consturct",
	"aquarius_response_free",
	"aquarius_response_copy",
	"aquarius_response_isvalid",
	"aquarius_response_isreadyonly",
	"aquarius_response_getstatus",
	"aquarius_response_setstatus",
	"aquarius_response_getstatustext",
	"aquarius_response_setstatustext",
	"aquarius_response_getmimetype",
	"aquarius_response_setmimetype",
	"aquarius_response_getheadermap",
	"aquarius_response_setheadermap",
	"aquarius_frame_loadrequest",
	"aquarius_jsdialogcallback_consturct",
	"aquarius_jsdialogcallback_copy",
	"aquarius_jsdialogcallback_free",
	"aquarius_jsdialogcallback_isvalid",
	"aquarius_jsdialogcallback_continue",
	"aquarius_filedialogcallback_consturct",
	"aquarius_filedialogcallback_copy",
	"aquarius_filedialogcallback_free",
	"aquarius_filedialogcallback_isvalid",
	"aquarius_filedialogcallback_continue",
	"aquarius_filedialogcallback_cancel",
	"aquarius_host_sendkeyevent",
	"aquarius_host_sendmouseclickevent",
	"aquarius_host_sendmousemoveevent",
	"aquarius_host_sendmousewheelevent",
	"aquarius_downloaditem_consturct",
	"aquarius_downloaditem_free",
	"aquarius_downloaditem_copy",
	"aquarius_downloaditem_isvalid",
	"aquarius_downloaditem_isinprogress",
	"aquarius_downloaditem_iscomplete",
	"aquarius_downloaditem_iscanceled",
	"aquarius_downloaditem_getcurrentspeed",
	"aquarius_downloaditem_getpercentcomplete",
	"aquarius_downloaditem_gettotalbytes",
	"aquarius_downloaditem_getreceivebytes",
	"aquarius_downloaditem_getstarttime",
	"aquarius_downloaditem_getendtime",
	"aquarius_downloaditem_getfullpath",
	"aquarius_downloaditem_getid",
	"aquarius_downloaditem_geturl",
	"aquarius_downloaditem_getoriginalurl",
	"aquarius_downloaditem_getsuggestedfilename",
	"aquarius_downloaditem_getcontentdisposition",
	"aquarius_downloaditem_getmimetype",
	"aquarius_beforedownloadcallback_consturct",
	"aquarius_beforedownloadcallback_free",
	"aquarius_beforedownloadcallback_copy",
	"aquarius_beforedownloadcallback_isvalid",
	"aquarius_beforedownloadcallback_continue",
	"aquarius_downloaditemcallback_consturct",
	"aquarius_downloaditemcallback_free",
	"aquarius_downloaditemcallback_copy",
	"aquarius_downloaditemcallback_isvalid",
	"aquarius_downloaditemcallback_cancel",
	"aquarius_downloaditemcallback_pause",
	"aquarius_downloaditemcallback_resume",
	"aquarius_authcallback_consturct",
	"aquarius_authcallback_copy",
	"aquarius_authcallback_free",
	"aquarius_authcallback_isvalid",
	"aquarius_authcallback_continue",
	"aquarius_authcallback_cancel",
	"aquarius_initial_initsettings",
	"NULL",
	"NULL",
	"NULL",
	"NULL",
	"aquarius_menuparams_getframeurl",
	"aquarius_menuparams_getlinkurl",
	"aquarius_menuparams_getsourceurl",
	"aquarius_menuparams_getpageurl",
	"aquarius_menuparams_getselectiontext",
	"aquarius_menuparams_getunfilteredlinkurl",
	"aquarius_menuparams_getframecharset",
	"aquarius_menuparams_getx",
	"aquarius_menuparams_gety",
	"aquarius_menumodel_getcount",
	"aquarius_menumodel_addseparator",
	"aquarius_menumodel_additem",
	"aquarius_menumodel_addradioitem",
	"aquarius_menumodel_addsubitem",
	"aquarius_menumodel_addcheckitem",
	"aquarius_menumodel_getlabel",
	"aquarius_menumodel_setlabel",
	"aquarius_menumodel_gettype",
	"aquarius_menumodel_ischecked",
	"aquarius_menumodel_setchecked",
	"aquarius_menumodel_isvisible",
	"aquarius_menumodel_setvisible",
	"aquarius_menumodel_isenabled",
	"aquarius_menumodel_setenabled",
	"aquarius_menumodel_consturct",
	"aquarius_menumodel_free",
	"aquarius_menumodel_copy",
	"aquarius_run_message_loop",
	"aquarius_quit_message_loop"
};

#endif
#endif