#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Creature.h"
using namespace std;

class Player : public Creature {
public:
	Player(string name);
	virtual void DoAction();
	virtual void DrawOnScreen();
};

Player::Player(string name) 
	: Creature(name) {}

void Player::DoAction() {
	cout << " is attacking!!" << endl;
}

void Player::DrawOnScreen() {
	cout << "Player " << CreatureName;
	DoAction();
}

#endif
