#ifndef NHL_H
#define NHl_H
#include <iostream>
#include "Athlete.h"
using namespace std;

class NHL : public Athlete {
public:
	NHL(string sport, double sal);
	virtual void pickLeaguePosition(int choice);
	virtual void printPositionOptions();
};

NHL::NHL(string sport, double sal) : Athlete(sport, sal) {
	average_salary = 2620000;
	percent = (salary / average_salary) * 100;
}

void NHL::printPositionOptions() {
	cout << "Which position does the athlete play?" << endl;
	cout << "(1-4)" << endl;
	cout << "1: center" << endl;
	cout << "2: winger" << endl;
	cout << "3: defenseman" << endl;
	cout << "4: goalie" << endl;
}

void NHL::pickLeaguePosition(int choice) {
	try {
		if (choice < 1 || choice > 4)
			throw string("invalid input: setting default value to 1.");
	}
	catch (string exceptionStirng) {
		cout << exceptionStirng << endl;
		choice = 1;
	}

	switch (choice) {
	case 1:
		position = "Center";
		break;
	case 2:
		position = "Winger";
		break;
	case 3:
		position = "Defenseman";
		break;
	case 4:
		position = "Goalie";
	}
}

#endif
