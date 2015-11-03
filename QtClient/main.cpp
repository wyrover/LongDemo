#include "mainwindow.h"
#include <QApplication>

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
#endif


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow HallWin;
    if( HallWin.GetNext() )
        HallWin.show();
    else
        return 0;

    return app.exec();
}
