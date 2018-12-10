#include "myserver.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QGraphicsItem>

myServer::myServer(){}
myServer::~myServer(){}

QTcpSocket* myServer::socket = 0;

QTcpSocket* myServer::GetSocket()
{
    if(socket == NULL)
    {
        socket = new QTcpSocket();
    }
    return socket;
}

void myServer::startServer()
{
    if(this->listen(QHostAddress::Any,5555))
    {
        qDebug()<<"LISTEN";
    }
    else{
        qDebug()<<"NOT LISTEN";
    }
}

void myServer::incomingConnection(int socketDescriptor)
{
//    MainWindow* instance = MainWindow::GetInstance();
//    MainWindow mw;

    QTcpSocket* socket = myServer::GetSocket();
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));

    qDebug()<<socketDescriptor<< "Client connected";
//    socket->write("You are connect");
//    qDebug()<<"Send client connect status - YES";
}

void myServer::sockReady()
{
    instance->drawConnection();
    instance->drawingenemyLife();
    instance->show();
    getResault();
}

void myServer::sockDisc()
{
    qDebug()<<"DISCONECT";
    instance->drawDisConnection();
    instance->show();
    socket->deleteLater();
}
void myServer::send(QString x, QString y)
{
    Data += x;
    Data += y;    
    socket->write(Data);
}

void myServer::getResault()
{
    SendClient = socket->readAll();
    qDebug()<< SendClient;

    buf_ = SendClient;
    qDebug()<<buf_;

    if(buf_ == "xxx")
    {
        instance->enemylife--;
        instance->drawingenemyLife();

        instance->fire_[instance->newX][instance->newY] = 2;
        instance->drawingFire();
    }

    if(buf_.length() < 3)
    {
        char x_str = buf_[0].toLatin1();
        char y_str = buf_[1].toLatin1();

        int x = (int)x_str - 48;
        int y = (int)y_str - 48;

        if(instance->matrix_[x][y] ==1)
        {
            instance->mylife--;
            instance->drawingYourLife();
            socket->write("xxx");
        }
        instance->matrix_[x][y] = 2;
        instance->drawing();
    }
}

