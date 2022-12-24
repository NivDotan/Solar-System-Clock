#ifndef MARS_H
#define MARS_H

#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include "CartesianCoord.h"

#define pi 3.14


using namespace std;
class Mars
{
private:
    //int Year, Month, Day, A, B;
    //float T,e,M,p,JD,L;

    double E, N, i, w, a, e, M, xv, yv, v, r, xh, yh;
    int d;

public:
    Mars() {
    }
    ~Mars() {
    }
    void SetDate(int y, int m, int D);
    void CalculateOrbit();
    double GetX(){return xh;}
    double GetY(){return yh;}
};



#endif // MARS_H
