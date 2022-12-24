
#ifndef CARTESIANCOORD_H
#define CARTESIANCOORD_H

#include <iostream>
using namespace std;

class CartesianCoord
{
private:
    double x, y;
    string name;

public:
    CartesianCoord(double NewX, double NewY, string planetName);
    double GetXCoord() {
        return x;
    }
    double GetYCoord() {
        return y;
    }
    string GetPlanetName() {
        return name;
    }
    void printCoord();
    int getX(){return x;}
    int getY(){return y;}

};


#endif // CARTESIANCOORD_H
