#pragma once

#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>


using namespace std;

//Interface

template<class T>
ostream& operator<<(ostream& os, const set<T>& s);

template<class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);

void Assert(bool b, const string& hint);

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string& test_name);

    ~TestRunner();
    
private:
    int fail_count=0;
};


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


template<class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
    try {
        func();
        cerr << test_name << " OK" << endl;
    }
    catch (const runtime_error& ex) {
        ++fail_count;
        cerr << test_name << " fails: " << ex.what() << endl;
    }
}

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " tests failed. Terminate";
        exit(1);
    }
}
