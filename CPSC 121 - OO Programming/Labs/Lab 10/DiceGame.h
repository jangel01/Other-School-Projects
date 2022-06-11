#ifndef DICEGAME_H
#define DICEGAME_H

#include <iostream>

using namespace std;

class DiceGame {
private:
	int dice1, dice2, dice3;
public:
	DiceGame();
	~DiceGame();
	void displayDice();
	void rerollDice(int dice);
};

DiceGame::DiceGame() {
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	dice3 = rand() % 6 + 1;
}

DiceGame::~DiceGame() {
	cout << "No shared Pointers left to manage dice object, Deconstructor called on dice object!" << endl;
}

void DiceGame::displayDice() {
	cout << "Dice #1 is " << dice1 << endl;
	cout << "Dice #2 is " << dice2 << endl;
	cout << "Dice #3 is " << dice3 << endl;

	if (dice1 == dice2 && dice1 == dice3) {
		cout << "all three dice are equal" << endl;
	}
	else if (dice1 == dice2 || dice2 == dice3 || dice1 == dice3) {
		cout << "two dice are equal" << endl;
	}
	else {
		cout << "no dice are equal" << endl;
	}
}

void DiceGame::rerollDice(int dice) {
	switch (dice) {
	case 1:
		dice1 = rand() % 6 + 1;
		break;
	case 2:
		dice2 = rand() % 6 + 1;
		break;
	case 3:
		dice3 = rand() % 6 + 1;
	}
}

#endif
