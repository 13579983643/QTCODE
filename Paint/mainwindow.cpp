#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

PaintedWidget::PaintedWidget(QWidget*parent):  //仅仅设置了窗口的大小和标题
    QWidget(parent)
{
    resize(800,600);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent*)  //绘制部分
{
    QPainter painter(this);             //在栈上创建一个QPainter对象，接受一个QPaintDevice指针作为参数
    painter.drawLine(80,100,650,500);
    painter.setPen(Qt::red);
    painter.drawRect(10,10,100,400);
    painter.setPen(QPen(Qt::green,5));  //OpenGL是一个状态机，保存的只是各种状态
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50,150,400,200);

}




