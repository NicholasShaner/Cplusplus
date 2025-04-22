#include <iostream>
using namespace std;

//***************************
//FUNCTIONS
//***************************
void insertInto(int a[], int size, int i) {
    int key = a[i];
    int j = i-1;
    while(j>=0 && a[j] > key) {
        a[j+1] = a[j];
        j = j-1;
    }
    a[j+1] = key;
}
void insertionSort(int a[], int size) {
    int i = 1;
    while(i < size) {
        insertInto(a, size, i);
        i++;
    }
}

//print function to display array, **better as a for loop?**
void displayArr(int a[], int size) {
    int i=0;
    cout << "Array: ";
    while(i < size) {
        cout << a[i] << " ";
        i++;
    }
    cout << endl;
}

//***************************
//MAIN
//***************************
int main() {

    int arr[] = {102, 12, 193, 1932, 192, 11, 293, 8, 123, 239};
    int size = sizeof(arr)/sizeof(arr[0]); //gains size of array by dividing total memory size of array by memory size of single element (could also use "int")

    displayArr(arr, size);
    insertionSort(arr, size);
    displayArr(arr, size);

    return 0;
}