#include "mainwindow.h"
#include "serverwindow.h"
#include "socketclient.h"
#include "socketserver.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app( argc, argv );
    QMessageBox errorBox;

    MainWindow w;
    ServerWindow sw;
    SocketClient client(&w);
    SocketServer server;


    if(!client.connectToHost("127.0.0.1", 4242, 500000)){

        errorBox.setText("Could not connect to host!");
        errorBox.exec();
        return -1;
    }


    QObject::connect(&client, SIGNAL(read(QString)), &w, SLOT(displayText(QString)));
    QObject::connect(&sw, SIGNAL(sendMsg(float, float, float, float, float)), &server, SLOT(sendData(float, float, float, float, float)));


    sw.show();
    w.show();

    return app.exec();
}
