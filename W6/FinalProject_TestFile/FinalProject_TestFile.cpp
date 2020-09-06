// FinalProject_TestFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

template<typename It>
void PrintVect(It first, It last) {
    for (first; first != last; ++first) {
        cout << *first << " ";
    }
}

template<typename Func>
void Test(map<int, vector<string>> vec, Func pred) {
    for (auto& [key, vals] : vec) {
        auto border = stable_partition(vals.begin(), vals.end(),
            [](const string& str) {
                return pred(key, str);
            }
        );
        cout << key << " ";
        PrintVect(vals.begin(), border);
    }
}

int main()
{
    map<int, vector<string>> mp = {
        {12, {"Hello", "Andrii", "Hura"}},
        {3, {"abvc", "azx", "Abbbcr"}},
        {8, {"asdasd", "2132dd", "1"}},
    };

    auto predicate = [](const int key, const string& str) {
        return key % 4 == 0 && str.length() >= 5;
    };

    //Test(mp, predicate);
    for (auto& [key, vals] : mp) {
        PrintVect(vals.begin(), vals.end());
        if (key > 8) {
            mp.erase(key);
        }
    }
    return 0;
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
