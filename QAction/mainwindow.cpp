#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Main Window"));  //设置主窗口的标题   文本使用tr()函数用于QT 国际化

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&open..."),this);  //在堆上创建openAction对象，传入一个图标、一个文本、一个指针
    openAction->setShortcuts(QKeySequence::Open);  //用于定义快捷键
    openAction->setStatusTip(tr("Open an existing file"));   //鼠标滑过这个action 时，会在主窗口的下方显示相应的提示
    connect(openAction,&QAction::triggered,this, &MainWindow::open);


    QMenu*file = menuBar()->addMenu(tr("&File"));  //menuBar()函数，创建一个菜单栏，
    file->addAction(openAction);

    QToolBar*toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    statusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("open"));
}
