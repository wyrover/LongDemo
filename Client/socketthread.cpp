#include "socketthread.h"

SocketThread::SocketThread(QObject *parent) : QThread(parent)
{

}

SocketThread::~SocketThread()
{
    if(_tcpSocket != nullptr)
    {
        delete _tcpSocket;
        _tcpSocket = nullptr;
    }
}

void SocketThread::run()
{
    _tcpSocket = new Socket();
}
