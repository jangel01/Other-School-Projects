#include <iostream>
#include <memory>
#include <iomanip>
#include "Athlete.h"
#include "NBA.h"
#include "MLB.h"
#include "NHL.h"
using namespace std;

int main()
{
	cout << setprecision(2) << fixed;

	int sport_choice;
	int position_choice;
	double salary;
	shared_ptr<Athlete> unknown = nullptr;

	cout << "Which sport does the athlete play?" << endl;
	cout << "1-3" << endl;
	cout << "1: NBA" << endl;
	cout << "2: MLB" << endl;
	cout << "3: NHL" << endl;

	cin >> sport_choice;
	try {
		if (sport_choice < 1 || sport_choice > 3)
			throw string("invalid input: setting default value to 1.");
	}
	catch (string exceptionString) {
		cout << exceptionString << endl;
		sport_choice = 1;
	}

	cout << "What is the athlete's salary?" << endl;

	cin >> salary;
	try {
		if (salary <= 0) 
			throw string("invalid input: setting default salary to 2500000");
	}
	catch (string exceptionString) {
		cout << exceptionString << endl;
		salary = 2500000;
	}

	switch (sport_choice) {
	case 1:
		unknown = make_shared<NBA>("NBA", salary);
		break;
	case 2:
		unknown = make_shared<MLB>("MLB", salary);
		break;
	case 3:
		unknown = make_shared<NHL>("NHL", salary);
	}

	unknown->printPositionOptions();
	cin >> position_choice;
	unknown->pickLeaguePosition(position_choice);

	cout << "Athlete Data: " << unknown->getAthleteSport() << " " << unknown->getAthletePosition() << endl;
	unknown->displayLeagueSalaryData();

	system("PAUSE");
	return 0;
}
