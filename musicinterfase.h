#ifndef MUSICINTERFASE_H
#define MUSICINTERFASE_H

#include "navigate.h"
#include "playcontrol.h"
#include "musiclist.h"
#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>

namespace Ui {
class MusicInterfase;
}

class MusicInterfase : public QWidget
{
    Q_OBJECT

public:
    explicit MusicInterfase(QWidget *parent = 0);
    ~MusicInterfase();

    void setControlsLayout();
private:
    Ui::MusicInterfase *ui;

    Navigate *musicNav;
    PlayControl *musicPlayControl;
    MusicList *musicList;

    //----------Layout
    QHBoxLayout *musicCenterLayout;
    QVBoxLayout *musicMainLayout;

    //----------Function
    void setControlsForm();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool pressFlag;
    QPoint beginPos;
};

#endif // MUSICINTERFASE_H
