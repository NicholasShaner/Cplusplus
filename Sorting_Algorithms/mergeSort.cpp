#include <iostream>
using namespace std;

//***************************
//FUNCTIONS
//***************************

void combineArrs(int a[], int start, int mid, int end) {
    int* buffer = new int [end+1]; //creates buffer (temp copy) for merged array
    int k = start;

    while(k <= end) {
        buffer[k] = a[k];
        k++;
    }

    int i = start;
    int j = mid + 1;
    k = start;

    while(i <= mid && j <= end) {
        if(buffer[i] <= buffer[j]) {
            a[k] = buffer[i];
            i++;
        }
        else {
            a[k] = buffer[j];
            j++;
        }
        k++;
    }
    while(i <= mid) {
        a[k] = buffer[i];
        i++;
        k++;
    }
    while(j <= end) {
        a[k] = buffer[j];
        j++;
        k++;
    }
    delete[] buffer;
}

//auxiliary/helper function
void mergeSort(int a[], int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    combineArrs(a, start, mid, end);
}

//wrapper function, calls auxiliary function
void mergeSort(int a[], int size) {
    mergeSort(a, 0, size-1);
}

//print function to display array
void displayArr(int a[], int size) {
    cout << "Array: ";
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//***************************
//MAIN
//***************************
int main () {

    int arr[] = {102, 12, 193, 1932, 192, 11, 293, 8, 123, 239};
    int size = sizeof(arr)/sizeof(arr[0]);

    displayArr(arr, size);
    mergeSort(arr, size);
    displayArr(arr, size);

    return 0;
}