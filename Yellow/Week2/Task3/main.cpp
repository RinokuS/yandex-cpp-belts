#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};


void TestIncognito(){
    {
        Person person;

        person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1967, "Sergeeva");

        Assert(person.GetFullName(1900) == "Incognito", "Incognito x1");
    }

    {
        Person person;

        person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1965, "Sergeeva");

        Assert(person.GetFullName(1964) == "Incognito", "Incognito x2");
    }

    {
        Person person;

        Assert(person.GetFullName(1964) == "Incognito", "Incognito x3");
    }
}

void TestUnknownFName(){
    {
        Person person;

        person.ChangeFirstName(1967, "Polina");
        person.ChangeLastName(1965, "Sergeeva");

        Assert(person.GetFullName(1966) == "Sergeeva with unknown first name", "UnknownF x1");
    }

    {
        Person person;

        person.ChangeLastName(1965, "Sergeeva");

        Assert(person.GetFullName(1965) == "Sergeeva with unknown first name", "UnknownF x1");
    }
}

void TestUnknownSName(){
    {
        Person person;

        person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1967, "Sergeeva");

        Assert(person.GetFullName(1966) == "Polina with unknown last name", "UnknownS x1");
    }

    {
        Person person;

        person.ChangeFirstName(1965, "Polina");

        Assert(person.GetFullName(1966) == "Polina with unknown last name", "UnknownS x2");
    }
}

void TestFullName(){
    {
        Person person;

        person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1967, "Sergeeva");

        Assert(person.GetFullName(1967) == "Polina Sergeeva", "Full x1");
    }

    {
        Person person;

        person.ChangeFirstName(1965, "Polina");
        person.ChangeLastName(1967, "Sergeeva");

        Assert(person.GetFullName(1975) == "Polina Sergeeva", "Full x2");
    }
}

void TestAll(){
    TestRunner runner;

    runner.RunTest(TestIncognito, "TestIncognito");
    runner.RunTest(TestUnknownSName, "TestUnknownSName");
    runner.RunTest(TestUnknownFName, "TestUnknownFName");
    runner.RunTest(TestFullName, "TestFullName");
}

int main() {
    TestAll();

    return 0;
}


