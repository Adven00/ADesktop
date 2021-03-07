// https://zhuanlan.zhihu.com/p/37877070

#ifndef WINAPI_H
#define WINAPI_H

#include <Windows.h>
#include <tchar.h>

#include <QWidget>

HWND GetWorkerW();

namespace WinAPI {
    void setWidgetBehindIcon(QWidget *widget);
    void hideConsoleWindow();
}

#endif // WINAPI_H
