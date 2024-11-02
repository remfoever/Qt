#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    //点击移动按钮，移动图片
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //如果要手动调用绘图事件  用update更新
        update();
    });



}

//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
//    //实例化画家对象   this指定是绘图设备
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(255,0,0));
//    //设置笔的宽度
//    pen.setWidth(3);
//    //设置画笔风格
//    pen.setStyle(Qt::DotLine);
//    //让画家使用画笔
//    painter.setPen(pen);


//    //设置画刷
//    QBrush brush(Qt::cyan);
//    //设置画刷风格
//    brush.setStyle(Qt::Dense7Pattern);

//    //让画家使用画刷
//    painter.setBrush(brush);

//    //划线
//    painter.drawLine(QPoint(0,0), QPoint(100,100));
//    //画圆    椭圆
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //画文字
//    painter.drawText(QRect(10,200,200,50) , "好好学习，天天向上");



    /////////////////////////高级设置/////////////////////////
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置抗锯齿能力   效率比较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));
//    //移动画家
//    painter.translate(100,0);

//    //保存画家状态
//    painter.save();

//    painter.drawRect(QRect(20,20,50,50));

//    painter.translate(100,0);
//    //还原画家保存状态
//    painter.restore();

//    painter.drawRect(QRect(20,20,50,50));



    /////////////////////////利用画家 画资源图片/////////////////////////

//    QTimer * timer = new QTimer(this);
//    timer->start(500);
//    connect(timer,&QTimer::timeout,[=](){
//    static int cnt = 1;

//        PosX = (cnt++)*10;
//        update();
//    });

    QPainter painter(this);
    //如果超出屏幕 从0开始
    if(PosX > this->width())
    {
        PosX = 0;
    }
    PosX += 20;
    painter.drawPixmap(QPoint(PosX,100),QPixmap(":/Image/Back_pressed.png"));



}


Widget::~Widget()
{
    delete ui;
}

