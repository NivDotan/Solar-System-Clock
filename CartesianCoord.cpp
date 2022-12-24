#include "CartesianCoord.h"

CartesianCoord::CartesianCoord(double NewX, double NewY, string planetName) {
    x = NewX;
    y = NewY;
    name = planetName;
}

void CartesianCoord::printCoord() {
    cout << "The coordinates of " << GetPlanetName() << ": (" << GetXCoord() << "," << GetYCoord() << ")" << endl;
}


// Link the getter with the window and multiply it
// Show the plantes on the window using untitled1

