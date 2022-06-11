#ifndef MLB_H
#define MLB_H
#include <iostream>
#include "Athlete.h"
using namespace std;

class MLB : public Athlete {
public:
	MLB(string sport, double sal);
	virtual void pickLeaguePosition(int choice);
	virtual void printPositionOptions();
};

MLB::MLB(string sport, double sal) : Athlete(sport, sal) {
	average_salary = 4170000;
	percent = (salary / average_salary) * 100;
}

void MLB::printPositionOptions() {
	cout << "What position does the athlete play?" << endl;
	cout << "(1-5)" << endl;
	cout << "1: pitcher" << endl;
	cout << "2: catcher" << endl;
	cout << "3: baseman" << endl;
	cout << "4: shortstop" << endl;
	cout << "5: outfielder" << endl;
}

void MLB::pickLeaguePosition(int choice) {
	try {
		if (choice < 1 || choice > 5)
			throw string("invalid input: setting default value to 1.");
	}
	catch (string exceptionStirng) {
		cout << exceptionStirng << endl;
		choice = 1;
	}

	switch (choice) {
	case 1:
		position = "Pitcher";
		break;
	case 2:
		position = "Catcher";
		break;
	case 3:
		position = "Baseman";
		break;
	case 4:
		position = "Shortstop";
		break;
	case 5:
		position = "Outfielder";
	}
}

#endif
