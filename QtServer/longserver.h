﻿#ifndef LONGSERVER_H
#define LONGSERVER_H
#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>

class LongServer : public QObject
{
    Q_OBJECT
public:
    explicit LongServer(QObject *parent = 0);

public:
    void start();

signals:

public slots:
    //有连接
    void newConnect();

    //读数据
    void readMessage();

    void sendMessage();

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_pTcpSocket;
};

#endif // LONGSERVER_H
