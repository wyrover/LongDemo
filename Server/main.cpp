#include <iostream>

#include "src/SysFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif


int main()
{
    auto aa = "ddddd";
    SysFunction::PrintLog(aa);
    int sockfd;
    return 0;
}

