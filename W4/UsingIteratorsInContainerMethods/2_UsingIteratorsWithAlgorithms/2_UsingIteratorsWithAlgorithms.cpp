// 2_UsingIteratorsWithAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

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
	set<string> langs = { "Python", "C++", "C", "Java", "C#" };
	
	cout<<all_of(begin(langs), end(langs),
		[](const string& lang) {
			return lang[0] >= 'A' && lang[0] <= 'Z';
		});


	/*vector<string> langs = { "Python", "C++", "C", "Java", "C#" };

	auto it = min_element(begin(langs), end(langs));
	cout << *it<<endl;

	auto it1 = max_element(begin(langs), end(langs));
	cout << *it1 << endl;

	auto it2 = minmax_element(begin(langs), end(langs));
	cout << *it2.first << " " << *it2.second << endl;
	*/
	/*auto it = remove_if(begin(langs), end(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});
	langs.erase(it, end(langs));*/
	//PrintRange(begin(langs), end(langs));

	/*vector<string> langs2 = { "Python", "C++", "C++", "Java", "C++" };
	auto it1 = unique(begin(langs2), end(langs2));
	langs2.erase(it1, end(langs2));
	PrintRange(begin(langs2), end(langs2));*/


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
