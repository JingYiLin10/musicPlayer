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
    musiclistsearch.cpp

HEADERS  += musicinterfase.h \
    navigate.h \
    playcontrol.h \
    musiclist.h \
    musiclistcloud.h \
    musiclistphone.h \
    musiclistsearch.h

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
    img/continue.png \
    img/next.png \
    img/pre.png \
    img/stop.png \
    img/cloud1.png \
    img/download1.png \
    img/like1.png \
    img/play1.png \
    img/sound.png \
    img/theme1.jpg \
    img/theme2.jpg \
    img/theme3.jpg \
    img/theme4.jpg \
    qss/musicList.qss \
    img/cloud2.png \
    img/download2.png \
    img/music1.png \
    img/music2.png \
    img/search2.png \
    img/update.png \
    img/cloud3.png \
    img/iphone.png \
    img/jack.png \
    img/wifi.png \
    qss/musicListCloud.qss \
    qss/musicListPhone.qss \
    img/Ruler.png \
    img/ruler1.png \
    img/maxSearch.png \
    img/MusicBox.png \
    qss/musicListSearch.qss

RC_FILE = exeicon.rc
