#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QEvent>
#include <QWidget>

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


class Label:public QWidget
{
public:
    Label()
    {
        installEventFilter(this);
    }

    bool eventFilter(QObject * watched,QEvent *event )
    {
        if(watched ==this){
            if( event->type() == QEvent::MouseButtonPress){
                qDebug() << "eventFilter";
            }
        }
        return false;
    }
protected:
    void mousePressEvent( QMouseEvent*)
    {
        qDebug() << "mousePressEvent";
    }

    bool event(QEvent * e)
    {
        if(e->type() == QEvent::MouseButtonPress ){
            qDebug() << "event";
        }
        return QWidget::event(e);
    }
};

class EventFilter: public QObject
{
public:
    EventFilter(QObject* watched, QObject* parent =0):
        QObject(parent),
        m_watched(watched)
    {

    }
    bool eventFilter(QObject* watched, QEvent * event)
    {
        if(watched == m_watched){
            if(event->type()== QEvent::MouseButtonPress){
                qDebug() << "QApplication::eventFilter";
            }
        }
        return false;
    }

private:
     QObject * m_watched;
};










#endif // MAINWINDOW_H
