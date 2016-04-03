QT += core
QT -= gui

CONFIG += c++11

TARGET = Semaphore
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    producer.cpp \
    consumer.cpp

HEADERS += \
    producer.h \
    consumer.h
