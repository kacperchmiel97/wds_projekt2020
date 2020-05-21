#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QtCore>
#include <QtNetwork>
/*!
 * \brief Odbiera i parsuje dane
 *
 */
class SocketClient : public QObject{
    Q_OBJECT
public:
    explicit SocketClient(QObject *parent = 0);
signals:
    void read(QString string);
    void updatePitch(float pitch);
    void updateX(float x);
    void updateY(float y);
    void updateTheta(float t);
    void updatePid(float pid);
    void newData(void);

public slots:
    bool connectToHost(QString host, int port, int timeout);
    void socketReadyRead(void);

private:
    QTcpSocket *socket;
    QSocketNotifier *m_notifier;
    QString infoText;
};

#endif // SOCKETCLIENT_H
