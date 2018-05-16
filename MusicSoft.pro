#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T18:18:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicSoft
TEMPLATE = app


SOURCES += main.cpp\
        musicinterfase.cpp \
    navigate.cpp \
    playcontrol.cpp \
    musiclist.cpp \
    musiclistcloud.cpp \
    musiclistphone.cpp \
    musiclistsearch.cpp \
    musiclistplay.cpp

HEADERS  += musicinterfase.h \
    navigate.h \
    playcontrol.h \
    musiclist.h \
    musiclistcloud.h \
    musiclistphone.h \
    musiclistsearch.h \
    musiclistplay.h

FORMS    += musicinterfase.ui

DISTFILES += \
    qss/musicMain.qss \
    qss/navigate.qss \
    qss/playcontrol.qss \
    img/close.png \
    img/mini.png \
    img/icon.png \
    img/result.png \
    img/search1.png \
    img/skin.png \
    img/next.png \
    img/pre.png \
    img/stop.png \
    img/like1.png \
    img/play1.png \
    img/sound.png \
    img/theme1.jpg \
    img/theme2.jpg \
    img/theme3.jpg \
    img/theme4.jpg \
    qss/musicList.qss \
    img/search2.png \
    img/update.png \
    img/cloud3.png \
    img/jack.png \
    img/wifi.png \
    qss/musicListCloud.qss \
    qss/musicListPhone.qss \
    img/Ruler.png \
    img/ruler1.png \
    img/maxSearch.png \
    img/MusicBox.png \
    qss/musicListSearch.qss \
    img/like2.png \
    img/item00.png \
    img/item02.png \
    img/item03.png \
    img/item04.png \
    img/item10.png \
    img/item12.png \
    img/item13.png \
    img/item14.png \
    img/download.png \
    img/continue.png \
    img/item01.png \
    img/item11.png \
    qss/musicListPlay.qss \
    img/showList.png \
    img/hideList.png

RC_FILE = exeicon.rc
