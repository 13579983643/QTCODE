#include "mainwindow.h"
#include <QApplication>
#include<QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(0,0,300,300);
    scene.addLine(0,0,150,150);

    QGraphicsView viem(&scene);
    viem.setWindowTitle("Graphics Viem");
    //viem.resize(500,500);
    viem.show();


    return a.exec();
}
