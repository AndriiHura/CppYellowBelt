// PA4_ClassRationalTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
//
//class Rational {
//public:
//    // Вы можете вставлять сюда различные реализации,
//    // чтобы проверить, что ваши тесты пропускают корректный код
//    // и ловят некорректный
//
//    Rational();
//    Rational(int numerator, int denominator) {
//    }
//
//    int Numerator() const {
//    }
//
//    int Denominator() const {
//    }
//};

void TestDefaultConstructor() {
    Rational r;
    AssertEqual(r.Denominator(), 1);
    AssertEqual(r.Numerator(), 0);
}

void TestParametrizedConstructor() {
    Rational r(4, 12);
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 3);

    Rational r1(9, 21);
    AssertEqual(r1.Numerator(), 3);
    AssertEqual(r1.Denominator(), 7);
}

void TestNegativeRationals() {
    Rational r(-4, 12);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 3);

    Rational r1(4, -12);
    AssertEqual(r1.Numerator(), -1);
    AssertEqual(r1.Denominator(), 3);

    Rational r2(-4, -12);
    AssertEqual(r2.Numerator(), 1);
    AssertEqual(r2.Denominator(), 3);
}

void TestZeroNumerator() {
    Rational r(0, 12);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}



int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestParametrizedConstructor, "TestParametrizedConstructor");
    runner.RunTest(TestNegativeRationals, "TestNegativeRationals");
    runner.RunTest(TestZeroNumerator, "TestZeroNumerator");

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
