#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"
#include <QDataStream>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QString>
#include "protocol.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Init();
    LoginDialog LoginDlg;

    //模态对话框
    if( LoginDlg.exec() == QDialog::Accepted )
        bNext = true;
    else
        bNext = false;

    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("评评理"));
}

MainWindow::~MainWindow()
{
    delete ui;
    m_tcpSocket->close();
}

bool MainWindow::GetNext()
{
    return bNext;
}

void MainWindow::Init()
{
    //初始化Socket线程
    /*
    SocketThread *socketThread = new SocketThread(this);
    //线程完成后删除自身的信号槽绑定
    connect( socketThread, &QThread::finished, socketThread, &QThread::deleteLater );
    //启动线程
    socketThread->start();
       */

    m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost("127.0.0.1",4001);
    const int nTimeout = 5 * 1000;
    if( !m_tcpSocket->waitForConnected( nTimeout ) )
    {
        //emit error(m_tcpSocket->error(), m_tcpSocket->errorString());
        return;
    }
    connect( m_tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::readMessage );

}

void MainWindow::readMessage()
{
    QByteArray tBuffer = m_tcpSocket->readAll();

    qDebug() << tBuffer;

}

void MainWindow::sendMessage()
{
    msgTest obj;
    obj.nFlag = 1;

    char cBuffer[1024];
    memcpy( cBuffer, &obj, sizeof(msgTest));

    QByteArray block;
    QDataStream out( &block, QIODevice::ReadWrite );
    out.setVersion( QDataStream::Qt_5_5 );
    out << (quint32) 0;
    out << msgTest::XY_ID;
    //设置发送内容
    out.writeBytes(cBuffer,sizeof(cBuffer));

    out.device()->seek(0);
    out << (quint32) (block.size() - sizeof(quint32));


    m_tcpSocket->write(block,sizeof(block));

    qDebug() << block;
}


void MainWindow::on_pushButton_clicked()
{
    sendMessage();
}
