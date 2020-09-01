// 1_ClassSpecificCodeWorkUnification_DeterminingAProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Animal {
public:

	Animal(const string& type)
		: type_(type) {
	}

	void Eat(const string& fruit) {
		cout << type_ << " eats an " << fruit << "·" << endl;
	}

	void Voice() const{
		if (type_ == "Cat") {
			cout << "meow!" << endl;
		}
		else if (type_ == "Dog") {
			cout << "Whaf!" << endl;
		}
		else if (type_ == "Parrot") {
			cout << name_ << " is good!" << endl;
		}
	}
private:
	const string type_;
};

class Cat :public Animal {
public:
	Cat() : Animal("Cat") {
	}
};

class Dog : public Animal {
public:
	Dog() : Animal("Dog") {
	}
};

class Parrot : public Animal {
public:
	Parrot(const string& name) : Animal("Parrot"), name_(name) {

	}

	void Talk() const {
		cout << name_ << " is good!" << endl;
	}
private:
	const string& name_;
};

void MakeSound(const Animal& a) {
	a.Voice();
}



int main()
{
	Cat c;
	Dog d;

	c.Eat("apple");
	d.Eat("orange");

	MakeSound(c);
	MakeSound(d);

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
