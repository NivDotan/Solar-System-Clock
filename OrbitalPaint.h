#ifndef ORBITALPAINT_H
#define ORBITALPAINT_H

#include <QGraphicsEllipseItem>
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLayout>
#include <QScreen>
#include <QSplashScreen>
#include <QApplication>

class OrbitalPaint : public QWidget
{
    Q_OBJECT
public:
    OrbitalPaint(QWidget *parent = nullptr);
    void setFloat(float tempNum);
    virtual void paintEvent(QPaintEvent *event);
    void doPainting();
    void setAngle(float Ang){Angle = Ang;}
    void Setwidth(double W){Width = W;}
    void Setheight(double h){Height = h;}
    void Setmargin(double m){Margin = m;}
    void SetAdjusted(double num1, double num2, double num3, double num4);

private:
    QLabel *label;
    float Angle;
    double Width;
    double Height;
    double Margin, adjustedLeft, adjustedTop, adjustedRight, adjustedBottom;
    void setup();
    QHBoxLayout *hLayout;
    QDialog *dialog;
};


#endif // ORBITALPAINT_H
