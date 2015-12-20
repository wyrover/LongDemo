#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H
#include <QThread>

#include "../ProtocolLogic/Socket.h"

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(QObject *parent = 0);
    ~SocketThread();

protected:
    void run();

private:
    Socket* _tcpSocket;
};

#endif // SOCKETTHREAD_H
