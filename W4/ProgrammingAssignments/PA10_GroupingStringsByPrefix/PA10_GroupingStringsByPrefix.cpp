// PA10_GroupingStringsByPrefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

template<typename RandomIt> pair<RandomIt, RandomIt> 
FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    string prefSt;
    prefSt.push_back(prefix);

    string prefEnd;
    prefEnd.push_back(static_cast<char>(prefix+1));

    return { lower_bound(range_begin,range_end, prefSt),
        lower_bound(range_begin, range_end, prefEnd) };
    
}

int main() {
    const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;

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
