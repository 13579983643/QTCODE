//#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button("Quit");
    //QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    QObject::connect(&button, &QPushButton::clicked, [](bool){qDebug() << "You CLICKED ME!";});

    button.show();
    //MainWindow w;
    //w.show();

    return app.exec();
}
