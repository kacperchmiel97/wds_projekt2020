#ifndef CHART_H
#define CHART_H

#include <QObject>
#include <QWidget>
#include <QtCharts>

#define SAMPLE_COUNT 200 //!< Ilość próbek pokazywanych na wykresie
#define DT 0.05 //!< Czas pomiędzy próbkami

/*!
 * \brief Rysuje wykres XY
 */
class Chart : public QObject
{
    Q_OBJECT
public:
    Chart(QObject *parent, QWidget *widget);
    ~Chart();

    void setYMinMax(float min, float max);
    void setTitle(QString title);

public slots:
    void updateValue(float t);
    void update(void);
    void resetTime(void);

private:
    QSplineSeries *series;
    QChart *chart;
    QChartView *view;
    QAbstractAxis *xAxis, *yAxis;

    float now;
    float currentValue;
};

#endif // CHART_H
