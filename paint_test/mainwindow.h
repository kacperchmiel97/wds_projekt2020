#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QSlider>
#include "renderarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void draw(void);

private:
    QLayout *layout;
    QPainter *painter;
    Ui::MainWindow *ui;
public:
    RenderArea *renderArea;

};
#endif // MAINWINDOW_H
