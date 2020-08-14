// 3_SafeUsageOfIntegerTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int avg = (sum / static_cast<int>(t.size()));
	cout << avg << endl;
}

int main()
{
	int a = 1;
	int b = 2;
	int c = a+++b;

	cout << (c) << endl;
	///*vector<int> x = { 4,5 };
	//for (int i = 0; i < static_cast<int>(x.size()); ++i) {
	//	cout << i << ' ' << x[i] << endl;
	//}

	//cout << (-1 < 1u) << endl;*/

	////PrintAverage();

	//vector<int> v = { };

	///*for (size_t i = 0; i + 1 < v.size(); ++i) {
	//	cout << v[i] << endl;
	//}*/

	//for (size_t k = v.size() ; k> 0; --k) {
	//	int i = k - 1;
	//	cout << v[i] << endl;

	//}
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
