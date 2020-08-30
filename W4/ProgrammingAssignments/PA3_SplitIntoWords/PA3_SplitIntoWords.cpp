// PA3_SplitIntoWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    auto it_begin = begin(s);
    auto it_end = begin(s);
    while (true) {
        it_end = find(it_begin, end(s), ' ');
        result.push_back({ it_begin, it_end });
        if (it_end == end(s)) {
            break;
        }
        it_begin = ++it_end;
    }
    return result;
}

int main() {
    string s = "C";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
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
