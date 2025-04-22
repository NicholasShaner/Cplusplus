#include <iostream>
using namespace std;



//***********************************************
//FUNCTIONS
//***********************************************

//function to swap two elements in an array
void swap( int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

//function to find the location of the smallest element in an array
int locOfSmallest(int a[], int start, int end) {
    int i = start;
    int j = i;
    while(i<=end) {
        if(a[i] < a[j]){
            j = i;
        }
        i++;
    }
    return j;
}

//function to sort an array using selection sort
void selectionSort(int a[], int n) {
    int i = 0;
    while(i<n-1) {
        int j = locOfSmallest(a, i, n-1);
        swap(a, i, j);
        i++;
    }
}

//print function to display array, **better as a for loop?**
void displayArr(int a[], int n) {
    int i = 0;
    cout << "Array: \n";
    while(i<n) {
        cout << a[i] << " ";
        i++;
    }
    cout << endl;
}

//***********************************************
//MAIN
//***********************************************

int main() {

    int arr[] = {102, 12, 193, 1932, 192, 11, 293, 8, 123, 239};
    int size = sizeof(arr)/sizeof(arr[0]); //calculates size of array by dividing allocated memory size of array by standard memory size of array element

    displayArr(arr, size);
    selectionSort(arr, size);
    displayArr(arr, size);


    return 0;
}