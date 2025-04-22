//============================================================================
// Name        : ABCUcourseCatelog.cpp
// Author      : Nicholas Shaner
// Version     : 1.0
// Last Updated: April 20, 2025
// Copyright   : Copyright © 2025,  portions Copyright © 2023 SNHU COCE
// Description : CS-300 Project Two
//============================================================================

#include <iostream>
#include <string>
#include <windows.h>    //For sleep function on Windows systems (dramatic effect)
// #include <unistd.h>    //For sleep function on Unix/Linux systems (dramatic effect)

#include "parseCSV.cpp"
#include "CourseConfig.h"
#include "BSTConfig.h"

using namespace std;


int main() {

    // Create a new Binary Search Tree to hold the course data
    BST *bst = new BST();
    // Create a new BSTParser object with the BST pointer
    csv::BSTParser *parser = new csv::BSTParser(bst);
    int choice = 0;
    string userCourseID;
    //Display the menu and get a menu selection from the user
    while (choice != 9) {
        cout << "\nWelcome to the course planner.\n" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl << endl;
        cout << "Please enter your choice from the menu above: ";
        cin >> choice;

    
        switch (choice) {
            case 1:
                cout << "\n..........Loading data.........." << endl;
                cout << "." << endl;
                //sleep(.8);    //system sleep function for Unix/Linux systems
                Sleep(800);    //system sleep function for Windows systems
                cout << ".." << endl;
                //sleep(.8);
                Sleep(800);
                cout << "..." << endl;
                //sleep(.8);
                Sleep(800);
                cout << "...." << endl;
                //sleep(.8);
                Sleep(800);
                // Parse the CSV file and load the data into the BST
                parser->ParseFile("compsciCatelog.csv");
                // cout << bst->root->course.getKey() << endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER
                break;
            case 2:
                cout << "\n..........Printing course list.........." << endl;
                cout << "\n\nHere is a sample course schedule..." << endl;
                cout << "----------------------------------------" << endl;
                // Print the course list from the BST
                bst->printCourses(bst->root);
                cout << "\n..........Print successful.........." << endl << endl;
                system("pause");
                break;
            case 3:
                cout << "\nEnter course ID to print: ";
                cin >> userCourseID;
                //Print course info from BST
                bst->BST::printCourse(bst->root, userCourseID);
                cout << "\n..........Print successful.........." << endl << endl;
                system("pause");
                break;
            case 9:
                cout << "\nThank you for using the course planner!" << endl << endl;
                cout << "..........Exiting program.........." << endl << endl;
                break;
            default:
                cout << "Invalid choice. Please choose from the menu options..." << endl;
                break;
        }
    }
    // Clean up memory
    delete parser;    //Delete parser object to prevent memory leaks
    delete bst;    //Delete BST object to prevent memory leaks
    cout << "..........Goodbye!.........." << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}