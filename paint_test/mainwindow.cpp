#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    painter= new QPainter(this);

    layout= new QHBoxLayout();
    renderArea= new RenderArea(this);

    ui->verticalSlider->setMaximum(60);
    ui->verticalSlider->setMinimum(-60);


    show();
    renderArea->setGeometry(ui->widget1->geometry());
    QWidget::connect(ui->verticalSlider, SIGNAL(valueChanged(int)), renderArea, SLOT(setRotation(int)));
    QWidget::connect(ui->verticalSlider, SIGNAL(valueChanged(int)), renderArea, SLOT(draw(void)));
}

void MainWindow::resizeEvent(QResizeEvent *){
    renderArea->setGeometry(ui->widget1->geometry());
}

void MainWindow::draw(void){
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
    painter->end();
}

