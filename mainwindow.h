#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow* GetInstance(QWidget* parent = 0);

    int matrix_[10][10];
    int fire_[10][10];
    int mylife = 10;
    int enemylife = 10;
    int newX = 0;
    int newY = 0;

public:
    Ui::MainWindow *ui;
    static MainWindow* mainInstance;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text_;
    QGraphicsTextItem *connection;
    void mousePressEvent(QMouseEvent *ev);


public:

    //matrix
    void drawing();
    void createMatrix();
    void creatShip();
    //fire
    void createFireMatrix();
    void drawingFire();
    //life
    void drawingYourLife();
    void drawingenemyLife();
    //conection
    void drawConnection();
    void drawDisConnection();
};

#endif // MAINWINDOW_H
