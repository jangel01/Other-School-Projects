#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "GeometricalShape.h"
using namespace std;

class Sphere : public GeometricalShape {
private:
	double radius, volume;
public:
	Sphere();
	Sphere(double, double, double, double);
	void calcSphereVolume();
	void printSphereInfo();
};

Sphere::Sphere() 
	: GeometricalShape(), radius(0) {}

Sphere::Sphere(double xP, double yP, double zP, double r) 
	: GeometricalShape(xP, yP, zP), radius(r) {}

void Sphere::calcSphereVolume() {
	volume = (4.0 / 3.0) * (3.14) * (pow(radius, 3));
}

void Sphere::printSphereInfo() {
	cout << "Dimensions - Radius: " << radius << endl;
	cout << "The volume is: " << volume << endl;
}


#endif
