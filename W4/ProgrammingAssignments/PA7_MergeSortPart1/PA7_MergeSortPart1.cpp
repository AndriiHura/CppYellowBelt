// PA7_MergeSortPart1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename It>
void PrintRange(It range_begin,
    It range_end) {
    for (auto it = range_begin;
        it != range_end; ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int range_length = range_end - range_begin;
    if (range_length > 1) {
    
        vector<typename RandomIt::value_type> elements(range_begin, range_end);

        auto itHalf = elements.begin() + range_length/2;

        MergeSort(elements.begin(), itHalf);
        MergeSort(itHalf, elements.end());

        merge(elements.begin(), itHalf,
            itHalf, elements.end(), range_begin);
    }
}

int main() {
    vector<int> v = { 6, 4, 7, 1 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
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
