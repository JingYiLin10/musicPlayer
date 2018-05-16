#include "musiclistsearch.h"

/**
 * @author: jingbo
 * @date: 2018/05/16
 * @desc: 音乐列表-搜索
 */

MusicListSearch::MusicListSearch(QWidget *parent) : QWidget(parent)
{
    icon = new QPushButton;
    searchLine = new QLineEdit;
    searchBtn = new QPushButton;

    iconLayout = new QHBoxLayout;
    searchLineLayout = new QHBoxLayout;
    searchBtnLayout = new QHBoxLayout;

    musicListSearchMainLayout = new QVBoxLayout;


    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void MusicListSearch::setControlsLayout()
{
    iconLayout->setMargin(0);
    iconLayout->addStretch();
    iconLayout->addWidget(icon);
    iconLayout->addStretch();

    searchLineLayout->setMargin(0);
    searchLineLayout->addStretch();
    searchLineLayout->addWidget(searchLine);
    searchLineLayout->addStretch();

    searchBtnLayout->setMargin(0);
    searchBtnLayout->addStretch();
    searchBtnLayout->addWidget(searchBtn);
    searchBtnLayout->addStretch();

    musicListSearchMainLayout->setMargin(0);
    musicListSearchMainLayout->setSpacing(20);
    musicListSearchMainLayout->addStretch(1);
    musicListSearchMainLayout->addLayout(iconLayout);
    musicListSearchMainLayout->addLayout(searchLineLayout);
    musicListSearchMainLayout->addLayout(searchBtnLayout);
    musicListSearchMainLayout->addStretch(10);
    setLayout(musicListSearchMainLayout);
}

void MusicListSearch::setControlsForm()
{
    icon->setFixedSize(200,200);
    icon->setIconSize(QSize(200,200));
    icon->setIcon(QIcon("../MusicSoft/img/maxSearch.png"));

    searchLine->setFixedSize(240, 24);
    searchLine->addAction(QIcon("../MusicSoft/img/search2.png"), QLineEdit::LeadingPosition);

    searchBtn->setText(tr("搜索"));
    searchBtn->setFixedSize(130,30);
    searchBtn->setStyleSheet("QPushButton{background: rgba(255,255,255,30);}"
                          "QPushButton:hover{background: rgba(255,255,255,60);}");
    searchBtn->setCursor(QCursor(Qt::PointingHandCursor));

}

void MusicListSearch::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255,10));
    this->setPalette(palette);

    QFile file(QString("../MusicSoft/qss/musicListSearch.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void MusicListSearch::connectSlot()
{

}
