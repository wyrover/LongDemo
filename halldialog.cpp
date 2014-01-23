#include "halldialog.h"
#include"dialog.h"
#include<QMessageBox>

HallDialog::HallDialog(QWidget *parent)
    : QDialog(parent)
{
    Dialog LoginDlg;
    if( LoginDlg.exec() == QDialog::Accepted )//实现应用程序级别的模态对话框
        bNext = true;
    else
        bNext = false;



    resize( 500,500 );
}
HallDialog::~HallDialog()
{

}

bool HallDialog::GetNext()
{
    return bNext;
}

