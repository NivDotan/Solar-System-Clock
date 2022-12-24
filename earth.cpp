#include "earth.h"

void Earth::CalculateOrbit() { // Will need to return a Cartesian coordinates Class.

    E = M + e * sin(M) * (1.0 + e * cos(M));
    xv = (a * (cos(E) - e));
    yv = (a * (sqrt(1.0 - e * e) * sin(E)));
    N = N * (3.14 / 180);
    w = w * (3.14 / 180);
    i = i * (3.14 / 180);
    v = atan2(yv, xv);
    r = sqrt((xv * xv) + (yv * yv));
    xh = r * (cos(N) * cos(v + w) - sin(N) * sin(v + w) * cos(i));
    yh = r * (sin(N) * cos(v + w) + cos(N) * sin(v + w) * cos(i));

    //cout << "Earth: xh " << xh << " yh " << yh << " rr" << r<< endl;
    CartesianCoord Earth = CartesianCoord(xh, yh, "Earth");
    Earth.printCoord();
}

void Earth::SetDate(int y, int m, int D) {
    d = 367 * y - 7 * (y + (m + 9) / 12) / 4 - 3 * ((y + (m - 9) / 7) / 100 + 1) / 4 + 275 * m / 9 + D - 730515;
    N = 0.0;
    i = 0.0;
    w = 282.9404 + 4.70935E-5 * d;
    a = 1.0000002;
    e = 0.016709 - 1.151E-9 * d;
    M = 356.0470 + 0.9856002585 * d;
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
