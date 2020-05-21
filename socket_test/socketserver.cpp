#include "socketserver.h"
#include <QTcpServer>

/*!
 * \brief Inicjalizuje połączenie z klientem
 * \param parent
 */
SocketServer::SocketServer(QObject *parent) : QObject(parent){

    server= new QTcpServer(this);

    if (!server->listen(QHostAddress::LocalHost, 4242)) {
        std::cout << "ERROR CREATING SERVER" << '\n';
            return;
    }

    connect(server, SIGNAL(newConnection(void)), this, SLOT(getSocket(void)));
    //connect(socket, &QAbstractSocket::disconnected, socket, &QObject::deleteLater);
}

SocketServer::~SocketServer(){
    delete server;
    delete socket;
}

/*!
 * \brief Wysyła dane w postaci stringa
 * \param pitch Pochylenie robota
 * \param x Współrzędna X
 * \param y Współrzędna Y
 * \param t Kąt względem osi Y na mapie
 * \param pid Odpowiedź regulatora PID
 */
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
