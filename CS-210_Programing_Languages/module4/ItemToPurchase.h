// ItemToPurchase.h

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

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

/*
* ItemToPurchase class declaration
*/
class ItemToPurchase {
    public:
        /*
        *  default constructor
        */
        ItemToPurchase();

        //class mutators

        void SetName(string name);
        void SetPrice(int price);
        void SetQuantity(int quantity);

        // class accessors

        string GetName() const;
        int GetPrice() const;
        int GetQuantity() const;


    private:
        /* 
        * private data members(variables) only available within Class
        */
        string itemName;
        int itemPrice;
        int itemQuantity;

};

#endif