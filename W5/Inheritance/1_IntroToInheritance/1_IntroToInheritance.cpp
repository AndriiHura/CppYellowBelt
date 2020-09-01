// 1_IntroToInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Fruit {
	int health = 0;
	string type = "Fruit";
};

struct Apple : public Fruit {
	Apple() {
		health = 10;
		type = "Apple";
	}
};

struct Orange : public Fruit {
	Orange() {
		health = 5;
		type = "Orange";
	}
};

struct Pineapple : public Fruit {
	Pineapple() {
		health = 15;
		type = "Pineapple";
	}
};

class Animal {
public:
	void Eat(const Fruit& f) {
		cout << type << " eats an " << f.type << ". " << f.health << " hp." << endl;
	}

	string type = "Animal";
};

class Cat :public Animal {
public:
	Cat() {
		type = "Cat";
	}
	void Meow() const {
		cout << "meow!" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		type = "Dog";
	}
};

void DoMeal(Animal& a, Fruit& f) {
	a.Eat(f);
}

int main()
{
	Cat c;
	c.Meow();
	Apple a;
	Pineapple o;
	Dog d;

	DoMeal(d, a);
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
