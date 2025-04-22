// Calculator.cpp

/***************
 *  CS-210 2-3 Assignment: What's bugging you?
 *  Calculator.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  March 17, 2024
 * 
 ***************/

#include <iostream>

using namespace std;

int main() {  // changed main() function return type to int

    /* 
    * removed char array as was not used anywhere in program
    * separated and corrected puntuation on integer variable declarations
    * changed integer variable names for readability
    */
	double userNum1;  
    double userNum2;
	char userOperator;  // claraified variable name (maybe too picky)
	char answer = 'y';  // corrected case of 'y' and punctions for char data type ('' not "")
	// newline whitespace for readability
    while (answer == 'y') {  // correct proper spacing around '==' and moved curly brace for readability
        // newline whitespace for readability
        /*
        * separated print statement for requested user input for readability and function
        * separated user input statement for functionality
        */
		cout << "Enter first integer: " << endl;
		cin >> userNum1;
        cout << "Enter operator ( +, -, *, / ): " << endl;
        cin >> userOperator;
        cout << "Enter second integer: " << endl;
        cin >> userNum2;
        cout << endl;  // newline whitespace for better format and readability
        /*
        * newline spacing for readability
        * added missing curly braces for all statement bodies and adjusted variable naming
        */
		if (userOperator == '+') {  // adjusted quotation for char data type
			cout << userNum1 << " + " << userNum2 << " = " << userNum1 + userNum2 << endl;  // corrected orientation of "<<"
        }
		if (userOperator == '-') {
			cout << userNum1 << " - " << userNum2 << " = " << userNum1 - userNum2 << endl; // corrected orientation of "<<"
        }
		if (userOperator == '*') {
			cout << userNum1 << " * " << userNum2 << " = " << userNum1 * userNum2 << endl;  // corrected operator in print statement to match statement argument
        }
		if (userOperator == '/') {
			cout << userNum1 << " / " << userNum2 << " = " << userNum1 / userNum2 << endl;  // corrected operator in print statement to match statement argument
        }

        cout << endl;  //newline spacing for better readability
		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
	}
// added return statement for testing and function to match adjusted "int main()" return data type"    
return 0;  
}

