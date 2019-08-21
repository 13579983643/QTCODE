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
   QMessageBox msgBox;
   msgBox.setText("The document has been modified.");
   msgBox.setInformativeText(tr("Do you want to save your changes?"));
   msgBox.setDetailedText(tr("Differences here..."));
   msgBox. setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
   msgBox.setDefaultButton(QMessageBox::Save);

   int ret = msgBox.exec();  //模态对话框，根据其返回值进行相应的操作
   switch(ret){
    case QMessageBox::Save:
       qDebug()<<"Save document！";
    case QMessageBox::Discard:
       qDebug()<<"Discard changes!";
        break;
    case QMessageBox::Cancel:
       qDebug()<<"Close document!";
        break;

   }
}


