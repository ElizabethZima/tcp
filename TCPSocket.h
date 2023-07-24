#ifndef TCP_TCPSOCKET_H
#define TCP_TCPSOCKET_H
#include "tcpserver.h"
#include "tcpclient.h"
#include <QTime>

void delay(){
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
};

class TCPSocket {

public:
    static void TCPSocketTry(){
        std::cout << "--- TCP Client ---" << std::endl;
        TcpClient tc;

        delay();

        std::cout << "--- TCP Server ---" << std::endl;
        TcpServer ts;
        ts.accept_connection();
        ts.read_and_reply();

        delay();


    }

};


#endif //TCP_TCPSOCKET_H
