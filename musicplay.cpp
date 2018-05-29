#include "musicplay.h"

MusicPlay::MusicPlay()
{

}

void MusicPlay::setPlayUrl(QString url)
{
    MusicPlay::mediaPlayer->setMedia(QUrl::fromLocalFile(url));
}

void MusicPlay::play()
{
    MusicPlay::mediaPlayer->play();
}

QMediaPlayer *MusicPlay::mediaPlayer = new QMediaPlayer;
