#ifndef MUSICLISTPLAY_H
#define MUSICLISTPLAY_H

/**
 * @author: jingbo
 * @date: 2018/05/16
 * @desc: 音乐列表-播放列表
 */

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QListView>
#include <QTreeView>
#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class MusicListPlay : public QWidget
{
    Q_OBJECT
public:
    explicit MusicListPlay(QWidget *parent = 0);

signals:

public slots:
    void isShowList();
private:
    QListView *defaultPlayList;
    QListView *recentPlayList;
    QPushButton *defaultListBtn;
    QPushButton *recentListBtn;//310宽度

    QVBoxLayout *musicListPlayMainLayout;
    //---Funciton
    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();



    //---Other
    bool isShowDefault;
    bool isShowRecent;
};

#endif // MUSICLISTPLAY_H
