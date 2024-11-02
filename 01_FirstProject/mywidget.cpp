#include "mywidget.h"
#include <QPushButton>	//按钮控件的头文件
#include "mypushbutton.h"
#include <QDebug>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
        //创建一个按钮
        QPushButton * btn = new QPushButton;
        //btn->show();	//show以顶层方式弹出窗口控件，让btn对象 依赖在 myWidght窗口中
        btn->setParent(this);

        //显示文本
        btn->setText("第一个按钮");

        //创建第二个按钮	按照控件大小创建窗口
        QPushButton * btn2 = new QPushButton("第二个按钮",this);

        //移动btn2按钮
        btn2->move(100,100);

        //重新制定按钮大小
        btn2->resize(50,50);

        //重置窗口大小
        resize(600,400);

        //设置固定的窗口大小
        setFixedSize(600,400);

        //设置窗口标题
        setWindowTitle("第一个窗口");

        //创建一个自己的按钮的对象
        MyPushButton * myBtn = new MyPushButton;
        myBtn ->setText("我自己的按钮");

        myBtn->move(200,0);
        myBtn->setParent(this); //设置到对象树中



        //需求    点击我的按钮 关闭窗口
        connect(myBtn, &QPushButton::clicked, this, &myWidget::close);


}

myWidget::~myWidget()
{
    qDebug() << "myWidget的析构调用";
}

