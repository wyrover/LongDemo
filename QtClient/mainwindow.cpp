#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"

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
    this->setWindowTitle(tr("评评理"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::GetNext()
{
    return bNext;
}
