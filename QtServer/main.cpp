//#include <QCoreApplication>
//#include <QDebug>

//Boost
#include <ctime>
#include <string>
#include <memory>
#include <functional>
#include <boost/asio.hpp>

//Openssl


#include <iostream>

using boost::asio::ip::tcp;
using namespace std;

void process_client( shared_ptr<tcp::socket> client )
{
    time_t now = time(0);
    shared_ptr<string> message( new string( ctime( &now ) ) );

    auto callback =[=]( const boost::system::error_code &err, size_t size )
    {
        if( (int)size == message->length() )
            cout << "write completed" << endl;
    };

    client->async_send( boost::asio::buffer( *message ), callback );
}

typedef function<void( const boost::system::error_code & )> accept_callback;

void start_accept( tcp::acceptor &server )
{
    shared_ptr<tcp::socket> client( new tcp::socket( server.get_io_service() ) );

    accept_callback callback = [&server,client]( const boost::system::error_code &error )
    {
        if( !error )
            process_client( client );

        start_accept( server );
    };

    server.async_accept( *client, callback );
}

int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 3200));
        start_accept(acceptor);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    /*
    QCoreApplication a(argc, argv);

    qDebug() << tmr.elapsed() << "S" << endl;

    return a.exec();
    */
    return 0;
}
