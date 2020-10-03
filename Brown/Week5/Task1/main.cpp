#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void PrintStats(vector<Person> persons){
    auto females_iter = partition(persons.begin(), persons.end(),
                          [](Person p){return p.gender == Gender::FEMALE;});

    auto employed_females_iter = partition(persons.begin(), females_iter,
                                [](Person p){return p.is_employed;});
    auto employed_males_iter = partition(females_iter, persons.end(),
                                         [](Person p){return p.is_employed;});

    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << '\n';
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), females_iter) << '\n';
    cout << "Median age for males = " << ComputeMedianAge(females_iter, persons.end()) << '\n';
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), employed_females_iter) << '\n';
    cout << "Median age for unemployed females = " << ComputeMedianAge(employed_females_iter, females_iter) << '\n';
    cout << "Median age for employed males = " << ComputeMedianAge(females_iter, employed_males_iter) << '\n';
    cout << "Median age for unemployed males = " << ComputeMedianAge(employed_males_iter, persons.end()) << '\n';
}

int main() {
    vector<Person> persons = {
            {31, Gender::MALE, false},
            {40, Gender::FEMALE, true},
            {24, Gender::MALE, true},
            {20, Gender::FEMALE, true},
            {80, Gender::FEMALE, false},
            {78, Gender::MALE, false},
            {10, Gender::FEMALE, false},
            {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
