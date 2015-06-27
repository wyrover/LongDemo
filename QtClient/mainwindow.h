#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    bool GetNext();

    void Init();

private:
    Ui::MainWindow *ui;

public slots:
    void readMessage();

    void sendMessage();

private slots:
    void on_pushButton_clicked();

private:
    bool bNext;
    QTcpSocket* m_tcpSocket;
};

#endif // MAINWINDOW_H
