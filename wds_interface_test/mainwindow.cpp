#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    ui= new Ui::MainWindow;

    ui->setupUi(this);

    update();
    show();

    realTimeDrawPlane= new RealtimeRenderer(ui->realtime_widget);
    mapDrawPlane= new MapRenderer(ui->map_widget);

    tiltChart= new Chart(this, ui->tiltchart_widget);
    tiltChart->setTitle("Tilt");
    tiltChart->setYMinMax(-60, 60);

    pidChart= new Chart(this, ui->pidchart_widget);
    pidChart->setTitle("PID response");
    pidChart->setYMinMax(-1000, 1000);

    realTimeDrawPlane->show();
    mapDrawPlane->show();
}

void MainWindow::draw(void){
    update();
    realTimeDrawPlane->update();
    mapDrawPlane->update();
    tiltChart->update();
    pidChart->update();
}

MainWindow::~MainWindow(){
    delete ui;
    delete realTimeDrawPlane;
    delete mapDrawPlane;
    delete tiltChart;
    delete pidChart;

    painter->end();
}


