#include "mainwindow.h"
#include "console.h"
#include <QApplication>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>

#include "../socket_test/socketclient.h"
#include "../socket_test/socketserver.h"
#include "../socket_test/serverwindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QMessageBox errorBox;
    MainWindow w; //!< Okno główne programu
    ServerWindow sw; //!< Okno emulatora
    SocketServer server(&sw); //!< Emulator
    SocketClient client(&w); //!< Odbiornik danych
    QTimer *timer; //!< Timer aktualizujący główne okno

    w.setWindowTitle("Interfejs robota balansującego");

    //Łączenie z hostem
    if(!client.connectToHost("127.0.0.1", 4242, 500000)){
        errorBox.setText("Could not connect to host!");
        errorBox.exec();
        return -1;
    }

    //Ustawianie emulatora
    QObject::connect(&sw, SIGNAL(sendMsg(float, float, float, float, float)), &server, SLOT(sendData(float, float, float, float, float)));

    //Ustawianie wykresów
    QWidget::connect(&client, SIGNAL(updatePitch(float)), w.tiltChart, SLOT(updateValue(float)));
    QWidget::connect(&client, SIGNAL(updatePid(float)), w.pidChart, SLOT(updateValue(float)));

    //Ustawianie widżetów rysujących
    QWidget::connect(&client, SIGNAL(updatePitch(float)), w.realTimeDrawPlane, SLOT(setRotation(float)));
    QWidget::connect(&client, SIGNAL(updateTheta(float)), w.mapDrawPlane, SLOT(setRotation(float)));
    QWidget::connect(&client, SIGNAL(updateX(float)), w.mapDrawPlane, SLOT(setX(float)));
    QWidget::connect(&client, SIGNAL(updateY(float)), w.mapDrawPlane, SLOT(setY(float)));

    //Inicjalizacja timera
    timer= new QTimer(&w);
    QWidget::connect(timer, SIGNAL(timeout()), &w, SLOT(draw(void)));
    timer->start(50);

    w.show();
    sw.show();

    return a.exec();
}
