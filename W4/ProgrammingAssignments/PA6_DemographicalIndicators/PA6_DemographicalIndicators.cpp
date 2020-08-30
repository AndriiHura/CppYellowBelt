// PA6_DemographicalIndicators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        }
    );
    return middle->age;
}

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;


    auto femaleIt = partition(begin(persons), end(persons),
        [](const Person& person) {
            return person.gender == Gender::FEMALE;
        });
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), femaleIt) << endl;


    auto maleIt = partition(begin(persons), end(persons),
        [](const Person& person) {
            return person.gender == Gender::MALE;
        });
    cout << "Median age for males = " << ComputeMedianAge(begin(persons), maleIt) << endl;


    auto employedFemaleIt = partition(begin(persons), end(persons),
        [](const Person& person) {
            return (person.gender == Gender::FEMALE && person.is_employed == true);
        });
    cout << "Median age for employed females = " 
        << ComputeMedianAge(begin(persons), employedFemaleIt) << endl;


    auto unemployedFemaleIt = partition(begin(persons), end(persons),
        [](const Person& person) {
            return (person.gender == Gender::FEMALE && person.is_employed == false);
        });
    cout << "Median age for unemployed females = " 
        << ComputeMedianAge(begin(persons), unemployedFemaleIt) << endl;


    auto employedMaleIt = partition(begin(persons), end(persons),
        [](const Person& person) {
            return (person.gender == Gender::MALE && person.is_employed == true);
        });
    cout << "Median age for employed males = "
        << ComputeMedianAge(begin(persons), employedMaleIt) << endl;


    auto unemployedMaleIt = partition(begin(persons), end(persons),
        [](const Person& person) {
            return (person.gender == Gender::MALE && person.is_employed == false);
        });
    cout << "Median age for unemployed males = "
        << ComputeMedianAge(begin(persons), unemployedMaleIt) << endl;
}

int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
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
