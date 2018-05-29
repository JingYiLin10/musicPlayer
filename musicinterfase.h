#ifndef MUSICINTERFASE_H
#define MUSICINTERFASE_H

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 音乐主界面框架
 */

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>

#include "navigate.h"
#include "playcontrol.h"
#include "musiclist.h"
#include "musicset.h"

namespace Ui {
class MusicInterfase;
}

class MusicInterfase : public QWidget
{
    Q_OBJECT

public:
    explicit MusicInterfase(QWidget *parent = 0);
    ~MusicInterfase();

public slots:
    void resultPre();

private:
    Ui::MusicInterfase *ui;

    Navigate *musicNav;
    PlayControl *musicPlayControl;
    MusicList *musicList;
    MusicSet *musicSet;

    //----------Layout
    QHBoxLayout *musicCenterLayout;
    QVBoxLayout *musicMainLayout;

    //----------Function
    void setControlsLayout();
    void setControlsForm();
    void connectSlot();

    //-----Nav
    QPushButton *resultPreBtn;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool pressFlag;
    QPoint beginPos;
};

#endif // MUSICINTERFASE_H
