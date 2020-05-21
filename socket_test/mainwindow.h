#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void displayText(QString t);
    void output(float pitch, float x, float y, float pid);

};
#endif // MAINWINDOW_H
