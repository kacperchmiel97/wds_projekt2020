#include "console.h"
#include <iostream>
#include <QString>
#include <QTextStream>

console::console(){

    m_notifier= new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readOnce()));
}

void console::readOnce(void){

    QTextStream stream(stdin);
    QString input;
    float x, y, r;

    stream.readLineInto(&input);
    x= y= r= input.toFloat();
    emit lineRead(x, y, r);
}
