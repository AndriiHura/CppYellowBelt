// 2_EnsuringRegularLaunchForUnitTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <map>
#include <set>
#include <exception>
#include <sstream>

using namespace std;

using Synonyms = map<string, set<string>>;

template<class T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

void AddSynonyms(Synonyms& synonyms,
    const string& first_word, const string& second_word) {
    // второе слово добавляем в список синонимов первого...
    synonyms[first_word].insert(first_word);
    // и наоборот
    synonyms[second_word].insert(first_word);
}

size_t GetSynonymsCount(Synonyms& synonyms,
    const string& first_word) {
    return synonyms[first_word].size();
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

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

void TestAddSynonyms() {
    {///Test1
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };
        AssertEqual(empty, expected, "Add to empty");
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
        AssertEqual(synonyms, expected, "Add to non-empty");
    }
}

void TestCount() {
    {//T1
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "count for empty");
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
}

void TestAreSynonyms() {
    {//T1
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");

    }
    {//T2
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "");
        Assert(AreSynonyms(synonyms, "b", "a"), "");
        Assert(AreSynonyms(synonyms, "a", "c"), "");
        Assert(AreSynonyms(synonyms, "c", "a"), "");
        Assert(!AreSynonyms(synonyms, "c", "b"), "");
        Assert(!AreSynonyms(synonyms, "b", "c"), "");
    }
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (const runtime_error& ex) {
            ++fail_count;
            cerr << test_name << " fails: " << ex.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " tests failed. Terminate";
            exit(1);
        }
    }
private:
    int fail_count = 0;
};

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
    tr.RunTest(TestCount, "TestCount");
}



int main() {
    TestAll();
   

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
