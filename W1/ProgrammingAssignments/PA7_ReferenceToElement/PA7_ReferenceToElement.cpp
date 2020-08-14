// PA7_ReferenceToElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include<string>
#include<exception>

using namespace std;
template<typename K, typename V> V& GetRefStrict(map<K, V>& m, const K& index);

template<typename K, typename V>
V& GetRefStrict( map<K, V>& m, const K& index) {
    if (m.count(index) == 0) {
        throw runtime_error("Error");
    }
    return m.at(index);
}

int main()
{
    map<int, string> m = { {0, "value"} };
    string& item = GetRefStrict(m,0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalu

    map<int, int> m1 = { {0, 0} };
    int& item1 = GetRefStrict(m1, 0);
    item1 = 28;
    cout << m1[0] << endl;
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
