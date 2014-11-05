//#include <QCoreApplication>
//#include <QDebug>

//Boost
#include <boost/timer.hpp>
#include <boost/asio.hpp>

//Openssl


#include <iostream>
using namespace std;

int main()
{
    boost::timer tmr;

    cout << tmr.elapsed() << "s" << endl;
    /*
    QCoreApplication a(argc, argv);

    qDebug() << tmr.elapsed() << "S" << endl;

    return a.exec();
    */
    return 0;
}
