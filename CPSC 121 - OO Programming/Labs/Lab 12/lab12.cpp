#include <iostream>
#include <memory>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "WildPig.h"
#include "Dragon.h"
using namespace std;

int main()
{
    shared_ptr<Player> person1 = make_shared<Player>("Timmy");
    person1->DrawOnScreen();
    cout << endl;

    shared_ptr<Monster> monster1 = make_shared<Monster>("UFO");
    monster1->DrawOnScreen();
    cout << endl;

    shared_ptr<WildPig> wildpig1 = make_shared<WildPig>("Piglet");
    wildpig1->DrawOnScreen();
    cout << endl;

    shared_ptr<Dragon> dragon1 = make_shared<Dragon>("Viserion");
    dragon1->DrawOnScreen();
    cout << endl;

    system("PAUSE");
    return 0;
}
