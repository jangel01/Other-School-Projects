#ifndef NBA_H
#define NBA_H
#include <iostream>
#include "Athlete.h"
using namespace std;

class NBA : public Athlete {
public:
	NBA(string sport, double sal);
	virtual void pickLeaguePosition(int position);
	virtual void printPositionOptions();
};

NBA::NBA(string sport, double sal) : Athlete(sport, sal) {
	average_salary = 4580000;
	percent = (salary / average_salary) * 100;
}

void NBA::printPositionOptions() {
	cout << "Which position does the athlete play?" << endl;
	cout << "(1-5)" << endl;
	cout << "1: point guard" << endl;
	cout << "2: shooting guard" << endl;
	cout << "3: small forward" << endl;
	cout << "4: power forward" << endl;
	cout << "5: center" << endl;
}

void NBA::pickLeaguePosition(int choice) {
	try {
		if (choice < 1 || choice > 5)
			throw string("invalid input: setting default value to 1.");
	} catch (string exceptionStirng) {
		cout << exceptionStirng << endl;
		choice = 1;
	}

	switch (choice) {
	case 1:
		position = "Point Guard";
		break;
	case 2:
		position = "Shooting Guard";
		break;
	case 3:
		position = "Small Forward";
		break;
	case 4: 
		position = "Power Forward";
		break;
	case 5: 
		position = "Center";
	}
}

#endif
