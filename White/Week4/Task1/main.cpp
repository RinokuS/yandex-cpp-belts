#include <iostream>
using namespace std;

struct Specialization{
    string value;

    explicit Specialization(const string& val){
        value = val;
    }
};

struct Course{
    string value;

    explicit Course(const string& val){
        value = val;
    }
};

struct Week{
    string value;

    explicit Week(const string& val){
        value = val;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization spec, Course cour, Week week){
        this->specialization = spec.value;
        this->course = cour.value;
        this->week = week.value;
    }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

    return 0;
}
