#ifndef VENUS_H
#define VENUS_H


#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include "CartesianCoord.h"

#define pi 3.14

using namespace std;
class Venus
{
private:
    //int Year, Month, Day, A, B;
    //float T,e,M,p,JD,L;

    double E, N, i, w, a, e, M, xv, yv, v, r, xh, yh;
    int d;

public:
    Venus() {
    }
    ~Venus() {
    }
    void SetDate(int y, int m, int D);
    void CalculateOrbit();
    double GetX(){return xh;}
    double GetY(){return yh;}
};



#endif // VENUS_H
