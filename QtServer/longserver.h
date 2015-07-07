#ifndef LONGSERVER_H
#define LONGSERVER_H
#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QString>

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

    //功能函数
public:
    //数据库存储
    void OperateDataBase();

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_pTcpSocket;
    QSqlDatabase m_dDatabase;
};

#endif // LONGSERVER_H
