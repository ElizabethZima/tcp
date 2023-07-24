#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <fstream>
#include "TCPSocket.h"
#include "iostream"
using namespace std;



int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TCPSocket::TCPSocketTry();


    return QCoreApplication::exec();

}

