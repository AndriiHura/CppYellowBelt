// 5_StoringObjectsOfDifferentTypesUsing_shared_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Animal {
public:

	Animal(const string& type)
		: type_(type) {
	}

	void Eat(const string& fruit) {
		cout << type_ << " eats an " << fruit << "." << endl;
	}

	virtual void Voice() const = 0;

private:
	const string type_;
};

class Cat :public Animal {
public:
	Cat() : Animal("Cat") {
	}

	void Voice() const override {
		cout << "meow!" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() : Animal("Dog") {
	}

	void Voice() const override {
		cout << "Whaf!" << endl;
	}
};

class Parrot : public Animal {
public:
	Parrot(const string& name) : Animal("Parrot"), name_(name) {}

	void Voice() const override {
		cout << name_ << " is good!" << endl;
	}
private:
	const string name_;
};

class Horse : public Animal {
public:
	Horse() : Animal("Horse") {}

	void Voice() const override {
		cout << "Brrrr" << endl;
	}

};

void MakeSound(const Animal& a) {
	a.Voice();
}



int main()
{
	

	vector<shared_ptr<Animal>> animals = { make_shared<Cat>(),
		make_shared<Dog>(), make_shared<Parrot>("Kesha") };

	for (auto a : animals) {
		MakeSound(*a);
	}

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
