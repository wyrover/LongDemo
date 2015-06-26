#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //
    Init();

    LoginDialog LoginDlg;
    //模态对话框
    if( LoginDlg.exec() == QDialog::Accepted )
        bNext = true;
    else
        bNext = false;

    ui->setupUi(this);
    this->setWindowTitle("评评理");
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
    //Initialization socket

    //设置定时器
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(OnUpdate()));
    timer->start(1000);
}
