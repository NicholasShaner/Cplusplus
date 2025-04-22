#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

int main() 
{
    int n;
    int arr[MAX];
    cout << "Enter a number N: (0-100)\n";
    cin >> n;

    //inputting values into the array
    for(int i = 0; i < n; i++) {
        arr[i] = (rand()%n);
    }

    //outputting unsorted array
    cout << "Unsorted Array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<endl;

    //sorting the array
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            //creates ascending order. for descending, swap '<' for '>' in the if statement
            if(arr[j] < arr[i]) { 
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //display sorted array
    cout << "Sorted Array: \n";
    for(int i = 0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}