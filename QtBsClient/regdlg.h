#ifndef REGDLG_H
#define REGDLG_H

#include <QDialog>
#include <QString>

namespace Ui {
class RegDlg;
}

class RegDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RegDlg(QWidget *parent = 0);
    ~RegDlg();

signals:
    void SendReg( const QString& msg );

private slots:
    void on_MobileNum_editingFinished();

    void on_Password_editingFinished();

    void on_SurePWD_editingFinished();

    void on_RegOKButton_clicked();

private:
    Ui::RegDlg *ui;
};

#endif // REGDLG_H
