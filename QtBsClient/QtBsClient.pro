#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T22:44:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBsClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    regdlg.cpp \
    sysfun.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    regdlg.h \
    sysfun.h \
    ../ProtocolLogic/protocol.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    regdlg.ui

CONFIG += C++11


