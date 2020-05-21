#include "realtimerenderer.h"

RealtimeRenderer::RealtimeRenderer(QWidget *parent) : QWidget(parent){
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    setGeometry(parent->geometry());
}

void RealtimeRenderer::paintEvent(QPaintEvent *){
    int x0= width()/2;
    int y0= height()-height()/4;
    int w= width()/8;
    int h= height()/2;

    int xc= x0-w/2;
    int yc= y0-h;

    QPainter painter(this);
    QPen pen(Qt::white);
    pen.setWidth(5);
    painter.setPen(pen);

    QRect rect= QRect(xc, yc, w, h);

    painter.translate(x0, y0);
    painter.rotate(rotation);
    painter.translate(-x0, -y0);

    painter.fillRect(rect, QBrush(Qt::black, Qt::SolidPattern));
    painter.setBrush(Qt::white);
    painter.drawEllipse(QPoint(x0, y0), w/2+10, w/2+10);
}
