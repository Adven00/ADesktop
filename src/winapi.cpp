#include "winapi.h"

HWND _WORKERW = nullptr;

inline BOOL CALLBACK EnumWindowsProc(_In_ HWND tophandle, _In_ LPARAM topparamhandle) {
    HWND defview = FindWindowEx(tophandle, 0, _T("SHELLDLL_DefView"), nullptr);
    if (defview != nullptr) {
        _WORKERW = FindWindowEx(0, tophandle, _T("WorkerW"), 0);
    }
    return true;
}

HWND GetWorkerW() 
{
    HWND windowHandle = FindWindow(_T("Progman"), nullptr);
    SendMessageTimeout(windowHandle, 0x052c, 0 ,0, SMTO_NORMAL, 0x3e8, nullptr);
    EnumWindows(EnumWindowsProc, (LPARAM)nullptr);
    ShowWindow(_WORKERW, SW_HIDE);
    return windowHandle;
}

void WinAPI::putWidgetBehindIcon(QWidget *widget) 
{
    SetParent((HWND)(widget->winId()), GetWorkerW());
}

void WinAPI::hideConsoleWindow() 
{
	HWND hwnd = FindWindow(_T("ConsoleWindowClass"), nullptr);
	if (hwnd) {
		ShowWindow(hwnd, SW_HIDE);
	}
}
