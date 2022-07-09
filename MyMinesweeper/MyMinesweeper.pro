#-------------------------------------------------
#
# Project created by QtCreator 2018-06-24T10:33:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyMinesweeper
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    about.cpp \
    help.cpp \
    choosegrade.cpp \
    gameover.cpp \
    primary.cpp \
    middle.cpp \
    premium.cpp

HEADERS  += widget.h \
    about.h \
    help.h \
    choosegrade.h \
    gameover.h \
    primary.h \
    middle.h \
    premium.h

RESOURCES += \
    image.qrc

CONFIG += C++11
