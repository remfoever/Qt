#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->actionnew->setIcon(QIcon("D:/MyQT/02_QtSource/Image/Back_pressed"));
    //使用添加Qt资源": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/new/prefix1/Image/Back_pressed"));
    ui->actionopen->setIcon(QIcon(":/new/prefix1/Image/Back_pressed"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

