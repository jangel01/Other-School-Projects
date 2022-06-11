#include <iostream>
#include <cmath>
#include <memory>
#include "GeometricalShape.h"
#include "Sphere.h"
#include "RectangularBox.h"
#include "Cylinder.h"

using namespace std;

int main()
{
    cout << "==Creating objects with default constructors!==" << endl;
    cout << "Sphere info:" << endl;
    shared_ptr<Sphere> sphere1 = make_shared<Sphere>();
    sphere1->printCoordinates();
    sphere1->calcSphereVolume();
    sphere1->printSphereInfo();
    cout << "Rectangular Box info:" << endl;
    shared_ptr<RectangularBox> rectangularBox1 = make_shared<RectangularBox>();
    rectangularBox1->printCoordinates();
    rectangularBox1->calcRectangleArea();
    rectangularBox1->printRectangleInfo();
    cout << "Cylinder info:" << endl;
    shared_ptr<Cylinder> cylinder1 = make_shared<Cylinder>();
    cylinder1->printCoordinates();
    cylinder1->calcCylinderVolume();
    cylinder1->printCylinderInfo();
    
    cout << endl;

    cout << "==Creating objects with overloaded constructors!==" << endl;
    cout << "Sphere info:" << endl;
    shared_ptr<Sphere> sphere2 = make_shared<Sphere>(2, 2, 5, 3.5);
    sphere2->printCoordinates();
    sphere2->calcSphereVolume();
    sphere2->printSphereInfo();
    cout << "Rectangular box info:" << endl;
    shared_ptr<RectangularBox> rectangularBox2 = make_shared<RectangularBox>(5, 0, -5, 2.5, 3.2, 1.5);
    rectangularBox2->printCoordinates();
    rectangularBox2->calcRectangleArea();
    rectangularBox2->printRectangleInfo();
    cout << "Cylinder info:" << endl;
    shared_ptr<Cylinder> cylinder2 = make_shared<Cylinder>(1, 1, 1, 4, 1.75);
    cylinder2->printCoordinates();
    cylinder2->calcCylinderVolume();
    cylinder2->printCylinderInfo();

    system("PAUSE");
    return 0;
}
