#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

// если имя неизвестно, возвращает пустую строку
vector<string> FindNameByYearWithHistory(const map<int, string>& names, int year) {
    vector<string> name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            if (name.empty() || item.second != name[name.size() - 1])
                name.push_back(item.second);
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
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
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }
    string GetFullNameWithHistory(int year) {
        // получаем имя и фамилию по состоянию на год year
        const vector<string> names_vector = FindNameByYearWithHistory(first_names, year);
        const vector<string> surnames_vector = FindNameByYearWithHistory(last_names, year);

        // если и имя, и фамилия неизвестны
        if (names_vector.empty() && surnames_vector.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (names_vector.empty()) {
            return get_surnames(surnames_vector) + " with unknown first name";

            // если неизвестна только фамилия
        } else if (surnames_vector.empty()) {
            return get_names(names_vector) + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return get_names(names_vector) + " " + get_surnames(surnames_vector);
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
    string get_surnames(const vector<string>& surnames_vector){
        if (surnames_vector.size() == 1) {
            return surnames_vector[surnames_vector.size() - 1];
        } else{
            string helper = surnames_vector[surnames_vector.size() - 2];
            for (int i = surnames_vector.size() - 3; i >= 0; --i) {
                helper += ", " + surnames_vector[i];
            }
            return surnames_vector[surnames_vector.size() - 1] + " (" + helper + ")";
        }
    }
    string get_names(const vector<string>& names_vector){
        if (names_vector.size() == 1) {
            return names_vector[names_vector.size() - 1];
        } else{
            string helper = names_vector[names_vector.size() - 2];
            for (int i = names_vector.size() - 3; i >= 0; --i) {
                helper += ", " + names_vector[i];
            }
            return names_vector[names_vector.size() - 1] + " (" + helper + ")";
        }
    }

};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
