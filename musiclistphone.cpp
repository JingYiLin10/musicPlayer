#include "musiclistphone.h"

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 音乐列表-手机
 */

MusicListPhone::MusicListPhone(QWidget *parent) : QWidget(parent)
{
    selectInfo = new QLabel;
    wiredConnBtn = new QPushButton;
    wifiConnBtn = new QPushButton;

    selectInfoLayout = new QHBoxLayout;
    wiredConnBtnlayout = new QHBoxLayout;
    wifiConnBtnLayout = new QHBoxLayout;
    musicListPhoneMainLayout = new QVBoxLayout;

    setLayout(musicListPhoneMainLayout);
    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void MusicListPhone::setControlsLayout()
{
    selectInfoLayout->setMargin(0);
    selectInfoLayout->setSpacing(0);
    wiredConnBtnlayout->setMargin(0);
    wiredConnBtnlayout->setSpacing(0);
    wifiConnBtnLayout->setMargin(0);
    wifiConnBtnLayout->setSpacing(0);
    musicListPhoneMainLayout->setMargin(0);
    musicListPhoneMainLayout->setSpacing(0);

    selectInfoLayout->addStretch();
    selectInfoLayout->addWidget(selectInfo);
    selectInfoLayout->addStretch();\
    wiredConnBtnlayout->addStretch();
    wiredConnBtnlayout->addWidget(wiredConnBtn);
    wiredConnBtnlayout->addStretch();
    wifiConnBtnLayout->addStretch();
    wifiConnBtnLayout->addWidget(wifiConnBtn);
    wifiConnBtnLayout->addStretch();
    musicListPhoneMainLayout->addStretch(2);
    musicListPhoneMainLayout->addLayout(selectInfoLayout);
    musicListPhoneMainLayout->addStretch(1);
    musicListPhoneMainLayout->addLayout(wiredConnBtnlayout);
    musicListPhoneMainLayout->addStretch(1);
    musicListPhoneMainLayout->addLayout(wifiConnBtnLayout);
    musicListPhoneMainLayout->addStretch(8);
}

void MusicListPhone::setControlsForm()
{
    selectInfo->setText(tr("请选择连接手机的方式"));
    wiredConnBtn->setFixedSize(205,100);
    wiredConnBtn->setIconSize(QSize(45,45));
    wiredConnBtn->setIcon(QIcon("../MusicSoft/img/jack.png"));
    wiredConnBtn->setText(tr(" 有线连接"));
    wiredConnBtn->setStyleSheet("QPushButton{background: rgba(255,255,255,30);}"
                                "QPushButton:hover{background: rgba(255,255,255,60);}");
    wiredConnBtn->setCursor(QCursor(Qt::PointingHandCursor));


    wifiConnBtn->setFixedSize(205,100);
    wifiConnBtn->setIconSize(QSize(45,45));
    wifiConnBtn->setIcon(QIcon("../MusicSoft/img/wifi.png"));
    wifiConnBtn->setText(tr(" 无线连接"));
    wifiConnBtn->setStyleSheet("QPushButton{background: rgba(255,255,255,30);}"
                                "QPushButton:hover{background: rgba(255,255,255,60);}");
    wifiConnBtn->setCursor(QCursor(Qt::PointingHandCursor));

    this->setWindowFlags(Qt::FramelessWindowHint);
}

void MusicListPhone::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255,10));
    this->setPalette(palette);

    QFile file(QString("../MusicSoft/qss/musicListCloud.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void MusicListPhone::connectSlot()
{

}
