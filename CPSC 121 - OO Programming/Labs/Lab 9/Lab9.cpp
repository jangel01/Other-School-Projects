#include <iostream>

using namespace std;

struct ListNode {
    double value;
    ListNode *nextPtr;
    ListNode(double value1, ListNode* nextNode = nullptr) {
        value = value1;
        nextPtr = nextNode;
    }
};

string emptyList(ListNode *head) {
    if (head == nullptr) {
        return "The list is empty";
    }
    else {
        return "The list is not empty";
    }
}

int main()
{
    ListNode* p = new ListNode(56.4);
    p = new ListNode(34.2, p);
    cout << (*p).value << endl;
    cout << "------" << endl;
    // BUILDING A LIST WITH A LOOP
    
    ListNode* head = nullptr;

    int number, input;
    cout << "How many numbers are in the list?" << endl;
    cin >> number;

    // BUILDING THE LIST from the head then make the new node the head!
    for (int i = 0; i < number; i++) {
        cout << "Enter a num" << endl;
        cin >> input;
        head = new ListNode(input, head);
    }

    // TRAVERSE THROUGH A LIST with a loop to print the values
    ListNode* myCurrentNode = head;

    int counter = 0;
    double sum1 = 0;
    cout << "Traverse the list of nodes!" << endl;

    while (myCurrentNode != nullptr) {
        counter++;
        cout << "Node " << counter << "'s value is " << myCurrentNode->value << endl;
        sum1 += myCurrentNode->value;
        myCurrentNode = myCurrentNode->nextPtr;
    }
    
    cout << "Sum is: " << sum1 << endl;
    /*
    head = head->nextPtr;
    myCurrentNode = head;
    cout << "deleting first node." << endl;

    while (myCurrentNode != nullptr) {
        counter++;
        cout << "Node " << counter << "'s value is " << myCurrentNode->value << endl;
        myCurrentNode = myCurrentNode->nextPtr;
    }
    */
    system("PAUSE");
    return 0;
}

