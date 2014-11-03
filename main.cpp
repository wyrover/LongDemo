#include "halldialog.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QTextCodec>

#include <iostream>
#include <fstream>
using namespace std;

fstream g_log;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*
    //中文支持
    QTextCodec *codec = QTextCodec::codecForName( "UTF-8" );
    QTextCodec::setCodecForLocale( codec );
    QFile file("./Log.txt");
    if( !file.open( QIODevice::ReadWrite | QIODevice::Text ) )
    {
        qDebug() << "Can't open the file!" << endl;
    }
    */

    g_log.open( "Log.txt", ios::out );
    if( g_log.is_open() )
        g_log << "------------ Start Log ----------------------" << endl;

    HallDialog HallDlg;
    if( HallDlg.GetNext() )
        HallDlg.show();//实现非模态对话框
    else
        return 0;

    int ret = app.exec();

    g_log << "------------ End Log ----------------------" << endl;
    g_log.close();
    return ret;
}
