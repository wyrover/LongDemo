#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T10:32:37
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = QtServer

INCLUDEPATH += $$PWD/../../boost/
INCLUDEPATH += $$PWD/../../openssl/include/

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

CONFIG += C++11

unix:LIBS += -lboost_system

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../boost/stage/lib/ -llibboost_system-vc120-mt-1_57
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../boost/stage/lib/ -llibboost_system-vc120-mt-gd-1_57

DEPENDPATH += $$PWD/../../boost/stage
