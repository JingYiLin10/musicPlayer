#include "navigate.h"

Navigate::Navigate(QWidget *parent) : QWidget(parent)
{
    navIcon = new QPushButton;
    loginBtn = new QPushButton;
    cut  = new QLabel;
    registBtn = new QPushButton;
    resultBtn = new QPushButton;
    updateBtn = new QPushButton;
    findEdit = new QLineEdit;
    skinBtn = new QPushButton;
    miniBtn = new QPushButton;
    closeBtn = new QPushButton;

    loginRegLayout = new QHBoxLayout;
    navMainLayout = new QHBoxLayout;
    setLayout(navMainLayout);
    setFixedHeight(50);
    setControlsLayout();
    setControlsForm();
    //setStyleSheet("background:yellow;");
    setControlsStyle();
    connectSlot();
}


void Navigate::setControlsLayout()
{
    loginRegLayout->setMargin(0);
    loginRegLayout->setSpacing(2);
    loginRegLayout->addWidget(loginBtn);
    loginRegLayout->addWidget(cut);
    loginRegLayout->addWidget(registBtn);

    navMainLayout->setMargin(12);
    navMainLayout->setSpacing(10);
    navMainLayout->addWidget(navIcon);
    navMainLayout->addLayout(loginRegLayout);
    navMainLayout->addStretch(3);
    navMainLayout->addWidget(resultBtn);
    navMainLayout->addWidget(updateBtn);
    navMainLayout->addWidget(findEdit);
    navMainLayout->addWidget(skinBtn);
    navMainLayout->addStretch(5);
    navMainLayout->addWidget(miniBtn);
    navMainLayout->addWidget(closeBtn);

}

void Navigate::setControlsForm()
{
    navIcon->setFixedSize(50, 30);
    navIcon->setIconSize(QSize(30, 30));
    navIcon->setIcon(QIcon("../MusicSoft/img/icon.png"));
    loginBtn->setFixedSize(30, 20);
    loginBtn->setText(tr("登录"));
    loginBtn->setCursor(QCursor(Qt::PointingHandCursor));
    cut->setText(tr("|"));
    registBtn->setFixedSize(30, 20);
    registBtn->setText(tr("注册"));
    registBtn->setCursor(QCursor(Qt::PointingHandCursor));
    resultBtn->setFixedSize(20, 20);
    resultBtn->setIconSize(QSize(20, 20));
    resultBtn->setIcon(QIcon("../MusicSoft/img/result.png"));
    resultBtn->setCursor(QCursor(Qt::PointingHandCursor));
    updateBtn->setFixedSize(20, 20);
    updateBtn->setIconSize(QSize(20, 20));
    updateBtn->setIcon(QIcon("../MusicSoft/img/update.png"));
    updateBtn->setCursor(QCursor(Qt::PointingHandCursor));
    findEdit->setFixedSize(260, 25);
    findEdit->addAction(QIcon("../MusicSoft/img/search2.png"), QLineEdit::TrailingPosition);
    skinBtn->setFixedSize(20, 20);
    skinBtn->setIconSize(QSize(20, 20));
    skinBtn->setIcon(QIcon("../MusicSoft/img/skin.png"));
    skinBtn->setCursor(QCursor(Qt::PointingHandCursor));
    miniBtn->setFixedSize(20, 20);
    miniBtn->setIconSize(QSize(20, 20));
    miniBtn->setIcon(QIcon("../MusicSoft/img/mini.png"));
    miniBtn->setCursor(QCursor(Qt::PointingHandCursor));
    closeBtn->setFixedSize(20, 20);
    closeBtn->setIconSize(QSize(20, 20));
    closeBtn->setIcon(QIcon("../MusicSoft/img/close.png"));
    closeBtn->setCursor(QCursor(Qt::PointingHandCursor));

}

void Navigate::setControlsStyle()
{
    QFile file(QString("../MusicSoft/qss/navigate.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void Navigate::connectSlot()
{
    connect(closeBtn,QPushButton::clicked,this, exit);
}
