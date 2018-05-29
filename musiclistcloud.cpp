#include "musiclistcloud.h"

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 音乐列表-云
 */

MusicListCloud::MusicListCloud(QWidget *parent) : QWidget(parent)
{
    icon = new QPushButton;
    prompt = new QLabel;
    useBtn = new QPushButton;

    iconLayout = new QHBoxLayout;
    promptLayout = new QHBoxLayout;
    useBtnLayout = new QHBoxLayout;
    musicListCloudMainLayout = new QVBoxLayout;

    setLayout(musicListCloudMainLayout);
    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void MusicListCloud::setControlsLayout()
{
    iconLayout->setMargin(0);
    iconLayout->setSpacing(0);
    promptLayout->setMargin(0);
    promptLayout->setSpacing(0);
    useBtnLayout->setMargin(0);
    useBtnLayout->setSpacing(0);
    musicListCloudMainLayout->setMargin(0);
    musicListCloudMainLayout->setSpacing(20);

    iconLayout->addStretch();
    iconLayout->addWidget(icon);
    iconLayout->addStretch();
    promptLayout->addStretch();
    promptLayout->addWidget(prompt);
    promptLayout->addStretch();
    useBtnLayout->addStretch();
    useBtnLayout->addWidget(useBtn);
    useBtnLayout->addStretch();
    musicListCloudMainLayout->addStretch(1);
    musicListCloudMainLayout->addLayout(iconLayout);
    musicListCloudMainLayout->addLayout(promptLayout);
    musicListCloudMainLayout->addLayout(useBtnLayout);
    musicListCloudMainLayout->addStretch(2);
}

void MusicListCloud::setControlsForm()
{
    icon->setFixedSize(175,115);
    icon->setIconSize(QSize(175,115));
    icon->setIcon(QIcon("../MusicSoft/img/cloud3.png"));

    prompt->setText(tr("云端备份 多屏同步"));

    useBtn->setFixedSize(170,35);
    useBtn->setText(tr("暂未开放"));
    useBtn->setStyleSheet("QPushButton{background: rgba(255,255,255,30);}"
                          "QPushButton:hover{background: rgba(255,255,255,60);}");
    useBtn->setCursor(QCursor(Qt::PointingHandCursor));

    this->setWindowFlags(Qt::FramelessWindowHint);
}

void MusicListCloud::setControlsStyle()
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

void MusicListCloud::connectSlot()
{

}
