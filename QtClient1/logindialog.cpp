﻿#include "logindialog.h"
#include "ui_logindialog.h"

#include "regdlg.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_regbutton_clicked()
{
    RegDlg regdlg;
    regdlg.exec();
}

void LoginDialog::on_loginbutton_clicked()
{
    accept();
}

void LoginDialog::on_Username_editingFinished()
{
    QString strName = ui->Username->text();
    ui->nikeerror->setText("");
    if( strName.isEmpty() )
    {
        ui->nikeerror->setText("请输入注册的手机号");
    }
    else if( strName.length() != 11)
    {
       ui->nikeerror->setText("手机号输入错误");
    }

}