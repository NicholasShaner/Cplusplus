//main.cpp

/***************
 *  CS-210 3-2 zyBooks Lab Activities
 *  main.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  March 24, 2024
 * 
 ***************/

#include <iostream>
#include <vector>
using namespace std;

/*
* SortVector function declared
*/
void SortVector(vector<int>& myVec);

int totalNumInputs;  // declared integer variable for total number of intigers being entered


int main() {
   /* Type your code here */
    cin >> totalNumInputs;  // receive total numbers of intigers being requested
    vector<int> myVec(totalNumInputs);  // initialize vector with parameter of total number of elements being entered

    /*
    * for loop to populate vector
    */
    for (int i = 0; i < totalNumInputs; i++) {
    cin >> myVec.at(i);
    }

    SortVector(myVec);  // function call to SortVector function with previously created vector as parameter

    /*
    * print statement for after sorted vector is returned to print vector in decending order
    */
    for (int j = 0; j < totalNumInputs; j++) {
        cout << myVec.at(j) << ",";
    }
    cout << endl;

    return 0;
}

/*
* SortVector function definition
*/
void SortVector(vector<int>& myVec) {
    int temp;  // local temporary integer variable declared to be used during sorting
    /*
    * nested for loops to iterate through the vector. loop iterates each index value though the entire list
    * prior to iterating to next index value and starting process all over
    */
    for (unsigned int i = 0; i < myVec.size(); i++) {
        for (unsigned int j = i + 1; j < myVec.size(); j++) {
            if (myVec.at(i) < myVec.at(j)) {  // if statement to determined if first integer is smaller than succeeding integer value
                temp = myVec.at(i);  // temp hold variable to assign preceding smaller index value
                myVec.at(i) = myVec.at(j);  // swapping larger integer to preceeding index
                myVec.at(j) = temp;  // reassigns smaller temp value to succeeding index 
            }
        }
    }
}