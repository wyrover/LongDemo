#include "halldialog.h"
#include"dialog.h"
#include<QMessageBox>
#include <QApplication>
#include<QDesktopWidget>

HallDialog::HallDialog(QWidget *parent)
    : QDialog(parent)
{
    Dialog LoginDlg;
    if( LoginDlg.exec() == QDialog::Accepted )//实现应用程序级别的模态对话框
        bNext = true;
    else
        bNext = false;

    //设置窗口的最大最小化
    setWindowFlags( Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint );

    QDesktopWidget *d = QApplication::desktop();
    QRect screenRect = d->screenGeometry();//获取桌面分辩率

    resize( screenRect.width(),screenRect.height() );
}
HallDialog::~HallDialog()
{

}

bool HallDialog::GetNext()
{
    return bNext;
}

