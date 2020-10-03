#include <iostream>
#include <string>
#include <vector>
#include<sstream>

using namespace std;

class Person;
class Student;
class Teacher;
class Policeman;
void VisitPlaces(const Person& person, const vector<string>& places);


class Person { // base abstract class
public:
    Person(const string& PersonName) : Name(PersonName) {}

    virtual string Type() const = 0; // abstract method return person's occupation

    string Introduce() const { // print occupation and person's name to string
        ostringstream os;
        os << Type() << ": " << Name;
        return os.str();
    }

    virtual void Walk(const string& destination) const { // print information about the movement of a person
        cout << Introduce() << " walks to: " << destination << endl;
    }
    string getName() const { return Name; }

protected:
    const string Name;
};


class Student : public Person {
public:

    Student(const string& StudentName, const string& favouriteSong) : Person(StudentName), FavouriteSong(favouriteSong) {}

    string Type() const override {
        return "Student";
    }

    void Learn() const {
        cout << Introduce() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << Introduce() << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};

class Teacher : public Person {
public:

    Teacher(const string& teacherName, const string& subject) : Person(teacherName), Subject(subject) {}

    string Type() const override {
        return "Teacher";
    }

    void Teach() const {
        cout << Introduce() << " teaches: " << Subject << endl;
    }

public:
    const string Subject;
};

class Policeman : public Person {
public:
    Policeman(const string& policemanName) : Person(policemanName) {}

    string Type() const override {
        return "Policeman";
    }

    void Check(const Person& person) const {
        cout << Introduce() << " checks " << person.Type() << ". "
             << person.Type() << "'s name is: " << person.getName() << endl;
    }
};

void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& place : places) {
        person.Walk(place);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "Queen: We will rock you");
    Student s_1("John", "Powerwolf: Army of the night");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    VisitPlaces(s_1, { "Moscow", "Warsaw", "York", "New York" });
    return 0;
}