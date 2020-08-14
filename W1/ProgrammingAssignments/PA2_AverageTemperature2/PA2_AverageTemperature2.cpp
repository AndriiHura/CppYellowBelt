// PA2_AverageTemperature2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <string>

using namespace std;

int main()
{
    int numOfDays;
    cin >> numOfDays;
    if (numOfDays != 0)
    {
        vector<int> temperatures;
        for (int i = 0; i < numOfDays; ++i) {
            int currentTemp;
            cin >> currentTemp;
            temperatures.push_back(currentTemp);
        }

        long long sum = 0;
        for (int x : temperatures) {
            sum += x;
        }
        int average = sum / static_cast<int>(temperatures.size());

        string SuitableDays;
        int amount = 0;

        for (int i = 0; i < numOfDays; ++i) {
            if (temperatures[i] > average) {
                amount += 1;
                SuitableDays += to_string(i) + " ";
            }
        }
        cout << amount << endl << SuitableDays;
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
