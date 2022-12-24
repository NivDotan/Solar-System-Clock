#ifndef EARTH_H
#define EARTH_H


#include <iostream>
#include <cmath>
#include <math.h>
#include "CartesianCoord.h"


#define pi 3.14
using namespace std;
class Earth
{
private:
    //int Year, Month, Day, A, B;
    //float T,e,M,p,JD,L;

    double E, N, i, w, a, e, M, xv, yv, v, r, xh, yh;
    int d;

public:
    Earth() {
    }
    ~Earth() {
    }
    void SetDate(int y, int m, int D);
    void CalculateOrbit();

    /*
    void setDate(int Y, int M, int D) {
        Year = Y;
        Month = M;
        Day = D;
    }
    void CalculateOrbit() {
        A = int(Year / 100);
        B = 2 - A + int(A / 4);

        JD = int(365.25 * Year) + int(30.6001 * (Month + 1)) + Day + 1720994.5 + B;

        T = (JD - 2415020.0) / 36525;

        L = 99.69668 + 36000.76892 * T + 0.0003025 * (T * T);//In degrees
        if (L > 360) {
            L = L / 360;
            L = (L - int(L)) * 360;
        }
        e = 0.0167;
        M = 358.47583 + 35999.04975 * T - 0.000150 * (T * T) - 0.0000033 * (T * T * T);//In degrees
        if (M > 360) {
            M = M / 360;
            M = (M - int(M)) * 360;
        }
        p = L - M; //In degrees

    }

    void ShowOrbit() {
        cout << "A " << A << "B " << B;
        cout << "T " << T << "L " << L << "e " << e << " M " << M << "p " << p;
    }*/

    void CalculateOrbit2(int y, int m, int D) {
        double E, N, i, w, a, e, M, xv, yv, v, r, xh, yh;
        int d;


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

        E = M + e * sin(M) * (1.0 + e * cos(M));

        cout << " E " << E << " ee" << e;

        xv = (a * (cos(E) - e));
        yv = (a * (sqrt(1.0 - e * e) * sin(E))) ;

        N = N * (3.14 / 180);
        w = w * (3.14 / 180);
        i = i * (3.14 / 180);
        cout << "N " << N << endl;
        v = atan2(yv, xv);
        r = sqrt((xv * xv) + (yv * yv));


        xh = r * (cos(N) * cos(v + w) - sin(N) * sin(v + w) * cos(i));
        yh = r * (sin(N) * cos(v + w) + cos(N) * sin(v + w) * cos(i));



        cout << "A " << xh << " B " << yh << " C"<< r;



        //---Mercury---//

        N = 48.3313 + 3.24587E-5 * d;
        i = 7.0047 + 5.00E-8 * d;
        w = 29.1241 + 1.01444E-5 * d;
        a = 0.387098;
        e = 0.205635 + (5.59E-10 * d);
        M = (168.6562 + 4.0923344368 * d);// Need to trandform to Radians
        cout << " M " << M << " ee" << e;
        while (M > 360 || M < 0) {
            if (M > 360) {
                M = M - 360;
            }
            if (M < 0) {
                M = M + 360;
            }
        }
        M = M * (3.14 / 180);
        cout << " M " << M << " ee" << e;
        //float E0 = M + e * (180 / pi) * sin(M) * (1.0 + e * cos(M));
        float E0 = M + e * sin(M) * (1.0 + e * cos(M));
        cout <<" E0 " << E0;
        //float E1 = E0 - (E0 - e * (180 / pi) * sin(E0) - M) / (1 - e * cos(E0));
        float E1 = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));

        //cout << " E1 " << E1 << " E0 " << E0;
        while (abs(E1 - E0) > 0.01) {
            E0 = E1;
            E1 = E0 - (E0 - e * (180 / pi) * sin(E0) - M) / (1 - e * cos(E0));

        }

        cout << " E1 " << E1 << " E0 " << E0;
        E = E1;

        xv = a * (cos(E) - e) ;
        yv = a * (sqrt(1.0 - (e * e)) * sin(E));

        v = atan2(yv, xv);
        r = sqrt(xv * xv + yv * yv);
        N = N * (3.14 / 180);
        w = w * (3.14 / 180);
        i = i * (3.14 / 180);
        xh = r * (cos(N) * cos(v + w) - sin(N) * sin(v + w) * cos(i));
        yh = r * (sin(N) * cos(v + w) + cos(N) * sin(v + w) * cos(i));

        cout << " DD " << xh << " BBB " << yh <<" rr" << r << endl;


        //---Mars---//

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

        E0 = M + e * sin(M) * (1.0 + e * cos(M));
        E1 = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));

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

        cout << " DD " << xh << " BBB " << yh << " rr" << r;


    }
    double GetX(){return xh;}
    double GetY(){return yh;}
};



#endif // EARTH_H
