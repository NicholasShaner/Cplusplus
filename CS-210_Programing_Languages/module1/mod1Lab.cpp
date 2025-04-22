// main.cpp

/***************
CS-210 1-4 zyBooks Lab: Driving Costs
main.cpp

Nicholas Shaner
SNHU
CS-210-R4727 Programming Languages
Prof. Cory Thoma
March 10, 2024
***************/

#include <iostream>
#include <iomanip>               //For setprecision
using namespace std;

int main() {

	double milesPerGallon;  // declared double for miles/gallon
	double costFuelPerGallon;  //declared double for cost of fuel per gallon

	cin >> milesPerGallon;  //user input miles per gallon
	cin >> costFuelPerGallon;  //user input cost of fuel per gallon

	cout << fixed << setprecision(2) << (20 / milesPerGallon) * costFuelPerGallon << " ";  //output for 20 mile trip
	cout << fixed << setprecision(2) << (75 / milesPerGallon) * costFuelPerGallon << " ";  //output for 75 miles trip
	cout << fixed << setprecision(2) << (500 / milesPerGallon) * costFuelPerGallon << endl;  //output for 500 miles trip



	return 0;
}

