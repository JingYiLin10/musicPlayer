#include "skindialog.h"

/**
 * @author: jingbo
 * @date: 2018/05/29
 * @desc: 皮肤对话框
 */

SkinDialog::SkinDialog()
{
    nav = new QWidget;
    titleInfo = new QLabel;
    closeBtn = new QPushButton;


    navLayout = new QHBoxLayout;
    skinDialogLayout = new QVBoxLayout;


    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

QPushButton *SkinDialog::getCloseBtn()
{
    return closeBtn;
}

void SkinDialog::setControlsLayout()
{
    setFixedSize(550,440);
    navLayout->setMargin(0);
    navLayout->addSpacing(10);
    navLayout->addWidget(titleInfo);
    navLayout->addStretch();
    navLayout->addWidget(closeBtn);
    navLayout->addSpacing(10);
    nav->setLayout(navLayout);

    skinDialogLayout->setMargin(0);
    skinDialogLayout->setSpacing(0);
    skinDialogLayout->addWidget(nav);
    skinDialogLayout->addStretch();
    this->setLayout(skinDialogLayout);

}

void SkinDialog::setControlsForm()
{


    nav->setFixedSize(550,35);
    nav->setStyleSheet("background: #2CA9E1;");
    titleInfo->setText(tr("主题皮肤与窗口调整"));
    closeBtn->setFixedSize(20,20);
    closeBtn->setIconSize(QSize(20,20));
    closeBtn->setIcon(QIcon("../MusicSoft/img/close.png"));

    this->setWindowFlags(Qt::FramelessWindowHint);
}

void SkinDialog::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255));
    this->setPalette(palette);


    QFile file(QString("../MusicSoft/qss/skinDialog.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void SkinDialog::connectSlot()
{
    connect(closeBtn, QPushButton::clicked, this, close);
}

void SkinDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        pressFlag = true;
        beginPos = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void SkinDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(pressFlag){
        QPoint relPos(QCursor::pos() - beginPos);
        move(relPos);
    }
    QWidget::mouseMoveEvent(event);
}

void SkinDialog::mouseReleaseEvent(QMouseEvent *event)
{
    pressFlag = false;
    QWidget::mouseReleaseEvent(event);
}
