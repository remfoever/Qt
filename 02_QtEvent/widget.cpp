#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
   id1 = startTimer(1000);   //参数1 间隔 单位ms
    //启动定时器
   id2 = startTimer(2000);   //参数1 间隔 单位ms


   //定时器的第二种方式
   QTimer * timer = new QTimer(this);
   //启动定时器
   timer->start(500);
   connect(timer,&QTimer::timeout,[=](){
       static int num4 =1;

       //label4每隔0.5s + 1
       ui->label_4->setText(QString::number(num4++));
    });

   //点击暂停 实现停止定时器

   connect(ui->btn,&QPushButton::clicked,[=](){
       timer->stop();
   });


   //给label1 安装事件过滤器
   //步骤一 安装事件过滤器
   ui->label->installEventFilter(this);
}


//步骤二 重写事件过滤器的事件
bool Widget::eventFilter(QObject * obj,QEvent * e){
    if(obj == ui->label)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent * ev = static_cast<QMouseEvent *>(e);
            QString str = QString("事件过滤器中::鼠标按下了 x=%1  y=%2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug()<<str;
            return true;    //代表用户自己处理这个事件，不向下发表
        }
    }
    //其他默认处理
    return QWidget::eventFilter(obj,e);
}



//重写定时器事件
void Widget::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == id1) {
        static int num =1;

        //label2每隔1s + 1
        ui->label_2->setText(QString::number(num++));
    }


    if (e->timerId() == id2) {
        static int num2 =1;

         //label3每隔2s + 1
        ui->label_3->setText(QString::number(num2++));
    }


}




Widget::~Widget()
{
    delete ui;
}

