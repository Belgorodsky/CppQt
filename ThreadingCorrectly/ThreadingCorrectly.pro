QT += core
QT -= gui

CONFIG += c++11

TARGET = ThreadingCorrectly
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myobject.cpp

HEADERS += \
    myobject.h
