#include "dialog.h"
#include<QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    UserName = new QLineEdit;
    UserName->setMaxLength(20);

    PassWord = new QLineEdit;
    PassWord->setEchoMode(QLineEdit::Password);
    PassWord->setMaxLength(20);

    LoginBtn = new QPushButton(tr("Login"));


    connect(LoginBtn,&QPushButton::clicked,this,&Dialog::Login);

    QVBoxLayout *mLayout = new QVBoxLayout;
    mLayout->addWidget(UserName);
    mLayout->addWidget(PassWord);
    mLayout->addWidget(LoginBtn);
    setLayout(mLayout);

    resize(300,300);
}

Dialog::~Dialog()
{

}

void Dialog::Login()
{

}
