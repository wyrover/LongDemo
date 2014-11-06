#ifndef HALLDIALOG_H
#define HALLDIALOG_H
#include<QDialog>

//这个是主界面类

class HallDialog : public QDialog
{
    Q_OBJECT
public:
    HallDialog(QWidget *parent = 0);
    ~HallDialog();

    bool GetNext();
    int  InitSocket();
private:
    bool bNext;//是否成功登录
};

#endif // HALLDIALOG_H
