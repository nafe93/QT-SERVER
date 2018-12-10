#include <QApplication>
#include "mainwindow.h"
#include "myserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow *w = new MainWindow();
    MainWindow* instance = MainWindow::GetInstance();
    myServer server;

    instance->show();

    instance->createMatrix();
    instance->createFireMatrix();
    instance->creatShip();
    instance->drawingYourLife();

    instance->drawingFire();
    instance->drawing();

    server.startServer();

    return a.exec();
}
