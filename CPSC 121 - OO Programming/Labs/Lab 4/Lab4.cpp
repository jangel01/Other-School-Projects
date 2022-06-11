/*  
  Name: Jason Angel
  Lab: 4
  Section: 5

  This program simulates the Montly hall game. 
*/

#include <iostream>
#include <time.h>

using namespace std;

const char GOAT = 'g';
const char CAR = 'c';

void startMessage();
void drawDoors(int, int, char, char, char);

int main()
{
    srand(time(0));
    char door1_item{ GOAT }, door2_item{ GOAT }, door3_item{ GOAT };
    int tries = 1;
    bool winner = false;
    int car_door = rand() % 3 + 1;

    switch (car_door) {
    case 1:
        door1_item = CAR;
        break;
    case 2:
        door2_item = CAR;
        break;
    default:
        door3_item = CAR;
    }

    startMessage();
    
    while (tries < 3 && winner == false) {
        int input;
        cin >> input;
        drawDoors(car_door, input, door1_item, door2_item, door3_item);
        if (input == car_door) {
            cout << "YOU WIN!" << endl;
            winner = true;
        }
        else {
            if (tries == 1) {
                cout << "You reveal a goat. Try one more time." << endl;
                tries++;
            }
            else {
                cout << "You reveal a goat! Bettte luck next time." << endl;
                tries++;
            }
        }
    }
  
    system("PAUSE");
    return 0;
   
}

// Function prints welcome information.
void startMessage() {
    cout << "Welcome to the Montly Hall Gameshow!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Behind one of these 3 doors is a brand new car." << endl;
    cout << "Behind the other two are goats. Guess the door with the hidden car and you win!" << endl;
    cout << "Choose a door" << endl;

    cout << "------          ------          ------" << endl;
    cout << "| 1  |          | 2  |          | 3   |" << endl;
    cout << "|    |          |    |          |     |" << endl;
    cout << "------          ------          ------" << endl;
}

// This function redraws the doors based on the door that is picked. 
void drawDoors(int car_door, int input, char door1_item, char door2_item, char door3_item) {
    char door1{ '1' }, door2{ '2' }, door3{ '3' };

    switch (input) {
    case 1:
        door1 = door1_item;
        break;
    case 2:
        door2 = door2_item;
        break;
    default:
        door3 = door3_item;
    }

    cout << "------          ------          ------" << endl;
    cout << "| " << door1 << "  |          | " << door2 << 
        "  |          | " << door3 << "   |" << endl;
    cout << "|    |          |    |          |     |" << endl;
    cout << "------          ------          ------" << endl;
}
