#include <iostream>
#include <map>
using namespace std;

void CommandReader(map<string, string>& countryToCapital){
    string command;
    cin >> command;

    if (command == "DUMP"){
        if (countryToCapital.empty()) {
            cout << "There are no countries in the world" << endl;
        } else {
            for (const auto& country_item : countryToCapital) {
                cout << country_item.first << "/" << country_item.second << " ";
            }
            cout << endl;
        }
    } else if (command == "RENAME"){
        string old_country_name, new_country_name;
        cin >> old_country_name >> new_country_name;
        if (old_country_name == new_country_name || countryToCapital.count(old_country_name) == 0 ||
        countryToCapital.count(new_country_name) == 1) {
            cout << "Incorrect rename, skip" << endl;
        } else {
            cout << "Country " << old_country_name << " with capital " << countryToCapital[old_country_name] <<
                 " has been renamed to " << new_country_name << endl;
            countryToCapital[new_country_name] = countryToCapital[old_country_name];
            countryToCapital.erase(old_country_name);
        }
    } else{
        string country;
        cin >> country;

        if (command == "ABOUT"){
            if (countryToCapital.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << countryToCapital[country] << endl;
            }
        } else{
            string newCapital;
            cin >> newCapital;

            if (countryToCapital.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << newCapital << endl;
            } else {
                const string& old_capital = countryToCapital[country];
                if (old_capital == newCapital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " << old_capital
                    << " to " << newCapital << endl;
                }
            }
            countryToCapital[country] = newCapital;
        }
    }
}

int main() {
    int comCounter;
    cin >> comCounter;
    map<string, string> countryToCapital;

    for (int i = 0; i < comCounter; ++i) {
        CommandReader(countryToCapital);
    }
    return 0;
}
