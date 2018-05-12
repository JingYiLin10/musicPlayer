#include "musicinterfase.h"
#include "ui_musicinterfase.h"

MusicInterfase::MusicInterfase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicInterfase)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1000,645);

    //子部件创建
    musicNav = new Navigate;
    musicPlayControl = new PlayControl;
    musicList = new MusicList;

    musicCenterLayout = new QHBoxLayout;
    musicMainLayout = new QVBoxLayout;
    setLayout(musicMainLayout);


    QPalette pal;
    QString imgname = "C:\\Users\\wjingbo\\Desktop\\MusicSoft\\img\\theme2.jpg";
    QPixmap pixmap(imgname);
    pal.setBrush(QPalette::Background, QBrush(pixmap));
    this->setAutoFillBackground(true);
    this->setPalette(pal);



    setControlsLayout();
    //setControlsForm();
}

MusicInterfase::~MusicInterfase()
{
    delete ui;
}

void MusicInterfase::setControlsLayout()
{
    musicCenterLayout->setMargin(0);
    musicCenterLayout->setSpacing(0);
    musicCenterLayout->addWidget(musicList);
    musicCenterLayout->addStretch();

    musicMainLayout->setMargin(0);
    musicMainLayout->setSpacing(0);
    musicMainLayout->addWidget(musicNav);
    musicMainLayout->addLayout(musicCenterLayout);
    musicMainLayout->addWidget(musicPlayControl);
}

void MusicInterfase::setControlsForm()
{
    musicList->setStyleSheet("background:red;");
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
