#ifndef WILDPIG_H
#define WILDPIG_H
#include <iostream>
#include "Creature.h"
#include "Monster.h"
using namespace std;

class WildPig : public Monster {
public:
	WildPig(string name);
	virtual void DoAction();
	virtual void DrawOnScreen();
};

WildPig::WildPig(string name) 
	:Monster(name) {}

void WildPig::DoAction() {
	cout << " is Running!!!" << endl;
}

void WildPig::DrawOnScreen() {
	cout << "WildPig " << CreatureName;
	DoAction();
}

#endif
