#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PlanetPaint.h"
#include "ui_mainwindow.h"
#include "CartesianCoord.h"
#include "OrbitalPaint.h"
#include <QScreen>
#include <QLayout>
#include <QWidget>
#include <vector>
#include <iostream>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetVecor( vector<CartesianCoord>);
    void ShowPlanets();
private:
    //Ui::MainWindow *ui;
    QPushButton *m_button;

    PlanetPaint *NewPlanet1;
    PlanetPaint *NewPlanet2;
    PlanetPaint *NewPlanet3;
    PlanetPaint *NewPlanet4;
    PlanetPaint *Sun;
    OrbitalPaint *Orbit;
    OrbitalPaint *Orbit2, *Orbit3;

        PlanetPaint *NewPlanet;
      PlanetPaint *m;
      PlanetPaint *CWC;
      void setup();
      void handleButton();
      void initUI();


    vector<CartesianCoord> Coords;
      QWidget *mainWidget;
      QVBoxLayout *vLayout;
      QLayout *Layout;
      Ui::MainWindow *ui;
      //QGraphicsLayout *graph;
};
#endif // MAINWINDOW_H
