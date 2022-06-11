#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
private:
	string name;
	int manufacture_id;
	double retail_value;
	int quantity;
public:
	void setName(string name);
	void setManufactureID(int manufacture_id);
	void setRetailValue(double retail_value);
	void setQuantity(int quantity);
	string getName();
	int getManufactureID();
	double getRetailValue();
	int getQuantity();
	void adjustQuantity(int quantity_of_transaction);
	void adjustPrice(double discount_amount);
	double getTransactionAmount(double quantity_sold);
};

void Item::setName(string name) {
	this->name = name;
}

void Item::setManufactureID(int manufacture_id) {
	this->manufacture_id = manufacture_id;
}

void Item::setRetailValue(double retail_value) {
	this->retail_value = retail_value;
}

void Item::setQuantity(int quantity) {
	this->quantity = quantity;
}

string Item::getName() {
	return name;
}

int Item::getManufactureID() {
	return manufacture_id;
}

double Item::getRetailValue() {
	return retail_value;
}

int Item::getQuantity() {
	return quantity;
}

// Function adjusts item quantity amount depending on the size of each transaction.
void Item::adjustQuantity(int quantity_of_transaction) {
	quantity -= quantity_of_transaction;
}

// Function sets new price for item depending on the discount amount the user inputs. 
// Function only executes if user wishes to add a discount after 2 items are sold.
void Item::adjustPrice(double discount_amount) {
	retail_value = (retail_value) - (retail_value * discount_amount);
}

// Function gets total price of transaction depending on the quantity sold of the item
double Item::getTransactionAmount(double quantity_sold) {
	return quantity_sold * retail_value;
}

#endif
