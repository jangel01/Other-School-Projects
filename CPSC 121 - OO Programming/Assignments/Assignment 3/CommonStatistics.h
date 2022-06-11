#ifndef COMMONSTATISITCS_H
#define COMMONSTATISITCS_H
#include <iostream>
using namespace std;

class CommonStatistics {
protected:
	string name, characterType;
	int health, armor, attackModifier, baseAttackRolls, baseAttackSides;
public:
	// All member variables are set to default values through derived classes other than the character name.
	CommonStatistics(string n);
	// Function outputs message and returns an initiative score.
	virtual int getInitiativeScore() = 0;
	// Function shows stats of the character. Some characters have unique characteristics.
	virtual void showStatistics() = 0;
	// Function deducts health from character. The parameter is derived based on whatever value is returned from
	// the attack() function
	virtual void takeDamage(int damage) = 0;
	// Function performs character attack. Returns a value that is used for the takeDamage() function.
	virtual int attack() = 0;
	// Function is unique to the player. Reset health back to its max capacity.
	virtual void resetHealth() {}
	// Function is unique to the player. Adjusts health based on RNG.
	virtual void heal() {}
	// Function returns health value of character
	int getHealth();
};

CommonStatistics::CommonStatistics(string n)  {
	name = n;
}

int CommonStatistics::getHealth() {
	return health;
}

#endif
