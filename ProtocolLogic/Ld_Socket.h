
#pragma once

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <string.h>

#ifndef INVALID_SOCKET
#define INVALID_SOCKET  (SOCKET)(~0)
#endif
#ifndef SOCKET_ERROR
#define SOCKET_ERROR            (-1)
#endif

typedef unsigned int   SOCKET;
#endif


#include <iostream>
#include <string>


class Ld_Socket
{
public:
    Ld_Socket();
    ~Ld_Socket();

public:
    bool Socket_Init();
    bool Socket_Close();
    int Socket_Connect( const char* lpHost, int nPort );
    int Socket_Send(const char* lpBuffer, int nBufLenght, int nFlags = 0);
    int Socket_Recv( char* lpBuffer, int nBufLenght, int nFlags = 0 );
	
private:
	SOCKET m_uSocket;

};
