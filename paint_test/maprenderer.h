#ifndef MAPRENDERER_H
#define MAPRENDERER_H

#include <QObject>
#include <QWidget>
#include <QPainter>

/*!
 * \brief Rysuje mapę
 */
class MapRenderer : public QWidget
{
    Q_OBJECT
public:
    MapRenderer(QWidget *parent=0);
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setRotation(float _r) {rotation= _r;}
    void setX(float _x) {x= _x;}
    void setY(float _y) {y= _y;}

private:
    float rotation, x, y;
};

#endif // MAPRENDERER_H
