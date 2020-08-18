// 1_IntroductionToUnitTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void AddSynonyms(map<string, set<string>>& synonyms,
    const string& first_word, const string& second_word) {
    // второе слово добавляем в список синонимов первого...
    synonyms[first_word].insert(first_word);
    // и наоборот
    synonyms[second_word].insert(first_word);
}

size_t GetSynonymsCount(map<string, set<string>>& synonyms,
    const string& first_word) {
    return synonyms[first_word].size();
}

bool AreSynonyms(map<string, set<string>>& synonyms,
    const string& first_word, const string& second_word){
    return synonyms[first_word].count(second_word) == 1;
}

int main() {
    int q;
    cin >> q;

    map<string, set<string>> synonyms;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "ADD") {
            string first_word, second_word;
            cin >> first_word >> second_word;
            AddSynonyms(synonyms, first_word, second_word);
        }
        else if (operation_code == "COUNT") {

            string word;
            cin >> word;
            cout << GetSynonymsCount(synonyms, word) << endl;

        }
        else if (operation_code == "CHECK") {

            string first_word, second_word;
            cin >> first_word >> second_word;

            // ищём второе слово во множестве синонимов первого
            // (можно было сделать и наоборот)
            if (AreSynonyms(synonyms, first_word, second_word)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }

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
