// chadaTechHeader.h

/***************
 *  CS-210 3-3 Project One
 *  chadaTech.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  March 24, 2024
 * 
 ***************/


#include <iostream>
#include <iomanip>

using namespace std;

/*
* Global variable declarations for 
* use in associated functions and methods.
*/
bool appRunning = true;
int twelveHour = 0;
int Minutes = 0;
int twentyFourHour = 0;
int seconds = 0;
string AmPm;

/*
*  program function declarations. placed within
* header file for clarity and readability
*/
int addHour();
int addMinute();
int addSecond();
void setTime();
void dispMenu();
void dispClocks();
void menuChoice();
string correctAmPm();