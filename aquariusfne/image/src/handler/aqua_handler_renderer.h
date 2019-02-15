#ifndef AQUA_HANDLER_RENDERER_H_
#define AQUA_HANDLER_RENDERER_H_
#include "utils\aqua_utils.h"

namespace AquaHandler {


	struct aqua_handler_renderer_t {

		///
		//	��CEF�����ĳ�ʼ���������������������UI�̡߳�
		///
		void (__stdcall *OnBeforeCommandLineProcessing) (const char *process_type, void *cmd);

		///
		//	��CEF�����ĳ�ʼ���������������������UI�̡߳�
		///
		void(__stdcall *OnContextInitialized)(void);

		///
		//	��Frame�ĵ�ַ�����仯ʱ���á�
		///
		void(__stdcall *OnAddressChange)(LPVOID browser,LPVOID frame,const char *url);

		///
		//	��ҳ�����ı�ʱ���á�
		///
		void(__stdcall *OnTitleChange)(LPVOID browser,const char *title);

		///
		//	��ҳ��ͼ�귢���仯ʱ���á�
		///
		void(__stdcall *OnFaviconURLChange)(LPVOID browser, LPVOID icon_urls);

		///
		//	��ҳ���е���ҳ�����л�Ϊȫ��ģʽʱ���á� ���|ȫ��| �����ݽ��Զ�������С������������������
		//	���|ȫ��| �Ǵ�������ݽ��Զ����ص���ԭʼ��С��λ�á� �����Ҫ���ͻ��˸������������Ĵ�С��
		///
		void(__stdcall *OnFullscreenModeChange)(LPVOID browser, bool fullscreen);

		///
		//	��������յ�״̬��Ϣʱ���á�|ֵ| ��������״̬��Ϣ����ʾ���ı���
		///
		void(__stdcall *OnStatusMessage)(LPVOID browser, const char *value);

		///
		//	��������ʾ����̨��Ϣ�� ����true��ֹͣ����Ϣ���������̨��
		///
		bool(__stdcall *OnConsoleMessage)(LPVOID browser, int level, const char *message, const char *source, int len);

		bool(__stdcall *OnBeforePopup)(LPVOID browser,LPVOID frame,
			const char *target_url,const char *target_frame_name,
			int target_disposition,bool user_gesture,
			LPVOID popupFeatures,LPVOID windowInfo,LPVOID bs,bool *no_javascript_access);

		void(__stdcall *OnAfterCreated)(LPVOID browser);

		bool(__stdcall *DoClose)(LPVOID browser);

		void(__stdcall *OnBeforeClose)(LPVOID browser);

		void(__stdcall *OnLoadingStateChange)(LPVOID browser,
			bool isLoading,
			bool canGoBack,
			bool canGoForward);

		void(__stdcall *OnLoadStart)(LPVOID browser,LPVOID frame,int transition_type);

		void(__stdcall *OnLoadEnd)(LPVOID browser, LPVOID frame, int httpStatusCode);

		void(__stdcall *OnLoadError)(LPVOID browser, LPVOID frame, int errorCode,
			const char* errorText, const char* failedUrl);

		void(__stdcall *OnContextCreated)(LPVOID browser);

		void(__stdcall *OnContextRelease)(LPVOID browser);

		bool(__stdcall *OnV8AccessorGet)(LPCSTR mainName,LPCSTR childName,LPVOID retval);

		bool(__stdcall *OnV8AccessorSet)(LPCSTR mainName, LPCSTR childName, LPVOID value);

		bool(__stdcall *OnV8AccessorExecute)(LPCSTR mainName, LPCSTR childName, int count, LPVOID argv, LPVOID retval);

		bool(__stdcall *OnBeforeResourceLoad)(LPVOID browser, LPVOID frame, LPVOID request, BOOL *is_coped);

		typedef void(CALLBACK *LPFN_REDIRECT_NEW_URL)(LPCSTR new_url,LPVOID params);
		void (__stdcall *OnResourceRedirect)(LPVOID browser,LPVOID frame,LPVOID request, LPFN_REDIRECT_NEW_URL callback,LPVOID params);


		void (__stdcall *OnResourceLoadComplete)(LPVOID browser,LPVOID frame,LPVOID request,LPVOID response,
			int status, __int64 received_content_length,void *data);

		bool(__stdcall *OnJSDialog)(LPVOID browser,
			LPCSTR origin_url,
			LPCSTR accept_lang,
			int dialog_type,
			LPCSTR message_text,
			LPCSTR default_prompt_text,
			LPVOID callback);

		bool(__stdcall *OnFileDialog)(LPVOID browser,
			int mode,
			LPCSTR title,
			LPCSTR default_file_path,
			LPVOID accept_filters,
			int selected_accept_filter,
			LPVOID callback);

		bool (__stdcall *OnPreKeyEvent)(LPVOID browser, LPVOID keyevent, bool* is_keyboard_shortcut);

		void (__stdcall *OnBeforeDownload)(LPVOID browser,LPVOID download_item,LPCSTR suggested_name,LPVOID callback);

		void (__stdcall *OnDownloadUpdated)(LPVOID browser,LPVOID download_item,LPVOID callback);

		bool (__stdcall *RunContextMenu)(LPVOID browser, LPVOID frame, int x, int y);

		bool (__stdcall *GetAuthCredentials)(LPVOID browser,LPVOID frame,bool isProxy,LPCSTR host,int port,LPCSTR realm,LPCSTR scheme,LPVOID callback);

		void (__stdcall *OnBeforeContextMenu)(LPVOID browser, LPVOID frame, LPVOID params, LPVOID model);

		bool (__stdcall *OnContextMenuCommand)(LPVOID browser, LPVOID frame, LPVOID params, int command_id);

		bool (__stdcall *OnBeforeBrowse)(LPVOID browser, LPVOID frame, LPVOID request, bool is_redirect);

		void(__stdcall *OnProtocolExecution)(LPVOID browser, const char *url, bool& allow_os_execution);

	};

	extern aqua_handler_renderer_t renderInterface;

	AQUAENTRY(void , Bind)(aqua_handler_renderer_t *renderEvents);
	

}
#endif