#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintStats(vector<Person> persons){
    cout << "Median age = " + to_string(ComputeMedianAge(persons.begin(), persons.end())) << endl;
    auto part_point = partition(persons.begin(), persons.end(),
            [](Person x){return x.gender == Gender::FEMALE;});
    cout << "Median age for females = " + to_string(ComputeMedianAge(persons.begin(), part_point)) << endl;
    cout << "Median age for males = " + to_string(ComputeMedianAge(part_point, persons.end())) << endl;
    auto part_point2 = partition(persons.begin(), part_point,
                                [](Person x){return x.is_employed;});
    auto part_point3 = partition(part_point, persons.end(),
                                 [](Person x){return x.is_employed;});
    cout << "Median age for employed females = " + to_string(ComputeMedianAge(persons.begin(), part_point2)) << endl;
    cout << "Median age for unemployed females = " + to_string(ComputeMedianAge(part_point2, part_point)) << endl;
    cout << "Median age for employed males = " + to_string(ComputeMedianAge(part_point, part_point3)) << endl;
    cout << "Median age for unemployed males = " + to_string(ComputeMedianAge(part_point3, persons.end())) << endl;
}
