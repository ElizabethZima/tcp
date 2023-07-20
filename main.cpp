//#include <QCoreApplication>
//#include <QDebug>
//#include <iostream>
//#include <fstream>
//#include "tcpclient.h"
//#include "tcpserver.h"
//#include "iostream"
//using namespace std;
//
//
//
//int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);
//
//    std::cout << "--- TCP Client ---" << std::endl;
//    TcpClient tc;
//
//    std::cout << "--- TCP Server ---" << std::endl;
//    TcpServer ts;
//}


#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создание объекта JSON
    QJsonObject jsonObject;
    jsonObject["name"] = "John Doe";
    jsonObject["age"] = 30;
    jsonObject["city"] = "New York";

    // Преобразование объекта JSON в документ JSON
    QJsonDocument jsonDoc(jsonObject);

    // Преобразование документа JSON в строку
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);

    qDebug() << "JSON строка:" << jsonString;

    // Парсинг строки JSON обратно в объекты Qt
    QJsonParseError parseError;
    QJsonDocument parsedDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Ошибка парсинга JSON:" << parseError.errorString();
        return -1;
    }

    if (!parsedDoc.isObject()) {
        qWarning() << "Документ не является объектом";
        return -1;
    }

    // Получение корневого объекта из документа JSON
    QJsonObject parsedObj = parsedDoc.object();

    QString name = parsedObj.value("name").toString();
    int age = parsedObj.value("age").toInt();
    QString city= parsedObj.value("city").toString();

    qDebug() << "Полученные данные:";
    qDebug() << "- Имя:" << name;
    qDebug() << "- Возраст:" << age;
    qDebug() << "- Город:" << city;

    return a.exec();
}