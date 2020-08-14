// PA6_EverythingToSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;
template<typename T> T Sqr(T t);

template<typename T> vector<T> Sqr(vector<T> vec);

template<typename First, typename Second> pair<First, Second> Sqr(pair<First, Second> p);

template<typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value> m);

template<typename T>
T Sqr(T t) {
    return t * t;
}

template<typename T>
vector<T> Sqr(vector<T> vec) {
    for (auto& el : vec) {
        el = Sqr(el);
    }
    return vec;
}

template<typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> p) {
    return make_pair(Sqr(p.first), Sqr(p.second));
}

template<typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value> m) {
    for (auto& [key, value] : m) {
        m[key] = Sqr(value);
    }
    return m;
}




int main()
{
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    vector<pair<int, int>> vec_of_pairs = { {2, 3}, {4, 8} };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(vec_of_pairs)) {
        cout << x.first << ' ' << x.second << endl;
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
