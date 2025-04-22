//============================================================================
// Name        : LinkedList.cpp
// Author      : Nicholas Shaner
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 3-2 Lists and Searching
//============================================================================

#include <algorithm>
#include <iostream>
#include <string> // atoi
#include <climits>
#include <time.h>
#include <list>



#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;

    //default constructor
    Bid() : bidId(""), title(""), fund(""), amount(0.0) {}
    // Parameterized constructor
    Bid(string id, string t, string f, double a) : bidId(id), title(t), fund(f), amount(a) {}

    // Copy constructor
    Bid(const Bid& other) {
        bidId = other.bidId;
        title = other.title;
        fund = other.fund;
        amount = other.amount;
    }

    // Copy assignment operator
    Bid& operator=(const Bid& other) {
        if (this == &other) return *this; // Handle self-assignment
        bidId = other.bidId;
        title = other.title;
        fund = other.fund;
        amount = other.amount;
        return *this;
    }
};

struct Node {
    Bid bid;
    Node* next;

    Node(Bid aBid) : bid(aBid), next(nullptr) {}
};

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList {

public:
    //Internal structure for list entries, housekeeping variables
    struct Node {
        Bid bid;
        Node* next;  

        // default constructor
        Node() : next(nullptr) {}

        // initialize with a bid
        Node(Bid aBid) {
            bid = aBid;
            Node* next = nullptr;
        }
    };


    Node* head = nullptr;
    Node* tail = nullptr;
    int size;


    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void PrintList();
    void removeBid(string bidId);
    Bid Search(string bidId);
    void displayBid(Node*);
    int Size();
};

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    // FIXME (1): Initialize housekeeping variables
    //set head and tail equal to nullptr
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * Destructor
 */
LinkedList::~LinkedList() {
    // start at the head
    Node* current = head;
    Node* temp;

    // loop over each node, detach from list then delete
    while (current != nullptr) {
        temp = current; // hang on to current node
        current = current->next; // make current the next node
        delete temp; // delete the orphan node
    }
}

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
    //Create new node
    Node* newNode = new Node(bid);
    //if there is nothing at the head...
    if (head == nullptr) 
    {
            // new node becomes the head and the tail
        head = newNode;
        tail = newNode;
    } 
            //else 
    else
    {
        // make current tail node point to the new node
        tail->next = newNode;
        // and tail becomes the new node
        tail = newNode;
    //increase size count
    size = size + 1;
    }
}

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {
    // start at the head
    Node* current = head;
    // while loop over each node looking for a match
    while(current!=nullptr)
    {
        //output current bidID, title, amount and fund
        LinkedList::displayBid(current);
        //set current equal to next
        current = current-> next;
    }
}
/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::removeBid(string bidId) {
    // FIXME (5): Implement remove logic
    // special case if matching node is the head
    Node* current = head;
    if(current-> bid.bidId == bidId)
    {
        // make head point to the next node in the list
        head = head->next;
        //decrease size count
        size = size - 1;

        cout << "head item matched and removed\n";

        //return
        return;
    }

    // while loop over each node looking for a match
    while(current != nullptr) //
    {
        // if the next node bidID is equal to the current bidID
        if(current->next-> bid.bidId == bidId)
        {
        	// hold onto the next node temporarily
            Node* temp = current-> next;
         // make current node point beyond the next node
            current-> next = temp-> next; //temp previously set as current->next
         // now free up memory held by temp
            temp = nullptr;

            cout << "CONFIRMED " << bidId << " removed successfully.\n";

         // decrease size count
            --size;
            return;
        }
    // current node is equal to next node
        current = current-> next;
    }
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId) {
    // special case if matching bid is the head
    if(LinkedList::head-> bid.bidId == bidId) //prior to spending the time and memory to initiate the search loop, if bidId of the head element is the same as the search key
    {
        return head-> bid; //return the head element
    }
    // start at the head of the list
    Node* current = head; //initialize a new Node to iterate through list

    // keep searching until end reached with while loop (current != nullptr)
    while(current != nullptr)
    {
        // if the current node matches, return current bid
        if(current-> bid.bidId == bidId)
        {
            return current-> bid;
        }
        // else current node is equal to next node

        current = current-> next;

    }
    //(the next two statements will only execute if search item is not found)
        //create new empty bid
    Bid bid = Bid();
        //return empty bid 
    return bid;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
    return size;
}

void LinkedList::displayBid(Node* current) {
    cout << current-> bid.bidId << ": " << current-> bid.title << " | " << current-> bid.amount
         << " | " << current-> bid.fund << endl;
    return;
}