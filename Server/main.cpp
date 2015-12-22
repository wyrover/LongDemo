#include <iostream>

#include "src/SysFunction.h"
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
//#include <windows.h>
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
#endif

#define SERVER_PORT 666
#define BUFFER_SIZE 1024
#define LISTEN_QUEUE 20

int main()
{
#ifdef _WIN32
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
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    //创建socket
    int server_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (server_socket < 0 )
    {
        std::cout << "Creat Socket Fail..." << std::endl;
        exit(1);
    }
    //Bind
    if ( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr)) != 0 )
    {
        std::cout << "Bind Socekt Fail..." << std::endl;
        exit(1);
    }
    //监听
    if ( listen(server_socket,LISTEN_QUEUE) )
    {
        std::cout << "Listen Socekt Fail..." << std::endl;
        exit(1);
    }
    while (1)
    {
        //client
        struct sockaddr_in client_addr;
#ifdef _WIN32
        int length = sizeof(client_addr);
#else
        socklen_t length = sizeof(client_addr);
#endif

        //
        int connt_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
        if (connt_socket < 0 )
        {
            std::cout << "Accept Socket Fail..." << std::endl;
            break;
        }
    }

#ifdef _WIN32
    //终止 DLL 的使用
    WSACleanup();
#endif
    return 0;
}

