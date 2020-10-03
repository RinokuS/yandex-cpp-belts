#include <iostream>
#include <exception>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
using namespace std;

class Date {
public:
    Date(){
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int year, int month, int day){
        if (month < 1 || month > 12){
            throw invalid_argument("Month value is invalid: " + to_string(month));
        } else if (day < 1 || day > 31){
            throw invalid_argument("Day value is invalid: " + to_string(day));
        }

        this->year = year;
        this->month = month;
        this->day = day;
    }
    int GetYear() const{
        return year;
    }
    int GetMonth() const{
        return month;
    }
    int GetDay() const{
        return day;
    }
    void WriteDate() const{
        cout << setw(4) << setfill('0') << year << '-' << setw(2) << setfill('0') << month
            << '-' << setw(2) << setfill('0') << day;
    }

private:
    int year, month, day;
};

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

class Database {
public:
    void AddEvent(const Date& date, const string& event){
        data_base[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event){
        if (data_base.count(date) > 0 && data_base[date].count(event) > 0){
            data_base[date].erase(event);
            return true;
        }
        return false;
    }
    int  DeleteDate(const Date& date){
        if (data_base.count(date) == 0){
            return 0;
        } else {
            const int count = data_base[date].size();
            data_base.erase(date);

            return count;
        }
    }
    set<string> Find(const Date& date) const{
        if (data_base.count(date) > 0){
            return data_base.at(date);
        } else{
            return {};
        }
    }

    void Print() const{
        for(const auto& [key, value]: data_base){
            for(const auto& event: value){
                key.WriteDate();
                cout << ' ' << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> data_base;
};

Date ParseDate(const string& date){
    stringstream ds(date);

    int year, month, day;

    if(!(ds >> year)){
        throw invalid_argument("Wrong date format: " + date);
    }
    if (ds.peek() != '-'){
        throw invalid_argument("Wrong date format: " + date);
    }
    ds.ignore(1);

    if(!(ds >> month)){
        throw invalid_argument("Wrong date format: " + date);
    }
    if (ds.peek() != '-'){
        throw invalid_argument("Wrong date format: " + date);
    }
    ds.ignore(1);

    if(!(ds >> day)){
        throw invalid_argument("Wrong date format: " + date);
    }
    if (!ds.eof()){
        throw invalid_argument("Wrong date format: " + date);
    }

    return Date(year, month, day);
}

int main() {
    Database db;

    string command_line;
    while (getline(cin, command_line)) {
        stringstream ss(command_line);

        string command, date_str, event;
        ss >> command;

        try {
            if (command == "Print") {
                db.Print();
            } else if (command.empty()){

            } else {
                ss >> date_str;

                if (!ss.eof()) {
                    ss >> event;
                }

                if (command == "Add" && !event.empty()) {
                    const Date date = ParseDate(date_str);
                    db.AddEvent(date, event);
                } else if (command == "Del") {
                    const Date date = ParseDate(date_str);
                    if (event.empty()) {
                        int count = db.DeleteDate(date);
                        cout << "Deleted " + to_string(count) + " events" << endl;
                    } else {
                        bool is_deleted = db.DeleteEvent(date, event);
                        string output = is_deleted ? "Deleted successfully" : "Event not found";
                        cout << output << endl;
                    }
                } else if (command == "Find") {
                    const Date date = ParseDate(date_str);
                    for (const string& ev : db.Find(date)) {
                        cout << ev << endl;
                    }
                } else{
                    throw logic_error("Unknown command: " + command);
                }
            }
        } catch(invalid_argument& ex){
            cout << ex.what() << endl;
        } catch(logic_error& ex){
            cout << ex.what() << endl;
        }
    }

    return 0;
}
