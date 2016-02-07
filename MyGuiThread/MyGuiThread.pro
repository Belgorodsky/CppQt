#-------------------------------------------------
#
# Project created by QtCreator 2016-02-07T18:37:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGuiThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    mythread.h

FORMS    += mainwindow.ui
