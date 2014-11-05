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

CONFIG   += console boost_system
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

CONFIG += C++11
