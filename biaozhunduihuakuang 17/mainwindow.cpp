#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QKeySequence>
#include<QTextEdit>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    saveAction = new QAction(QIcon(":/images/doc-open"),tr("&save..."),this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);

    QMenu*file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);


    QToolBar* toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".",tr("Text Files(*.txt)"));
    //来获取需要打开的文件的路径，（父窗口，对话框标题，对话框打开时的默认目录，过滤器）
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text ))//只读方式文本方式
        {
            QMessageBox::warning(this,tr("Read File"),tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }else{
        QMessageBox::warning(this,tr("PATH"),tr("You did not select any file."));

    }
}

void MainWindow::saveFile()
{
    QString path =QFileDialog::getSaveFileName(this,tr("Open File"),".",tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("Write File"),tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out<< textEdit->toPlainText();
        file.close();

    }else{
        QMessageBox::warning(this, tr("Path"),tr("You did not select any file."));

    }
}













