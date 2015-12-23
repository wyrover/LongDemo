
#include "Ld_Socket.h"

Ld_Socket::Ld_Socket()
: m_uSocket(INVALID_SOCKET)
{
    Socket_Init();
}

Ld_Socket::~Ld_Socket()
{
#ifdef _WIN32
	WSACleanup();
#endif
}

bool Ld_Socket::Socket_Init()
{

#ifdef _WIN32
    WSADATA wsaData;
    WORD wVersion = MAKEWORD(2, 2);
    int nError = WSAStartup(wVersion, &wsaData);
    if(nError != 0)
    {
        std::cout << "WSAStartup failed with error: " << nError << std::endl;
        return false;
    }
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        std::cout << "Could not find a usable version of Winsock.dll" << std::endl;
        WSACleanup();
        return false;
    }
    else
        std::cout << "The Winsock 2.2 dll was found okay" << std::endl;

#endif
	if( m_uSocket != INVALID_SOCKET )
	{
        Socket_Close();
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
        Socket_Close();
        return false;
    }
#else
    int nFlags = fcntl( m_uSocket, F_GETFL, 0 );
    int nRet = fcntl( m_uSocket, F_SETFL, nFlags | O_NONBLOCK );
    if( nRet == SOCKET_ERROR )
    {
        Socket_Close();
        return false;
    }
#endif
    return true;
}

bool Ld_Socket::Socket_Close()
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

int Ld_Socket::Socket_Connect(const char *lpHost, int nPort)
{
	if( lpHost == nullptr || nPort == 0 )
	{
		return SOCKET_ERROR;
	}
    struct sockaddr_in SockAddr;
    memset( &SockAddr,0,sizeof(SockAddr) );

    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = ::inet_addr(lpHost);
    if( SockAddr.sin_addr.s_addr == INADDR_NONE )
    {
        LPHOSTENT lphost = ::gethostbyname(lpHost);
        if (lphost != NULL)
        {
            SockAddr.sin_addr.s_addr = ((LPIN_ADDR)lphost->h_addr)->s_addr;
        }
        else
        {
            return SOCKET_ERROR;
        }
    }

    SockAddr.sin_port = htons(nPort);

    return ::connect(m_uSocket,(const sockaddr*)&SockAddr,sizeof(SockAddr));
}

int Ld_Socket::Socket_Send(const char *lpBuffer, int nBufLenght, int nFlags)
{
    if( m_uSocket == INVALID_SOCKET )
        return 0;
    return ::send(m_uSocket,lpBuffer, nBufLenght, nFlags);
}

int Ld_Socket::Socket_Recv(char *lpBuffer, int nBufLenght, int nFlags)
{
    if( m_uSocket == INVALID_SOCKET )
        return 0;
    return ::recv(m_uSocket, lpBuffer, nBufLenght, nFlags);
}
