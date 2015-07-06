#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"
#include <QDataStream>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include "../ProtocolLogic/protocol.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Init();
    LoginDialog LoginDlg;
    connect( &LoginDlg, &LoginDialog::SendLogin, this, &MainWindow::sendMessage);
    connect( &LoginDlg, &LoginDialog::SendReg, this, &MainWindow::sendMessage);
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
    m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost("127.0.0.1",4001);
    if( !m_tcpSocket->waitForConnected() )
    {
        return;
    }
    connect( m_tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::readMessage );

}

void MainWindow::readMessage()
{
    QByteArray tBuffer = m_tcpSocket->readAll();

    qDebug() << tBuffer;

}

void MainWindow::sendMessage(const QString& msg )
{
    m_tcpSocket->write(msg.toStdString().c_str(), strlen(msg.toStdString().c_str()));
    //m_tcpSocket->write(block,sizeof(block));
    m_tcpSocket->waitForBytesWritten();
    qDebug() << msg;
}

void MainWindow::on_pushButton_clicked()
{
    QString msg = QString::number( GL_XYID::GLXY_TEST );
    sendMessage(msg);
}
