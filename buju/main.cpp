#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>  //只能输入数字的输入框，并且带有箭头的步进按钮
#include<QSlider>    //带有滑块的滑竿
#include<QHBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Enter your age");

    QSpinBox* spinBox = new QSpinBox(&window);
    QSlider* slider = new QSlider(Qt::Horizontal, &window);
    spinBox->setRange(0,130);
    slider->setRange(0,130);

    //双向数据绑定
    QObject::connect(slider, &QSlider::valueChanged, spinBox , &QSpinBox::setValue);
    void(QSpinBox::*spinBoxSignal)(int)= &QSpinBox::valueChanged;  //创建一个函数指针，这个函数指针参数指定为int
    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);  //QSpinBox::valueChanged是一个overloaded的函数
    spinBox->setValue(35);

    QHBoxLayout  * layout = new QHBoxLayout; //布局管理器
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window.setLayout(layout);

    window.show();

    return a.exec();
}
