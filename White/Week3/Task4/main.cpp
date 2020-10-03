#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            year_to_name[year] = first_name;
            name_change_year.push_back(year);
            sort(begin(name_change_year), end(name_change_year));
        }
        void ChangeLastName(int year, const string& last_name) {
            year_to_surname[year] = last_name;
            surname_change_year.push_back(year);
            sort(begin(surname_change_year), end(surname_change_year));
        }
        string GetFullName(int year) {
            bool name_changed = count_if(begin(name_change_year),
                    end(name_change_year), [year](int x){return x <= year;}) != 0;
            bool surname_changed = count_if(begin(surname_change_year),end(surname_change_year),
                    [year](int x){return x <= year;}) != 0;

            if (!name_changed && !surname_changed){
                return "Incognito";
            } else if (name_changed && !surname_changed){
                return find_name(year) + " with unknown last name";
            } else if (!name_changed && surname_changed){
                return find_surname(year) + " with unknown first name";
            } else{
                return find_name(year) + " " + find_surname(year);
            }
        }
    private:
        map<int, string> year_to_name, year_to_surname;
        vector<int> name_change_year, surname_change_year;
        string find_name(int year){
            for (unsigned long i = name_change_year.size() - 1; i >= 0 ; --i) {
                if (name_change_year[i] <= year) {
                    return year_to_name[name_change_year[i]];
                }
            }
            return "None";
        }
        string find_surname(int year){
            for (unsigned long i = surname_change_year.size() - 1; i >= 0 ; --i) {
                if (surname_change_year[i] <= year) {
                    return year_to_surname[surname_change_year[i]];
                }
            }
            return "None";
        }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
