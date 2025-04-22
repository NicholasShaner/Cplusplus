//linked list - a series of connected nodes, each of which is a data structure 
//  (not really a structure on its own but a list of individual structures with reference pointers pointing to next structure)
//              Grows and shrinks during runtime as needed (NOT fixed size)
//              Nodes are dynamically allocated (add nodes as needed, removed unneeded nodes)
//              Nodes contain one or more members containing data
//              Contain a pointer containing the address of the next node in the list
// *faster than vectors when inserting/deleting nodes*
// Fundamental operations: 
//  - appending node, traversing list, inserting a node at specific location, deleting nodes, linear search, destroying thet list
/*Standard declaration in C++:
    struct Node {
        int value;
        Node* next;
    };
*/

#include <iostream>
using namespace std;

//STRUCT Node framework
struct Node {
    int value;
    Node *next;
};

//FUNCTION DECLARATIONS
bool isEmpty(Node *head);
char menu();
void insertAsFirstElement(Node *&head, Node *&last, int value);
void insert(Node *&head, Node *&last, int value);
void remove(Node *&head, Node *&last);
void showList(Node *current);

//***********************
//MAIN
//***********************

int main() {

/*APPEND NODE - add new node to end of list (creates unordered list)
    -create a node
    -store data in the node
        -check if list empty, if so new node is designated as first node in list. if not empty, need traverse list to find last node
    -append the node to end of list
*/
    Node *head = nullptr;
    Node *last = nullptr;
    char choice;
    int value;

    do{
        choice = menu();
        switch(choice)
        {
            case '1':   cout << "Please Enter A Value: ";
                        cin >> value;
                        insert(head, last, value);
                        break;
            case '2':   remove(head, last);
                        break;
            case '3':   showList(head);
                        break;
            case '4':   cout << "System Exit Confirmed...\n";
                        exit(0);
            default:    cout << "Please Enter A Valid Selection ('4' To Exit Program)\n";
        }
    }while(choice != 4);

    return 0;
}

//***********************
//FUNCTIONS
//***********************

bool isEmpty(Node *head){
    if(head == nullptr){
        return true;
    }
    else {
        return false;
    }
}

char menu(){
    char choice;
    cout << "MENU:\n";
    cout << "1. Add Node\n";
    cout << "2. Remove Node\n";
    cout << "3. Show Node List\n";
    cout << "4. Exit\n";

    cin >> choice;
    return choice;

}

void insertAsFirstElement(Node *&head, Node *&last, int value){
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;
    head = temp;
    last = temp;
}

void insert(Node *&head, Node *&last, int value){
    if(isEmpty(head)){
        insertAsFirstElement(head, last, value);
    }
    else {
        Node *temp = new Node;
        temp->value = value;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

void remove(Node *&head, Node *&last){
    if(isEmpty(head)){
        cout << "The Linked List is already empty\n";
    }
    else if(head == last){
        delete head;
        head = nullptr;
        last = nullptr;
    }
    else{
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void showList(Node *current){
    if(isEmpty(current)){
        cout << "The Linked List is empty\n";
    }
    else{
        cout << "The list contains: \n";
        while(current != nullptr){
            cout << current->value << endl;
            current = current->next;
        }
    }
}