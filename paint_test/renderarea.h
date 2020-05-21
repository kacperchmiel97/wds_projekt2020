#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent=0);
    //QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

public slots:
    //void setTransformed(bool transformed) override;
    void draw(void);
    void setRotation(float r);

private:
    float rotation;
};

#endif // RENDERAREA_H
