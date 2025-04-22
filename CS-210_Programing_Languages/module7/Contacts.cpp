//Contacts.cpp

/***************
 *  CS-210 7-2 zyBooks Lab Activity
 *  COntacts.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  April 21, 2024
 * 
 ***************/

#include <iostream>  // I/O stream file required for input/output
#include <istream>  // istream file required for getline
#include <string>  // string file required for string type handling
using namespace std;

// Linked List class for creating, assigning, and accessing List nodes
class ContactNode {
    public:
    
    //  Class contructor with name and phoneNumber parameters. Sets contact information to private variables
        ContactNode(string name, string phoneNumber);

        //  declaration and definitions of Class accessor functions
        string GetName() const {  // retrieves class contact name
            return contactName;
        }

        string GetPhoneNumber() const {  // retrieves class contact phone number
            return contactPhoneNumber;
        }

        ContactNode* GetNext() {  // gets the next pointer assigned as linked list is filled
            return nextNodePtr;
        }

        void InsertAfter(ContactNode* nodePtr) {  // allows for setting next node in linked list in respect to designated current pointer location
            ContactNode* tempPtr = nullptr;
            tempPtr = this->nextNodePtr;
            this->nextNodePtr = nodePtr;
            nodePtr->nextNodePtr = tempPtr;
        }

        void PrintContactNode() {  // print statement to output desired formatting
            cout << "Name: " << contactName << endl;
            cout << "Phone number: " << contactPhoneNumber << endl;
        }

    
    private:
        // private data members, accessable to only the class member
        string contactName;
        string contactPhoneNumber;
        ContactNode* nextNodePtr;
   
};

// member function definition
ContactNode::ContactNode(string name, string phoneNumber) {
    contactName = name;  // sets user input name to contactName string
    contactPhoneNumber = phoneNumber;  // sets user input phone number to contactPhoneNumber string
    nextNodePtr = nullptr;  // sets default next node pointer to nullptr
}

int main() {

    // local variable declaration
    string name;
    string phoneNumber;

    /*
    * Get user input for contact information for name and phone number.
    * declare person 1 with user input values and set new node into Linked List ContactNode
    */
    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode* person1 = new ContactNode(name, phoneNumber);

    /*
    * Get user input for contact information for name and phone number.
    * declare person 2 with user input values and set new node into Linked List ContactNode
    */
    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode* person2 = new ContactNode(name, phoneNumber);
    person1->InsertAfter(person2);

    /*
    * Get user input for contact information for name and phone number.
    * declare person 3 with user input values and set new node into Linked List ContactNode
    */
    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode* person3 = new ContactNode(name, phoneNumber);
    person2->InsertAfter(person3);

    // print statements to output each contact individually
    cout << "Person 1: " << person1->GetName() << ", " << person1->GetPhoneNumber() << endl;
    cout << "Person 2: " << person2->GetName() << ", " << person2->GetPhoneNumber() << endl;
    cout << "Person 3: " << person3->GetName() << ", " << person3->GetPhoneNumber() << endl;
    cout << endl;

    // while loop to output contacts as a Contact List
    cout << "CONTACT LIST" << endl;
    ContactNode* currentNode = person1;  // sets current node to person1
    while (currentNode != nullptr) {  // loop iterates until nothing left
        currentNode->PrintContactNode();  // calls print function on current Liked List class node
        cout << endl;
        delete currentNode;  // deletes currentNode from memory
        currentNode = currentNode->GetNext();  // resets currentnode to next node in List
        
    }
   
   return 0;
}
