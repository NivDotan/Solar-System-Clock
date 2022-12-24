#include "PlanetPaint.h"

PlanetPaint::PlanetPaint(QWidget *parent)
    : QWidget{parent}
{

}

void PlanetPaint::paintEvent(QPaintEvent *event)
{doPainting();}

void PlanetPaint::doPainting(){
    QPainter ellipsePainter(this);

    ellipsePainter.setBrush(Qt::SolidPattern);

    QPen pen;
    pen.setWidth(8);
    pen.setBrush(Qt::SolidPattern);

    ellipsePainter.setPen(pen);

    ellipsePainter.drawEllipse(QRect(4,4,30,30));
    //ellipsePainter.rotate(45);
    //ellipsePainter.drawEllipse(QRect(4,4,15,30));




}
