#include "aqua_menu.h"
#include "include\cef_menu_model.h"
#include "include\cef_context_menu_handler.h"

#include "utils\aqua_conv.h"

using namespace AquaCef;

AQUAENTRYFULL(int, ContextMenu, GetFrameUrl)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetFrameUrl();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetLinkUrl)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetLinkUrl();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetSourceUrl)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetSourceUrl();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetPageUrl)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetPageUrl();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetSelectionText)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetSelectionText();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetUnfilteredLinkUrl)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetUnfilteredLinkUrl();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetFrameCharset)(LPVOID object, LPSTR buf, int len) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetFrameCharset();
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetXCoord)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		int result;
		p->AddRef();
		result = p->GetXCoord();
		p->Release();
		return result;
	}
	return 0;
}

AQUAENTRYFULL(int, ContextMenu, GetYCoord)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefContextMenuParams*>(object);
		int result;
		p->AddRef();
		result = p->GetYCoord();
		p->Release();
		return result;
	}
	return 0;
}

//-----------------------------------------------------------------------------------

AQUAENTRYFULL(int, MenuModel, GetCount)(LPVOID object) {
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		int result;
		p->AddRef();
		result = p->GetCount();
		p->Release();
		return result;
	}
	return 0;
}

AQUAENTRYFULL(BOOL, MenuModel, AddSeparator)(LPVOID object) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->AddSeparator();
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, AddItem)(LPVOID object, int command_id, LPCSTR label) {
	BOOL result = false;
	if (object) {
		aqua_convert conv;
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		auto pLabel = conv.from_bytes(label);
		result = p->AddItem(command_id, pLabel);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, AddRadioItem)(LPVOID object, int command_id, LPCSTR label, int group_id) {
	BOOL result = false;
	if (object) {
		aqua_convert conv;
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		auto pLabel = conv.from_bytes(label);
		result = p->AddRadioItem(command_id, pLabel, group_id);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(void, MenuModel, AddSubItem)(LPVOID object, int command_id, LPCSTR label, DWORD *pRetVal) {
	if (object) {
		aqua_convert conv;
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		auto pLabel = conv.from_bytes(label);
		CefRefPtr<CefMenuModel> SubMenu = p->AddSubMenu(command_id, pLabel);
		SubMenu->AddRef();
		pRetVal[1] = (DWORD)((LPVOID)SubMenu);
		p->Release();
	}
}

AQUAENTRYFULL(BOOL, MenuModel, AddCheckItem)(LPVOID object, int command_id, LPCSTR label) {
	BOOL result = false;
	if (object) {
		aqua_convert conv;
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		auto pLabel = conv.from_bytes(label);
		result = p->AddCheckItem(command_id, pLabel);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, MenuModel, GetLabel)(LPVOID object, LPSTR buf, int len, int command_id) {
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		aqua_convert conv;
		CefString path;
		p->AddRef();
		path = p->GetLabel(command_id);
		p->Release();
		if (path.length() > 0) {
			auto v = conv.to_bytes(path.c_str());
			if (len == 0) return v.length();
			else {
				memmove(buf, v.c_str(), v.length());
				return v.length();
			}
		}
	}
	return 0;
}

AQUAENTRYFULL(BOOL, MenuModel, SetLabel)(LPVOID object, int command_id, LPCSTR label) {
	BOOL result = false;
	if (object) {
		aqua_convert conv;
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		auto pLabel = conv.from_bytes(label);
		result = p->SetLabel(command_id, pLabel);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(int, MenuModel, GetType)(LPVOID object, int command_id) {
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		int result;
		p->AddRef();
		result = p->GetType(command_id);
		p->Release();
		return result;
	}
	return 0;
}

AQUAENTRYFULL(BOOL, MenuModel, IsChecked)(LPVOID object, int command_id) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->IsChecked(command_id);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, SetChecked)(LPVOID object, int command_id, bool checked) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->SetChecked(command_id, checked);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, IsVisible)(LPVOID object, int command_id) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->IsVisible(command_id);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, SetVisible)(LPVOID object, int command_id, bool visible) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->SetVisible(command_id, visible);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, IsEnabled)(LPVOID object, int command_id) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->IsEnabled(command_id);
		p->Release();
	}
	return result;
}

AQUAENTRYFULL(BOOL, MenuModel, SetEnabled)(LPVOID object, int command_id, bool enabled) {
	BOOL result = false;
	if (object) {
		auto p = reinterpret_cast<CefMenuModel*>(object);
		p->AddRef();
		result = p->SetEnabled(command_id, enabled);
		p->Release();
	}
	return result;
}