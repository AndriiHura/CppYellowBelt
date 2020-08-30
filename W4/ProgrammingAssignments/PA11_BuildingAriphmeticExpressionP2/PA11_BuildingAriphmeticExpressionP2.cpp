// PA11_BuildingAriphmeticExpressionP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <deque>

using namespace std;

void PrintDeque(const deque<string>& dq) {
    for (const auto& el : dq) {
        cout << el;
    }
}

int main()
{
    deque<string> result;
    string start;
    cin >> start;

    result.push_back(start);


    int NumOfOperations;
    cin >> NumOfOperations;
   

    for (int i = 0; i < NumOfOperations; ++i) {

        string operation;
        string number;
        cin >> operation >> number;

        string currentExpression = " " + operation + " " + number;
        if((operation == "*" || operation == "/")
            && (result.back()[1] == '+' || result.back()[1] == '-'))
        {
            result.push_front("(");
            result.push_back(")");
            result.push_back(currentExpression);
           
        }
        else {
            result.push_back(currentExpression);
        }
    }

    PrintDeque(result);
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
