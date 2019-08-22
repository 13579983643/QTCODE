#include "mainwindow.h"
#include <QApplication>
#include <QPaintEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PaintedWidget paint;
    paint.show();

    return a.exec();
}
