#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <functional>

#include "date.h"

#pragma once

using namespace std;

typedef function<bool(const Date &, const string &)> predicateType;
typedef pair<Date, string> databasePairType;

class Database {
public:
    void Add(const Date& date, const string& event);

    vector<databasePairType> FindIf(const predicateType& predicate) const;

    int RemoveIf(const predicateType& predicate);

    databasePairType Last(const Date& date) const;

    void Print(ostream&) const;

private:
    map<Date, vector<string>> data_base;
    map<string, set<Date>> help_map;
};

ostream &operator<<(ostream &os, const databasePairType& pair);