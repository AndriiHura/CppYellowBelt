// 1_UsingIteratorsInContainerMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename It>
void PrintRange(It range_begin,
	It range_end) {
	for (auto it = range_begin;
		it != range_end; ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
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
	vector<string> langs = {"Python", "C++", "C", "Java", "C#" };
	auto it = find(begin(langs), end(langs), "C++");

	/*langs.erase(it);
	PrintRange(begin(langs), end(langs));*/

	/*langs.erase(it, end(langs));
	PrintRange(begin(langs), end(langs));*/

	langs.erase(it, end(langs));
	langs.insert(begin(langs), "C++");
	PrintRange(begin(langs), end(langs));

	vector<string> langs2 = { "Python", "C++", "C", "Java", "C#" };

	langs.insert(begin(langs), begin(langs2), end(langs2));
	PrintRange(begin(langs), end(langs));

	vector<string> langs3 = { "Python", "C++", "C", "Java", "C#" };

	auto it1 = find(begin(langs3), end(langs3), "C++");

	langs3.erase(it1, end(langs3));
	langs3.insert(begin(langs3), 5, "Hello");
	PrintRange(begin(langs3), end(langs3));


	vector<string> langs4 = { "Python", "C++", "C", "Java", "C#" };

	auto it2 = find(begin(langs4), end(langs4), "C++");

	langs4.erase(it2, end(langs4));
	langs4.insert(begin(langs4), { "Hello", "I", "am", "Andrii" });
	PrintRange(begin(langs4), end(langs4));


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
