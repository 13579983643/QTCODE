#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintDevice>
#include <QBitmap>
#include <QPaintEvent>

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
    QPixmap pixmap("qt-logo.png");
    QPixmap bitmap("qt-logo.png");
    painter.drawPixmap(10,10,250,125,pixmap);
    painter.drawPixmap(270,10,250,125,bitmap);
    QPixmap whitePixmap("qt-logo-white.png");
    QBitmap whiteBitmap("qt-logo-white.png");
    painter.drawPixmap(10,140,250,125,whitePixmap);
    painter.drawPixmap(270,140,250,125,whiteBitmap);
}



