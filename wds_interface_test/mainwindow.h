#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include "../paint_test/realtimerenderer.h"
#include "../paint_test/maprenderer.h"
#include "chart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void draw(void);

private:
    QLayout *layout;
    QPainter *painter;
    Ui::MainWindow *ui;

public:
    RealtimeRenderer *realTimeDrawPlane;
    MapRenderer *mapDrawPlane;
    Chart *tiltChart;
    Chart *pidChart;
};
#endif // MAINWINDOW_H
