#include "halldialog.h"
#include"dialog.h"
#include<QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

//Boost
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <iostream>

using boost::asio::ip::tcp;


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

    InitSocket();
}
HallDialog::~HallDialog()
{

}

bool HallDialog::GetNext()
{
    return bNext;
}

int HallDialog::InitSocket()
{

    try
    {
        boost::asio::io_service IO_service;
        tcp::endpoint End_Point( boost::asio::ip::address::from_string( "127.0.0.1"), 3200 );

        tcp::socket Socket( IO_service );
        Socket.connect( End_Point );

        for( ;; )
        {
            boost::array<char,128> Buf;
            boost::system::error_code Error;

            size_t Len = Socket.read_some( boost::asio::buffer( Buf ), Error );
            if( Error == boost::asio::error::eof )
                break;
            else if( Error )
            {
                throw boost::system::system_error( Error );
            }

            std::cout.write( Buf.data(), Len );
        }
    }
    catch( std::exception &e )
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
