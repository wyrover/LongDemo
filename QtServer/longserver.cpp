#include "longserver.h"

#include <stdlib.h>
#include <QByteArray>

LongServer::LongServer(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
}

void LongServer::start()
{
    if( !m_tcpServer->listen(QHostAddress::Any,4001 ) )
    {
        m_tcpServer->close();
        return;
    }

    connect( m_tcpServer, SIGNAL(newConnection()), this, SLOT(newConnect()) );
}

void LongServer::newConnect()
{
    //得到每个连进来的socket
    m_pTcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_pTcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

void LongServer::readMessage()
{
    //读取信息
    QByteArray tBuffer = m_pTcpSocket->readAll();
    qDebug() << tBuffer;
}
