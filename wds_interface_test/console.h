#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QString>
#include <QSocketNotifier>

/*!
 * \brief Klasa do asynchronicznego nasłuchiwania na wejściu stdin (nieużywana)
 */
class console : public QObject
{
    Q_OBJECT
public:
    console();
signals:
    void lineRead(float x, float y, float r);

private:
    QSocketNotifier *m_notifier;

private slots:
    void readOnce(void);
};

#endif // CONSOLE_H
