// pepper.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "pepper_renderer.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	CefMainArgs mainArgs(hPrevInstance);
	return CefExecuteProcess(mainArgs, (new PepperRenderer), NULL);
}
