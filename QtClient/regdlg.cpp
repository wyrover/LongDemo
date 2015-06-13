#include "regdlg.h"
#include "ui_regdlg.h"

#include "sysfun.h"

RegDlg::RegDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegDlg)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("注册"));
}

RegDlg::~RegDlg()
{
    delete ui;
}

void RegDlg::on_MobileNum_editingFinished()
{
    QString strNumber = ui->MobileNum->text();
    ui->phnumerr->setText(tr(""));
    if( strNumber.isEmpty() )
    {
        ui->phnumerr->setText(tr("请输入手机号"));
    }
    else if( !SysFun::isDigitStr(strNumber) )
    {
        ui->phnumerr->setText(tr("请输入正确的手机号"));
    }
    else if( strNumber.count() != 11 )
    {
        ui->phnumerr->setText(tr("请输入完整的手机号"));
    }
}

void RegDlg::on_Password_editingFinished()
{
    QString strPwd = ui->Password->text();
    ui->pwderror->setText(tr(""));
    if (strPwd.isEmpty() )
    {
        ui->pwderror->setText(tr("请输入密码"));
    }
    else if( strPwd.count() < 6 )
    {
        ui->pwderror->setText(tr("密码过于简单"));
    }
}

void RegDlg::on_SurePWD_editingFinished()
{
    QString strPwd = ui->Password->text();
    QString strSurepwd = ui->SurePWD->text();
    ui->pwdsureerr->setText(tr(""));
    if( strSurepwd.isEmpty() )
    {
        ui->pwdsureerr->setText(tr("请确认你的密码"));
    }
    else if( strPwd != strSurepwd )
    {
        ui->pwdsureerr->setText(tr("请输入相同的密码"));
    }
}

void RegDlg::on_RegOKButton_clicked()
{

}
