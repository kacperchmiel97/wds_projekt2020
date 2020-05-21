#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QtCore>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
signals:
    void read(QString string);

public slots:
    bool connectToHost(QString host, int port, int timeout);
    void socketReadyRead()
    {
        infoText= socket->readLine();
        emit read(infoText);
    }


private:
    QTcpSocket *socket;
    QSocketNotifier *m_notifier;
    QString infoText;
};

#endif // SOCKETCLIENT_H
