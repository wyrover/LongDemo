#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T21:57:30
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = QtServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    longserver.cpp

HEADERS += \
    longserver.h

CONFIG += C++11
