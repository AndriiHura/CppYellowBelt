// PA2_GetDistinctRealRootCountTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void Assert(bool b, const string& hint) {
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

int GetDistinctRealRootCount(double a, double b, double c) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}
void TestTwoZeroCoefs() {
    {//T1
        int a = 0;
        int b = 0;
        int c = 1;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 0,"TwoZeroCoefs - a, b");
    }
    {//T2
        int a = 1;
        int b = 0;
        int c = 0;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "TwoZeroCoefs - c, b");
    }
    {//T3
        int a = 0;
        int b = 1;
        int c = 0;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "TwoZeroCoefs - a, c");
    }
}

void TestOneZeroCoef() {
    {//T1
        int a = 1;
        int b = 1;
        int c = 0;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 2, "OneZeroCoef - c");
    }
    {//T2
        int a = 1;
        int b = 0;
        int c = 1;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 0, "OneZeroCoef - b, c is posetive");
    }
    {//T3
        int a = 1;
        int b = 0;
        int c = -1;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 2, "OneZeroCoef - b, c is negative");
    }
    {//T4
        int a = 0;
        int b = 1;
        int c = 1;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "OneZeroCoef - a");
    }
}

void TestNoZeroCoef() {
    {
        int a = 1;
        int b = 1;
        int c = 1;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 0, "NoZeroCoef - Descriminant is Posetive");
    }
    {
        int a = 1;
        int b = -4;
        int c = 4;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 1, "NoZeroCoef - Descrimoinant is Zero");
    }
    {
        int a = 1;
        int b = 2;
        int c = -3;
        AssertEqual(GetDistinctRealRootCount(a, b, c), 2, "NoZeroCoef - Descrimoinant is Posetive");
    }
}


int main() {
    TestRunner runner;
    runner.RunTest(TestNoZeroCoef, "TestNoZeroCoef");
    runner.RunTest(TestOneZeroCoef, "TestOneZeroCoef");
    runner.RunTest(TestTwoZeroCoefs, "TestTwoZeroCoefs");

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
