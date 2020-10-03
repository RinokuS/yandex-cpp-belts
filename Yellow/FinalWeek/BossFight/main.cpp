#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

#include "database.h"
#include "date.h"
#include "condition_parser.h"

string ParseEvent(istream &is) {
    string event;

    while (is.peek() == ' ') {
        is.get();
    }
    getline(is, event);

    return event;
}


int main() {
    Database db;

    string command_line;
    while (getline(cin, command_line)) {
        stringstream ss(command_line);

        string command, event;
        ss >> command;

        try {
            if (command == "Add") {
                const Date date = ParseDate(ss);
                if (!ss.eof()) {
                    event = ParseEvent(ss);
                }

                db.Add(date, event);
            } else if (command == "Print") {
                db.Print(cout);
            } else if (command == "Del") {
                auto condition = ParseCondition(ss);

                auto predicate = [condition](const Date &date, const string &event) {
                    return condition->Evaluate(date, event);
                };

                int count = db.RemoveIf(predicate);
                cout << "Removed " << count << " entries" << endl;
            } else if (command == "Find") {
                auto condition = ParseCondition(ss);

                auto predicate = [condition](const Date &date, const string &event) {
                    return condition->Evaluate(date, event);
                };

                const auto entries = db.FindIf(predicate);
                for (const auto &entry : entries) {
                    cout << entry << endl;
                }
                cout << "Found " << entries.size() << " entries" << endl;
            } else if (command == "Last"){
                try {
                    cout << db.Last(ParseDate(ss)) << endl;
                } catch (invalid_argument &) {
                    cout << "No entries" << endl;
                }
            } else if (command.empty()) {
                continue;
            } else{
                throw logic_error("Unknown command: " + command);
            }
        } catch(invalid_argument& ex){
            cout << ex.what() << endl;
        } catch(logic_error& ex){
            cout << ex.what() << endl;
        }
    }

    return 0;
}
