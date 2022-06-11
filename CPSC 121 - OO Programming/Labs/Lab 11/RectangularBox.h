#ifndef RECTANGULARBOX_H
#define RECTANGULARBOX_H

#include <iostream>
#include "GeometricalShape.h"
using namespace std;

class RectangularBox : public GeometricalShape {
private:
	double height, length, width, volume;
public:
	RectangularBox();
	RectangularBox(double, double, double, double, double, double);
	void calcRectangleArea();
	void printRectangleInfo();
};

RectangularBox::RectangularBox()
	: GeometricalShape(), height(0), length(0), width(0) {}

RectangularBox::RectangularBox(double xP, double yP, double zP, double h, double l, double w)
	: GeometricalShape(xP, yP, zP), height(h), length(l), width(w) {}

void RectangularBox::calcRectangleArea() {
	volume = height * length * width;
}

void RectangularBox::printRectangleInfo() {
	cout << "Dimensions - Height: " << height << " Length: " << length <<  " width: " << width << endl;
	cout << "The volume is: " << volume << endl;
}

#endif
