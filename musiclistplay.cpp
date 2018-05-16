#include "musiclistplay.h"

/**
 * @author: jingbo
 * @date: 2018/05/16
 * @desc: 音乐列表-播放列表
 */

MusicListPlay::MusicListPlay(QWidget *parent) : QWidget(parent)
{
    defaultPlayList = new QListView;
    recentPlayList = new QListView;
    defaultListBtn = new QPushButton;
    recentListBtn = new QPushButton;
    musicListPlayMainLayout = new QVBoxLayout;


    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void MusicListPlay::isShowList()
{
    QPushButton *senderBtn = qobject_cast<QPushButton *>(sender());
    if(senderBtn == defaultListBtn){
        if(isShowDefault){
            defaultPlayList->hide();
            isShowDefault = false;
            defaultListBtn->setIcon(QIcon("../MusicSoft/img/hideList.png"));
        }
        else{
            defaultPlayList->show();
            isShowDefault = true;
            defaultListBtn->setIcon(QIcon("../MusicSoft/img/showList.png"));
        }
    }
    else{
        if(isShowRecent){
            recentPlayList->hide();
            isShowRecent = false;
            recentListBtn->setIcon(QIcon("../MusicSoft/img/hideList.png"));
            recentListBtn->setStyleSheet("border-bottom: 1px solid rgba(255, 255, 255, 10%)");
        }
        else{
            recentPlayList->show();
            isShowRecent = true;
            recentListBtn->setIcon(QIcon("../MusicSoft/img/showList.png"));
            recentListBtn->setStyleSheet("border-bottom: 1px solid rgba(255, 255, 255, 0%)");
        }
    }

}

void MusicListPlay::setControlsLayout()
{
    musicListPlayMainLayout->setMargin(0);
    musicListPlayMainLayout->setSpacing(0);
    musicListPlayMainLayout->addWidget(defaultListBtn);
    musicListPlayMainLayout->addWidget(defaultPlayList);
    musicListPlayMainLayout->addWidget(recentListBtn);
    musicListPlayMainLayout->addWidget(recentPlayList);
    musicListPlayMainLayout->addStretch();
    setLayout(musicListPlayMainLayout);
}

void MusicListPlay::setControlsForm()
{
    defaultListBtn->setFixedSize(310,40);
    defaultListBtn->setIconSize(QSize(16,16));
    defaultListBtn->setIcon(QIcon("../MusicSoft/img/hideList.png"));
    defaultListBtn->setText(tr("默认列表  [2]"));
//    defaultListBtn->setStyleSheet("border-bottom: 1px solid rgba(255, 255, 255, 10%)");
    isShowDefault = false;
    recentListBtn->setFixedSize(310,40);
    recentListBtn->setIconSize(QSize(16,16));
    recentListBtn->setIcon(QIcon("../MusicSoft/img/hideList.png"));
    recentListBtn->setText(tr("最近播放  [2]"));
    recentListBtn->setStyleSheet("border-bottom: 1px solid rgba(255, 255, 255, 10%)");
    isShowRecent = false;

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *item = nullptr;
    QString infoPre = "", musicInfo;
    infoPre.resize(5, QChar(32));
    QString timeInfo = "00:00";
    musicInfo.resize(0);
    musicInfo = infoPre + "陈一发儿 - 阿婆说";
    musicInfo += "  \t\t";
    item = new QStandardItem(musicInfo + timeInfo);
    model->appendRow(item);

    musicInfo.resize(0);
    musicInfo = infoPre + "陈一发儿 - 童话镇aaaa";
    musicInfo += "  \t\t";
    item = new QStandardItem(musicInfo + timeInfo);
    model->appendRow(item);
    defaultPlayList->setModel(model);
    defaultPlayList->setFixedHeight(64);
    defaultPlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    defaultPlayList->hide();

    recentPlayList->setModel(model);
    recentPlayList->setFixedHeight(64 + 1); //底边框为1px, 动态设置高度需+1
    recentPlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    recentPlayList->hide();
    recentPlayList->setStyleSheet("border-bottom: 1px solid rgba(255, 255, 255, 10%)");
    recentPlayList->setSpacing(0);

}

void MusicListPlay::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255,0));
    this->setPalette(palette);

    QFile file(QString("../MusicSoft/qss/musicListPlay.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void MusicListPlay::connectSlot()
{
    connect(defaultListBtn, QPushButton::clicked, this, isShowList);
    connect(recentListBtn, QPushButton::clicked, this, isShowList);
}
