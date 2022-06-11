/* Name: Jason Angel
* assignment 2
* section 5
* 
* This assignment practices the concepts of classes, functions, and header files. The class for this program 
  is in the header file "item.h".  Program simulates a simple inventory managment system. 
*/
#include <iostream>
#include <iomanip>
#include "Item.h"

using namespace std;

void createInventory(Item[4]);
void showInventory(Item[4]);
void performTransaction(Item[4]);
void startSale(Item[4]);
bool itemsInStock(Item[4]);

int main()
{
    // Fix retail prices to two decimal places.
    cout << setprecision(2) << fixed;

    cout << "==Welcome to the inventory helper!==" << endl;
    cout << "-store hours will begin shortly." << endl;
    cout << "Please update your inventory..." << endl;
    cout << endl;

    Item inventory[4];
    // Populate empty inventory
    createInventory(inventory);
    // show initial inventory user created
    showInventory(inventory);
    cout << endl;

    char input;
    cout << "Business hours are now open." << endl;
    cout << "Would you like to perform a transaction? (y/n)" << endl;
    cin >> input;
    cout << endl;

    int items_sold = 0;
    while (input == 'y' && itemsInStock(inventory) == true)  {
        // Sale starts after two items are sold
        if (items_sold == 2) {
            startSale(inventory);
        }

        performTransaction(inventory);
        cout << "Would you like to perform another transaction? (y/n)" << endl;
        cin >> input;
        cout << endl;

        items_sold++;
    }
    

    cout << "Closing shop -- inventory left." << endl;
    showInventory(inventory);

    system("PAUSE");
    return 0;
}

// Function prompts user to create inventory of 4 items which are stored in a array of objects.
void createInventory(Item inventory[4]) {
    for (int i = 0; i < 4; i++) {
        string name;
        int manufacture_id;
        double retail_value;
        int quantity;

        cout << "Enter item " << i + 1 << " to add to inventory." << endl;
        cout << "Please enter the product name." << endl;
        cin >> name;
        inventory[i].setName(name);
        cout << "Enter product manufacture's id." << endl;
        cin >> manufacture_id;
        inventory[i].setManufactureID(manufacture_id);
        cout << "Enter the retail value." << endl;
        cin >> retail_value;
        inventory[i].setRetailValue(retail_value);
        cout << "Enter quantity available." << endl;
        cin >> quantity;
        inventory[i].setQuantity(quantity);

    }
    cout << endl;
}

// Function shows all inventory information. Is used at the start and end of program.
void showInventory(Item inventory[4]) {
    for (int i = 0; i < 4; i++) {
        cout << inventory[i].getQuantity() << " " << inventory[i].getName() << " left in stock at $" <<
             inventory[i].getRetailValue() << " item id " << inventory[i].getManufactureID() << endl;
    }
}

// Function performs transaction. Asks user what item they would like to purchase and the quantity.
void performTransaction(Item inventory[4]) {
    int item_choice;
    int quantity_amount; 

    cout << "=====Menu=====" << endl;
    cout << "Enter which item you would like to purchase." << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << inventory[i].getQuantity() << " " << inventory[i].getName() << " left in stock at $" <<
             inventory[i].getRetailValue() << " item id " << inventory[i].getManufactureID() << endl;
    }
    
    do {
        cin >> item_choice;
        // adjust item_choice so it is correctly used in inventory array
        item_choice -= 1;
        if (inventory[item_choice].getQuantity() == 0) {
            cout << "That item is out of stock. Please pick another item." << endl;
        }
    } while (inventory[item_choice].getQuantity() == 0);
    
    cout << "How much would you like to buy? " << endl;
    cin >> quantity_amount;

    // verify the quantity user inputted is not greater than what is available of the item that is being purchased.
    while (quantity_amount > inventory[item_choice].getQuantity()) {
        cout << "Not enough " << inventory[item_choice].getName() << " in stock (" << inventory[item_choice].getQuantity() <<
            ") total stock. ";
        cout << "Enter new amount." << endl;
        cin >> quantity_amount;
    }

    inventory[item_choice].adjustQuantity(quantity_amount);

    cout << "SOLD " << quantity_amount << " " << inventory[item_choice].getName() <<" for $" << 
        inventory[item_choice].getTransactionAmount(quantity_amount) << endl;
    cout << endl;
}

// Function prompts the user if they would like to enter a discount after 2 items are sold. 
// If user says yes, function prompts for discount amount and adjusts prices for each indivudal item accordingly.
void startSale(Item inventory[4]) {
    char add_discount;

    cout << "2 items sold!" << endl;
    cout << "Sale starting!" << endl;
    cout << "Would you like to enter a discount? (y/n)" << endl;
    cin >> add_discount;
    double discount_percentage;
    if (add_discount == 'y') {
        do {
            cout << "Enter the custom discount percentage." << endl;
            cin >> discount_percentage;
        } while (discount_percentage < 0.01 || discount_percentage > 0.99);

        for (int i = 0; i < 4; i++) {
            inventory[i].adjustPrice(discount_percentage);
            cout << "Price for " << inventory[i].getName() << " on sole for $" << inventory[i].getRetailValue() << endl;
        }
    }
    else {
        cout << "No sale will take place, all prices remain the same." << endl;
    }
    cout << endl;
}

// Function checks on the status of the inventory. If the inventory is still in stock, the program continues (function returns true). 
// If the inventory is empty, the program ends (function returns false).
bool itemsInStock(Item inventory[4]) {
    int cumulative_item_quantity = 0;
    for (int i = 0; i < 4; i++) {
        cumulative_item_quantity += inventory[i].getQuantity();
    }

    if (cumulative_item_quantity == 0) {
        return false;
    }   
    return true;
}
