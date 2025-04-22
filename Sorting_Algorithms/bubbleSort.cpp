#include <iostream>
using namespace std;

//*********************************
//FUNCTIONS
//*********************************

//function to swap elements
void swapElements(int a[], int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

//bubble sort functions~~~~~~~~~~~~~~~~

//bubble starts from last element and works its way down to index 0
void bubble(int a[], int size) {
    int i = size-1;
    while (i>0) {
        if (a[i] < a[i-1]) {
            swapElements(a, i, i-1);
        }
        i--;
    }
}

//bubbleSort starts at first element and works its way up to last elemend
void bubbleSort(int a[], int size) {
    int i = 0;
    // while loop to start at first element, and calls each element to "bubble" function to determine correct location
    while(i<size-1) {
        bubble(a, size);
        i++;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//print function to display array, **better as a for loop?**
void displayArr(int a[], int size) {
    int i=0;
    cout << "Array: ";
    while (i < size) {
        cout << a[i] << " ";
        i++;
    }
    cout << endl;
    cout << endl;
}

//*********************************
//MAIN
//*********************************

int main() {

    int arr[] = {102, 12, 193, 1932, 192, 11, 293, 8, 123, 239};
    int size = sizeof(arr)/sizeof(arr[0]); //gains size of array by dividing total memory size of array by memory size of single element (could also use "int")

    displayArr(arr, size);
    bubbleSort(arr, size);
    displayArr(arr, size);

    return 0;
}