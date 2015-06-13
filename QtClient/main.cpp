#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow HallWin;
    if( HallWin.GetNext() )
        HallWin.show();
    else
        return 0;

    return app.exec();
}
