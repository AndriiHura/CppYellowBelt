// 3_ReturningSeveralValuesFromAFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <tuple>
#include<map>
#include <string>
#include<set>

using namespace std;

class Cities {
public:
    tuple<bool, string> FindCountry(const string& city) const {
        if (cityToCountry.count(city) == 1) {
            return {true, cityToCountry.at(city)};
        }
        else if (ambigousCities.count(city) == 1) {
            return {false, "Ambigous"};
        }
        else {
            return { false, "Not exists" };
        }
    }
private:
    map<string, string> cityToCountry;
    set<string> ambigousCities;
};

int main()
{
  /*  Cities cities;
    auto t =cities.FindCountry("Volgograd");

    cout << get<1>(t);*/

    /*Cities cities;
    bool success;
    string message;
    tie(success, message) = cities.FindCountry("Volgograd");*/

    Cities cities;
    auto [success, message] = cities.FindCountry("Volgograd");

    cout <<success<< " "<<message<<endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
