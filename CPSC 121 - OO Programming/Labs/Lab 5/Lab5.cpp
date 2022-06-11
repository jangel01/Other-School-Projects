/*
* Name: Jason Angel
* Lab: 5
* Section: 5
*
* This lab simulates a virtual pet game. Keep your pet alive by choosing an action that improves an attribute.
* You win if pet reaches age 5, you lose if any attribute falls to 0.
*
* This program is an introduction to classes.
*/
#include <iostream>
#include <time.h>

using namespace std;

class Pet {
private:
    bool isAlive = true;
    string pet_name;
    int hunger;
    int cleaniess;
    int happiness;
    int health;
    int age;
public:
    // Constructor asks for pet name, randomizes pet attributes, and sets pat age to 0.
    Pet() {
        cout << "-Virtual Orangutan-" << endl;
        cout << "---- - m------m------" << endl;
        cout << "       @(o.o)@" << endl;
        cout << "          0)~~" << endl;
        cout << "         o o" << endl;
        cout << "Please enter a name for your pet." << endl;
        cout << "Orangutan: ";
        cin >> pet_name;
        hunger = rand() % 5 + 1;
        cleaniess = rand() % 5 + 1;
        happiness = rand() % 5 + 1;
        health = rand() % 5 + 1;
        age = 0;
    }

    // Function is called when feed choice is selected. Adds a point to hunger, pet ages by 1.
    void feed() {
        hunger++;
        age++;
        cout << pet_name << " dances with joy and devours pasta." << endl;
    }

    // Function is called when wash choice is selected. Adds a point to cleaniess, pet ages by 1.
    void wash() {
        cleaniess++;
        age++;
        cout << pet_name << " puts a fight to resist, however he gives " <<
            "in and becomes squeaky clean." << endl;
    }

    // Function is called when play choice is selected. Adds a point to happiness, pet ages by 1.
    void play() {
        happiness++;
        age++;
        cout << pet_name << " goes for a bike ride." << endl;
    }

    // Function is called when health choice is selected. Adds a point to health, pet ages by 1.
    void heal() {
        health++;
        age++;
        cout << pet_name << " thrashes around the pet office breaking " <<
            "a window trying to escape from a shot." << endl;
    }

    // Function selects random attribute to deduct a point from.
    void randomAttribute() {
        int num = rand() % 4 + 1;
        switch (num) {
        case 1:
            hunger--;
            break;
        case 2:
            cleaniess--;
            break;
        case 3:
            happiness--;
            break;
        case 4:
            health--;
        }
    }

    // Function displays and updates pet attributes.
    void displayAttributes() {
        cout << "--" << pet_name << "'s stats --" << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Cleaniess: " << cleaniess << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Health: " << health << endl;
        cout << "Age: " << age << endl;

    }

    // Function displays menu of choices for user to pick.
    void displayMenu() {
        cout << "Main menu: " << endl;
        cout << "1. Feed" << endl;
        cout << "2. Wash" << endl;
        cout << "3. Play" << endl;
        cout << "4. Health" << endl;
    }

    // Function updates game status and returns boolean value.
    // Pet is no longer alive if pet reaches age 5 or an attribute reaches 0.
    bool playing() {
        if (age == 5) {
            displayAttributes();
            cout << pet_name << " died of old age." << endl;
            isAlive = false;
            return isAlive;
        }

        if (hunger == 0 || cleaniess == 0 || happiness == 0 || health == 0) {
            displayAttributes();
            cout << pet_name << " died tragically." << endl;
            isAlive = false;
            return isAlive;
        }
        return isAlive;
    }
};


int main() {
    srand(time(0));

    Pet pet1;

    while (pet1.playing() == true) {
        pet1.displayAttributes();
        pet1.displayMenu();

        // input corresponds to what the user picks from the menu of actions.
        int input;
        do {
            cout << "Enter a number (1-4):" << endl;
            cin >> input;
        } while (input < 1 || input > 4);

        switch (input) {
        case 1:
            pet1.randomAttribute();
            pet1.feed();
            break;
        case 2:
            pet1.randomAttribute();
            pet1.wash();
            break;
        case 3:
            pet1.randomAttribute();
            pet1.play();
            break;
        case 4:
            pet1.randomAttribute();
            pet1.heal();
        }
    }

    system("PAUSE");
    return 0;
}



