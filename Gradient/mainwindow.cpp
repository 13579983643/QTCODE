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

void PaintedWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    QLinearGradient linearGradient(60,50,200,200);
    linearGradient.setColorAt(0.2,Qt::white);
    linearGradient.setColorAt(0.6,Qt::green);
    linearGradient.setColorAt(1.0,Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(50,50,200,150);
}
