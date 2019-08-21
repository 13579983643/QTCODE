#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu*file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar* toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
   //QDialog dialog(this);
   // dialog.setWindowTitle(tr("hello dialog!"));
   // dialog.exec();  //模态对话框，我们不能与主框口进任何交互，知道我们关闭了该对话框
   // qDebug() << dialog.result();
   //dialog.show();  //不会阻塞当前进程，建立在栈上，

    //建立在堆上
   // QDialog* dialog = new QDialog;
    //dialog->setAttribute(Qt::WA_DeleteOnClose);  //设置对话框关闭时，自动销毁对话框
    //dialog->setWindowTitle(tr("heelo dialog"));
    //dialog->show();


    if(QMessageBox::Yes == QMessageBox::question(this,tr("Question"),tr("Are you OK?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
    //使用QMessageBox::question()来询问一个问题，这个对话框的父窗口是this,也就是我们的MainWindow
    //这是一个模态对话框，因此我们可以直接获取其返回值
    {
        QMessageBox::information(this,tr("Hmmm..."),tr("I am glad to hear that!"));
    }else{
        QMessageBox::information(this,tr("Hmmm..."),tr("I'm sorry!"));
    }


}


