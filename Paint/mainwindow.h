#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class PaintedWidget : public QWidget
{
  Q_OBJECT
 public:
    PaintedWidget(QWidget * parent = 0);
 protected:
    void paintEvent(QPaintEvent*);

};


#endif // MAINWINDOW_H
