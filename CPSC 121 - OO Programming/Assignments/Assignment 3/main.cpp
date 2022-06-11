/*  Jason Angel
    Assignment 3 - Dungeons & Dragons 
    Section 5
    
    This program practices virtual functions and smart pointers to simulate a basic RPG. 
*/
#include <iostream>
#include <memory>
#include <time.h>
#include "CommonStatistics.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

using namespace std;

void playerChoice(int& input);
void gameRound(int& input, shared_ptr<Warrior> &warriorPlayer, shared_ptr<CommonStatistics> &enemy);

int main()
{
    srand(time(0));

    shared_ptr<CommonStatistics> enemy = nullptr;
    bool game_over = false;
    int currentInput;

    // Create and introduce player.
    shared_ptr<Warrior> warriorPlayer = make_shared<Warrior>("Knight Timmy");
    cout << endl;
    // Create and introduce first enemy.
    enemy = make_shared<Mage>("Wizard Gandolfo");
    cout << endl;

    // Show stats for player and first enemy.
    warriorPlayer->showStatistics();
    cout << endl;
    enemy->showStatistics();
    cout << endl;
    
    // Prgoram continues to loop until either the enemey or player reaches 0 health or below. This is the first battle.
    while (game_over == false) {
        gameRound(currentInput, warriorPlayer, enemy);

        if (warriorPlayer->getHealth() <= 0) {
            cout << " You have no more health, you lost the video game." << endl;
            game_over = true;
        }

        if (enemy->getHealth() <= 0 && warriorPlayer->getHealth() > 0) {
            cout << "The enemy has been slain!" << endl;
            cout << endl;
            break;
        }
    }

    // If player lost first battle, end the program.
    if (game_over == true) {
        return 0;
    }

    // Reset player health back to its capacity.
    warriorPlayer->resetHealth();
    cout << endl;

    // Introduce second enemy.
    enemy = make_shared<Rogue>("Assassin Jim");
    cout << endl;

    // Show stats for player and second enemy.
    warriorPlayer->showStatistics();
    cout << endl;
    enemy->showStatistics();
    cout << endl;

    // Just like the first while loop, program will continue to loop until either the enemy or player reach 0 health 
    // or below. This loop executes the second and last battle. If the player wins, they win the videogame.
    while (game_over == false) {
        gameRound(currentInput, warriorPlayer, enemy);

        if (warriorPlayer->getHealth() <= 0) {
            cout << "You have no more health, you lost the video game." << endl;
            game_over = true;
        }

        if (enemy->getHealth() <= 0 && warriorPlayer->getHealth() > 0) {
            cout << "The enemy has been slain!" << endl;
            cout << "You won the video game!" << endl;
            game_over = true;
        }
    }
   
    system("PAUSE");
    return 0;
}

// This function performs all the actions of a single round. The third paramter can take any enemy, despite
// it being defined as a base class.
void gameRound(int &curremtInput, shared_ptr<Warrior> &warriorPlayer, shared_ptr<CommonStatistics> &enemy) {
    // Condition of the if statment compares who has the higher initiative score. Whoever has the highest goes first.
    // Note that the order of the actions is dependent on who goes first as the "else" segment of the if statment performs
    // the same thing but in a different order.
    if (enemy->getInitiativeScore() < warriorPlayer->getInitiativeScore()) {
        cout << endl;
        playerChoice(curremtInput);
        switch (curremtInput) {
        case 1:
            // whatever is inside the () is performed and outputted first. I was thinking about making variables to hold 
            // the values but that takes up more lines of code.
            enemy->takeDamage(warriorPlayer->attack());
            warriorPlayer->takeDamage(enemy->attack());
            break;
        case 2:
            warriorPlayer->heal();
            warriorPlayer->takeDamage(enemy->attack());
        }
    }  else {
        cout << endl;
        warriorPlayer->takeDamage(enemy->attack());
        cout << endl;
        playerChoice(curremtInput);
        switch (curremtInput) {
        case 1:
            enemy->takeDamage(warriorPlayer->attack());
            break;
        case 2:
            warriorPlayer->heal();
        }
    }
    cout << endl;
}

// Function outputs choice menu and asks for input from the player
void playerChoice(int &currentInput) {
    cout << "Your Move:" << endl;
    cout << "What will you do?" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Heal" << endl;
    cin >> currentInput;
    cout << endl;
}
