// 2_IntegerTypesConversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<limits>

using namespace std;

void PrintAverage() {
	vector<int> t = { -8, -7, 3 };

	int sum = 0;
	for (int x : t) {
		sum += x;
	}
	int avg = (sum / t.size());
	cout << avg << endl;
}

int main()
{
	/*cout << numeric_limits<int>::max() + 1 << endl
		<< numeric_limits<int>::min() - 1 << endl;*/

	//int x = 2'000'000'000;
	//int y = 1'000'000'000;

	//cout << (x + y) / 2 << endl;

	/*int x = 2'000'000'000;
	unsigned int y = x;

	cout << x << ' ' << y << endl;*/

	/*int x = -2'000'000'000;
	unsigned int y = x;

	cout << x << ' ' << y << endl;*/

	int x = -1;

	unsigned int y = 1;

	cout << (x < y)<<endl;
	cout << (-1 < 1u) << endl;

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
