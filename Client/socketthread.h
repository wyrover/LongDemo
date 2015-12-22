#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H
#include <QThread>

#include "../ProtocolLogic/Ld_Socket.h"

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(QObject *parent = 0);
    ~SocketThread();

protected:
    void run();

private:
    Ld_Socket* _tcpSocket;
};

#endif // SOCKETTHREAD_H
