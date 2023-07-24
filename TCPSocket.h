#ifndef TCP_TCPSOCKET_H
#define TCP_TCPSOCKET_H
#include "tcpserver.h"
#include "tcpclient.h"


class TCPSocket {

public:
    static void TCPSocketTry(){
        std::cout << "--- TCP Client ---" << std::endl;
        TcpClient tc;


        std::cout << "--- TCP Server ---" << std::endl;
        TcpServer ts;
        ts.accept_connection();
        ts.read_and_reply();


    }

};


#endif //TCP_TCPSOCKET_H
