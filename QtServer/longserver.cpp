#include "longserver.h"

#include <stdlib.h>
#include <QByteArray>
#include <QString>
#include "../ProtocolLogic/protocol.h"
#include "../ProtocolLogic/sysfun.h"

LongServer::LongServer(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
    m_dDatabase = QSqlDatabase::addDatabase("QMYSQL");
    m_dDatabase.setHostName("127.0.0.1");
    m_dDatabase.setDatabaseName("ddd");
    m_dDatabase.setUserName("root");
    m_dDatabase.setPassword("Soft_1202");
    if( !m_dDatabase.open() )
    {
        m_dDatabase.close();
    }
}

void LongServer::start()
{
    if( !m_tcpServer->listen(QHostAddress::Any,4001 ) )
    {
        m_tcpServer->close();
        return;
    }

    connect(m_tcpServer,&QTcpServer::newConnection,this,&LongServer::newConnect);
}

void LongServer::newConnect()
{
    //得到每个连进来的socket
    m_pTcpSocket = m_tcpServer->nextPendingConnection();
    connect( m_pTcpSocket,&QTcpSocket::readyRead,this,&LongServer::readMessage );
}

void LongServer::readMessage()
{
    //读取信息
    QByteArray tBuffer = m_pTcpSocket->readAll();
    qDebug() << tBuffer;
    QString data = QString(tBuffer);
    SysFun::AnalysisData( data );
    sendMessage();
}

void LongServer::sendMessage()
{
    QString ss = "hello Client";
    m_pTcpSocket->write(ss.toStdString().c_str(), strlen(ss.toStdString().c_str()));
}

void LongServer::OperateDataBase()
{

}
