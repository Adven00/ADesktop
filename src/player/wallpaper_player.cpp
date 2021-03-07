#include "wallpaper_player.h"

WallpaperPlayer::WallpaperPlayer(QWidget *parent) : QWidget(parent)
{
    output_is_occupied_ = false;
    setDefaultMediaPath();

    player_ = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    list_ = new QMediaPlaylist(this);

    list_->addMedia(media_url_);
    list_->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    player_->setPlaylist(list_);

    playWallpaper(); // todo
}

void WallpaperPlayer::setDefaultMediaPath() // todo
{
    QDir dir(QDir::currentPath());
    dir.cdUp();

    media_url_ =  QUrl::fromLocalFile(dir.path() + "/resource/video/test1.mp4");
}

void WallpaperPlayer::playWallpaper()
{
    if (!output_is_occupied_)
    {
        output_ = new QVideoWidget(this);

        output_->setFullScreen(true);
        WinAPI::setWidgetBehindIcon(output_);
        player_->setVideoOutput(output_);

        output_is_occupied_ = true;
    }

    player_->play();
}

void WallpaperPlayer::stopWallpaper()
{
    // todo
}


