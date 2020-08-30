// 6_DifferencesBetweenSetAndVectorIterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

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
	//vector<string> langs = { "Python", "C++", "C", "Java", "C#" };

	//vector<string> c_langs;
	//auto it = find_if(begin(langs), end(langs),
	//	[](const string& lang) {
	//		return lang[0] == 'C';
	//	});

	//cout << it - begin(langs) << endl;
	////PrintRange(begin(c_langs), end(c_langs));

	//set<int> s = { 1,6,8,9 };
	//auto it1 = s.find(6);

	//PrintRange(next(it1), end(s));

	const istream_iterator<string> start(cin);
	const istream_iterator<string> end;
	vector<string> strings(start, end);
	vector<string> more_strings(start, end);
	
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
