#ifndef CYLINDER
#define CYLINDER

#include <iostream>
#include "GeometricalShape.h"
using namespace std;

class Cylinder : public GeometricalShape {
private:
	double height, radius, volume;
public:
	Cylinder();
	Cylinder(double, double, double, double, double);
	void calcCylinderVolume();
	void printCylinderInfo();
};

Cylinder::Cylinder()
	: GeometricalShape(), height(0), radius(0) {}

Cylinder::Cylinder(double xP, double yP, double zP, double h, double r)
	: GeometricalShape(xP, yP, zP), height(h), radius(r) {}

void Cylinder::calcCylinderVolume() {
	volume = (3.14) * (pow(radius, 2)) * (height);
}

void Cylinder::printCylinderInfo() {
	cout << "Dimensions - Height: " << height << " Radius: " << radius << endl;
	cout << "The volume is " << volume << endl;
}

#endif
