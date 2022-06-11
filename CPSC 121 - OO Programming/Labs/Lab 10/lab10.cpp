#include <iostream>
#include <memory>
#include <time.h>
#include "DiceGame.h"

using namespace std;

void checkPtrStatus(shared_ptr<DiceGame> &smartPtr1, shared_ptr<DiceGame> &smartPtr2);

int main()
{
    srand(time(0));
    int input;

    cout << "====Creating Shared Pointer #1 to create the object====" << endl;
    shared_ptr<DiceGame> smartPtr1 = make_shared<DiceGame>();
    smartPtr1->displayDice();
    cout << endl;

    cout << "====Now creating Shared Pointer #2 to manage the same object." << endl;
    shared_ptr<DiceGame> smartPtr2 = smartPtr1;
    cout << "Pick a dice to reroll." << endl;
    cin >> input;
    smartPtr2->rerollDice(input);
    smartPtr2->displayDice();
    cout << endl;

    cout << "====Checking if pointers are being utilizied====" << endl;
    checkPtrStatus(smartPtr1, smartPtr2);
    cout << endl;

    cout << "====Releasing Pointer #1====" << endl;
    smartPtr1.reset();
    cout << "====Checking if pointers are being utilizied====" << endl;
    checkPtrStatus(smartPtr1, smartPtr2);
    cout << endl;

    cout << "====Releasing Pointer #2====" << endl;
    smartPtr2.reset();
    cout << "====Checking if pointers are being utilizied====" << endl;
    checkPtrStatus(smartPtr1, smartPtr2);

    system("PAUSE");
    return 0;
}


void checkPtrStatus(shared_ptr<DiceGame> &smartPtr1, shared_ptr<DiceGame> &smartPtr2) {
    if (smartPtr1) {
        cout << "Ptr1 currenty points to an object" << endl;
    }
    else {
        cout << "Ptr1 currently points to no object." << endl;
    }
    if (smartPtr2) {
        cout << "Ptr2 currently points to an object." << endl;
    }
    else {
        cout << "Ptr2 currently points to no object." << endl;
    }
    cout << endl;

    cout << "Ptr1's # of references in shared grouping: " << smartPtr1.use_count() << endl;
    cout << "Ptr2's # of references in shared grouping: " << smartPtr2.use_count() << endl;
}
