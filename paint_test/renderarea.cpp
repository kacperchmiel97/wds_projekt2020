#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) : QWidget(parent){
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    setGeometry(parent->geometry());
}

QSize RenderArea::sizeHint() const{
    return QSize(500,500);
}

void RenderArea::paintEvent(QPaintEvent *){
    QPen pen(Qt::white);
    int x0= width()/2;
    int y0= height()-height()/4;
    int w= width()/8;
    int h= height()/2;

    int xc= x0-w/2;
    int yc= y0-h;

    QPainter painter(this);

    QRect rect= QRect(xc, yc, w, h);

    pen.setWidth(5);
    painter.setPen(pen);
    //painter.drawRect(shape);
    painter.fillRect(rect, QBrush(Qt::red, Qt::SolidPattern));

    painter.drawEllipse(QPoint(x0, y0), w/2+10, w/2+10);

    painter.translate(x0, y0);
    painter.rotate(rotation);
    painter.translate(-x0, -y0);

    painter.fillRect(rect, QBrush(Qt::black, Qt::SolidPattern));
    painter.setBrush(Qt::white);
    painter.drawEllipse(QPoint(x0, y0), w/2+10, w/2+10);
}

void RenderArea::draw(void){
    update();
}
void RenderArea::setRotation(float r){
    rotation= r;
}
