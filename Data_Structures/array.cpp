// array - simple linear list of unordered elements OF SAME DATATYPE. accessable by index starting at 0.

#include <iostream>
#include <array>
using namespace std;

int main() {

    cout << "Enter number of variable: ";
    int elements;
    cin >> elements;
    /*int arr[5];*/ // declares array of 5 elements
    //manually setting all elements
    /*
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    */

    //for loop to set elements
    int arr[elements];
    int temp = elements;
    for(int i = 0; i < elements; i++) {
        arr[i] = temp;
        temp--;
    }

    for(int i = 0; i < elements; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}