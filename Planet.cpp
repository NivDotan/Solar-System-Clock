#include "Planet.h"




void Planet::CalculateOrbit() {
    E0 = M + e * sin(M) * (1.0 + e * cos(M));
    E1 = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));

    while (abs(E1 - E0) > 0.01) { //Increase the 0.01 to 0.001 if you want more accurate calculation
        E0 = E1;
        E1 = E0 - (E0 - e * (180 / pi) * sin(E0) - M) / (1 - e * cos(E0));

    }
    E = E1;

    xv = a * (cos(E) - e);
    yv = a * (sqrt(1.0 - (e * e)) * sin(E));

    v = atan2(yv, xv);
    r = sqrt(xv * xv + yv * yv);
    N = N * (3.14 / 180);
    w = w * (3.14 / 180);
    i = i * (3.14 / 180);
    xh = r * (cos(N) * cos(v + w) - sin(N) * sin(v + w) * cos(i));
    yh = r * (sin(N) * cos(v + w) + cos(N) * sin(v + w) * cos(i));

    //cout << "Mars: xh  " << xh << " yh " << yh << " rr" << r;
    //CartesianCoord Mars = CartesianCoord(xh, yh, Name);
    //Plant.printCoord();
}

void Planet::SetDate(int y, int m, int D) {
    d = 367 * y - 7 * (y + (m + 9) / 12) / 4 - 3 * ((y + (m - 9) / 7) / 100 + 1) / 4 + 275 * m / 9 + D - 730515;
    /*
    N = 49.5574 + 2.11081E-5 * d;
    i = 1.8497 - 1.78E-8 * d;
    w = 286.5016 + 2.92961E-5 * d;
    a = 1.523688;
    e = 0.093405 + 2.516E-9 * d;
    M = 18.6021 + 0.5240207766 * d;*/

    N = N1 + N2 * d;
    i = i1 + i2 * d;
    w = w1 + w2 * d;
    //a = 1.523688;
    e = e1 + e2 * d;
    M = M1 + M2 * d;

    while (M > 360 || M < 0) {
        if (M > 360) {
            M = M - 360;
        }
        if (M < 0) {
            M = M + 360;
        }
    }
    M = M * (3.14 / 180);
}

void Planet::SetOrbitParameters(double tmpN1, double tmpN2, double tmpi1, double tmpi2, double tmpw1, double tmpw2, double tmpa, double tmpe1, double tmpe2, double tmpM1, double tmpM2){
    N1 = tmpN1;
    N2 = tmpN2;
    i1 = tmpi1;
    i2 = tmpi2;
    w1 = tmpw1;
    w2 = tmpw2;
    a = tmpa;
    e1 = tmpe1;
    e2 = tmpe2;
    M1 = tmpM1;
    M2 = tmpM2;
}
