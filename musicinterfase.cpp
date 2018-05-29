#include "musicinterfase.h"
#include "ui_musicinterfase.h"

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 音乐主界面框架
 */

MusicInterfase::MusicInterfase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicInterfase)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1000,645);

    //子部件创建
    musicNav = new Navigate;
    resultPreBtn = musicNav->getResultPreBtn();


    musicPlayControl = new PlayControl;
    musicList = new MusicList;
    musicSet = new MusicSet;

    musicCenterLayout = new QHBoxLayout;
    musicMainLayout = new QVBoxLayout;
    setLayout(musicMainLayout);


    QPalette pal;
    QString imgname = "../MusicSoft/img/theme3.jpg";
    QPixmap pixmap(imgname);
    pal.setBrush(QPalette::Background, QBrush(pixmap));
    this->setAutoFillBackground(true);
    this->setPalette(pal);



    setControlsLayout();
    setControlsForm();
    connectSlot();
}

MusicInterfase::~MusicInterfase()
{
    delete ui;
}

void MusicInterfase::resultPre()
{
    musicSet->resultPreIndex();
}

void MusicInterfase::setControlsLayout()
{
    musicCenterLayout->setMargin(0);
    musicCenterLayout->setSpacing(0);
    musicCenterLayout->addWidget(musicList);
    musicCenterLayout->addWidget(musicSet);

    musicMainLayout->setMargin(0);
    musicMainLayout->setSpacing(0);
    musicMainLayout->addWidget(musicNav);
    musicMainLayout->addLayout(musicCenterLayout);
    musicMainLayout->addWidget(musicPlayControl);
}

void MusicInterfase::setControlsForm()
{

    this->setWindowFlags(Qt::FramelessWindowHint);
}

void MusicInterfase::connectSlot()
{
    connect(resultPreBtn, QPushButton::clicked, this, resultPre);
}



//---------------------------------protected

void MusicInterfase::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        pressFlag = true;
        beginPos = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void MusicInterfase::mouseMoveEvent(QMouseEvent *event)
{
    if(pressFlag){
        QPoint relPos(QCursor::pos() - beginPos);
        move(relPos);
    }
    QWidget::mouseMoveEvent(event);
}

void MusicInterfase::mouseReleaseEvent(QMouseEvent *event)
{
    pressFlag = false;
    QWidget::mouseReleaseEvent(event);
}
