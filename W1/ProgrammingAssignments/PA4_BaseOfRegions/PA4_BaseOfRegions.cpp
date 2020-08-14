// PA4_BaseOfRegions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include <vector>
#include<map>
#include <tuple>
#include <algorithm>

using namespace std;
//enum class Lang {
//    DE, FR, IT
//};
//
//struct Region
//{
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};

//int FindMaxRepetitionsCount(const vector<Region>& regions) {
//    if (regions.empty()) {
//        return 0;
//    }
//
//    vector<tuple<string, string, map<Lang, string>, int64_t>> newRegions;
//
//    for (const Region& r : regions) {
//        newRegions.push_back(tie(r.std_name,
//            r.parent_std_name, r.names, r.population));
//    }
//    int numOfRepetitions = 0;
//    for (const auto& r : newRegions) {
//        int currentElementRepetitions = count(begin(newRegions), end(newRegions), r);
//        if (currentElementRepetitions > numOfRepetitions) {
//            numOfRepetitions = currentElementRepetitions;
//        }
//    }
//    return numOfRepetitions;
//}

//int FindMaxRepetitionCount(const vector<Region>& regions) {
//    if (regions.empty()) {
//        return 0;
//    }
//
//    int numOfRepetitions = 0;
//    for (const Region& r : regions) {
//        int currentElReps = count(begin(regions), end(regions), r);
//        if (currentElReps > numOfRepetitions) {
//            numOfRepetitions = currentElReps;
//        }
//    }
//    return numOfRepetitions;
//}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    if (regions.empty()) {
        return 0;
    }

    map<Region, int> RegToReps;
    for (const Region& r : regions) {
        if (RegToReps.count(r)!=1) {
            RegToReps[r] = 1;
        }
        else {
            ++RegToReps[r];
        }
    }
    int numOfRepetitions = 1;
    for (const pair<Region, int>& p : RegToReps) {
        if (numOfRepetitions < p.second) {
            numOfRepetitions = p.second;
        }
    }
    return numOfRepetitions;
}

bool operator==(const Region& lhs, const Region& rhs) {
    auto lhsNew = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
    auto rhsNew = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
    return lhsNew == rhsNew;
}

bool operator<(const Region& lhs, const Region& rhs) {
    auto lhsNew = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
    auto rhsNew = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
    return lhsNew < rhsNew;
}

int main()
{
    cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
        }) << endl;

    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
        }) << endl;

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
