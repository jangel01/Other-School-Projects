/*
    Name: Jason Angel
    Section: 5
    Lab: 2

    This lab simulates a basic RPG using functions.

*/

#include <iostream>
#include <time.h>

using namespace std;

char menu();
void takeHit(int &playerHP);
int makeAttack(int enemyHP);
void healthPack(int &playerHP, int &enemyHP);
void poison(bool &check_if_poisoned); 

int main()
{
    srand(time(0));
    int playerHP = 20;
    int enemyHP = 10;
    bool game_over = false;
    bool is_poisoned = false;
    bool check_if_poisoned = false;
    int round_iteration = 3;

    cout << "Starting the RPG!" << endl;
    cout << "You spawned with 20 health." << endl;

 
    while (game_over == false) {
        char player_choice = menu();
        
        if (player_choice == 'b') {
            cout << "You ran away safely." << endl;
            cout << "Game over." << endl;
            break;
        }
       
        if (is_poisoned == false) {
            poison(check_if_poisoned);
        } 

        if (check_if_poisoned == true && playerHP > 0 && round_iteration > 0) {
            is_poisoned = true;
            round_iteration--;
            playerHP -= 1;
            if (round_iteration > 0) {
                cout << "You have lost 1 health from being poisoned. "
                    << round_iteration << " round(s) left." << endl;
            } else {
                is_poisoned = false;
                check_if_poisoned = false;
                round_iteration = 3;
            }  
        }


        takeHit(playerHP);
        enemyHP = makeAttack(enemyHP);
        healthPack(playerHP,enemyHP);
        
        if (playerHP <= 0 || enemyHP <= 0) {
            cout << "Game over." << endl;
            game_over = true;
        }
    }
    
    cout << endl;

    system("PAUSE");
    return 0;
}

// Function outputs selection menu and returns the player's action.
char menu() {
    char action;
    do {
        cout << "An enemy lies before you, what will you do?" << endl;
        cout << "'a' Attack, 'b' Run" << endl;
        cin >> action;
        if (action != 'a' && action != 'b') {
            cout << "PLEASE ENTER VALID ANSWER" << endl;
        }
    } while (action != 'a' && action != 'b');

    return action;
}

// Function calculates attack made against the player and substracts it from 
// the player's health.
void takeHit(int &playerHP) {
    int enemy_num = rand() % 5 + 1;
    playerHP -= enemy_num;

    cout << "The enemy strieks you for " << enemy_num << " damage!" << endl;
    if (playerHP > 0) {
        cout << playerHP << " HP reamining." << endl;
    }
    else {
        cout << "You died." << endl;
    }
}

// Function calculates attack made against the enemy and subtracts it from
// enemy's total health.
int makeAttack(int enemyHP) {
    int player_num = rand() % 3 + 1;
    enemyHP -= player_num;

    cout << "You strike your foe for " << player_num << " damage!" << endl;
    if (enemyHP > 0) {
        cout << enemyHP << " Enemy HP remaining." << endl;
    }
    else {
        cout << "Your foe has been slain!" << endl;
    }

    return enemyHP;
}

// chance of either player or enemy gaining health (was added, but not necessary for lab)
void healthPack(int &playerHP, int &enemyHP) {
    int num = rand() % 3 + 1;
    int second_num = rand() % 2 + 1;
    if (num == 3 && playerHP > 0 && enemyHP > 0) {
        cout << "--------------------------------" << endl;
        if (second_num == 1) {
            cout << "Congrats, you gained 2 health!" << endl;
            playerHP += 2;
            cout << "You now have " << playerHP << " health." << endl;
        }
        else {
            cout << "Oh no, the enemy gained 1 health!" << endl;
            enemyHP += 1;
            cout << "Your enemy now has " << enemyHP << " health." << endl;
        }
        cout << "--------------------------------" << endl;
    }
}

void poison(bool &check_if_poisoned) {
    int num = rand() % 5 + 1;
    if (num == 5) {
        cout << "--------------------------------" << endl;
        cout << "You have been cursed by the RNG god." << endl;
        cout << "You are now poisoned for the next 3 rounds." << endl;
        check_if_poisoned = true;
        cout << "--------------------------------" << endl;
    }
}

