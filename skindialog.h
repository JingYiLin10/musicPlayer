#ifndef SKINDIALOG_H
#define SKINDIALOG_H

/**
 * @author: jingbo
 * @date: 2018/05/29
 * @desc: 皮肤对话框
 */

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class SkinDialog : public QDialog
{
public:
    SkinDialog();
    QPushButton *getCloseBtn();
private:
    QWidget *nav;
    QLabel *titleInfo;
    QPushButton *closeBtn;

    QHBoxLayout *navLayout;

    QVBoxLayout *skinDialogLayout;


    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();

protected:
    //--鼠标移动事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool pressFlag;
    QPoint beginPos;
};

#endif // SKINDIALOG_H
