#ifndef PLANETPAINT_H
#define PLANETPAINT_H

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
#include <QSplashScreen>

class PlanetPaint : public QWidget
{
    Q_OBJECT
public:
    PlanetPaint(QWidget *parent = nullptr);
    void setFloat(float tempNum);
    virtual void paintEvent(QPaintEvent *event);
    void doPainting();
private:
    QLabel *label;
    float x, y;
    void setup();
    QHBoxLayout *hLayout;
    QDialog *dialog;

signals:

};

#endif // PLANETPAINT_H
