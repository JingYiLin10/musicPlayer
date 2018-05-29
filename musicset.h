#ifndef MUSICSET_H
#define MUSICSET_H

/**
 * @author: jingbo
 * @date: 2018/05/29
 * @desc: 音乐功能集合
 */

#include <QFile>
#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPushButton>
#include <QStack>

class MusicSet : public QWidget
{
    Q_OBJECT
public:
    explicit MusicSet(QWidget *parent = 0);
    void resultPreIndex();
signals:

public slots:
    void switchSetItem(int);

private:
    QPushButton *setItemBtn[4]; //0乐库 1MV 2歌单 3歌词
    QPushButton *hLine;
    QHBoxLayout *setItemLayout; //集合项布局
    QStackedLayout *setFuncLayout;
    QVBoxLayout *musicSetMainLayout;

    QStack<int> resultIndex;
    int currentIndex;

    //--------Function
    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();
};

#endif // MUSICSET_H
