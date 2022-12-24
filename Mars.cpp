#include "Mars.h"


void Mars::SetDate(int y, int m, int D) {
    d = 367 * y - 7 * (y + (m + 9) / 12) / 4 - 3 * ((y + (m - 9) / 7) / 100 + 1) / 4 + 275 * m / 9 + D - 730515;
    N = 49.5574 + 2.11081E-5 * d;
    i = 1.8497 - 1.78E-8 * d;
    w = 286.5016 + 2.92961E-5 * d;
    a = 1.523688;
    e = 0.093405 + 2.516E-9 * d;
    M = 18.6021 + 0.5240207766 * d;
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

void Mars::CalculateOrbit() {
    float E0 = M + e * sin(M) * (1.0 + e * cos(M));
    float E1 = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));

    while (abs(E1 - E0) > 0.001) {
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
    CartesianCoord Mars = CartesianCoord(xh, yh, "Mars");
    Mars.printCoord();
}
