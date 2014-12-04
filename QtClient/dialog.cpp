#include "dialog.h"
#include <QVBoxLayout>
#include "halldialog.h"
#include <QHBoxLayout>

#include "sysfunction.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    UserName = new QLineEdit;
    UserName->setMaxLength(60);

    PassWord = new QLineEdit;
    PassWord->setEchoMode(QLineEdit::Password);
    PassWord->setMaxLength(30);

    LoginBtn = new QPushButton(tr("登录"));

    RememberPwd = new QCheckBox(tr("记住密码"));

    AutoLogin = new QCheckBox(tr("自动登录"));


    connect(LoginBtn,&QPushButton::clicked,this,&Dialog::accept);
    connect(RememberPwd,&QCheckBox::clicked,this,&Dialog::CheckRemPwd);
    connect(AutoLogin,&QCheckBox::clicked,this,&Dialog::CheckAuto);

    QHBoxLayout *rLayout = new QHBoxLayout;
    rLayout->addWidget(RememberPwd);
    rLayout->addWidget(AutoLogin);

    QVBoxLayout *mLayout = new QVBoxLayout;
    mLayout->addWidget(UserName);
    mLayout->addWidget(PassWord);
    mLayout->addLayout(rLayout);
    mLayout->addWidget(LoginBtn);
    setLayout(mLayout);

    resize(300,300);
}

Dialog::~Dialog()
{
    if( UserName != nullptr )
    {
        delete UserName;
        UserName = nullptr;
    }
    if( PassWord != nullptr )
    {
        delete PassWord;
        PassWord = nullptr;
    }
    if( LoginBtn != nullptr )
    {
        delete LoginBtn;
        LoginBtn = nullptr;
    }
}

void Dialog::accept()
{
    if( RememberPwd->isChecked() )
    {
        //UserName->text();
        //SysFunction::ShareFunction()->SaveStringData();
    }
    QDialog::accept();
}

void Dialog::CheckAuto()
{
    RememberPwd->setChecked(true);
}

void Dialog::CheckRemPwd()
{

}



