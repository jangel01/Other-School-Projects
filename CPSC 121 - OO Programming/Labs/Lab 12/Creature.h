#ifndef CREATIRE_H
#define CREATIRE_H
using namespace std;

class Creature {
protected:
	string CreatureName;
public:
	Creature(string name);
	virtual void DoAction() = 0;
	virtual void DrawOnScreen() = 0;
};

Creature::Creature(string name)
	:CreatureName(name) {}

#endif
