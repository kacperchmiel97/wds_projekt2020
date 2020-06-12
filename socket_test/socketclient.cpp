#include "socketclient.h"
#include "socketclient.h"
#include <iostream>
#include <string>

SocketClient::SocketClient(QObject *parent) : QObject(parent){
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(connection_lost()));
}

/*!
 * \brief Inicjalizuje połączenie z hostem
 * \param host IP hosta
 * \param port Port hosta
 * \param timeout Czas oczekiwania na połączenie
 * \return Sukces nawiązania połączenia
 */
bool SocketClient::connectToHost(QString host, int port, int timeout){
    socket->connectToHost(host, port);
    return socket->waitForConnected(timeout);
}

void SocketClient::connection_lost(void){
    emit disconnected();
}

/*!
 * \brief Parsuje otrzymane dane i emituje sygnały
 */
void SocketClient::socketReadyRead(){
    infoText= socket->readLine();

    //emit read(infoText);
    //std::cout << infoText.toStdString();

    float pitch, x, y, t, pid;

    QStringList input= infoText.split(' ');

    pitch= input.at(0).toFloat();
    x= input.at(1).toFloat();
    y= input.at(2).toFloat();
    t= input.at(3).toFloat();
    pid= input.at(4).toFloat();

    emit updatePitch(pitch);
    emit updateX(x);
    emit updateY(y);
    emit updateTheta(t);
    emit updatePid(pid);
    emit newData();
}
