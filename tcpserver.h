#ifndef TCP_TCPSERVER_H
#define TCP_TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>

class TcpServer : QTcpServer
{
Q_OBJECT

public:
    TcpServer(QTcpServer *p = nullptr);
    ~TcpServer();

    void accept_connection(); // Обрабатываем запрос на подключение
    void read_and_reply(); // читаем сообщение и отвечаем, затем отключаемся

private:
    QTcpServer *tServer;
    QTcpSocket *tSocket;
};



#endif //TCP_TCPSERVER_H
