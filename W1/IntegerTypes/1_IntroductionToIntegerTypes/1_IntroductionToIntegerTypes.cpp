// 1_IntroductionToIntegerTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<limits>

using namespace std;

int main()
{
	cout << sizeof(int) << endl;

	int x = 0;
	cout << sizeof(x) << endl;

	cout << sizeof(4000'000'000'000'000'000) << endl;

	cout << numeric_limits<int>::min() << '.' <<
		numeric_limits<int>::max() << endl;

	cout << numeric_limits<short>::min() << '.' <<
		numeric_limits<short>::max() << endl;

	cout << numeric_limits<long int>::min() << '.' <<
		numeric_limits<long int>::max() << endl;

	cout << numeric_limits<long long >::min() << '.' <<
		numeric_limits<unsigned long long>::max() << endl;

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
