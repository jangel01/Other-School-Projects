#ifndef MAGE_H
#define MAGE_H
#include <iostream>
#include "CommonStatistics.h"
using namespace std;

class Mage : public CommonStatistics {
public:
	Mage(string n);
	virtual void showStatistics();
	virtual int getInitiativeScore();
	virtual void takeDamage(int damage);
	virtual int attack();
};

Mage::Mage (string n): CommonStatistics(n) {
	characterType = "Mage";
	health = 15;
	armor = 2;
	attackModifier = 7;
	baseAttackRolls = 1;
	baseAttackSides = 4;
	cout << "A " << characterType << " named " << name << " appears and is ready to battle!" << endl;
}

void Mage::showStatistics() {
	cout << characterType << " " << name << "'s current stats:" << endl;
	cout << "Health: " << health << endl;
	cout << "Base Attack Die: " << baseAttackRolls << " D" << baseAttackSides << endl;
	cout << "Armor: " << armor << endl;
	cout << "Attack Modifier (Intellect): " << attackModifier << endl;
}

int Mage::getInitiativeScore() {
	int score = rand() % 20 + 1;
	cout << "The " << characterType << " rolled 1 dice (1-20). Initiative score of " << score << " and has no speed modifier" << endl;
	return score;
}

void Mage::takeDamage(int damage) { 
	health = (health + armor) - damage;
	cout << name << " has taken " << damage - armor << " damage and is now at " << health << " HP" << endl;
}

int Mage::attack() {
	int damageScore = rand() % (baseAttackRolls * baseAttackSides) + 1;
	cout << name << " rolled " << baseAttackRolls << " dice (" << baseAttackRolls << "-" << baseAttackSides
		<< "). Damage score of " << damageScore << " + an intellect modifer of " << attackModifier <<
		" for a total of " << damageScore + attackModifier << endl;
	return damageScore + attackModifier;
}

#endif
