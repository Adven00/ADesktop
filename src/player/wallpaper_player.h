#ifndef WALLPAPER_PLAYER_H
#define WALLPAPER_PLAYER_H

#include "utils/winapi.h"

#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QUrl>
#include <QDir>

class WallpaperPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit WallpaperPlayer(QWidget *parent = 0); // split

public slots:
    void playWallpaper();
    void stopWallpaper();
    
private:
    QUrl media_url_;
    bool output_is_occupied_;

    QMediaPlayer *player_;
    QMediaPlaylist *list_;
    QVideoWidget *output_;

    void setDefaultMediaPath();
};

#endif // WALLPAPER_PLAYER_H