#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel*label = new QLabel("hello world");  //app退出时，组件 却没有关闭，程序就会崩溃
    label->show();
    //QLabel label("hello,world");
    //label.show();
    return app.exec();
}
