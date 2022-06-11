#ifndef GEOMETRICALSHAPE_H
#define GEOMETRICALSHAPE_H

#include <iostream>
using namespace std;

class GeometricalShape {
private:
	double xPosition, yPosition, zPosition;
public:
	GeometricalShape();
	GeometricalShape(double, double, double);
	void printCoordinates();
};

GeometricalShape::GeometricalShape()
	: xPosition(0), yPosition(0), zPosition(0) {}

GeometricalShape::GeometricalShape(double xPosition, double yPosition, double zPosition) 
	: xPosition(xPosition), yPosition(yPosition), zPosition(zPosition) {}

void GeometricalShape::printCoordinates() {
	cout << "The center coordinate is at X: " << xPosition << " Y: " << yPosition << " Z: " <<
		zPosition << endl;
}

#endif
