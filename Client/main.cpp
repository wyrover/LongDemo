#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "login_gui.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //注册组件到QML
    qmlRegisterType<Login_Gui>("Login_Gui", 1, 0, "Login_Gui");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

