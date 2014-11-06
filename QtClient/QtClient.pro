#-------------------------------------------------
#
# Project created by QtCreator 2014-11-06T15:18:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtClient
TEMPLATE = app

INCLUDEPATH += $$PWD/../../boost/
INCLUDEPATH += $$PWD/../../openssl/include/
INCLUDEPATH += $$PWD/../../jsoncpp/include/json/

#add this .so to use boost::asio
unix:LIBS += -lboost_system

SOURCES += main.cpp\
        dialog.cpp \
    halldialog.cpp \
    tabconfig.cpp \
    cgamedata.cpp \
    sysfunction.cpp \
    ../../tinyxml2/tinyxml2.cpp

HEADERS  += dialog.h \
    halldialog.h \
    tabconfig.h \
    cgamedata.h \
    sysfunction.h \
    ../../tinyxml2/tinyxml2.h

CONFIG += C++11

RC_ICONS = qtdemo.ico

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../boost/stage/lib/ -llibboost_system-vc120-mt-1_57
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../boost/stage/lib/ -llibboost_system-vc120-mt-gd-1_57

DEPENDPATH += $$PWD/../../boost/stage
