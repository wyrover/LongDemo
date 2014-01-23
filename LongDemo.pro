#-------------------------------------------------
#
# Project created by QtCreator 2014-01-17T22:20:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LongDemo
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    halldialog.cpp \
    tabconfig.cpp

HEADERS  += dialog.h \
    halldialog.h \
    tabconfig.h

CONFIG += C++11

RC_ICONS = qtdemo.ico
