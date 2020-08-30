// PA8_NearestElementSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<set>
#include<algorithm>
#include <iterator>

using namespace std;

set<int>::const_iterator 
FindNearestElement(const set<int>& numbers, int border) {
    auto itLower = numbers.lower_bound(border);
    if (itLower == numbers.begin()) {
        return itLower;
    }
    else if (itLower == numbers.end()) {
        return prev(itLower);
    }
    else {
        if (*itLower - border >= border - *prev(itLower))
        {
            return prev(itLower);
        }
        else {
            return(itLower);
        }
    }

    

}

int main() {
    set<int> numbers = { 1, 4, 6 };
    cout <<
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
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
