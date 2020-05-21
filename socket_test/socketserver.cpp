#include "socketserver.h"
#include <QTcpServer>


SocketServer::SocketServer(QObject *parent) : QObject(parent){

    server= new QTcpServer(this);

    if (!server->listen(QHostAddress::LocalHost, 4242)) {
        std::cout << "ERROR CREATING SERVER" << '\n';
            return;
    }

    connect(server, SIGNAL(newConnection(void)), this, SLOT(getSocket(void)));
    connect(socket, &QAbstractSocket::disconnected, socket, &QObject::deleteLater);
}

SocketServer::~SocketServer(){
    delete server;
}

void SocketServer::sendData(float pitch, float x, float y, float t, float pid){
    QString msg;
    msg=
            QString::number(pitch) + ' ' +
            QString::number(x) + ' ' +
            QString::number(y) + ' ' +
            QString::number(t) + ' ' +
            QString::number(pid) +'\n';

    socket->write(msg.toUtf8());
}
