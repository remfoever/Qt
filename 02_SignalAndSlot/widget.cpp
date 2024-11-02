#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
//Teacher   类 老师类
//Student   类 学生类


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);
    //创建一个学生对象
    this->st = new Student(this);

//    //老师饿了 学生请客的连接
//    connect(zt, &Teacher::hungry, st, &Student::treat);

//    //调用下课函数
//    classIsOver();

    //连接带参数的 信号和槽
    //指针->地址
    //函数指针->函数地址
    void(Teacher :: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student :: *studentSlot)(QString) = &Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
//    classIsOver();

    //点击一个下课按钮 再触发下课
    QPushButton * btn = new QPushButton("下课", this);
    //重置窗口大小
    this->resize(600,400);

    //点击按钮 触发下课
//    connect(btn,&QPushButton::clicked, this, &Widget::classIsOver);

    //无参版本的信号和槽连接
    void(Teacher :: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student :: *studentSlot2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked, zt, teacherSignal2);

    //断开信号
//    disconnect(zt,teacherSignal2,st,studentSlot2);
    //QT4版本 信号槽 连接无参版本
    //优点：参数直观，缺点：类型不做检测
    connect(zt,SIGNAL(hungry()), st, SLOT(treat()));

    QPushButton * btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->setText("关闭");
    btn2->move(100,0);

    connect(btn2,&QPushButton::clicked, this, [=](){
//        this->close();
//        emit zt->hungry("宫保鸡丁");
    });

//    [=](){
//      btn->setText("aaaa");
//      btn2->setText("bbbb");
//    }();

}


void Widget::classIsOver(){
//    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}



Widget::~Widget()
{
    delete ui;
}

