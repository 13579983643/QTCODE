#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QObject>
class Newspaper : public  QObject  //只有继承了QObject类的类，才具有信号槽 的能力
{
    Q_OBJECT  //凡是QObject类(不管是直接类还是间接子类，都应该在第一行添加宏)
public:
    Newspaper(const QString & name) :
        m_name(name)
    {
    }

    void send()
    {
        emit newPaper(m_name);  //emit 是Qt对C++的扩展，是一个关键字，其实也是一个宏，
    }
signals:
    void newPaper(const QString &name);
private:
    QString m_name;
};




#endif // NEWSPAPER_H
