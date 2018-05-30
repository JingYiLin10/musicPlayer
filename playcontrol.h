#ifndef PLAYCONTROL_H
#define PLAYCONTROL_H

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 播放控制/其他按钮
 */

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTimer>

#include "musicplay.h"

class PlayControl : public QWidget
{
    Q_OBJECT
public:
    explicit PlayControl(QWidget *parent = 0);

signals:

public slots:
    void likeBtnSlot();
    void pauseMusicSlot();
    void playTimeSlot();    //时间轴1秒
    void playStateStop();   //播放结束
private:
    QPushButton *preAMusicBtn;//上一首
    QPushButton *pauseMusicBtn;//暂停
    QPushButton *nextAMusicBtn;//下一首

    QLabel *musicInfo;
    QLabel *musicTime;
    QSlider *musicSchedule;

    QPushButton *likeBtn;
    QPushButton *downloadBtn;//下载
    QPushButton *playModeBtn;//模式
    QPushButton *musicSound;//音量
    QPushButton *lyrics;//歌词
    QPushButton *soundEffect;
    QPushButton *playMusicList;//播放列表

    //------Layout

    QHBoxLayout *controlLayout; //上/暂停/下控制
    QHBoxLayout *musicInfoTimeLayout;//信息/时间
    QVBoxLayout *musicInfoScheduleLayout;//进度
    QHBoxLayout *otherActLayout;//其他
    QHBoxLayout *controlMainLayout;//汇总

    //--------Function
    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();

    //----
    bool isLike;    //是否喜欢
    bool isPlay;    //是否播放

    //--播放控制
    QTimer * playTime;

};

#endif // PLAYCONTROL_H
