//vector - aka array list (dynamic array) that does not require size declaration. As size grows or shrinks new array 
//          allocated in memory to increase/decrease size an memory location.
//          **GOOD PRACTICE* when iterating vector, use size() not const value to avoid over/under interating complete list

#include <iostream>
#include <vector>
using namespace std;

//function declaration used to pass input into vector function (bottom of page)
void getNumber(vector<int>&); //NEED TO PASS BY REFERENCE

int main() {

    // DEFINING VECTORS. datatype can vary and even include struct templates**
    
    //*without specifying size*
    vector<int> vector_one;
    
    //*specifying size* - creates vector that is 5 elements long
    vector<int> vector_two(5);
    
    //*specifying size and value* - creates vector that is 5 elements long initialized to given values. 
    //(if only one value specified, all elements equal to value)
    vector<int> vector_three(3, 1);
    //can initialize all values without size spec.
    vector<int> vector_four{ 1, 2, 3, 4, 5 };
    
    //*can declare vector with another vector* - effectively makes copy of old vector into new vector
    vector<int> vector_five(vector_one);

    //ADDING VALUES to vector use method psh_back() - adds values to end of vector
    vector_one.push_back(8);
    vector_one.push_back(4);
    vector_one.push_back(5);

    //REMOVING VALUES from vector
    //from back of vector, use pop_back()
    vector_one.pop_back();
    //remove all values from vector, use clear()
    // vector.clear();

    //checking is vector is empty, use empty()
    if(!vector_one.empty()) {
        cout << "Vector is NOT empty";
    }
    else{
        cout << "vector IS empty";
    }
    cout << endl;


    //size method  - returns how many elements in vector
    cout << "Number of elements: " << vector_one.size() << endl;

    //printing contents of vector using standard for loop
    cout << "Vector Elements: " << endl;
    for( int i=0; i < vector_one.size(); i++){
        cout << "Element #" << i+1 << " - " << vector_one[i] << endl; //can also use vector.at(i)
    }
    //can also used range based looping with vectors
    // cout << "Elements: ";
    // for(auto elem : vector) //to compile correctly need to use cpp 11 compiling extension, (g++ -std=c++11 vector.cpp -o vector)
    //     cout << elem << " ";
    // cout << endl;

    //to use input to fill vector, need to pass vector to function USING PASS BY REFERENCE (&) against vector NOT variable name
    vector<int> a;
    getNumber(a);
    for(auto num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
void getNumber(vector<int>& b){
    int in;
    cout << "Enter integers, type -99 to quit: \n";
    cin >> in;
    while(in != -99) { //while loop until sentinal value entered or prog. manually terminated
        b.push_back(in);
        cout << "Enter integers, type -99 to quit: \n";
        cin >> in;
    }
}