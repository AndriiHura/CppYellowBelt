// PA8_MergeSortPart2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int range_length = range_end - range_begin;
    if (range_length > 1) {

        vector<typename RandomIt::value_type> elements(range_begin, range_end);


        auto itFirstThird = elements.begin() + range_length / 3;
        auto itSecondThird = itFirstThird + range_length / 3;

        MergeSort(elements.begin(), itFirstThird);
        MergeSort(itFirstThird, itSecondThird);
        MergeSort(itSecondThird, elements.end());

        vector<typename RandomIt::value_type> tmp;
        merge(elements.begin(), itFirstThird,
            itFirstThird, itSecondThird, back_inserter(tmp));




        merge(tmp.begin(), tmp.end(),
            itSecondThird, elements.end(), range_begin);
    }
}

int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
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
