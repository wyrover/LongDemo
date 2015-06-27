#include <QCoreApplication>

#include <longserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LongServer tServer;
    tServer.start();

    return a.exec();
}
