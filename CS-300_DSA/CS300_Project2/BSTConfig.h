//============================================================================
// Name        : BSTConfig.h
// Author      : Nicholas Shaner
// Version     : 1.0
// Last Updated: April 20, 2025
// Copyright   : Copyright © 2025,  portions Copyright © 2023 SNHU COCE
// Description : CS-300 Project Two
//============================================================================
#pragma once 

#ifndef _BSTConfig_H_
#define _BSTConfig_H_

#include <string>
#include <vector>
#include <iostream>

#include "CourseConfig.h"

using namespace std;


//*****************************************************************************
//Node structure for BST

struct Node
{
    //member variable
    Course course;
    Node* left;
    Node* right;

    //constructors to create Node objects
    Node()
    {
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(Course course) : Node()
    {
        this->course = course;
    }

    //destructor to delete Node objects
    virtual ~Node()
    {
        delete left;
        Node* left = nullptr;
        delete right;
        Node* right = nullptr;
    }
};


//*****************************************************************************
//BST class declarations

class BST
{
    public:
        Node* root = nullptr;    //default node pointer fpr root of BST

        //Constructors
        BST();    //default constructor
        BST(Node* root);    //default constructor with root node passed
        ~BST();    //Destructor

        //Public Methods
        void addNode(Node* node, Course course);    //Add a new node to BST
        void printCourses(Node* node);    //Prints list of all courses in BST
        void printCourseInfo(Node* node);    //internal print statement for list display
        void printCourse(Node* node, string courseID);    //Prints course information for user desired course ID
    private:
        //Private Method
        BST *bst;
};


//*****************************************************************************
//BST class initialization and constructors

//Default constructor
BST::BST()
{
    this->root = nullptr;
}

//Default constructor with root node passed
BST::BST(Node* node)
{
    this->root = node;
}

//Destructor
BST::~BST()
{
    delete root;
    root = nullptr;
    cout << "BST removed..." << endl;
}

//*****************************************************************************
//Public Methods

//Add new node to BST
void BST::addNode(Node* node, Course course)
{
    //BST empty, new node is set to root
    Node* newNode = new Node(course);

    if(BST::root == nullptr)
    {
        root = newNode;    //Sets new Node to root node of BST

        // cout << "New node added as BST root..." <<endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER
        
        return;
    }

    //If BST not empty, traverse tree to find appropraite location for new Node
    if(node == nullptr)
    {
        node = newNode;
        
        // cout << "New node added to BST..." << endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER
        
        delete newNode;    //Delete new node to prevent memory leaks once added to BST
    }
    else
    {
        //New node is less than current node, recursively call addNode on left side
        if(node->course.Course::getKey() > newNode->course.Course::getKey())
        {
            if(node->left == nullptr)
            {
                node->left = newNode;

                // cout << "New node added to left side of BST..." << endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER
            }

            else
            {
                addNode(node->left, course);    //recurisive call
            }
        }

        //New node is greater than current node, recursively call addNode on right side
        else if(node->course.Course::getKey() < newNode->course.Course::getKey())
        {
            if(node->right == nullptr)
            {
                node->right = newNode;

                // cout << "New node added to right side of BST..." << endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER
            }

            else
            {
                addNode(node->right, course);    ////recursive call
            }
        }

        //New node is equal to a current node in BST, duplicate is not added to BST
        else
        {
            cout << "Course ID already in program, new node not added to BST..." << endl;
        }
    }
}


void BST::printCourseInfo(Node* node) 
{
    cout <<endl;
    cout << "Course Key: " << node->course.Course::getKey() << endl;
    cout << "Course ID: " << node->course.courseID << endl;
    cout << "Course Name: " << node->course.Course::courseName << endl;
    cout << "Course Prerequisites: ";
    //Check if there are any prerequisites for the course and print them
    if(node->course.coursePrereqs.size() > 0)
    {
        for(int i = 0; i < node->course.Course::coursePrereqs.size(); i++)
        {
            cout << node->course.Course::coursePrereqs[i];
        }
        cout << endl;
    }
}


//Print list of all courses in BST
void BST::printCourses(Node* node)
{
    //base case for empty tree
    if(BST::root == nullptr)
    {
        cout << "BST is empty..." << endl;
        return;
    }

    if(node != nullptr)
    {
        BST::printCourses(node->left);    //recursive call to left side of tree)

        //Traverse tree in order to print all courses in BST
        BST::printCourseInfo(node);    //recursive call to left side of tree

        BST::printCourses(node->right);    //recursive call to the right side of tree
        
    }
    
}


//Print course information for user desired course ID
void BST::printCourse(Node* temp, string courseID)
{
    string searchKey = Course::convertCourseIDToKey(courseID);    //Convert course ID to get key value for searching
    
    // cout << searchKey << endl;    //DEBUGGING COMMENT/REMOVE THIS LINE LATER

    //base base for empty tree
    if(BST::root == nullptr)
    {
        cout << "BST is empty..." << endl;
        return;
    }

    if(temp != nullptr)
    {
        //Recursive function to find and print course information
        if(searchKey == temp->course.Course::getKey())
        {
            BST::printCourseInfo(temp);   //Course class function to display course info to user
        }
        else if (searchKey < temp->course.Course::getKey())
        {
            BST::printCourse(temp->left, courseID);
        }

        else
        {
            BST::printCourse(temp->right, courseID);
        }
    }
    else
    {
        cout << "\n..........Course ID not found in BST.........." << endl;
        return;
    }
    cout << endl;
}

#endif // _BSTConfig_H_