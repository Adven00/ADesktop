#ifndef WALLPAPER_PLAYER_H
#define WALLPAPER_PLAYER_H

#include "winapi.h"

#include <QUrl>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSystemTrayIcon>
#include <QApplication>
#include <QFileDialog>

#include <QDebug>

class WallpaperPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit WallpaperPlayer(QWidget *parent = 0);

public slots:
    void playWallpaper();
    void addWallpaper();

private:
    bool output_is_occupied_;

    QMediaPlayer *player_;
    QMediaPlaylist *list_;
    QVideoWidget *output_;
    QSystemTrayIcon *system_tray_icon_;

    void setDefaultMediaPath();
};

#endif // WALLPAPER_PLAYER_H