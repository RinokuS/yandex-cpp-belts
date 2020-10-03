#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student{
    string name, surname;
    string birth_day, birth_month, birth_year;

    string FullName() const{
        return name + ' ' + surname;
    }

    string BirthDate() const{
        return birth_day + '.' + birth_month + '.' + birth_year;
    }
};

void ReadStudents(vector<Student>& students){
    for(Student& student: students){
        string name, surname;
        string day, month, year;
        cin >> name >> surname >> day >> month >> year;
        student = {name, surname, day, month, year};
    }
}

void Commander(const string& command, const int& number, const vector<Student>& students){
    if (number <= students.size() && number > 0){
        if (command == "name"){
            cout << students[number-1].FullName() << endl;
        } else if(command == "date"){
            cout << students[number-1].BirthDate() << endl;
        } else{
            cout << "bad request" << endl;
        }
    } else{
        cout << "bad request" << endl;
    }
}

void ReadCommands(const vector<Student>& students, const int& m){
    for (int i = 0; i < m; ++i) {
        string command;
        int number;
        cin >> command >> number;

        Commander(command, number, students);
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<Student> students(n);
    ReadStudents(students);

    cin >> m;
    ReadCommands(students, m);

    return 0;
}
