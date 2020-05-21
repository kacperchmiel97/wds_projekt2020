#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

void MainWindow::displayText(QString t){
    ui->textEdit->setText(t);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::output(float pitch, float x, float y, float pid){

    std::cout << "P:" << pitch << " X: " << x << " Y: " << y << " PID: " << pid << '\n';
}
