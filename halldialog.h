#ifndef HALLDIALOG_H
#define HALLDIALOG_H
#include<QDialog>

class HallDialog : public QDialog
{
    Q_OBJECT
public:
    HallDialog(QWidget *parent = 0);
    ~HallDialog();

    bool GetNext();
private:
    bool bNext;//是否成功登录
};

#endif // HALLDIALOG_H
