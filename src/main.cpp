#include <QApplication>

#include "wallpaper_player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    
    WallpaperPlayer p;
    WinAPI::hideConsoleWindow();

    return a.exec();
}