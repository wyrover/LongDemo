#include <iostream>

#include "src/SysFunction.h"
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
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
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    //
    int server_socket = socket(AF_INET,SOCK_STREAM,0);
    if (server_socket < 0 )
    {
        std::cout << "Creat Socket Fail..." << std::endl;
        exit(1);
    }
    //
    if ( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr)) != 0 )
    {
        std::cout << "Bind Socekt Fail..." << std::endl;
        exit(1);
    }
    //
    if ( listen(server_socket,LISTEN_QUEUE) )
    {
        std::cout << "Listen Socekt Fail..." << std::endl;
        exit(1);
    }
    while (1)
    {
        //client
        struct sockaddr_in client_addr;
        socklen_t length = sizeof(client_addr);

        //
        int connt_socket = accept(server_socket,(struct sockaddr*)&client_addr,&length);
        if (connt_socket < 0 )
        {
            std::cout << "Accept Socket Fail..." << std::endl;
            break;
        }
    }
    return 0;
}

