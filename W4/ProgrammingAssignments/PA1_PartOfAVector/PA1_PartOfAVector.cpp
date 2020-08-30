// PA1_PartOfAVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto result = find_if(begin(numbers), end(numbers),
        [](const int& el) {
            return el < 0;
        });
    if (result == end(numbers)) {
        auto it = end(numbers);
        while (it != begin(numbers)) {
            --it;
            cout << *it << " ";
        }
    }
    else {
        while (result != begin(numbers)) {
            --result;
            cout << *result << " ";
        }
    }

}

int main()
{
    PrintVectorPart({ 6, 1, 8, -5, 4 });
    cout << endl;
    PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
    cout << endl;
    PrintVectorPart({ 6, 1, 8, 5, 4 });
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
