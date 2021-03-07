#include <QApplication>

#include "player/wallpaper_player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    WallpaperPlayer vw;
    vw.show();
    
    WinAPI::hideConsoleWindow();

    return a.exec();
}