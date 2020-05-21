#include "chart.h"

Chart::Chart(QObject *parent, QWidget *widget) : QObject(parent)
{
    series= new QSplineSeries;
    chart= new QChart;
    view= new QChartView(chart, widget);

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("A Chart");

    xAxis= chart->axes()[0];
    yAxis= chart->axes()[1];

    view->setRenderHint(QPainter::Antialiasing);
    view->setGeometry(widget->geometry());

    now= 0;

    for(uint i= 0; i < SAMPLE_COUNT; i++){
        series->append(now, 0);
        now+= DT;
    }

    xAxis->setMin(now - DT * SAMPLE_COUNT);
    xAxis->setMax(now);

    view->show();
}

Chart::~Chart(){
    delete series;
    delete chart;
    delete view;
}

void Chart::setYMinMax(float min, float max){
    yAxis->setMin(min);
    yAxis->setMax(max);
}

void Chart::setTitle(QString title){
    chart->setTitle(title);
}

void Chart::update(void){
    series->append(now, currentValue);
    series->remove(0);

    now+= DT;
    xAxis->setMin(now - DT * SAMPLE_COUNT);
    xAxis->setMax(now);

    view->update();
}

void Chart::updateValue(float t){
    currentValue= t;
}