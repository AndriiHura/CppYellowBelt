// 1_IntroToIterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct Lang {
	string name;
	int age;
};

int main()
{
	vector<Lang> langs = {
		{"Python", 26},
		{"C++", 34}, 
		{"C", 45}, 
		{"Java", 22}, 
		{"C#", 17}
	};

	auto result = find_if(
		begin(langs), end(langs),
		[](const Lang& lang) {
			return lang.name[0] == 'D';
		});
	/*string& ref = *result;
	ref = "D++";
	cout << ref << endl;
	cout << *result << endl;
	*result = "F++";
	cout << *result << endl;*/

	if (result == end(langs)){
		cout << "Not found." << endl;
	}
	else {
		cout << (*result).age << endl;
		cout << result->age << endl;
	}

	cout << (langs).front().name << " " << begin(langs)->age;
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
