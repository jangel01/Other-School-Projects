#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include "BloodData.h"

using namespace std;

class Patient {
private:
	int id_number;
	int age;
	BloodData blood_data;
public:
	Patient();
	Patient(int, int, char, string);
	int getID();
	int getAge();
	void displayBlood();
};

Patient::Patient() {
	id_number = 0;
	age = 0;
}

Patient::Patient(int ID, int a, char r_f, string b_t) {
	id_number = ID;
	age = a;
	BloodData custom_blood_data(r_f, b_t);
	blood_data = custom_blood_data;
}

int Patient::getID() {
	return id_number;
}

int Patient::getAge() {
	return age;
}

void Patient::displayBlood() {
	cout << "Blood Type: " << blood_data.getBT() << blood_data.getRF() << endl;
}

#endif
