#include "musicset.h"

/**
 * @author: jingbo
 * @date: 2018/05/29
 * @desc: 音乐功能集合
 */

MusicSet::MusicSet(QWidget *parent) : QWidget(parent)
{

    for(int i = 0; i < 4; ++i){
        setItemBtn[i] = new QPushButton;
    }
    hLine = new QPushButton;
    setItemLayout = new QHBoxLayout;
    setFuncLayout = new QStackedLayout;
    musicSetMainLayout = new QVBoxLayout;

    this->setFixedSize(690,527);
    this->setLayout(musicSetMainLayout);

    setControlsLayout();
    setControlsForm();
    setControlsStyle();
    connectSlot();
}

void MusicSet::resultPreIndex()
{
    int index = -1;
    if(resultIndex.size() != 1)
        resultIndex.pop();
    if(!resultIndex.empty()){
        index = resultIndex.top();
    }
    switchSetItem(index);
}

void MusicSet::switchSetItem(int index)
{
    QString style1 = "QPushButton{color: white; font: 18px; font-family: 黑体;}"
                    "QPushButton:hover{color: #FFFEA1;}";
    QString style2 = "QPushButton{color: #FFFEA1; font: 18px; font-family: 黑体;}";
    QString style3 = "QPushButton{color: black; font: 18px; font-family: 黑体;}"
                    "QPushButton:hover{color: #37AEFE;}";
    QString style4 = "QPushButton{color: #37AEFE; font: 18px; font-family: 黑体;}";
    QPalette palette;
    int toIndex = 0;
    if(index == 0){
         QPushButton *senderBtn = qobject_cast<QPushButton *>(sender());
         for(int i = 0; i < 4; ++i){
             if(setItemBtn[i] == senderBtn)
                 toIndex = i + 1;
         }
    }
    toIndex = toIndex == 0 ? index : toIndex;
    if(index != -1){
        for(int i = 0; i < 4; ++i){
            if(toIndex == 4)
                setItemBtn[i]->setStyleSheet(style1);
            else
                setItemBtn[i]->setStyleSheet(style3);
        }
    }
    else{
        return ;
    }
    if(toIndex == 4){
        hLine->setStyleSheet("background: QColor(255,255,255,0); border: 0px;");
        palette.setColor(QPalette::Background, QColor(255,255,255,0));
        setItemBtn[toIndex - 1]->setStyleSheet(style2);
    }
    else{
        hLine->setStyleSheet("background: #E5E5E5; border: 0px;");
        palette.setColor(QPalette::Background, QColor(255,255,255));
        setItemBtn[toIndex - 1]->setStyleSheet(style4);
    }
    this->setPalette(palette);
    if(index == 0 && currentIndex != toIndex)
        resultIndex.push(toIndex);
    currentIndex = toIndex;
}

void MusicSet::setControlsLayout()
{
    setItemLayout->setMargin(6);
    setItemLayout->setSpacing(30);
    setItemLayout->addStretch();
    for(int i = 0; i < 4; ++i){
        setItemLayout->addWidget(setItemBtn[i]);
    }
    setItemLayout->addStretch();

    //setFuncLayout

    musicSetMainLayout->setMargin(0);
    musicSetMainLayout->setSpacing(0);
    musicSetMainLayout->addLayout(setItemLayout);
    musicSetMainLayout->addWidget(hLine);
    musicSetMainLayout->addStretch();

}

void MusicSet::setControlsForm()
{
    setItemBtn[0]->setText(tr("乐库"));
    setItemBtn[1]->setText(tr("歌单"));
    setItemBtn[2]->setText(tr("MV"));
    setItemBtn[3]->setText(tr("歌词"));
    for(int i = 1; i < 4; ++i){
        QString style = "QPushButton{color: black; font: 18px; font-family: 黑体;}"
                        "QPushButton:hover{color: #37AEFE;}";
        setItemBtn[i]->setStyleSheet(style);
    }
    setItemBtn[0]->setStyleSheet("QPushButton{color: #37AEFE; font: 18px; font-family: 黑体;}");
    currentIndex = 1;
    resultIndex.push(currentIndex);
    hLine->setFixedSize(690, 1);
    hLine->setStyleSheet("background: #E5E5E5; border: 0px;");
}

void MusicSet::setControlsStyle()
{
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255));
    this->setPalette(palette);

    QFile file(QString("../MusicSoft/qss/musicSet.qss"));
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void MusicSet::connectSlot()
{
    for(int i = 0; i < 4; i++){
        connect(setItemBtn[i], QPushButton::clicked, this, switchSetItem);
    }
}
