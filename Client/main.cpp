#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "login_gui.h"
#include "cglobaldata.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CGlobalData::getInstance()->LoadParameter();

    //注册组件到QML
    qmlRegisterType<Login_Gui>("Login_Gui", 1, 0, "Login_Gui");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
