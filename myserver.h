#ifndef MYSERVER_H
#define MYSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>

namespace Ui { class MainWindow; }

class myServer: public QTcpServer
{
    Q_OBJECT

public:
    myServer();
    ~myServer();

public:

    static QTcpSocket* socket;
    static QTcpSocket* GetSocket();

    QByteArray Data;
    QByteArray SendClient;

    MainWindow* instance = MainWindow::GetInstance();
    void send(QString x, QString y);
    QString buf_;

public slots:
    void getResault();
    void startServer();
    void incomingConnection(int socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H
