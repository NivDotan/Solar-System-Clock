#include "OrbitalPaint.h"

OrbitalPaint::OrbitalPaint(QWidget *parent)
    : QWidget{parent}
{

}

void OrbitalPaint::paintEvent(QPaintEvent *event)
{doPainting();}

void OrbitalPaint::doPainting(){
    QPainter ellipsePainter(this);
    ellipsePainter.setRenderHint(QPainter::Antialiasing, true); //- For HD
    ellipsePainter.setBrush(Qt::NoBrush);

    QPen pen;
    pen.setWidth(3);
    //pen.setBrush(Qt::SolidLine);

    ellipsePainter.setPen(pen);


    ellipsePainter.rotate(Angle); // Float Angle


    //ellipsePainter.drawEllipse(QRect(180,-190,258,270));// Is 368 and 465 is radius or Not
    //ellipsePainter.drawEllipse(QRect(200,4,258,270));
    //ellipsePainter.drawEllipse(QRect(200,4,50,100));

    //Mercury Orbit
    //ellipsePainter.drawEllipse(QRect(0,Margin,Width,Height).adjusted(1.5, 1.5, -65, -30));// Works- Need to reCalibrate the orbit place for each plant we will create 4 parameters
    ellipsePainter.drawEllipse(QRect(0,Margin,Width,Height).adjusted(adjustedLeft,adjustedTop, adjustedRight, adjustedBottom));


}

void OrbitalPaint::SetAdjusted(double num1 = 1.5, double num2 = 1.5 , double num3 = 0, double num4 = 0){
    adjustedLeft = num1;
    adjustedTop = num2;
    adjustedRight = num3;
    adjustedBottom = num4;
}

