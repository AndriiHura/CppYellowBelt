// PA10_GroupingStringsByPrefixP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

template<typename RandomIt> pair<RandomIt, RandomIt>
    FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
        string tmp = prefix;
        ++tmp.back();

        return { lower_bound(range_begin,range_end, prefix),
            lower_bound(range_begin, range_end, tmp) };

    }

    int main() {
        const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

        const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
        for (auto it = mo_result.first; it != mo_result.second; ++it) {
            cout << *it << " ";
        }
        cout << endl;

        const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
        cout << (mt_result.first - begin(sorted_strings)) << " " <<
            (mt_result.second - begin(sorted_strings)) << endl;

        const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
        cout << (na_result.first - begin(sorted_strings)) << " " <<
            (na_result.second - begin(sorted_strings)) << endl;

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
