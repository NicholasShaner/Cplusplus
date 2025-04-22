
//stack structure is a Last-In First-Out (LIFO) structure (like vertical stack of books), can add and remove from top of stack
// push() to add to top of stack
// pop() to remove from top of stack
// top() to inspect top element in stack as well as remove and assign top element to new variable (will remove when reassigned)
// empty() to see if stack is empty
// size() to return size of stack
// swap() to swap two stack OBJECTS of same data type (takes all elems of one stack and swaps them with another stack)
    //search online for workaround to swap top elements
// see below for "search" work-around

#include <iostream>
#include <stack>
using namespace std;

//empty() method to determine if stack is empty or not
void emptyStack(stack<string> myStack) {
    if(myStack.empty()) {
        cout << "STACK IS EMPTY";
    }
    else {
        cout << "STACK IS NOT EMPTY";
    }
}

// Function to print the elements of the stack
void printStack(stack<string> myStack) {
    while (!myStack.empty()) {
        cout << myStack.top() << endl;
        myStack.pop();
    }
}

int main() {

    //instantiate new stack object
    stack<string> myStack; //can use all datatypes (int, double, string, charr, bool, etc.)
    
    //push() method to add elements of designated type to top of stack (first element added is at bottom of stack, aka last in list)
    myStack.push("MineCraft");
    myStack.push("Skyrim");
    myStack.push("Call of Duty");
    myStack.push("Lego: Marvels");
    
    //pop() method removed the top element of stack
    // myStack.pop();

    //top() removes top item from stack (just like pop()) to assign to new variable
    // string favoriteGame = myStack.top();
    // cout << "Favorite Game: \n";

    //top() used to view top element of stack, will NOT remove from stack if NOT reassigned
    // cout << myStack.top() << "\n";

    //size() used to return size of stack
    // cout << myStack.size() << "\n";





    printStack(myStack);
    emptyStack(myStack);
    
    return 0;
}
//***********************
//SEARCH
//***********************
//search feature not technically in std::stack operations, to search for item, 
//need to transfer elements to temp stack and evaluate then transfer back to original stack on closure

// bool searchInStack(stack<int> searchStack, int target) {
//     stack<int> tempStack;
//     bool found = false;

//     while (!searchStack.empty()) {
//         if (searchStack.top() == target) {
//             found = true;
//             break;
//         }
//         tempStack.push(searchStack.top());
//         searchStack.pop();
//     }
//     while (!tempStack.empty()) {
//         searchStack.push(tempStack.top());
//         tempStack.pop();
//     }
//     return found;
// }

// int main() {    
//     stack<int> intStack;

//     intStack.push(10);
//     intStack.push(20);
//     intStack.push(30);
//     intStack.push(40);

//     int searchElement = 30;
//     if (searchInStack(intStack, searchElement)) {
//         cout << searchElement << " found in the stack." << endl;
//     } else {
//         cout << searchElement << " not found in the stack." << endl;
//     }

//     return 0;
// }
//*********************