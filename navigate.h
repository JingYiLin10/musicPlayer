#ifndef NAVIGATE_H
#define NAVIGATE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QFile>
#include <QDebug>

class Navigate : public QWidget
{
    Q_OBJECT
public:
    explicit Navigate(QWidget *parent = 0);


signals:

public slots:

private:
    QPushButton *navIcon;
    QPushButton *loginBtn;
    QLabel *cut;
    QPushButton *registBtn;
    QPushButton *resultBtn;
    QPushButton *updateBtn;
    QLineEdit *findEdit;
    QPushButton *skinBtn;
    QPushButton *miniBtn;
    QPushButton *closeBtn;

    //----------Layout
    QHBoxLayout *loginRegLayout;
    QHBoxLayout *navMainLayout;

    //----------Function
    void setControlsLayout();
    void setControlsForm();
    void setControlsStyle();
    void connectSlot();
};

#endif // NAVIGATE_H
