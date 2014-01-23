#include "halldialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HallDialog HallDlg;
    if( HallDlg.GetNext() )
        HallDlg.show();//实现非模态对话框
    else
        return 0;

    return a.exec();
}
