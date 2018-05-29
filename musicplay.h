#ifndef MUSICPLAY_H
#define MUSICPLAY_H

#include <QObject>
#include <QMediaPlayer>
class MusicPlay
{
public:
    MusicPlay();
    static QMediaPlayer *mediaPlayer;
    static void setPlayUrl(QString);
    static void play();


};

#endif // MUSICPLAY_H
