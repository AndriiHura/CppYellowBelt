// 4_EnumTypesAndSwithcOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<set>

using namespace std;

void ProcessRequest1(set<int>& numbers, const string request_type, int request_data) {
    if (request_type == "ADD") {
        numbers.insert(request_data);
    }
    else if (request_type == "REMOVE") {
        numbers.erase(request_data);
    }
    else if (request_type == "NEGATE") {
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
    }
}

void ProcessRequest1(
    set<int>& numbers,
    int request_type,
    int request_data) {
    if (request_type == 0) {
        numbers.insert(request_data);
    }
    else if (request_type == 1) {
        numbers.erase(request_data);
    }
    else if (request_type == 2) {
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
    }
}

enum class RequestType {
    ADD,
    REMOVE,
    NEGATE
};

void ProcessRequest3(
    set<int>& numbers,
    RequestType request_type,
    int request_data) {
    if (request_type == RequestType::ADD) {
        numbers.insert(request_data);
    }
    else if (request_type == RequestType::REMOVE) {
        numbers.erase(request_data);
    }
    else if (request_type == RequestType::NEGATE) {
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
    }
}

void ProcessRequest4(
    set<int>& numbers,
    RequestType request_type,
    int request_data) {
    switch (request_type) {
    case RequestType::ADD:
        numbers.insert(request_data);
        break;
    case RequestType::REMOVE:
        numbers.erase(request_data);
        break;
    case RequestType::NEGATE:
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
        break;
    }
}

void ProcessRequest5(
    set<int>& numbers,
    RequestType request_type,
    int request_data) {
    switch (request_type) {
    case RequestType::ADD:
        numbers.insert(request_data);
        break;
    case RequestType::REMOVE:
        numbers.erase(request_data);
        break;
    case RequestType::NEGATE:
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
        break;
    default:
        cout << "Unknown request" << endl;
    }
}


void ProcessRequest6(
    set<int>& numbers,
    RequestType request_type,
    int request_data) {
    switch (request_type) {
    case RequestType::ADD:
        numbers.insert(request_data);
        break;
    case RequestType::REMOVE:
        numbers.erase(request_data);
        break;
    case RequestType::NEGATE: {  // фигурные скобки обязательны
        bool contains = numbers.count(request_data) == 1;
        if (contains) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
        break;
    }
    default:
        cout << "Unknown request" << endl;
    }
}

int main()
{
    std::cout << "Hello World!\n";
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
