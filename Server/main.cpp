#include <iostream>

#include "src/SysFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#ifdef _WIN32
#include <winsock2.h>
//#include <windows.h>
#else
    #include <unistd.h>  //close
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #define SOCKET int
#endif

//bind: Permission denied
//Only the root user is allowed to bind to ports <= 1024. Every ports > 1024 can be bound to by normal users.
#define SERVER_PORT 6666
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
    SOCKET server_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (server_socket < 0 )
    {
        perror("socket");
        exit(1);
    }
    //Bind
    if ( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr)) != 0 )
    {
        perror("bind");
        exit(1);
    }
    //监听
    if ( listen(server_socket,LISTEN_QUEUE) )
    {
        perror("listen");
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
        SOCKET connt_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
        if (connt_socket < 0 )
        {
            std::cout << "Accept Socket Fail..." << std::endl;
            break;
        }

        //接收客户端的数据
        char _szBuffer[BUFFER_SIZE] = {0};
        int recvCnt = recv(connt_socket, _szBuffer, BUFFER_SIZE, 0);
        if(recvCnt > 0)
        {
            std::cout << _szBuffer << std::endl;
        }

        //向客户端发送数据
        std::string str{"Hello World!---Server"};
        send(connt_socket, str.c_str(), str.length(), 0);

#ifdef _WIN32
        closesocket(connt_socket);
#else
        close(connt_socket);
#endif
        //重置缓冲区
        memset(_szBuffer, 0, BUFFER_SIZE);
    }

#ifdef _WIN32
    closesocket(server_socket);

    //终止 DLL 的使用
    WSACleanup();
#else
    close(server_socket);
#endif

    return 0;
}
