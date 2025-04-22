//============================================================================
// Name        : CourseConfig.h
// Author      : Nicholas Shaner
// Version     : 1.0
// Last Updated: April 20, 2025
// Copyright   : Copyright © 2025,  portions Copyright © 2023 SNHU COCE
// Description : CS-300 Project Two
//============================================================================
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;



class Course
{
    public:
        //member variables
        string Key; //used to store refactored course ID for searching in BST
        string courseID;
        string courseName;
        vector<string> coursePrereqs{};
        
        //constructors, used to create course objects
        Course()
        {
            this->Key = "";
            this->courseID = "";
            this->courseName = "";
            this->coursePrereqs = vector<string>{};
            return;
        }

        Course(string courseID, string courseName, vector<string> coursePrereqs) : Course()
        {
            this->Key = Course::convertCourseIDToKey(courseID);
            this->courseID = courseID;
            this->courseName = courseName;
            this->coursePrereqs = coursePrereqs;
            return;
        };

        //member getters and setters
        string getKey() const
        {
            return Key;
        }
        string getCourseID() const
        {
            return courseID;
        }
        string getCourseName() const
        {
            return courseName;
        }
        vector<string> getCoursePrereqs() const
        {
            return coursePrereqs;
        }

        void setKey(string courseID)
        {
            this->Key = convertCourseIDToKey(courseID);
        }
        void setCourseID(string courseID)
        {
            this->courseID = courseID;
        }
        void setCourseName(string courseName)
        {
            this->courseName = courseName;
        }
        void setCoursePrereqs(vector<string> coursePrereqs)
        {
            this->coursePrereqs = coursePrereqs;
        }

        //public class methods
        static string convertCourseIDToKey(string courseID);
};


//============================================================================


// Class fuctions

string Course::convertCourseIDToKey(string courseID)
{
    string tempKey = "";
    for(int i = 4; i <courseID.length(); i++)
    {
        tempKey += courseID[i];
    }
    return tempKey;
}




