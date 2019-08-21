//#include "mainwindow.h"
#include <QApplication>
#include"eventlabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EventLabel* label= new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300,200);
    label->show();
    //组建至少在移除鼠标点击后，才能被追踪，也就是能够发出mouseMoveEvent() 事件
    return a.exec();
}
