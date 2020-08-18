// 1_AnalyzingUnitTestFrameworkDisadvantages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <exception>
#include <sstream>

using namespace std;

using Synonyms = map<string, set<string>>;

void AddSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word) {
    // второе слово добавляем в список синонимов первого...
    synonyms[first_word].insert(second_word);
    // и наоборот
    synonyms[second_word].insert(first_word);
}

size_t GetSynonymsCount(Synonyms& synonyms,
    const string& first_word) {
    return synonyms[first_word].size()+1;
}

bool AreSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word) {
    return synonyms[first_word].count(second_word) == 1;
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << "!=" << u << " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

void TestAddSynonyms() {
    {///Test1
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };
        assert(empty == expected);
    }
    {///Test2
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a", "c");

        Synonyms expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"b", "a"}}
        };
        assert(synonyms == expected);
    }
    cout << "TestAdd OK" << endl;
}

void TestCount() {
    {//T1
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"),0u, "count for empty");
    }
    {//T2
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u, "count for a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 1u, "count for b");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u, "count for z");
    }
    cout << "TestCount OK" << endl;
}

void TestAreSynonyms() {
    {//T1
        Synonyms empty;
        assert(!AreSynonyms(empty, "a", "b"));
        assert(!AreSynonyms(empty, "b", "a"));

    }
    {//T2
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        assert(AreSynonyms(synonyms, "a", "b"));
        assert(AreSynonyms(synonyms, "b", "a"));
        assert(AreSynonyms(synonyms, "a", "c"));
        assert(AreSynonyms(synonyms, "c", "a"));
        assert(!AreSynonyms(synonyms, "c", "b"));
        assert(!AreSynonyms(synonyms, "b", "c"));
    }
    cout << "TestAreSynonyms OK" << endl;
}

void TestAll() {
    TestCount();
    TestAreSynonyms();
    TestAddSynonyms();
}

int main() {
    TestAll();
    return 0;
    int q;
    cin >> q;

    Synonyms synonyms;

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
