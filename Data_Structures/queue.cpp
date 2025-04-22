
//queue = First-In First-Out (FIFO) structure. Like a line of people, "first come, first served".
//      useful for collection prior to processing linear data structure
// push() to add to top of stack
// pop() to remove from top of stack
// top() to inspect top element in stack as well as remove and assign top element to new variable (will remove when reassigned)
// empty() to see if stack is empty
// size() to return size of stack

#include <iostream>
#include <queue>
using namespace std;

//********************
//FUNCTIONS
//********************

//function to verify if queue is empty or not
void isEmpty(queue<string> queue) {
    if(!queue.empty()) {
        cout << "Queue is NOT empty.";
    }
    else {
        cout << "Sorry, Queue IS empty.";
    }
    cout << endl;
}

//print function
void printQueue(queue<string> queue) {
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
}

//********************
//MAIN
//********************
int main() {

    //instantiate a new queue
    queue<string> myQueue;
    
    //push() to add elements to back of queue
    myQueue.push("Karen");
    myQueue.push("Tom");
    myQueue.push("Tyler");
    myQueue.push("Paul");

    //pop() to remove element from front of queue
    // myQueue.pop();

    //size() to return size of structure (number of elements)
    // cout << myQueue.size() << endl;

//FUNCTION CALLS
    //check is Queue is Empty
    isEmpty(myQueue);

    //Print Queue
    printQueue(myQueue);
    //print first element of queue
    cout << myQueue.front() << endl;
    //print last element in queue
    cout << myQueue.back() << endl;

    

    return 0;
}