// 3_OrderOfConstructingClassInstances.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Log {
	Log(string name) : n(name) {
		cout << "+ " << n << endl;
	}
	~Log() {
		cout << "- " << n << endl;
	}

	string n;
};

struct Fruit {
	Fruit(const string& t): l(t + " (Fruit)") {

	}

	const Log l = Log("Fruit");
};

struct Apple : public Fruit {
	Apple(const string& t) : Fruit(t), l(t) {
	}

	const Log l;

};

class AppleTree {
public:
	AppleTree(const string& t)
		: type(t)
		, a1(type + "a1")
		, a2(type + "a2"){

	}

	string type;
	Apple a1;
	Apple a2;

};

int main()
{
	AppleTree at("AppleTree");

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
