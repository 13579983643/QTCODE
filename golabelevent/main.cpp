#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QEvent>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Label label;
    app.installEventFilter(new EventFilter(&label,&label));
    label.show();
    return app.exec();
}
