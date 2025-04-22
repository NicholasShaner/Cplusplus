//main.cpp

/***************
 *  CS-210 6-3 zyBooks Lab Activity
 *  main.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  April 14, 2024
 * 
 ***************/

#include <string>
#include <iostream>

using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
    
      // FIXME: The following line will throw an ios_base::failure.
      //        Insert a try/catch statement to catch the exception.
      //        Clear cin's failbit to put cin in a useable state.

    /*
    *Try/Catch loop requested by assignment.
    */
    try {
      cin >> age;  // get next input assignment int age 
      /*
      * if loop to validate input and throw exception if error occurs
      */
      if (!cin.fail()) {
        cout << inputName << " " << (age + 1) << endl;  // print statement if input validated
      }

      else {
        throw ios_base::failure(0);  // exception throw
      }
    }

    /*
    * catch statement to handle exception
    */
    catch(...) {
      cin.clear();  // clear the error
      cin.ignore(256, '\n');  // clear the cin buffer up to the newline character
      age = 0;  // set age to 0
      cout << inputName << " " << age << endl;  // new print statement with default 'error' value 0
    }
    
    cin >> inputName;  // get next user input string and continue while loop
  }
   
  return 0;
}