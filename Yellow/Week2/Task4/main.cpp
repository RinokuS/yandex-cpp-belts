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

void TestConstructor(){
    {
        Rational rat;

        Assert(rat.Numerator() == 0, "Empty num");
        Assert(rat.Denominator() == 1, "Empty den");
    }

    {
        Rational rat(2, 6);

        Assert(rat.Numerator() == 1, "Auto editing num");
        Assert(rat.Denominator() == 3, "Auto editing den");
    }

    {
        Rational rat(-2, 6);
        Rational rat2(2, -6);

        Assert(rat.Numerator() == -1 && rat2.Numerator() == -1, "Auto sign num");
        Assert(rat.Denominator() == 3 && rat2.Denominator() == 3, "Auto sign den");
    }

    {
        Rational rat(-12, -6);
        Rational rat2(12, 6);

        Assert(rat.Numerator() == 2 && rat2.Numerator() == 2, "Delete sign num");
        Assert(rat.Denominator() == 1 && rat2.Denominator() == 1, "Delete sign den");
    }

    {
        Rational rat(0, 155);

        Assert(rat.Numerator() == 0 && rat.Denominator() == 1, "Zero num");
    }
}

void TestAll(){
    TestRunner runner;

    runner.RunTest(TestConstructor, "TestConstructor");
}

int main() {
    TestAll();
    // добавьте сюда свои тесты
    return 0;
}
