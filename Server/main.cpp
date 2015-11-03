#include <iostream>

#include "src/SysFunction.h"
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
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
    WSAStartup( MAKEWORD(2, 2), &wsaData);
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