/* OLD CODE
* 
#include <iostream>
#include <time.h>

using namespace std;

class Pet {
private:
    bool isAlive = true;
    string pet_name;
    int hunger;
    int cleaniess;
    int happiness;
    int health;
    int age;
public:
    // Each time an object is created from pet class, constructor asks for pet name, 
    // randomizes pet attributes, and sets pat age to 0.
    Pet() {
        cout << "-Virtual Orangutan-" << endl;
        cout << "---- - m------m------" << endl;
        cout << "       @(o.o)@" << endl;
        cout << "          0)~~" << endl;
        cout << "         o o" << endl;
        cout << "Please enter a name for your pet." << endl;
        cout << "Orangutan: ";
        cin >> pet_name;
        hunger = rand() % 5 + 1;
        cleaniess = rand() % 5 + 1;
        happiness = rand() % 5 + 1;
        health = rand() % 5 + 1;
        age = 0;
    }

    // Function is called when feed choice is selected. Adds a point to hunger, pet ages by 1.
    void feed() {
        hunger++;
        age++;
        cout << pet_name << " dances with joy and devours pasta." << endl;
    }

    // Function is called when wash choice is selected. Adds a point to cleaniess, pet ages by 1.
    void wash() {
        cleaniess++;
        age++;
        cout << pet_name << " puts a fight to resist, however he gives " <<
            "in and becomes squeaky clean." << endl;
    }

    // Function is called when play choice is selected. Adds a point to happiness, pet ages by 1.
    void play() {
        happiness++;
        age++;
        cout << pet_name << " goes for a bike ride." << endl;
    }

    // Function is called when health choice is selected. Adds a point to health, pet ages by 1.
    void heal() {
        health++;
        age++;
        cout << pet_name << " thrashes around the pet office breaking " <<
            "a window trying to escape from a shot." << endl;
    }

    // function selects random attribute to deduct a point from.
    void randomAttribute() {
        int num = rand() % 4 + 1;
        switch (num) {
        case 1:
            hunger--;
            break;
        case 2:
            cleaniess--;
            break;
        case 3:
            happiness--;
            break;
        default:
            health--;
        }
    }

    // Function displays and updates pet attributes
    void displayAttributes() {
        cout << "--" << pet_name << "'s stats --" << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "Cleaniess: " << cleaniess << endl;
        cout << "Happiness: " << happiness << endl;
        cout << "Health: " << health << endl;
        cout << "Age: " << age << endl;

    }

    // Function displays menu, and asks for user input. User input then calls specified function associated
    // with the user's choice.
    void displayMenu() {
        cout << "Main menu: " << endl;
        cout << "1. Feed" << endl;
        cout << "2. Wash" << endl;
        cout << "3. Play" << endl;
        cout << "4. Health" << endl;

        int input;
        do {
            cout << "Enter a number (1-4):" << endl;
            cin >> input;
        } while (1 < input && input > 4);

        switch (input) {
        case 1:
            randomAttribute();
            feed();
            break;
        case 2:
            randomAttribute();
            wash();
            break;
        case 3:
            randomAttribute();
            play();
            break;
        default:
            randomAttribute();
            heal();
        }
    }

    // Function loops through game until the pet is no longer alive.
    // Pet is no longer alive if pet reaches age 5 or an attribute reaches 0.
    void playing() {
        while (isAlive == true) {
            displayAttributes();
            displayMenu();

            if (age == 5) {
                displayAttributes();
                cout << pet_name << " died of old age." << endl;
                isAlive = false;
            }

            if (hunger == 0 || cleaniess == 0 || happiness == 0 || health == 0) {
                displayAttributes();
                cout << pet_name << " died tragically." << endl;
                isAlive = false;
            }
        }
    }
};


int main() {
    srand(time(0));

    Pet pet1;
    pet1.playing();
  
    system("PAUSE");
    return 0;
}

*/
