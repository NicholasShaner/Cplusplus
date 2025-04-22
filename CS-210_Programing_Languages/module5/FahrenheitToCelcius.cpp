//FahrenheitToCelcius.cpp
/***************
 *  CS-210 3-3 Project One
 *  FahrenheitToCelcius.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  April 7, 2024
 * 
 ***************/

#include <iostream>  
#include <fstream>  // required definition for reading/writing to file
#include <string>  // required definition for receiving strings
using namespace std;

int main() {
    /*
    * declared variables
    */
    ifstream inFS;  // input stream object created
    ofstream outFS;  // output stream object created
    string sampleCity;  // variable to receive city read from file
    int sampleTemp;  // variable to receive temperature read from file
    double FahrToCelc;  // variable assigned when processing fahrenheit temperature from file to new celsius temperature

    /*
    * input file FahrenheitTemperature.txt opened to read input data from
    */
    inFS.open("FahrenheitTemperature.txt");
    // validate that file is opened properly
    if (!inFS.is_open()) {
        cout << "Could not open file FahrenheitTemperature.txt";
        return 1;
    }
    
    /*
    * output file CelsiusTemperature.txt opened to write new calculated celsius values to 
    */
    outFS.open("CelsiusTemperature.txt");
    // validate that file is opened properly
    if (!outFS.is_open()) {
        cout << "Could not open file CelsiusTemperature.txt";
        return 1;
    }

    
    /*
    * while loop to prossess input file
    */
    while (!inFS.fail()) {  // while there isn't a problem extracting data from the file
        inFS >> sampleCity;  // input file stream to get the next string city name
        
        inFS >> sampleTemp;  // input file stream to get the next integer temperature value

        /*
        * if statement to handle if there is an error while reading temperature values
        */
        if (inFS.fail()) {
            cout << "There was no sample Temperature reported for " << sampleCity << endl;
        }
        // if no error occures Fahrenheit to Celsius calculation is performed then output to new file
        else {
            FahrToCelc = ((sampleTemp - 32) * (5 / 9.0));  // temperature calculation, divide by 9.0 to verify double output
            
            /*
            * output stream to print city name and new celsius values to file
            */
            outFS << sampleCity << " " << FahrToCelc << endl;
        }

        inFS.ignore();  // ignores newline character prior to receiving next string city name
    }
        inFS >> sampleCity;  // input string repeat to receive next string city name

    /*
    * close inFS file statements to close input file FahrenheitTemperature.txt
    * and outFS output file CelsiusTemperature.txt
    */
    inFS.close();
    outFS.close();

    return 0;
}