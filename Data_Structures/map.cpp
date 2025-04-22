/*
map (std:: ordered/unordered)  -    data collection, similar dictionary storing key: value pairs
                                    **KEYS MUST BE UNIQUE**
                                BASIC OPERATIONS:
                                 insert(pair<type, type>("key", "value"))
                                 at()
                                 'map'[index]
                                 find(key)
                                 begin()/end() (for traversing)
                                 erase(key)
                                 count(key)
                                 clear()
                                 swap() *must be same type
                                 .first *accesses key
                                 .second *accesses value
            DECLARATION:
                map<key_type, value_type, comp> mapName; *types CAN be different!
                    comp (optional) - used to call custom comparator fuction when sorting
                                    - when omitted, map sorted in increasing order by keys
                                    
        COMPILING: using "auto" type in print func. requires '-std=c++11'
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    // Declare map
    map<string, string> myDict;

    //Adding key/value pairs (std::map will auto order map alphanumerically)
    myDict.insert(pair<string, string>("Strawberry", "die Erdbeere"));
    myDict.insert(pair<string, string>("Apple", "der Apfel"));
    myDict.insert(pair<string, string>("Orange", "die Orange, die Agfelsine"));
    myDict.insert(pair<string, string>("Banana", "die Banane"));
    
    

    // Print map (will compile fine without '{}' too!)
    cout << "Ordered map: \n";

    for(const auto pair : myDict)
    {
        cout << pair.first << " in German is: " << pair.second << endl;
    }
    cout <<endl;

    // Declaring unordered_map
    unordered_map<string, string> myDict2;

    //Adding key/value pairs (std::map will auto order map alphanumerically)
    myDict2.insert(pair<string, string>("Strawberry", "die Erdbeere"));
    myDict2.insert(pair<string, string>("Apple", "der Apfel"));
    myDict2.insert(pair<string, string>("Orange", "die Orange, die Agfelsine"));
    myDict2.insert(pair<string, string>("Banana", "die Banane"));
    
    //Accessing Elements
    myDict2["Strawberry"] = "Die Erdbeere"; //re-initialized element with key "Strawberry" from "die..." to "Die..."
    
    cout << "Map size: " << myDict2.size() << endl;

    // Print map (will compile fine without '{}' too!)
    cout << "Unordered map: \n";
    for(const auto pair : myDict2)
    {
        cout << pair.first << " in German is: " << pair.second << endl;
    }

    

    return 0;
}