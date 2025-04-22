/*
* Pointer       -       container that stored memory location of data
*                       **REMEMBER! -> Pointer needs to be same datatype as variable/data being pointed to
*/

#include <iostream>

using namespace std;

int main()
{

    int n = 5;
    cout << "Value of variable n: " << n << endl;
    cout << "Memory location of variable n: " << &n << endl; // ampersand (&) = "address of" **displays memory address of variable

    int *ptr = &n; // asteric (*) = "location of" ptr equals "address of" n
    cout << "Memory location variable ptr is pointing to: " << ptr << endl; //displays same memory address from above
    cout << "Dereferenced value of pointer ptr: " << *ptr << endl; //asteric = dereferences and displays value of memory location

    *ptr = 10;
    cout << "Updated value of memory location ptr is pointing to: " << *ptr << endl;
    cout << "Updated value of n: " << n; //Displays updated value of n even though never explivitly reassigned variable n



    system("pause >0");
    return 0;
}