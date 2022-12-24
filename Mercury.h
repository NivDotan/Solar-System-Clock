#ifndef MERCURY_H
#define MERCURY_H

#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include "CartesianCoord.h"

#define pi 3.14
using namespace std;
class Mercury
{
private:
    double E, N, i, w, a, e, M, xv, yv, v, r, xh, yh;
    int d;

public:
    Mercury() {
    }
    ~Mercury() {
    }
    void SetDate(int y, int m, int D);
    void CalculateOrbit();
    double GetX(){return xh;}
    double GetY(){return yh;}
};

#endif // MERCURY_H
