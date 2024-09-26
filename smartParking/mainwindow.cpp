#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino->openConnection();
    connect(arduino, &seriallink::gotNewData, this , &MainWindow::updateGUI);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGUI(QByteArray data){
    ui->lcd_byte_received->display(ui->lcd_byte_received->value() + data.size());
}


void MainWindow::on_pushButton_clicked()
{
    if (arduino->isWritable())
        arduino->write("gate opened");
    else
        qDebug() <<"Couldn't write to serial";
}

void MainWindow::on_pushButton_2_clicked()
{
    if (arduino->isWritable())
        arduino->write("gate closed");
    else
        qDebug() <<"Couldn't write to serial";
}



























