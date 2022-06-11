#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include "Creature.h"
using namespace std;

class Monster : public Creature {
public:
	Monster(string name);
	virtual void DoAction();
	virtual void DrawOnScreen();
};

Monster::Monster(string name)
	:Creature(name) {}

void Monster::DoAction() {
	cout << " is doing monster stuff!!" << endl;
}

void Monster::DrawOnScreen() {
	cout << "Monster " << CreatureName;
	DoAction();
}

#endif
