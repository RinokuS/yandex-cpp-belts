#include <sstream>
#include <string>
#include <functional>
#include <iomanip>

#include "date.h"

Date::Date() {
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day) {
    if (month < 1 || month > 12){
        throw invalid_argument("Month value is invalid: " + to_string(month));
    } else if (day < 1 || day > 31){
        throw invalid_argument("Day value is invalid: " + to_string(day));
    }

    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() == rhs.GetYear()){
        if (lhs.GetMonth() == rhs.GetMonth()){
            return lhs.GetDay() < rhs.GetDay();
        } else{
            return lhs.GetMonth() < rhs.GetMonth();
        }
    } else{
        return lhs.GetYear() < rhs.GetYear();
    }
}

bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.GetDay() == rhs.GetDay() &&
            lhs.GetMonth() == rhs.GetMonth() &&
            lhs.GetYear() == rhs.GetYear());
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return (lhs == rhs) || (lhs < rhs);
}

bool operator>(const Date& lhs, const Date& rhs) {
    return rhs < lhs;
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return (lhs == rhs) || (lhs > rhs);
}

ostream &operator<<(ostream& os, const Date& date){
    os << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) << setfill('0') << date.GetMonth()
         << '-' << setw(2) << setfill('0') << date.GetDay();

    return os;
}

Date ParseDate(istream& is) {
    int year, month, day;
    is >> year;
    is.get();
    is >> month;
    is.get();
    is >> day;

    return Date(year, month, day);
}