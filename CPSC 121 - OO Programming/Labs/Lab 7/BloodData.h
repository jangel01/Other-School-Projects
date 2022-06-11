#ifndef BLOODDATA_H
#define BLOODDATA_H

#include <iostream>

using namespace std;

class BloodData {
private:
	string blood_type;
	char RhFactor;
public:
	BloodData();
	BloodData(char, string);
	string getBT();
	char getRF();
};

BloodData::BloodData() {
	blood_type = "O";
	RhFactor = '+';
}

BloodData::BloodData(char r_f, string b_t) {
	if (r_f == '-' || r_f == '+') {
		RhFactor = r_f;
	}
	else {
		RhFactor = '?';
	}

	if (b_t == "O" || b_t == "A" || b_t == "B" || b_t == "AB") {
		blood_type = b_t;
	}
	else {
		blood_type = "?";
	}
}

string BloodData::getBT() {
	return blood_type;
}

char BloodData::getRF() {
	return RhFactor;
}

#endif
