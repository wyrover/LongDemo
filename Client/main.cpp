#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "login_gui.h"
#include "cglobaldata.h"

#include <iostream>
#include <string>

#ifdef Q_OS_WIN32
#include <winsock2.h>
#endif

#define SERVER_PORT 6666

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CGlobalData::getInstance()->LoadParameter();

#ifdef Q_OS_WIN32
    //初始化 DLL
    WSADATA wsaData;

    WORD wVersion = MAKEWORD(2, 2);
    int nError = WSAStartup(wVersion, &wsaData);
    if(nError != 0)
    {
        std::cout << "WSAStartup failed with error: " << nError << std::endl;
        return -1;
    }
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        std::cout << "Could not find a usable version of Winsock.dll" << std::endl;
        WSACleanup();
        return -1;
    }
    else
        std::cout << "The Winsock 2.2 dll was found okay" << std::endl;
#endif

    struct sockaddr_in _serverAddr;

    SOCKET _clientSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(_clientSocket < 0)
    {
        std::cout << "Creat Socket Fail..." << std::endl;
        //exit(1);
    }

    memset(&_serverAddr,0,sizeof(_serverAddr));
    _serverAddr.sin_family = AF_INET;
    _serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    _serverAddr.sin_port = htons(SERVER_PORT);

    if(::connect(_clientSocket, (struct sockaddr*)&_serverAddr, sizeof(_serverAddr)) < 0)
    {
        std::cout << "Connect Fail...." << std::endl;
        //exit(1);
    }

    std::string str{"Hello World!---Client"};
    if(::send(_clientSocket, str.c_str(), str.length(), 0) < 0)
    {
        //printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        //exit(0);
    }

    char _szBuffer[MAXBYTE] = {0};
    if(recv(_clientSocket, _szBuffer, MAXBYTE, 0) == -1)
    {
       //perror("recv error");
       //exit(1);
    }
    printf("Received : %s ", _szBuffer);

#ifdef Q_OS_WIN32
    closesocket(_clientSocket);

    //终止使用 DLL
    WSACleanup();
#else
    closesocket(_clientSocket);
#endif


    //注册组件到QML
    qmlRegisterType<Login_Gui>("Login_Gui", 1, 0, "Login_Gui");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
