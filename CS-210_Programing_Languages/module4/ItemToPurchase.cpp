// ItemToPurchase.cpp

/***************
 *  CS-210 4-3 zyBooks Lab Activity 6.17
 *  Online_Shopping_Cart
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  March 31, 2024
 * 
 ***************/

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"  // inherits attributes and declarations from ItemToPurchase.h file


/*
*  default constructor in case class arguments are not passed in properly
*/
ItemToPurchase::ItemToPurchase() {
    itemName = "none";  // default name set to none, will indicate name was not set properly
    itemPrice = 0;  // default item price set to 0, will indicate price was not set properly
    itemQuantity = 0;  // default item quantity set to 0, will indicate quantity was not set properly
}

//class mutators

void ItemToPurchase::SetName(string name) {  // mutator to set object item name
    itemName = name;
}
void ItemToPurchase::SetPrice(int price) {  // mutator to set object item price
    itemPrice = price;
}
void ItemToPurchase::SetQuantity(int quantity) {  // mutator to set object item quantity
    itemQuantity = quantity;
}

// class accessors

string ItemToPurchase::GetName() const {  // accessor to retrieve object item name
    return itemName;
}
int ItemToPurchase::GetPrice() const {  // accessor to retrieve object item price
    return itemPrice;
}
int ItemToPurchase::GetQuantity() const {  // accessor to retriece object item quantity
    return itemQuantity;
}
