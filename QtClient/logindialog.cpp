#include "logindialog.h"
#include "ui_logindialog.h"

#include "regdlg.h"
#include "mainwindow.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    m_sParent = parent;
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("登录"));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_regbutton_clicked()
{
    RegDlg regdlg;
    connect( &regdlg, &RegDlg::SendReg, this, &LoginDialog::ReadReg);
    regdlg.exec();
}

void LoginDialog::on_loginbutton_clicked()
{
    SendLogin("kkdkkdk");
    accept();
}

void LoginDialog::on_Username_editingFinished()
{
    QString strName = ui->Username->text();
    ui->nikeerror->setText("");
    if( strName.isEmpty() )
    {
        ui->nikeerror->setText(QStringLiteral("请输入注册的手机号"));
    }
    else if( strName.length() != 11)
    {
       ui->nikeerror->setText(QStringLiteral("手机号输入错误"));
    }

}


void LoginDialog::ReadReg( const QString& msg )
{
    SendReg(msg);
}

