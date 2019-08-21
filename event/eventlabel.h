#ifndef EVENTLABEL_H
#define EVENTLABEL_H
#include<QLabel>
#include<QMouseEvent>
#include<QString>

class EventLabel:public QLabel  //eventlabel 继承了Qlabel 覆盖了 press move release 三个函数
{
protected:
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
};

void EventLabel::mouseMoveEvent(QMouseEvent * event)  //使用HTML来格式化文字
{
    this->setText(QString("<center><h1>Move:(%1,%2)</h1></center>").arg(QString::number(event->x()), QString::number(event->y()))); //x替换%1 ，y替换%2
}

void EventLabel::mousePressEvent(QMouseEvent * event)
{
    this->setText(QString("<center><h1>Press:(%1,%2)</h1></center>").arg(QString::number(event->x()), QString::number(event->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent* event)
{
    QString msg;
    msg.sprintf("<center><h1>Release:(%d,%d)</h1></center>",event->x(),event->y());
    this->setText(msg);
}

#endif // EVENTLABEL_H
