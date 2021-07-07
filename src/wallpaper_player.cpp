#include "wallpaper_player.h"

WallpaperPlayer::WallpaperPlayer(QWidget *parent) : QWidget(parent)
{
    // player 
    output_is_occupied_ = false;
    player_ = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    list_ = new QMediaPlaylist(this);
    list_->addMedia(QUrl::fromLocalFile("../resource/video/test1.mp4"));
    list_->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player_->setPlaylist(list_);
    player_->setVolume(0);

    // system trsy icon
    QMenu *system_tray_menu_ = new QMenu(this);
    QAction *close = new QAction("close", system_tray_menu_);
    QAction *play = new QAction("play", system_tray_menu_);
    QAction *change = new QAction("change", system_tray_menu_);
    system_tray_menu_->addAction(close);
    system_tray_menu_->addAction(play);
    system_tray_menu_->addAction(change);

    connect(close, &QAction::triggered, qApp, &QApplication::quit);
    connect(play, &QAction::triggered, this, &WallpaperPlayer::playWallpaper);
    connect(change, &QAction::triggered, this, &WallpaperPlayer::changeWallpaper);

    system_tray_icon_ = new QSystemTrayIcon(this);
    system_tray_icon_->setIcon(QIcon("../resource/icon.ico"));
    system_tray_icon_->setToolTip("ADesktop"); 
    system_tray_icon_->setContextMenu(system_tray_menu_);
    system_tray_icon_->show();
}

void WallpaperPlayer::playWallpaper()
{
    if (!output_is_occupied_)
    {
        output_ = new QVideoWidget(this);

        output_->setFullScreen(true);
        WinAPI::putWidgetBehindIcon(output_);
        player_->setVideoOutput(output_);

        output_is_occupied_ = true;
    }

    player_->play();
}

void WallpaperPlayer::changeWallpaper()
{
    QUrl new_media = QFileDialog::getOpenFileUrl(this, 
                                             "Select a video", 
                                             QUrl::fromLocalFile("../resource/video"),
                                             "Videos (*.mkv *.mp4)");

    if (!new_media.isEmpty())
    {
        list_->clear();
        list_->addMedia(new_media);
        player_->setPlaylist(list_);

        delete output_;
        output_is_occupied_ = false;
    }
}
