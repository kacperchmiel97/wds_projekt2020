#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = nullptr);
    ~ServerWindow();

signals:
    void sendMsg(float pitch, float x, float y, float t, float pid);

private slots: 
    void sendPitch(int p){
        pitch= (float)p;
        emit sendMsg(pitch, x, y, theta, pid);
    }

    void sendTheta(int t){
        theta= (float)t;
        emit sendMsg(pitch, x, y, theta, pid);
    }

    void sendX(int _x){
        x= (float)_x;
        emit sendMsg(pitch, x, y, theta, pid);
    }

    void sendY(int _y){
        y= (float)_y;
        emit sendMsg(pitch, x, y, theta, pid);
    }

    void sendPid(int _pid){
        pid= (float)_pid;
        emit sendMsg(pitch, x, y, theta, pid);
    }

private:
    Ui::ServerWindow *ui;
    float pitch, x, y, theta, pid;
};

#endif // SERVERWINDOW_H
