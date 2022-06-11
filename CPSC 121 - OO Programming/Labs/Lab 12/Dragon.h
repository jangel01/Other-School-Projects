#ifndef DRAGON_H
#define DRAGON_H
#include <iostream>
#include "Creature.h"
#include "Monster.h"
using namespace std;

class Dragon : public Monster {
public:
	Dragon(string name);
	virtual void DoAction();
	virtual void DrawOnScreen();
};

Dragon::Dragon(string name) 
	:Monster(name) {}

void Dragon::DoAction() {
	cout << " is breathing Fire!!!" << endl;
}

void Dragon::DrawOnScreen() {
	cout << "Dragon " << CreatureName;
	DoAction();
}

#endif
