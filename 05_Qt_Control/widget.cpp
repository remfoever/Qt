#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidgetItem>
//#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选按钮 男默认选中
    ui->rBtnMan->setChecked(true);
    //选中女后 打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug() << "选择了女了";
    });


    //多选按钮 2是选中  0是未选中 1是半选中
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
        qDebug()<< state;
    });


    //利用listWidget写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
//    //将第一行的诗放到listWidget中
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList   QList<QString>
    QStringList list;
    list <<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);



}

Widget::~Widget()
{
    delete ui;
}

