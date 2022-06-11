#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include "CommonStatistics.h"
using namespace std;

class Warrior : public CommonStatistics {
private:
	int healingRolls, healingSides, iniHealth, iniModifier;
public:
	Warrior(string n);
	virtual void showStatistics();
	virtual int getInitiativeScore();
	virtual void takeDamage(int damage);
	virtual int attack();
	virtual void resetHealth();
	virtual void heal();
};

Warrior::Warrior (string n) : CommonStatistics(n) {
	characterType = "Warrior";
	health = 20;
	armor = 5;
	healingRolls = 2;
	healingSides = 5;
	attackModifier = 3;
	baseAttackRolls = 1;
	baseAttackSides = 6;
	iniModifier = 4;
	iniHealth = health;
	cout << "You are now " << name << ", a ferocious " << characterType  << endl;
}

void Warrior :: showStatistics () {
	cout << characterType << " " <<  name << "'s current stats:" << endl;
	cout << "Health: " << health << endl;
	cout << "Healing Die: " << healingRolls << " D" << healingSides << endl;
	cout << "Base Attack Die: " << baseAttackRolls << " D" << baseAttackSides << endl;
	cout << "Armor: " << armor << endl;
	cout << "Attack Modifer (Strength): " << attackModifier << endl;
	cout << "Initiative Modifier (Speed): " << iniModifier << endl;
}

int Warrior::getInitiativeScore() {
	int score = rand() % 20 + 1;
	cout << "You rolled 1 dice (1-20). Initiative score of " << score << " + a speed modifer of "
		<< iniModifier << " for a total of " << score + iniModifier << endl;
	return score + iniModifier;
}

int Warrior::attack() {
	int damageScore = rand() % (baseAttackRolls * baseAttackSides) + 1;
	cout << "You rolled " << baseAttackRolls << " dice (" << baseAttackRolls << "-" << baseAttackSides
		<< "). Damage score of " << damageScore << " + a strength modifer of " << attackModifier <<
		" for a total of " << damageScore + attackModifier << endl;
	return damageScore + attackModifier;
}

void Warrior::heal() {
	int healingScore = rand() % (healingRolls * healingSides) + 1;
	// If condition makes sure player does not go above max capacity of their health.
	// There are multiple variables to compare the value of the player's health and the amount of health the player gained.
	if (health < iniHealth) {
		cout << "You heal yourself for " << healingScore << " hit points!" << endl;
		int healthDifference = iniHealth - health;
		while (healthDifference > 0 && healingScore > 0) {
			health++;
			healthDifference--;
			healingScore--;
		}
		cout << "Total HP now at: " << health << " (HP cap: " << iniHealth << ")" << endl;
	} else {
		cout << "You heal yourself for " << healingScore << " hit points!" << endl;
		cout << "Total HP capped at: " << iniHealth << endl;
	}
}

void Warrior::takeDamage(int damage) {
	health = (health + armor) - damage;
	cout << name << " has taken " << damage - armor << " damage and is now at " << health << " HP" << endl;
}

void Warrior::resetHealth() {
	health = iniHealth;
	cout << "A magical fairy vists you, health has been reset to " << iniHealth << endl;
}

#endif
