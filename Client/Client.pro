TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    cglobaldata.cpp \
    login_gui.cpp \
    socketthread.cpp \
    ../ProtocolLogic/Logplus.cpp \
    ../ProtocolLogic/Socket.cpp \
    ../ProtocolLogic/SysFunction.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    cglobaldata.h \
    login_gui.h \
    socketthread.h \
    ../ProtocolLogic/Logplus.h \
    ../ProtocolLogic/protocol.h \
    ../ProtocolLogic/Socket.h \
    ../ProtocolLogic/SysFunction.h \
    ../ProtocolLogic/rapidjson/allocators.h \
    ../ProtocolLogic/rapidjson/document.h \
    ../ProtocolLogic/rapidjson/encodedstream.h \
    ../ProtocolLogic/rapidjson/encodings.h \
    ../ProtocolLogic/rapidjson/filereadstream.h \
    ../ProtocolLogic/rapidjson/filewritestream.h \
    ../ProtocolLogic/rapidjson/memorybuffer.h \
    ../ProtocolLogic/rapidjson/memorystream.h \
    ../ProtocolLogic/rapidjson/pointer.h \
    ../ProtocolLogic/rapidjson/prettywriter.h \
    ../ProtocolLogic/rapidjson/rapidjson.h \
    ../ProtocolLogic/rapidjson/reader.h \
    ../ProtocolLogic/rapidjson/stringbuffer.h \
    ../ProtocolLogic/rapidjson/writer.h \
    ../ProtocolLogic/rapidjson/error/en.h \
    ../ProtocolLogic/rapidjson/error/error.h \
    ../ProtocolLogic/rapidjson/internal/biginteger.h \
    ../ProtocolLogic/rapidjson/internal/diyfp.h \
    ../ProtocolLogic/rapidjson/internal/dtoa.h \
    ../ProtocolLogic/rapidjson/internal/ieee754.h \
    ../ProtocolLogic/rapidjson/internal/itoa.h \
    ../ProtocolLogic/rapidjson/internal/meta.h \
    ../ProtocolLogic/rapidjson/internal/pow10.h \
    ../ProtocolLogic/rapidjson/internal/stack.h \
    ../ProtocolLogic/rapidjson/internal/strfunc.h \
    ../ProtocolLogic/rapidjson/internal/strtod.h \
    ../ProtocolLogic/rapidjson/internal/swap.h \
    ../ProtocolLogic/rapidjson/msinttypes/inttypes.h \
    ../ProtocolLogic/rapidjson/msinttypes/stdint.h

