#pragma once

#include"date.h"

#include<string>
#include<map>
#include<set>
#include <algorithm>
#include <memory>
#include <functional>

using Pred= function<bool(const Date&, const string&)>;

using namespace std;


class Database {
public:
    void Add(const Date& date, const string& event);

    void RemoveEmpty();
    
    int RemoveIf(Pred predicate);

    string Last(const Date& date) const;
    
    vector<pair<Date, string>> FindIf(Pred predicate) const;

    void Print(ostream& os) const;

private:
    map<Date, set<string>> unique_storage;
    map<Date, vector<string>> storage;
};

ostream& operator<<(ostream& os, pair<Date, string> entry);