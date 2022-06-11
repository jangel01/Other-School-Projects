#include <iostream>
#include "Patient.h"
#include "BloodData.h"

using namespace std;

int main()
{
    Patient Timmy;
    cout << "Patient ID: " << Timmy.getID() << endl;
    cout << "Patient Age: " << Timmy.getAge() << endl;
    Timmy.displayBlood();

    Patient Spike(1337, 19, '-', "AB");
    cout << "Patient ID: " << Spike.getID() << endl;
    cout << "Patient Age: " << Spike.getAge() << endl;
    Spike.displayBlood();

    system("PAUSE");
    return 0;
}
