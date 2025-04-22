/*
map (std::map<list>)  -     to associate map key with multiple values, can use value type <list>
            DECLARATION:
                std::map<key_type, std::list<list_type> mapName;

        COMPILING: using "auto" type in print func. requires '-std=c++11'
*/

#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

int main()
{
    map<string, list<string>> Pokedex;

    list<string> pikachuAttacks {"Thunder Shock, ", "Tail Whip, ", "Quick Attack"};
    list<string> charmanderAttacks {"Flame Thrower, ", "Scary Face"};
    list<string> chikoritaAttacks {"Razor Leaf, ", "Poison Powder"};

    Pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
    Pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
    Pokedex.insert(pair<string, list<string>>("Chikorita", chikoritaAttacks));


    //Accessing and printing elements
    for (const auto pair : Pokedex) //for each Pokemon in Pokedex
    {
        cout << "Pokemon: " << pair.first << ", Attributes: "; //Print Pokemons name
        for(auto value : pair.second)// for each value in attribute list print all values
        {
            cout << value << " ";
        }
        cout << endl;
    }

    // system("Pause>0"); //used to pause windows terminal and force user to close. allows viewing terminal results
    return 0;
}