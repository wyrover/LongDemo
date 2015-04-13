#include <iostream>

//for bzero
#include <string.h>

//for exit
#include <stdlib.h>

//for close
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PROT 6666
#define LISTENNQ   5
#define BUFFER_SIZE 1024

int main()
{
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PROT);

    int server_socket = socket(AF_INET,SOCK_STREAM,0);

    if( server_socket < 0 )
    {
        std::cout << "Create Socket Failed!" << std::endl;
        exit(1);
    }

    if( bind(server_socket, (struct sockaddr*)&server_addr,sizeof(server_addr)) )
    {
        std::cout << "Server Bind Faile!" << std::endl;
        exit(1);
    }

    if( listen(server_socket,LISTENNQ) )
    {
        std::cout << "Listen Failed!" << std::endl;
        exit(1);
    }

    std::cout << "success" << std::endl;

    while (1)
    {
        int connect_socket = accept( server_socket,(struct sockaddr*)NULL,NULL );
        if( connect_socket < 0 )
        {
            std::cout << "Accept Failed!" << std::endl;
            break;
        }

        char buffer[BUFFER_SIZE];
        bzero(buffer,BUFFER_SIZE);
        int length = recv( connect_socket,buffer,BUFFER_SIZE,0);
        if( length < 0 )
        {
            std::cout << "Server Recieve Data Failed!" << std::endl;
            break;
        }
        close(connect_socket);
    }
    //
    close(server_socket);
    return 0;
}

