// 4_AlgorithmsThatReturnSetOfElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		cout << *it << ", ";
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
	vector<string> langs = { "Python", "C++", "C", "Java", "C#" };

	/*auto it = partition(begin(langs), end(langs),
		[](const string& lang) {
			return lang[0] == 'C';
		});*/

	vector<string> c_langs(langs.size());

	//auto it = copy_if(begin(langs), end(langs), begin(c_langs),
	//	[](const string& lang) {
	//		return lang[0] == 'C';
	//	});

	//PrintRange(begin(c_langs), it);

	set<int> a = { 1, 8, 3 };
	set<int> b = { 3, 6, 8 };

	vector<int> v(a.size());
	auto it = set_intersection(begin(a), end(a),
		begin(b), end(b), begin(v));
	PrintRange(begin(v), it);

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
