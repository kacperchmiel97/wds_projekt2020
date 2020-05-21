#ifndef REALTIMERENDERER_H
#define REALTIMERENDERER_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class RealtimeRenderer : public QWidget
{
    Q_OBJECT
public:
    RealtimeRenderer(QWidget *parent=0);
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setRotation(float r) {rotation= r;}

private:
    float rotation;
};

#endif // REALTIMERENDERER_H
