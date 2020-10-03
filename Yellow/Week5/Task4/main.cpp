#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Humanoid{
public:
    Humanoid(const string& name) : name(name){
    }

    virtual void Walk(const string& destination) const = 0;

    virtual string Checked() const = 0;

    virtual string Log() const = 0;

protected:
    const string name;
};

class Student : public Humanoid {
public:

    Student(const string& name, const string& favouriteSong) : Humanoid(name),
    FavouriteSong(favouriteSong) {
    }

    void Learn() const {
        cout << Log() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << Log() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << Log() << " sings a song: " << FavouriteSong << endl;
    }

    string Log() const override {
        return "Student: " + name;
    }

    string Checked() const override {
        return " checks Student. Student's name is: " + name;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Humanoid {
public:

    Teacher(const string& name, const string& subject) : Humanoid(name), Subject(subject) {
    }

    void Teach() const {
        cout << Log() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << Log() << " walks to: " << destination << endl;
    }

    string Log() const override {
        return "Teacher: " + name;
    }

    string Checked() const override {
        return " checks Teacher. Teacher's name is: " + name;
    }

private:
    const string Subject;
};


class Policeman : public Humanoid {
public:
    Policeman(const string& name) : Humanoid(name) {
    }

    void Check(Humanoid& h) {
        cout << Log() << h.Checked() << endl;
    }

    void Walk(const string& destination) const override {
        cout << Log() << " walks to: " << destination << endl;
    }

    string Log() const override {
        return "Policeman: " + name;
    }

    string Checked() const override {
        return " checks Policeman. Policeman's name is: " + name;
    }
};

void VisitPlaces(Humanoid& h, const vector<string>& places) {
    for (const auto& p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
