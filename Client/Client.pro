TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    ../ProtocolLogic/Socket.cpp \
    ../ProtocolLogic/SysFunction.cpp \
    login_gui.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

win32: LIBS += -lwsock32

HEADERS += \
    ../ProtocolLogic/Socket.h \
    ../ProtocolLogic/SysFunction.h \
    login_gui.h

