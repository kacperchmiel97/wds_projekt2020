#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <iostream>

/*!
 * \brief Inicjalizuje okno emulatora
 * \param parent
 */
ServerWindow::ServerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);

    ui->pitchSlider->setMinimum(-60);
    ui->pitchSlider->setMaximum(60);

    ui->thetaSlider->setMinimum(-180);
    ui->thetaSlider->setMaximum(180);

    ui->xSlider->setMinimum(-250);
    ui->xSlider->setMaximum(250);
    ui->ySlider->setMinimum(-250);
    ui->ySlider->setMaximum(250);

    ui->pidSlider->setMinimum(-1000);
    ui->pidSlider->setMaximum(1000);

    pitch= x= y= theta= pid= 0;


    connect(ui->pitchSlider, SIGNAL(valueChanged(int)), this, SLOT(sendPitch(int)));
    connect(ui->thetaSlider, SIGNAL(valueChanged(int)), this, SLOT(sendTheta(int)));
    connect(ui->xSlider, SIGNAL(valueChanged(int)), this, SLOT(sendX(int)));
    connect(ui->ySlider, SIGNAL(valueChanged(int)), this, SLOT(sendY(int)));
    connect(ui->pidSlider, SIGNAL(valueChanged(int)), this, SLOT(sendPid(int)));
}

ServerWindow::~ServerWindow()
{
    delete ui;
}
