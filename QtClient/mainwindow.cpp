﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"
#include <QTimer>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
}

void MainWindow::OnUpdate()
{
    //定时器处理函数

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
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    //connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError));

    //设置定时器
    /*
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(OnUpdate()));
    timer->start(1000);
    */
}

void MainWindow::readMessage()
{
    QByteArray tBuffer = m_tcpSocket->readAll();

    qDebug() << tBuffer;
    QDataStream in( m_tcpSocket );

    //设置流的版本
    in.setVersion(QDataStream::Qt_5_0);
}

void MainWindow::sendMessage()
{

}
