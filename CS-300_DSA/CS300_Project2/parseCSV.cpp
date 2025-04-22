//============================================================================
// Name        : parseCSV.cpp
// Author      : Nicholas Shaner
// Version     : 1.0
// Last Updated: April 20, 2025
// Copyright   : Copyright © 2025,  portions Copyright © 2023 SNHU COCE
// Description : CS-300 Project Two
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "CourseConfig.h"
#include "BSTConfig.h"

namespace csv
{
    class BSTParser
    {
        
    public:
        //Constructors
        BSTParser();
        BSTParser(BST* bst);
        ~BSTParser();
        void ParseFile(string fileName);
        vector<string> Split(string line);

    private:
        // Private variables to hold objects private data
        string line;
        vector<string> indices{};
        BST *bst;
        bool isLoaded;
    };
}

//*****************************************************************************
// Class function definitions

namespace csv
{
    //Default constructor to create new Binary Search Tree
    BSTParser::BSTParser()
    {
        this->bst = new BST();
        this->isLoaded = false;    //set to false until file is loaded
    }

    //Constructor with BST object passed as argument
    BSTParser::BSTParser(BST *bst)
    {
        this->bst = bst;
        this->isLoaded = false;
    }

    //Destructor to delete BST object
    BSTParser::~BSTParser()
    {
        delete this->bst->root;    //delete BST object
    }

    vector<string> BSTParser::Split(string line)
    {
        char delimiter = ',';    //Deliminiter for splitting line items
        vector<string> attributes{};
        string temp = "";    //Temporary string to hold each item

        for(int i = 0; i < line.length(); i++)
        {
            while(line[i] != delimiter && i < line.length())
            {
                temp += line[i];    //Add each character to temp string until delimiter is reached
                i++;    //Increment index to next character in line)
            }  
            attributes.push_back(temp);    //Add each attribute item to vector
            temp = "";    //Reset temp string for next line item 
        }

        return attributes;    //Return vector of attributes
    }


    //Method to parse a CSV file, receiving the file name/path as an argument
    void BSTParser::ParseFile(string fname)
    {
        ifstream file;    //Open file stream object
        string line = "";    //String to hold each line of the CSV file;
        vector<string> objectItems;    //Vector to hold each collection of line attributes
        
        //Object variables used to assign value to course object attributes when declaring new course objects
        string courseID;
        string courseName;
        vector<string> coursePrereqs;
        
        file.open(fname);    //Open CSV file passing file name or path as argument

        if(!file.is_open())    //Easy error checking to make sure file is actually open
        {
            cout << "Sorry, could not open the selected file. Please try again..." << endl;
            return;
        }

        //While loop to continually read file and parse each line until end of file
        while(!file.eof())
        {
            getline(file, line, '\n');
            //Split function call to change current string of all attributes into accessible vector
            objectItems = Split(line);
            
            // for(int i =0; i < objectItems.size(); i ++) {    //DEBUGGING COMMENT/REMOVE THIS LINE LATER
            //     cout << objectItems[i] << ' ' << endl;
            // }
            
            //Additional input verification to make sure the line is not empty, and has AT LEAST ID and Name before parsing it
            if(objectItems.size() > 1)    //Makes sure that new line has AT LEAST 2 items
            {
                //Assign constant values to course object attribute holders
                courseID = objectItems[0];    //Course ID is first item in line
                courseName = objectItems[1];    //Course name is second item in line
                if(objectItems.size() > 2)    //3+ items means there are prerequisites
                {
                    for(int i = 2; i < objectItems.size(); i++)
                    {
                        coursePrereqs.push_back(objectItems[i] + ' ');    //Adds each prerequisite to course prereqs vector
                    }
                }


                //Push parsed line attributes to new course object
                Course course(courseID, courseName, coursePrereqs);
                course.setKey(courseID);    //Sets additional key value for BST storage and searching

                // cout << "Course " << course.Course::Key << " added." << endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER

                //Add new course object to BST
                this->bst->addNode(bst->root, course);
                this->isLoaded = true;    //Set to true when file loaded successfully
                objectItems.clear();    //Clear object items vector for next line
                coursePrereqs.clear();    //Clear course prereqs vector for next line
            }

            else
            {
                continue;    //Continue to next line in file
            }
        }

        cout << "\n..........End of file reached, load complete.........." << endl;
        file.close();    //Closes file stream after complete
        return; 
    }
}