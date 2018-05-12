#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QWidget>
#include <QPushButton>
#include <QStackedLayout>
#include <QFile>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MusicList : public QWidget
{
    Q_OBJECT
public:
    explicit MusicList(QWidget *parent = 0);

signals:

public slots:

private:
    QPushButton *playListBtn;
    QPushButton *cloudBtn;
    QPushButton *downloadBtn;
    QPushButton *searchBtn;

    //----------Layout
    QHBoxLayout *operNavLayout;
    QStackedLayout *operObjLayout;
    QVBoxLayout *musicListMainLayout;

    //--------Fcuntion
    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();
};

#endif // MUSICLIST_H
