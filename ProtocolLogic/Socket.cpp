
#include "Socket.h"

Socket::Socket()
: m_uSocket(INVALID_SOCKET)
{
#ifdef _WIN32
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);
#endif

	Init();
}

Socket::~Socket()
{
#ifdef _WIN32
	WSACleanup();
#endif
}

bool Socket::Init()
{
	if( m_uSocket != INVALID_SOCKET )
	{
		Close();
	}
    m_uSocket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    if( m_uSocket == INVALID_SOCKET )
    {
    	return false;
    }
//Socket设置为非阻塞模式
#ifdef _WIN32
    unsigned long flag = 1;
    int nRet = ioctlsocket( m_uSocket, FIONBIO, (unsigned long *)&flag );
    if( nRet == SOCKET_ERROR )
    {
        Close();
        return false;
    }
#else
    int nFlags = fcntl( m_uSocket, F_GETFL, 0 );
    int nRet = fcntl( m_uSocket, F_SETFL, nFlags | O_ONOBLOCK );
    if( nRet == SOCKET_ERROR )
    {
        Close();
        return false;
    }
#endif
    return true;
}

bool Socket::Close()
{
	if( m_uSocket != INVALID_SOCKET )
	{
#ifdef _WIN32
		closesocket(m_uSocket);
#else
		close(m_uSocket);
#endif
		m_uSocket = INVALID_SOCKET;
	}
	return true;
}

int Socket::Connect(const char *lpHost, int nPort)
{
	if( lpHost == nullptr || nPort == 0 )
	{
		return SOCKET_ERROR;
	}
    struct sockaddr_in SockAddr;
    memset( &SockAddr,0,sizeof(SockAddr) );

    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.S_un.S_addr = ::inet_addr(lpHost);
    if( SockAddr.sin_addr.S_un.S_addr == INADDR_NONE )
    {
        return false;
    }

    SockAddr.sin_port = htons(nPort);

    return ::connect(m_uSocket,(const sockaddr*)&SockAddr,sizeof(SockAddr));
}

int Socket::Send(const char *lpBuffer, int nBufLenght, int nFlags)
{
    if( m_uSocket == INVALID_SOCKET )
        return 0;
    return ::send(m_uSocket,lpBuffer, nBufLenght, nFlags);
}

int Socket::Recv(char *lpBuffer, int nBufLenght, int nFlags)
{
    if( m_uSocket == INVALID_SOCKET )
        return 0;
    return ::recv(m_uSocket, lpBuffer, nBufLenght, nFlags);
}
