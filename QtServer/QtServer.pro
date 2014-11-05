#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T10:32:37
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = QtServer

INCLUDEPATH += ../../boost/
INCLUDEPATH += ../../openssl/include/

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lboost_system

SOURCES += main.cpp

CONFIG += C++11
