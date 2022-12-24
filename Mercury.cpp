#include "Mercury.h"

void Mercury::SetDate(int y, int m, int D) {
    d = 367 * y - 7 * (y + (m + 9) / 12) / 4 - 3 * ((y + (m - 9) / 7) / 100 + 1) / 4 + 275 * m / 9 + D - 730515;
    N = 48.3313 + 3.24587E-5 * d;
    i = 7.0047 + 5.00E-8 * d;
    w = 29.1241 + 1.01444E-5 * d;
    a = 0.387098;
    e = 0.205635 + (5.59E-10 * d);
    M = (168.6562 + 4.0923344368 * d);// Need to trandform to Radians

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

void Mercury::CalculateOrbit() {
    float E0 = M + e * sin(M) * (1.0 + e * cos(M));
    float E1 = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));

    while (abs(E1 - E0) > 0.01) {
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

    //cout << "Mercury: xh " << xh << " yh " << yh << " rr" << r << endl;
    CartesianCoord Mercury = CartesianCoord(xh, yh, "Mercury");
    Mercury.printCoord();
}
