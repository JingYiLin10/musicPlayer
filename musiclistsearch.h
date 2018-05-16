#ifndef MUSICLISTSEARCH_H
#define MUSICLISTSEARCH_H

/**
 * @author: jingbo
 * @date: 2018/05/14
 * @desc: 音乐列表-搜索
 */

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QHBoxLayout>
#include <QVBoxLayout>


class MusicListSearch : public QWidget
{
    Q_OBJECT
public:
    explicit MusicListSearch(QWidget *parent = 0);

signals:

public slots:

private:
    QPushButton *icon;
    QLineEdit *searchLine;
    QPushButton *searchBtn;

    QHBoxLayout *iconLayout;
    QHBoxLayout *searchLineLayout;
    QHBoxLayout *searchBtnLayout;

    QVBoxLayout *musicListSearchMainLayout;

    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();
};

#endif // MUSICLISTSEARCH_H
