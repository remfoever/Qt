#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);

    //QSpinBox 移动  QSlider跟着移动

    void(QSpinBox:: * spSignal ) (int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);

    //QSlider滑动 QSpin跟着改变
    connect(ui->horizontalSlider, &QSlider::valueChanged,ui->spinBox, QSpinBox::setValue);

}



//设置数字
void smallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}
//获取数字
int smallWidget::getNum() {
    return ui->spinBox->value();
}













smallWidget::~smallWidget()
{
    delete ui;
}
