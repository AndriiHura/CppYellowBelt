// IntroductionToTemplates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <map>
#include<sstream>
#include <utility>

using namespace std;

template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1,
    const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return make_pair(f, s);
}

template<typename T>
T Sqr(T x) {
    return x * x;
}

int main()
{
    auto p = make_pair( 2.5, 3 );
    auto result = Sqr(p);
    cout << result.first << " " << result.second << endl;
}

//int Sqr(int x) {
//    return x * x;
//}
//
//double Sqr(double x) {
//    return x * x;
//}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
