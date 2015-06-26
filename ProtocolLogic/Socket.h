
#pragma once

#ifdef _WIN32
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


class Socket
{
public:
	Socket();
	~Socket();

public:
	virtual bool Init();
	virtual bool Close();
    virtual int Connect( const char* lpHost, int nPort );
    virtual int Send(const char* lpBuffer, int nBufLenght, int nFlags = 0);
    virtual int Recv( char* lpBuffer, int nBufLenght, int nFlags = 0 );
	
private:
	SOCKET m_uSocket;

};
