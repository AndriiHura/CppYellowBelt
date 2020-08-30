// 3_SetAndMapIterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

struct Lang {
	string name;
	int age;
};

using LangIt = vector<string>::iterator;

template<typename It>
void PrintRange(It range_begin,
	It range_end) {
	for (auto it = range_begin;
		it != range_end; ++it)
	{
		cout << *it << " ";
	}
}


template<typename It>
void PrintMapRange(It range_begin,
	It range_end) {
	for (auto it = range_begin;
		it != range_end; ++it)
	{
		cout << it->first << " " << it->second << " ";
	}
}

int main()
{
	//set<string> langs = { "Python", "C++", "C", "Java", "C#" };
	map<string, int> langs = {
		{"Python", 26},
		{"C++", 34},
		{"C", 45},
		{"Java", 22},
		{"C#", 17}
	};
	//PrintRange(begin(langs), end(langs));
	//PrintRange(begin(langs[0]), end(langs[0]));

	auto it = langs.find("C++");
	PrintMapRange(begin(langs), it);
	cout << endl;
	PrintMapRange(it, end(langs));

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
