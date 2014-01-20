#include "dialog.h"
#include<QVBoxLayout>
#include<halldialog.h>

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

void Dialog::Login()
{

    HallDialog *HallDlg = new HallDialog;
    HallDlg->setWindowTitle(tr("Hall"));
    HallDlg->exec();

//    this->hide();
}
