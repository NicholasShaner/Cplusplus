//============================================================================
// Name        : VectorSorting.cpp
// Author      : Nicholas Shaner
// Version     : 1.0
// Copyright   : Copyright � 2025 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// forward declarations

double strToDouble(string str, char ch);

int partition(vector<Bid>& bids, int begin, int end); // partition function used to partition bids vector for sorting
void selectionSort(vector<Bid>& bids); // selection sort algorithm function to perform selection sort on vector
void quickSort(vector<Bid>& bids, int begin, int end); // quick sort algorithm function to perform quick sort on vector


//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information using console (std::in)
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) {
    cout << "**Loading CSV file " << csvPath << "**" << endl;

    // Define a vector data structure to hold a collection of bids.
    vector<Bid> bids;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bids.push_back(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

// FIXME (2a): Implement the quick sort logic over bid.title
/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */
int partition(vector<Bid>& bids, int begin, int end) {
    //set low and high equal to begin and end
    int low = begin; //instantiates integer low to equal first element index of vector
    int high = end; //instantiates integer high to equal last element index of vector
    
    // Calculate the middle element as middlePoint (int)
    int middlePoint = (begin + end)/2; // instantiates middlePoint integer variable by adding given first and last element indexes and dividing by two
    
    // Set Pivot as middlePoint element title to compare (string)  
    Bid pivot = bids.at(middlePoint); // sets element at index of calculated middlePoint to pivot element of Bid object for partition sorting
    
    // while not done 
    bool done = false; //boolean to control while loop iteration
    while(!done){ //while loop to sort elements
        
        // keep incrementing low index while bids[low].title < Pivot
        while(bids.at(low).title < pivot.title){
            ++low;
        }
        
        // keep decrementing high index while Pivot < bids[high].title
        while(pivot.title < bids.at(high).title){
            --high;
        }
        
        /* If there are zero or one elements remaining,
            all bids are partitioned. Return high */
        if(low >=high){
            return high;
            done = true;
        }
       
        // else swap the low and high bids (built in vector method)
            // move low and high closer ++low, --high
        else{
            swap(bids.at(low), bids.at(high)); //built in C++ vector method that swaps two elements
            ++low;
            --high;
        }
    }
    //return high
    return high;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */
void quickSort(vector<Bid>& bids, int begin, int end) {
    //set mid equal to 0
    int mid = 0;
    
    /* Base case: If there are 1 or zero bids to sort,
     partition is already sorted otherwise if begin is greater
     than or equal to end then return*/
    if(begin >= end) { //self check to determine if vector is empty or only has one element
            return;
    }
    /* Partition bids into low and high such that
     midpoint is location of last element in low */
    mid = partition(bids, begin, end); //partition function call to get the middlePoint element of vector and ensure all elements lower than pivot are to left and all element equal or higher to pivot are to the right
    
    // recursively sort low partition (begin to mid)
    quickSort(bids, begin, mid); //recursive function call to sort first half of vector between first element and element just before middlePoint (middlePoint can be included in either vector partition)
    
    // recursively sort high partition (mid+1 to end)
    quickSort(bids, mid+1, end); //recursive function call to sort second half of vector between middlePoint element and end of vector
}

// FIXME (1a): Implement the selection sort logic over bid.title
/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */
void selectionSort(vector<Bid>& bids) {
    //define min as int (index of the current minimum bid)
    int min = 0;
    // check size of bids vector
    // set size_t platform-neutral result equal to bid.size()
    int size_t = bids.size();
    // pos is the position within bids that divides sorted/unsorted
    // for size_t pos = 0 and less than size -1
    for(int pos = 0; pos < size_t; ++pos){
        // set min = pos
        min = pos;
        // loop over remaining elements to the right of position
        for(int i = pos+1; i < size_t; ++i){
            // if this element's title is less than minimum title
            if(bids.at(i).title.compare(bids.at(min).title) < 0){ //std::string.compare function used to compare titles, if lower than min, returns negative integer and minimum is set to new index value
                // this element becomes the minimum
                min = i;
            }
        }
        if(min != pos) { //compares that the minimum value in the vector is the current position
        // swap the current minimum with smaller one found
            // swap is a built in vector method
            swap(bids.at(pos), bids.at(min)); //swap function used to swap the elements at index of the current minimum position with the new minimum found
        }
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            //alteration to given code to allow for user selection of each csv file
            int selectFile;
            cout << "Type '1' for \"Total Monthly Sales\", Type '2' for \"Dec 2016 Monthly Sales\": ";
            cin >> selectFile;
            cout << endl;
            if(selectFile == 1){
                //initialize a timer variable before loading bids
                ticks = clock();
                //complete method call to load the bids from total monthly sales csv
                bids = loadBids("eBid_Monthly_Sales.csv");
            }
            else if (selectFile == 2) {
                //initialize a timer variable before loading bids
                ticks = clock();
                //complete method call to load bids from Dec_2016 monthly sales csv
                bids = loadBids("eBid_Monthly_Sales_Dec_2016.csv");
            }
            // Initialize a timer variable before loading bids
            // ticks = clock();

            // // Complete the method call to load the bids
            // bids = loadBids(csvPath);
            cout << endl;
            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            cout << endl;

            break;

        case 2:
            // Loop and display the bids read
            cout << endl;
            cout << "***************************************" << endl;
            cout << endl;
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;
            cout << "***************************************" << endl;
            cout << endl;

            break;

        // FIXME (1b): Invoke the selection sort and report timing results
            case 3:
                // Initialize a timer variable before sorting bids with selectionSort
                ticks = clock(); //pulled from previous cases
                
                //function call to sort bids
                selectionSort(bids);

                //print statement to match desired output
                cout << bids.size() << " bids sorted\n"; //structured from previous cases

                // Calculate elapsed time and display result (pulled from previous cases)
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << endl;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                cout << endl;

                break; // break switch
        // FIXME (2b): Invoke the quick sort and report timing results
            case 4:
                // Initialize a timer variable before sorting bids
                ticks = clock(); //pulled from previous cases

                //function call to quick Sort bids
                quickSort(bids, 0, bids.size()-1); //bids.size()-1 used because size() does not account for 0 index

                //print statement to match desired output
                cout << bids.size() << " bids sorted\n"; //structured from previous cases

                // Calculate elapsed time and display result (pulled from previous cases)
                ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                cout << endl;
                cout << "time: " << ticks << " clock ticks" << endl;
                cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
                cout << endl;

                break; // break switch
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
