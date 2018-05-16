#include "playcontrol.h"

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 播放控制/其他按钮
 */

PlayControl::PlayControl(QWidget *parent) : QWidget(parent)
{
    preAMusicBtn = new QPushButton;
    pauseMusicBtn = new QPushButton;
    nextAMusicBtn = new QPushButton;

    musicInfo = new QLabel;
    musicTime = new QLabel;
    musicSchedule = new QSlider(Qt::Horizontal);

    likeBtn = new QPushButton;
    downloadBtn = new QPushButton;
    playModeBtn = new QPushButton;
    musicSound = new QPushButton;
    soundEffect = new QPushButton;
    lyrics = new QPushButton;
    playMusicList = new QPushButton;

    controlLayout = new QHBoxLayout;
    musicInfoTimeLayout = new QHBoxLayout;
    musicInfoScheduleLayout = new QVBoxLayout;
    otherActLayout = new QHBoxLayout;
    controlMainLayout = new QHBoxLayout;

    setLayout(controlMainLayout);
    setFixedHeight(68);
    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void PlayControl::likeBtnSlot()
{
    if(isLike){
        likeBtn->setIcon(QIcon("../MusicSoft/img/like1.png"));
        isLike = false;
    }
    else{
        likeBtn->setIcon(QIcon("../MusicSoft/img/like2.png"));
        isLike = true;
    }
}

void PlayControl::setControlsLayout()
{
    controlLayout->setMargin(10);
    controlLayout->setSpacing(20);//待调整数值
    controlLayout->addSpacing(10);
    controlLayout->addWidget(preAMusicBtn);
    controlLayout->addWidget(pauseMusicBtn);
    controlLayout->addWidget(nextAMusicBtn);

    musicInfoTimeLayout->setMargin(0);
    musicInfoTimeLayout->setSpacing(0);
    musicInfoTimeLayout->addWidget(musicInfo);
    musicInfoTimeLayout->addStretch();
    musicInfoTimeLayout->addWidget(musicTime);

    musicInfoScheduleLayout->setMargin(0);
    musicInfoScheduleLayout->setSpacing(5);//调整数值
    musicInfoScheduleLayout->addStretch();
    musicInfoScheduleLayout->addLayout(musicInfoTimeLayout);
    musicInfoScheduleLayout->addWidget(musicSchedule);
    musicInfoScheduleLayout->addStretch();

    otherActLayout->setMargin(20);
    otherActLayout->setSpacing(30);//调整数值
    otherActLayout->addWidget(likeBtn);
    otherActLayout->addWidget(downloadBtn);
    otherActLayout->addWidget(playModeBtn);
    otherActLayout->addWidget(musicSound);
    otherActLayout->addWidget(soundEffect);
    otherActLayout->addWidget(lyrics);
    otherActLayout->addWidget(playMusicList);

    controlMainLayout->setMargin(0);
    controlMainLayout->setSpacing(20);//调整数值
    controlMainLayout->addLayout(controlLayout);
    controlMainLayout->addLayout(musicInfoScheduleLayout);
    controlMainLayout->addStretch();
    controlMainLayout->addLayout(otherActLayout);
}

void PlayControl::setControlsForm()
{
    preAMusicBtn->setFixedSize(35,35);
    preAMusicBtn->setIconSize(QSize(15,15));
    preAMusicBtn->setIcon(QIcon("../MusicSoft/img/pre.png"));
    preAMusicBtn->setStyleSheet("border: 2px solid white;");
    preAMusicBtn->setCursor(QCursor(Qt::PointingHandCursor));

    pauseMusicBtn->setFixedSize(45,45);
    pauseMusicBtn->setIconSize(QSize(40,40));
    pauseMusicBtn->setIcon(QIcon("../MusicSoft/img/stop.png"));
    pauseMusicBtn->setStyleSheet("border-radius: 22px;border: 2px solid white;");
    pauseMusicBtn->setCursor(QCursor(Qt::PointingHandCursor));

    nextAMusicBtn->setFixedSize(35,35);
    nextAMusicBtn->setIconSize(QSize(15,15));
    nextAMusicBtn->setIcon(QIcon("../MusicSoft/img/next.png"));
    nextAMusicBtn->setStyleSheet("border: 2px solid white;");
    nextAMusicBtn->setCursor(QCursor(Qt::PointingHandCursor));

    musicInfo->setText(tr("music"));
    musicTime->setText(tr("00:00/00:00"));
    musicSchedule->setFixedWidth(365);
    musicSchedule->setCursor(QCursor(Qt::PointingHandCursor));

    likeBtn->setFixedSize(20,20);
    likeBtn->setIconSize(QSize(20,20));
    likeBtn->setIcon(QIcon("../MusicSoft/img/like1.png"));
    likeBtn->setCursor(QCursor(Qt::PointingHandCursor));
    isLike = false;

    downloadBtn->setFixedSize(20,20);
    downloadBtn->setIconSize(QSize(20,20));
    downloadBtn->setIcon(QIcon("../MusicSoft/img/download.png"));
    downloadBtn->setCursor(QCursor(Qt::PointingHandCursor));

    playModeBtn->setFixedSize(20,20);
    playModeBtn->setIconSize(QSize(20,20));
    playModeBtn->setIcon(QIcon("../MusicSoft/img/play1.png"));
    playModeBtn->setCursor(QCursor(Qt::PointingHandCursor));

    musicSound->setFixedSize(20,20);
    musicSound->setIconSize(QSize(20,20));
    musicSound->setIcon(QIcon("../MusicSoft/img/sound.png"));
    musicSound->setCursor(QCursor(Qt::PointingHandCursor));

    soundEffect->setFixedSize(50,20);
    soundEffect->setStyleSheet("border: 1px solid white; border-radius: 10px; color: white;");
    soundEffect->setText(tr("音 效"));
    soundEffect->setCursor(QCursor(Qt::PointingHandCursor));

    lyrics->setFixedSize(20, 20);
    lyrics->setText(tr("词"));
    lyrics->setStyleSheet("font: 16px; font-weight: bold; color: white; font-family: 黑体;");
    lyrics->setCursor(QCursor(Qt::PointingHandCursor));

    playMusicList->setFixedSize(20,20);
    playMusicList->setIconSize(QSize(20,20));
    playMusicList->setIcon(QIcon("../MusicSoft/img/cloud1.png"));
    playMusicList->setCursor(QCursor(Qt::PointingHandCursor));
}

void PlayControl::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255,40));
    this->setPalette(palette);

    QFile file(QString("../MusicSoft/qss/playcontrol.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void PlayControl::connectSlot()
{
    connect(likeBtn, QPushButton::clicked, this, likeBtnSlot);
}
