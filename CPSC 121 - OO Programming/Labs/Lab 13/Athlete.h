#ifndef ATHLETE_H
#define ATHLETE_H
#include <iostream>
using namespace std;

class Athlete {
protected:
	double salary;
	double average_salary;
	double percent;
	string position;
	string league;
public:
	Athlete(string sport, double sal);
	virtual void pickLeaguePosition(int choice) = 0;
	virtual void printPositionOptions() = 0;
	void displayLeagueSalaryData();
	string getAthletePosition();
	string getAthleteSport();
};

Athlete::Athlete(string sport, double sal) {
	league = sport;
	salary = sal;
}

string Athlete::getAthletePosition() {
	return position;
}

string Athlete::getAthleteSport() {
	return league;
}

void Athlete::displayLeagueSalaryData() {
	cout << "This Athlete's salary of $" << salary << " compares to " << percent << "% of the average "
		<< league << " player's salary of $" << average_salary << endl;
}

#endif
