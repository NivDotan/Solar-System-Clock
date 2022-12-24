#include "Venus.h"

void Venus::CalculateOrbit() { // Will need to return a Cartesian coordinates Class.

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

    //cout << "Venus: xh " << xh << " yh " << yh << " rr" << r << endl;
    CartesianCoord Venus = CartesianCoord(xh, yh, "Venus");
    Venus.printCoord();
}

void Venus::SetDate(int y, int m, int D) {
    d = 367 * y - 7 * (y + (m + 9) / 12) / 4 - 3 * ((y + (m - 9) / 7) / 100 + 1) / 4 + 275 * m / 9 + D - 730515;
    N = 76.6799 + 2.46590E-5 * d;
    i = 3.3946 + 2.75E-8 * d;
    w = 54.8910 + 1.38374E-5 * d;
    a = 0.723330;
    e = 0.006773 - 1.302E-9 * d;
    M = 48.0052 + 1.6021302244 * d;
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
