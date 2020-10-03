#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <iostream>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs){
    vector<int> vec1 = {lhs.year, lhs.month, lhs.day};
    vector<int> vec2 = {rhs.year, rhs.month, rhs.day};
    return vec1 < vec2;
}

bool operator<(const Time& lhs, const Time& rhs){
    vector<int> vec1 = {lhs.hours, lhs.minutes};
    vector<int> vec2 = {rhs.hours, rhs.minutes};
    return vec1 < vec2;
}

bool operator==(const Date& lhs, const Date& rhs){
    vector<int> vec1 = {lhs.year, lhs.month, lhs.day};
    vector<int> vec2 = {rhs.year, rhs.month, rhs.day};
    return vec1 == vec2;
}

bool operator==(const Time& lhs, const Time& rhs){
    vector<int> vec1 = {lhs.hours, lhs.minutes};
    vector<int> vec2 = {rhs.hours, rhs.minutes};
    return vec1 == vec2;
}

ostream& operator<<(ostream& os, const Date& date){
    os << date.day << ":" << date.month << ":" << date.year << endl;
    return os;
}

ostream& operator<<(ostream& os, const Time& time){
    os << time.hours << ":" << time.minutes << endl;
    return os;
}

istream& operator>>(istream& is, Date& date){
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;

    return is;
}

istream& operator>>(istream& is, Time& time){
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;

    return is;
}

#define UPDATE_FIELD(ticket, field, values)                 \
    if (values.find(#field) != values.end()) {              \
        istringstream is(values.find(#field)->second);      \
        is >> ticket.field;                                 \
    }


void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
            {"departure_date", "2018-2-28"},
            {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
            {"price", "12550"},
            {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 РЅРµ СЃРѕРґРµСЂР¶РёС‚ РєР»СЋС‡РµР№ "departure_date" Рё "departure_time", РїРѕСЌС‚РѕРјСѓ
    // Р·РЅР°С‡РµРЅРёСЏ СЌС‚РёС… РїРѕР»РµР№ РЅРµ РґРѕР»Р¶РЅС‹ РёР·РјРµРЅРёС‚СЊСЃСЏ
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}