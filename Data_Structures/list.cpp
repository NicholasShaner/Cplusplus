/*list      -        similar to linked list, used to store items in non continuous memory locations
*                       - dynamic container so grows/shrinks as needed without needing to specify size allocation
*                       - implemented as doubly linked list where each element associated with pointer to next and previous element
*                       - COMMON USE OPERATORS:
*                           Adding Elements:
*                               push_back() - add to end of list
*                               push_front() - add to front of list
*                               insert() - add at specific position
*                           Removing Elements:
*                               pop_back() - remove last element
*                               pop_front() - remove first element
*                               erase() - remove element at spec. position or range
*                               remove() - remove all elements with spec. value
*                           Others:
*                               size() - returns number of elements in list
*                               empty() - checks if list is empty
*                               clear() - removes all elements from list
*                               front() - accesses first element
*                               back() - accesses last element
*           COMPILING: g++ fileName -o execFileName (EXCEPT WHEN INITIALIZING LIST DURING DECLARATION -> -std=c++11)
*/
#include <iostream>
#include <list>
using namespace std;


/*********************
 *  FUNCTION DECLARATION 
 *********************/

void display(const list<int>& list);
void orderedPlayerList(int employeeNum, list<int>& employeeList);


/**********************
 * MAIN
 **********************/

int main() {
    //declaring a list object
    list<int> myList;
    //ADDING ELEMENTS(see header)
    myList.push_back(5);
    myList.push_back(10);
    myList.push_back(15);
    myList.push_front(25);

    //printing list (function)
    // for(list<int>::iterator it = myList.begin(); it != myList.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    display(myList);

    cout << endl;

    //erase element
    myList.erase(myList.begin()); // erases element at front
    myList.erase(--myList.end()); // erases element at end (--myList decrements last element before end(null))

    display(myList);

    cout << endl;

    //implementing list like videogame lobby (ranked by experience (XP))
    list<int> allPlayers = {2, 9 ,3, 6, 7, 1, 4, 10, 8, 3, 2, 9};

    list<int> beginners; //players rated 1-5
    list<int> pros; //players rated 6-10

    //iterate lobby and separate players into appropriate game
    for(list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++)
    {
        int rating = *it; //temp variable to handle each iterative element (DEREFERENCED)
        
        //organizes elements into new UNORDERED lists according to rank
        /*
        if(rating>=1 && rating<=5) //if 1-5 add to beginners
        {
            beginners.push_back(rating);
        }
        else if(rating > 5 && rating <= 10) //else if 6-10 add to pros
        {
            pros.push_back(rating);
        } 
        */

        //organized elements into new ORDERED list according to rank 
        if(rating >= 1 && rating <= 5)
        {
            orderedPlayerList(rating, beginners);
        }
        else if(rating > 5 && rating <= 10)
            orderedPlayerList(rating, pros);
    }


    //display player ranking list
    cout << "Beginners: \n";
    display(beginners);
    cout << endl;
    cout << "Pros: \n";
    display(pros);
    cout << endl;
    


    return 0;
}

/**********************
 * FUNCTION INITIALIZATION
 **********************/

void display(const list<int>& myList)
{
    for(list<int>::const_iterator it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << endl;
    }
}

void orderedPlayerList(int employeeNum, list<int>& employeeList)
{
    for(list<int>::iterator it = employeeList.begin(); it != employeeList.end(); it++)
    {
        if(*it > employeeNum)
        {
            employeeList.insert(it, employeeNum);
            return;
        }
    }
    employeeList.push_back(employeeNum);
}