//second example of linkedList via CodeBeauty
/*
Head Element                                    Tail Element
value|nextptr-> value|nextptr-> value|nextptr-> value|nextptr-> nullptr
*/
#include <iostream>
using namespace std;

//CLASS INSTANTIATION
class Node
{
public: //public access modifyer allows access to elements outside of class
    int value;
    Node* next;
};

//FUNCTION DECLARATION
void printList(Node* n);
void insertFront(Node** head, int newVal);
void insertEnd(Node** head, int newVal);
void insertAfter(Node* prevNode, int newVal);
/*
        MAIN 
*/
int main() 
{
    // Create new Nodes (elements)
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initialize Node attributes
    head->value = 1; // '->' used to access class elements when using pointers
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = nullptr;

    // print linkedList function call
    // printList(head);

    /* 
    INSERTING NEW NODES
    */
   // Beginning
    insertFront(&head, -1); //added first to front of list
    insertFront(&head, -2); //added second to new front

    // End
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    //after select node
    insertAfter(second, 0);

    printList(head);
    
    return 0;
}

// FUNCTIONS

// PRINT linkedList
void printList(Node* n)
{
    while(n != nullptr)
    {
        cout << n->value << endl;
        n = n->next;
    }
}

void insertFront(Node** head, int newVal)
{
    //1. Declare and prepare new Node
    Node * newNode = new Node();
    newNode->value = newVal;
    //2. Position new Node in FRONT of current head
    newNode->next = *head; //new node pointing to current head node
    //3. Move head of list to point at newNode
    *head = newNode;
}

void insertEnd(Node** head, int newVal)
{
    // 1. prepare a newNode as tail node
    Node * newNode = new Node();
    newNode->value = newVal;
    newNode->next = nullptr;
    // 2. if linkedList empty, newNode will be head
    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }
    // 3. Else, find last node and store location of last node in "temp" node 'last'
    Node* last = *head;
    while(last->next != nullptr)
    {
        last = last->next;
    }
    // 4. Insert newNode after last node (at end of linkedList)
    last->next = newNode;
}

void insertAfter(Node* prevNode, int newVal)
{
    // 1. Check is prevNode is null
    if(prevNode == nullptr)
    {
        cout << "Previous Node can not be null\n";
        return;
    }
    // 2. Prepare new node
    Node* newNode = new Node();
    newNode->value = newVal;
    // 3. insert newNode after prevNode
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}