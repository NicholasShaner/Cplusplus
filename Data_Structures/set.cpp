//set     ->            ordered collection of unique elements
//                      data structure to tell if element exists or not (basically)
//                      element value IS its identifier so no two elements can be the same
//                      size and memory allocation self controlled
//                      elements associated by value(key) NOT position   
//      WHEN COMPILING: g++ -std=c++11 REQUIRED


#include <iostream>
#include <set>
using namespace std;

int main() {
    //declaration similar to other data sets
    set<char> set1;
    // adding elements to set
    set1.insert('N');
    set1.insert('I');
    set1.insert('C');
    set1.insert('K');

    //printing elements of set
    for(auto elem = set1.begin(); elem != set1.end(); elem++){
        cout << *elem << " ";
        /*
        REMEMBER!! set is ORDERED so order entered is not always order stored
        For set2, input was N, I, C, K but output was C, I, K, N 
        */
    }
    cout << endl;


    set<char> set2 = {'N', 'I', 'C', 'K'}; //set NOT can be initialized during declaration
    
    //printing elements of set
    for(auto elem = set2.begin(); elem != set2.end(); elem++){
        cout << *elem << " ";
        /*
        REMEMBER!! set is ORDERED so order entered is not always order stored
        For set2, input was N, I, C, K but output was C, I, K, N 
        */
    }
    cout << endl;

    /***************************
     * searching set elements
     ***************************/

    if(set1.find('K') == set2.end()) {
        cout << "Could NOT find K" << endl;
    } else {
        cout << "FOUND K!!" << endl;
    }

    /***************************
    * using set to parce through and inspect string
    ****************************/
    string test = "This is just a test"; //initialize a string object
    set<char> exists; //create set

    //loop through string object
    for(int i=0; i < test.length(); ++i)
    {
        char letter = test.at(i);
        exists.insert(test[i]);
    }
    
    //Printing elements of set
    for(auto elem = exists.begin(); elem != exists.end(); ++elem)
    {
        cout << *elem << " ";
    }
    cout << endl;
    
    //can also use for each loop with set
    for (const auto& elem : exists) {
        cout << elem << " ";
    }
    cout << endl;

    /*
    REMEMBER!! set elements are UNIQUE and ORDERED so order entered is not always order stored, 
    and set will only store ONE instance of each matching element. First element stored 
    ie. iterated through "This is only a test", stored and output "T a e h i j s t u"
    */

    /************************
     * finding if set of letters exist in another set
     ************************/

    //evaluating if all letters in the string "find" are present in the string "name"
    string name = "Nicholas Shaner"; //initialize string to be searched
    string find = "school"; //initialize string to search for letters
    set<char> finder; //instantiate set

    // loop to add letters from search string (find) to set
    for(int i = 0; i < find.length(); ++i)
    {
        char letter = find.at(i);
        finder.insert(letter);
    }

    //loop to iterate through string to be searched (name) and erase matching letters from search string (find)
    for(int i = 0; i < name.length(); ++i)
    {
        char letter = name.at(i);
        finder.erase(letter);
    }
    //if statement to eval if any letters left in set (finder) after search iterations completed
    if(finder.size() > 0) // if elements left in finder after iteration then all letters not found
    {
        cout << "All letters NOT present" << endl;
    } else { //else finder is empty meaning all letters of find present in searched string name
        cout << "ALL LETTERS PRESENT!" <<  endl;
    }


    return 0;
}