// PA5_TestPalindromFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
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

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
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

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
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

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint = {}) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void TestEmptyString() {
    Assert(IsPalindrom(""));
}

void TestSameLetter() {
    Assert(IsPalindrom("a"));
    Assert(IsPalindrom("aa"));
    Assert(IsPalindrom("aaa"));
    Assert(IsPalindrom("bbbbb"));
}

void TestSpaces() {
    Assert(IsPalindrom(" "));
    Assert(IsPalindrom("  "));
    Assert(IsPalindrom(" a "));
    Assert(IsPalindrom(" aa "));
    Assert(!IsPalindrom(" a"));
    Assert(!IsPalindrom(" a  "));
}

void TestNormalWords() {
    Assert(IsPalindrom("madam"));
    Assert(!IsPalindrom("madamm"));
}
void TestFirstAndLastChars(){
    Assert(IsPalindrom("qrrq"));
    Assert(!IsPalindrom("qrrqq"));
    Assert(!IsPalindrom("mqrrq"));

    Assert(!IsPalindrom("madrqdam"));
}

int main() {
    TestRunner runner;
    runner.RunTest(TestEmptyString, "TestEmptyString");
    runner.RunTest(TestSameLetter, "TestSameLetter");
    runner.RunTest(TestSpaces, "TestSpaces");
    runner.RunTest(TestNormalWords, "TestNormalWords");
    runner.RunTest(TestFirstAndLastChars, "TestFirstAndLastChars");

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
