#ifndef AQUA_MENU_H_
#define AQUA_MENU_H_

#include "utils\aqua_utils.h"

namespace AquaCef {

	AQUAENTRYFULL(int, ContextMenu, GetFrameUrl)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetLinkUrl)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetSourceUrl)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetPageUrl)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetSelectionText)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetUnfilteredLinkUrl)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetFrameCharset)(LPVOID object, LPSTR buf, int len);

	AQUAENTRYFULL(int, ContextMenu, GetXCoord)(LPVOID object);

	AQUAENTRYFULL(int, ContextMenu, GetYCoord)(LPVOID object);

	//----------------------------------------------------------------------------------------------------

	AQUAENTRYFULL(int, MenuModel, GetCount)(LPVOID object);

	AQUAENTRYFULL(BOOL, MenuModel, AddSeparator)(LPVOID object);

	AQUAENTRYFULL(BOOL, MenuModel, AddItem)(LPVOID object, int command_id, LPCSTR label);

	AQUAENTRYFULL(BOOL, MenuModel, AddRadioItem)(LPVOID object, int command_id, LPCSTR label, int group_id);

	AQUAENTRYFULL(void, MenuModel, AddSubItem)(LPVOID object, int command_id, LPCSTR label, DWORD *pRetVal);

	AQUAENTRYFULL(BOOL, MenuModel, AddCheckItem)(LPVOID object, int command_id, LPCSTR label);

	AQUAENTRYFULL(int, MenuModel, GetLabel)(LPVOID object, LPSTR buf, int len, int command_id);

	AQUAENTRYFULL(BOOL, MenuModel, SetLabel)(LPVOID object, int command_id, LPCSTR label);

	AQUAENTRYFULL(int, MenuModel, GetType)(LPVOID object, int command_id);

	AQUAENTRYFULL(BOOL, MenuModel, IsChecked)(LPVOID object, int command_id);

	AQUAENTRYFULL(BOOL, MenuModel, SetChecked)(LPVOID object, int command_id, bool checked);

	AQUAENTRYFULL(BOOL, MenuModel, IsVisible)(LPVOID object, int command_id);

	AQUAENTRYFULL(BOOL, MenuModel, SetVisible)(LPVOID object, int command_id, bool visible);

	AQUAENTRYFULL(BOOL, MenuModel, IsEnabled)(LPVOID object, int command_id);

	AQUAENTRYFULL(BOOL, MenuModel, SetEnabled)(LPVOID object, int command_id, bool enabled);
}

#endif