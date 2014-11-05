#-------------------------------------------------
#
# Project created by QtCreator 2014-01-17T22:20:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtClient

INCLUDEPATH += ../../boost/
INCLUDEPATH += ../../openssl/include/

TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    halldialog.cpp \
    tabconfig.cpp \
    jsoncpp/source/json_reader.cpp \
    jsoncpp/source/json_value.cpp \
    jsoncpp/source/json_writer.cpp \
    tinyxml2/tinyxml2.cpp

HEADERS  += dialog.h \
    halldialog.h \
    tabconfig.h \
    jsoncpp/include/assertions.h \
    jsoncpp/include/autolink.h \
    jsoncpp/include/config.h \
    jsoncpp/include/features.h \
    jsoncpp/include/forwards.h \
    jsoncpp/include/json.h \
    jsoncpp/include/reader.h \
    jsoncpp/include/value.h \
    jsoncpp/include/version.h \
    jsoncpp/include/writer.h \
    jsoncpp/source/json_batchallocator.h \
    jsoncpp/source/json_tool.h \
    tinyxml2/tinyxml2.h

CONFIG += C++11

RC_ICONS = qtdemo.ico

OTHER_FILES += \
    Config.xml \
    open.jpg \
    open.ico \
    qtdemo.ico \
    LongDemo.pro.user
