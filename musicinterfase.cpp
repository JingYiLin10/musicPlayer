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
    this->setFixedSize(1000,645);

    //子部件创建
    musicNav = new Navigate;
    resultPreBtn = musicNav->getResultPreBtn();
    skinBtn = musicNav->getSkinBtn();
    skinDiaCloseBtn = musicNav->getSkinDialogCloseBtn();

    musicPlayControl = new PlayControl;
    musicList = new MusicList;
    musicSet = new MusicSet;

    musicCenterLayout = new QHBoxLayout;
    musicMainLayout = new QVBoxLayout;
    setLayout(musicMainLayout);


    QPalette pal;
    QString imgname = "../localMusic/陈一发儿/photo/cyfe4.jpg";
    QPixmap pixmap(imgname);
    pixmap = pixmap.scaled(QSize(1000, 645));
    pal.setBrush(QPalette::Background, QBrush(pixmap));
//    QPainter painter(this);
//    painter.drawPixmap(0,0,this->width(), this->height(), pixmap);
    this->setAutoFillBackground(true);
    this->setPalette(pal);


    musicPlay = new MusicPlay;  //只为生成静态，不使用


    mask = new QWidget;
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

void MusicInterfase::showMask()
{
    mask->setGeometry(0, 0, mask->width(), mask->height());
    mask->show();
}

void MusicInterfase::hideMask()
{
    mask->hide();
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
    //--skin
    mask->setFixedSize(1000,645);
    mask->setStyleSheet("QWidget{background-color:rgba(0,0,0,0.4);}");
    mask->setWindowFlags(Qt::FramelessWindowHint);
    mask->setParent(this);
    mask->hide();

    this->setWindowFlags(Qt::FramelessWindowHint);
}

void MusicInterfase::connectSlot()
{
    //--Nav
    connect(resultPreBtn, QPushButton::clicked, this, resultPre);
    connect(skinBtn, QPushButton::clicked, this, showMask);
    connect(skinDiaCloseBtn, QPushButton::clicked, this, hideMask);
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
