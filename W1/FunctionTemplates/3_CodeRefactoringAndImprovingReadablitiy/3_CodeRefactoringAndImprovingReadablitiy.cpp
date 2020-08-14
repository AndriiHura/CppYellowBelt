// 2_UniversalFunctionsForOutputingContainersIntoStream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <map>
#include<sstream>
#include <utility>

using namespace std;

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << ',' << p.second << ')';
}

template <typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool first = true;
    for (const auto& i : c) {
        if (!first) {
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}



template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vi) {
    return out << '[' << Join(vi, ',') << ']';
}

template<typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) {
    return out << '{' << Join(m, ',') << '}';
}


int main()
{
    vector<double> vi = { 1.6, 2.9, 3 };
    cout << vi << endl;

    map<int, int> m = { {1,2.5}, {3, 4} };
    cout << m << endl;

    vector<vector<int>> v = { {1,2}, {3, 4, 5} };
    cout << v << endl;
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
