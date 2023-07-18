

#ifndef TCP_TCPCLIENT_H
#define TCP_TCPCLIENT_H


#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
Q_OBJECT

public:
    TcpClient(QObject *p = 0);
    ~TcpClient();

public slots:
    void send_msg(); // отправляем сообщение на сервер
    void read_msg(); // Считываем информацию, возвращаемую сервером
    void end_connent(); // Запрос после отключения

private:
    QTcpSocket *tSocket;
};

#endif // TCPCLIENT_H

#endif //TCP_TCPCLIENT_H
