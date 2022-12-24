#ifndef PLANET_H
#define PLANET_H

#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include "CartesianCoord.h"
#define pi 3.14

using namespace std;

class Planet
{

private:
    double E, N, i, w, a, e, M, xv, yv, v, r, xh, yh;
    double N1, N2, i1, i2, w1, w2, e1, e2, M1, M2; //Tmp parameters for setter
    float E0,E1;
    int d;
    string Name;

public:
    Planet(){
    }
    ~Planet() {
    }
    void SetDate(int y, int m, int D);
    void CalculateOrbit();
    double GetX(){return xh;}
    double GetY(){return yh;}
    void SetOrbitParameters(double tmpN1, double tmpN2, double tmpi1, double tmpi2, double tmpw1, double tmpw2, double tmpa, double tmpe1, double tmpe2, double tmpM1, double tmpM2);
};

#endif // PLANET_H
