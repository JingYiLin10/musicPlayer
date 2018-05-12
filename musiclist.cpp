#include "musiclist.h"

MusicList::MusicList(QWidget *parent) : QWidget(parent)
{
    playListBtn = new QPushButton;
    cloudBtn = new QPushButton;
    downloadBtn = new QPushButton;
    searchBtn = new QPushButton;

    operNavLayout = new QHBoxLayout;
    operObjLayout = new QStackedLayout;
    musicListMainLayout = new QVBoxLayout;

    this->setFixedSize(310,527);
    this->setLayout(musicListMainLayout);

    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void MusicList::setControlsLayout()
{
    operNavLayout->setMargin(10);
    operNavLayout->setSpacing(0);
    operNavLayout->addSpacing(40);
    operNavLayout->addWidget(playListBtn);
    operNavLayout->addStretch();
    operNavLayout->addWidget(cloudBtn);
    operNavLayout->addStretch();
    operNavLayout->addWidget(downloadBtn);
    operNavLayout->addStretch();
    operNavLayout->addWidget(searchBtn);
    operNavLayout->addSpacing(40);

    musicListMainLayout->setMargin(0);
    musicListMainLayout->setSpacing(0);
    musicListMainLayout->addLayout(operNavLayout);
    musicListMainLayout->addStretch();

}

void MusicList::setControlsForm()
{
    playListBtn->setFixedSize(25,25);
    playListBtn->setIconSize(QSize(25,25));
    playListBtn->setIcon(QIcon("C:\\Users\\wjingbo\\Desktop\\MusicSoft\\img\\music1.png"));
    playListBtn->setCursor(QCursor(Qt::PointingHandCursor));

    cloudBtn->setFixedSize(25,25);
    cloudBtn->setIconSize(QSize(25,25));
    cloudBtn->setIcon(QIcon("C:\\Users\\wjingbo\\Desktop\\MusicSoft\\img\\cloud1.png"));
    cloudBtn->setCursor(QCursor(Qt::PointingHandCursor));

    downloadBtn->setFixedSize(25,25);
    downloadBtn->setIconSize(QSize(25,25));
    downloadBtn->setIcon(QIcon("C:\\Users\\wjingbo\\Desktop\\MusicSoft\\img\\download1.png"));
    downloadBtn->setCursor(QCursor(Qt::PointingHandCursor));

    searchBtn->setFixedSize(25,25);
    searchBtn->setIconSize(QSize(25,25));
    searchBtn->setIcon(QIcon("C:\\Users\\wjingbo\\Desktop\\MusicSoft\\img\\search1.png"));
    searchBtn->setCursor(QCursor(Qt::PointingHandCursor));

}

void MusicList::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255,20));
    this->setPalette(palette);
}

void MusicList::connectSlot()
{
    QFile file(QString("C:\\Users\\wjingbo\\Desktop\\MusicSoft\\qss\\musicList.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}
