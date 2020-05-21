#include "maprenderer.h"

MapRenderer::MapRenderer(QWidget *parent) : QWidget(parent){
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    x= 0;
    y= 0;

    setGeometry(parent->geometry());
}

void MapRenderer::paintEvent(QPaintEvent *){
    int x0= width()/2;
    int y0= height()/2;

    int xp= x0 + x;
    int yp= y0 + y;

    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(5);
    painter.setPen(pen);

    painter.translate(xp, yp);
    painter.rotate(rotation);
    painter.translate(-xp, -yp);

    painter.setBrush(Qt::white);
    painter.drawEllipse(QPoint(xp, yp), 25, 25);
    painter.setBrush(Qt::black);
    painter.drawLine(xp, yp, xp, yp - 25);
}
