// PA9_NamesAndSurenames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<map>
#include <algorithm>

using namespace std;

// ���� ��� ����������, ���������� ������ ������
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // ���������� ��� ����������

    auto range_end = names.upper_bound(year);

    // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
    if (range_end != names.begin())
    {
        name = prev(range_end)->second;
    }

    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // �������� ��� � ������� �� ��������� �� ��� year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // ���� � ���, � ������� ����������
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // ���� ���������� ������ ���
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // ���� ���������� ������ �������
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // ���� �������� � ���, � �������
        }
        else {
            return first_name + " " + last_name;
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
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
