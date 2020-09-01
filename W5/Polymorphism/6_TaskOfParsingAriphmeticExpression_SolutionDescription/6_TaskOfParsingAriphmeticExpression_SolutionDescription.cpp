// 6_TaskOfParsingAriphmeticExpression_SolutionDescription.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<memory>

using namespace std;

class Node {
public:
	virtual int Evaluate() { return 0; }
};

class Value : public Node {
public:
	Value(int d): d_ (d){}

	int Evaluate() override {
		return d_;
	}
private:
	const int d_;
};

class Variable : public Node {
public:
	Variable(const int& x) : x_(x){}

	int Evaluate() override {
		return x_;
	}

private:
	const int& x_;
};

class Operation : public Node {
public:
	Operation(char op, shared_ptr<Node> left, shared_ptr<Node> right)
		: op_(op), left_(left), right_(right){}

	int Evaluate() override {
		if (op_ == '*') {
			return left_->Evaluate() * right_->Evaluate();
		}
		else if (op_ == '+') {
			return left_->Evaluate() + right_->Evaluate();
		}
		else if (op_ == '-') {
			return left_->Evaluate() - right_->Evaluate();
		}
		return 0;
	}

private:
	const char op_;
	shared_ptr<Node> left_, right_;

};

//Node Parse(const string& token, int& x) {
//
//}

int main()
{
	string tokens = "5+7-x*x+x";


	//cout << "Enter expression: ";
	//cin >> tokens;


	int x;
	//auto expr = Parse(tokens, x);

	shared_ptr<Node> var1 = make_shared<Variable>(x);
	shared_ptr<Node> var2 = make_shared<Variable>(x);
	shared_ptr<Node> mul1 = make_shared<Operation>('*', var1, var2);

	shared_ptr<Node> dig1 = make_shared<Variable>(5);
	shared_ptr<Node> dig2 = make_shared<Variable>(7);

	shared_ptr<Node> var3 = make_shared<Variable>(x);
	shared_ptr<Node> plus1 = make_shared<Operation>('+', dig1, dig2);
	shared_ptr<Node> minus1 = make_shared<Operation>('-', plus1, mul1);
	shared_ptr<Node> plus2 = make_shared<Operation>('+', minus1, var3);







	cout << "Enter x: ";
	while(cin>>x)
	{
		cout << plus2->Evaluate() << endl;
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
