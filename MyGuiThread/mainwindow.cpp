#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _thread = new MyThread(this);
    connect(_thread, &MyThread::numberChanged, this, &MainWindow::onNumberChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNumberChanged(int i)
{
    ui->label->setText(QString::number(i));
}

void MainWindow::on_pushButton_clicked()
{
    //started
    _thread->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    //stoped
    _thread->setStop(true);
}
