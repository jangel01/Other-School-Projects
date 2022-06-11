#ifndef ROGUE_H
#define ROGUE_H
#include <iostream>
#include "CommonStatistics.h"
using namespace std;

class Rogue : public CommonStatistics {
private:
	int iniModifier;
public:
	Rogue(string n);
	virtual void showStatistics();
	virtual int getInitiativeScore();
	virtual void takeDamage(int damage);
	virtual int attack();
};

Rogue::Rogue(string n) : CommonStatistics(n) {
	characterType = "Rogue";
	health = 10;
	armor = 3;
	attackModifier = 4;
	baseAttackRolls = 2;
	baseAttackSides = 4;
	iniModifier = 5;
	cout << "A " << characterType << " named " << name << " appears and is ready to battle!" << endl;
}

void Rogue::showStatistics() {
	cout << characterType << " " << name << "'s current stats:" << endl;
	cout << "Health: " << health << endl;
	cout << "Base Attack Die: " << baseAttackRolls << " D" << baseAttackSides << endl;
	cout << "Armor: " << armor << endl;
	cout << "Attack Modifier (Agility): " << attackModifier << endl;
	cout << "Initiative Modifier (Speed): " << iniModifier << endl;
	cout << "50% chance to dodge an incoming attack." << endl;
}

int Rogue::getInitiativeScore() {
	int score = rand() % 20 + 1;
	cout << "The " << characterType << " rolled 1 dice (1-20). Initiative score of " << score << " + a speed modifer of "
		<< iniModifier << " for a total of " << score + iniModifier << endl;
	return score + iniModifier;
}

void Rogue::takeDamage(int damage) {
	int dodge = rand() % 2 + 1;
	if (dodge == 1) {
		cout << name << " dodged the attack!" << endl;
	}
	else {
		health = (health + armor) - damage;
		cout << name << " has taken " << damage - armor << " damage and is now at " << health << " HP" << endl;
	}
}

int Rogue::attack() {
	int damageScore = rand() % (baseAttackRolls * baseAttackSides) + 1;
	cout << name << " rolled " << baseAttackRolls << " dice (" << baseAttackRolls << "-" << baseAttackSides
		<< "). Damage score of " << damageScore << " + an agility modifer of " << attackModifier <<
		" for a total of " << damageScore + attackModifier << endl;
	return damageScore + attackModifier;
}
#endif
