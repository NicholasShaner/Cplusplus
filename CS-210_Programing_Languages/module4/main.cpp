// main.cpp

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

#include "ItemToPurchase.h"
#include "ItemToPurchase.cpp"

int main() {
    /*
    * class object declaration for 2 items as requested in activity outline
    */
   ItemToPurchase item1;
   ItemToPurchase item2;
   
   // local variables for receiving input and setting class arguments
   string name;
   int price;
   int quantity;

   /*
   * Item 1 user input
   */
   cout << "Item 1\n";
   cout << "Enter the item name:\n";
   getline(cin, name);  // get item 1 name from user
   item1.SetName(name);  // set item 1 name to class object item1
   cout << "Enter the item price:\n";
   cin >> price;  // get item 1 price from user
   item1.SetPrice(price);  // set item 1 price to class object item1
   cout << "Enter the item quantity:\n";
   cin >> quantity;  // get item 1 quantity from user
   item1.SetQuantity(quantity);  // set item 1 quantity to class object item1
   
   cin.ignore();
   
   cout << endl;
   cout << "Item 2\n";
   cout << "Enter the item name:\n";
   getline(cin, name);  // get item 2 name from user
   item2.SetName(name);  // set item 2 name to class object item2
   cout << "Enter the item price:\n";
   cin >> price;  // get item 2 price from user
   item2.SetPrice(price);  // set item 2 price to class object item2
   cout << "Enter the item quantity:\n";
   cin >> quantity;  // get item 2 quantity from user
   item2.SetQuantity(quantity);  // set item 2 quantity to class object item2

   /*
   * print statement for item1 and item2 totals determined by unit price and quantity requested
   * better to be placed within a class function??
   * */
   cout << "\n";
   cout << "TOTAL COST\n";
   // item1 total print statement
   cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $";
   int total1 = (item1.GetQuantity() * item1.GetPrice());  // declared total1 local variable
   cout << total1 << endl;
   // item2 total print statement
   cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $";
   int total2 = (item2.GetQuantity() * item2.GetPrice());  // declared total2 local variable
   cout << total2 << endl;
   cout << endl;
   cout << "Total: $" << (total1 + total2) << endl;   

   
   return 0;
}