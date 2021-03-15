#include <QApplication>
#include <QQmlApplicationEngine>

#include "player/wallpaper_player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine("E:/study/Computer/project/ADesktop/src/ui/test.qml");
    
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    WinAPI::hideConsoleWindow();

    return a.exec();
}