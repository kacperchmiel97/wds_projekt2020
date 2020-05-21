#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QMessageBox>
#include <iostream>

/*!
 * \brief Emuluje hosta dostarczającego dane o robocie
 */
class SocketServer  : public QObject
{
    Q_OBJECT
public:
    explicit SocketServer(QObject *parent= 0);
    ~SocketServer();

private slots:
    void getSocket(void){
        socket= server->nextPendingConnection();
    }

    void sendData(float pitch, float x, float y, float t, float pid);


private:
    QTcpServer *server;
    QTcpSocket *socket;
    QNetworkSession *session;
};

#endif // SOCKETSERVER_H
