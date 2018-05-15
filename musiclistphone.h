#ifndef MUSICLISTPHONE_H
#define MUSICLISTPHONE_H

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 音乐列表-手机
 */

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MusicListPhone : public QWidget
{
    Q_OBJECT
public:
    explicit MusicListPhone(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *selectInfo;
    QPushButton *wiredConnBtn;
    QPushButton *wifiConnBtn;

    //------------Layout
    QHBoxLayout *selectInfoLayout;
    QHBoxLayout *wiredConnBtnlayout;
    QHBoxLayout *wifiConnBtnLayout;

    QVBoxLayout *musicListPhoneMainLayout;

    //------------Function
    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();
};

#endif // MUSICLISTPHONE_H
