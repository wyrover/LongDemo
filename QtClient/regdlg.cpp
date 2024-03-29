﻿#include "regdlg.h"
#include "ui_regdlg.h"

#include "../ProtocolLogic/SysFunction.h"
#include "../ProtocolLogic/protocol.h"

RegDlg::RegDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("注册"));
}

RegDlg::~RegDlg()
{
    delete ui;
}

void RegDlg::on_MobileNum_editingFinished()
{
    QString strNumber = ui->MobileNum->text();
    ui->phnumerr->setText("");
    if( strNumber.isEmpty() )
    {
        ui->phnumerr->setText(QStringLiteral("请输入手机号"));
    }
    else if( !SysFunction::IsDigitStr(strNumber.toStdString()) )
    {
        ui->phnumerr->setText(QStringLiteral("请输入正确的手机号"));
    }
    else if( strNumber.count() != 11 )
    {
        ui->phnumerr->setText(QStringLiteral("请输入完整的手机号"));
    }
}

void RegDlg::on_Password_editingFinished()
{
    QString strPwd = ui->Password->text();
    ui->pwderror->setText("");
    if (strPwd.isEmpty() )
    {
        ui->pwderror->setText(QStringLiteral("请输入密码"));
    }
    else if( strPwd.count() < 6 )
    {
        ui->pwderror->setText(QStringLiteral("密码过于简单"));
    }
}

void RegDlg::on_SurePWD_editingFinished()
{
    QString strPwd = ui->Password->text();
    QString strSurepwd = ui->SurePWD->text();
    ui->pwdsureerr->setText("");
    if( strSurepwd.isEmpty() )
    {
        ui->pwdsureerr->setText(QStringLiteral("请确认你的密码"));
    }
    else if( strPwd != strSurepwd )
    {
        ui->pwdsureerr->setText(QStringLiteral("请输入相同的密码"));
    }
}

void RegDlg::on_RegOKButton_clicked()
{
    QString strPhoneNum = ui->MobileNum->text();
    QString strPwd = ui->SurePWD->text();
    //XYID#moblienum#password
    QString msg = QString("%1#%2#%3").arg(QString::number( GL_XYID::GLXY_REGISTER )).arg(strPhoneNum).arg(strPwd);
    SendReg(msg);
}
