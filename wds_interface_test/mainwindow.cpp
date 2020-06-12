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

    ipDialog= new ipdialog(this);
    host_ip= "192.168.1.163";
    ipDialog->setText(host_ip);

    server= new SocketServer(this);
    sw= new ServerWindow();
    client= new SocketClient(this);

    //Ustawianie emulatora
    connect(sw, SIGNAL(sendMsg(float, float, float, float, float)), server, SLOT(sendData(float, float, float, float, float)));

    //Ustawianie wykresów
    connect(client, SIGNAL(updatePitch(float)), tiltChart, SLOT(updateValue(float)));
    connect(client, SIGNAL(updatePid(float)), pidChart, SLOT(updateValue(float)));

    //Ustawianie widżetów rysujących
    connect(client, SIGNAL(updatePitch(float)), realTimeDrawPlane, SLOT(setRotation(float)));
    connect(client, SIGNAL(updateTheta(float)), mapDrawPlane, SLOT(setRotation(float)));
    connect(client, SIGNAL(updateX(float)), mapDrawPlane, SLOT(setX(float)));
    connect(client, SIGNAL(updateY(float)), mapDrawPlane, SLOT(setY(float)));

    //Ustawianie dialogu IP
    connect(ipDialog, SIGNAL(enteredText(QString)), this, SLOT(clientConnect(QString)));

    //Inicjalizacja timera
    timer= new QTimer(this);
    QWidget::connect(timer, SIGNAL(timeout()), this, SLOT(draw(void)));

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionReset_timebase, SIGNAL(triggered()), tiltChart, SLOT(resetTime()));
    connect(ui->actionReset_timebase, SIGNAL(triggered()), pidChart, SLOT(resetTime()));
    connect(ui->actionShow_emulator, SIGNAL(toggled(bool)), this, SLOT(emulatorToggleShow(bool)));
    connect(ui->actionReconnect, SIGNAL(triggered()), ipDialog, SLOT(showWindow()));

    realTimeDrawPlane->show();
    mapDrawPlane->show();
    sw->hide();
}

void MainWindow::draw(void){
    update();
    realTimeDrawPlane->update();
    mapDrawPlane->update();
    tiltChart->update();
    pidChart->update();
}

void MainWindow::clientConnect(QString ip){
    if(!client->connectToHost(ip, 4242, 5000)){
        errorBox.setText("Could not connect to host!");
        errorBox.setWindowTitle("Error");
        errorBox.exec();
    }
    else{
        tiltChart->resetTime();
        pidChart->resetTime();
        timer->start(50);
        ipDialog->hideWindow();
    }
}

void MainWindow::connection_lost(void){
    timer->stop();
    errorBox.setText("Lost connection to host!");
    errorBox.setWindowTitle("Error");
    errorBox.exec();

    tiltChart->resetTime();
    pidChart->resetTime();
}

void MainWindow::emulatorToggleShow(bool show){
    if(show)
        sw->show();
    else
        sw->hide();
}

void MainWindow::closeEvent(QCloseEvent *event){
    sw->close();
}

MainWindow::~MainWindow(){
    delete ui;
    delete realTimeDrawPlane;
    delete mapDrawPlane;
    delete tiltChart;
    delete pidChart;
    delete sw;
    delete server;
    delete client;
    delete timer;
    delete ipDialog;

    painter->end();
}
