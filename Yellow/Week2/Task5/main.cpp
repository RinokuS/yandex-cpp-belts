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

bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void TestPol(){
    Assert(IsPalindrom(""), "Empty string");
    Assert(IsPalindrom("a"), "One-symbol string");
    Assert(IsPalindrom("gg"), "Two-symbols string");
    Assert(IsPalindrom("kek"), "Simple palindrom");
    Assert(IsPalindrom("wasitacaroracatisaw"), "Hard palindrom");
    Assert(IsPalindrom("k k"), "Pal spaces");
}

void TestNotPol(){
    Assert(!IsPalindrom("ab"), "Simple not pal");
    Assert(!IsPalindrom("abc"), "Simple not pal x2");
    Assert(!IsPalindrom("abbc"), "Simple not pal x3");
    Assert(!IsPalindrom("Madam"), "Simple not pal x4");
    Assert(!IsPalindrom("wasitacarolacatisaw"), "Hard not pal");
    Assert(!IsPalindrom("zasitacaroracatisaw"), "Hard not pal x2");
    Assert(!IsPalindrom("awasitacaroracatisaw"), "Hard not pal x3");
    Assert(!IsPalindrom("wasitacaroracatisawa"), "Hard not pal x4");
    Assert(!IsPalindrom("wasitaca oracatisaw"), "Not pal spaces");
    Assert(!IsPalindrom(" woow  "), "Not pal spaces x2");
    Assert(!IsPalindrom("L  O L"), "Not pal spaces x2");

}

void TestAll(){
    TestRunner runner;

    runner.RunTest(TestPol, "TestPol");
    runner.RunTest(TestNotPol, "TestNotPol");
}

int main() {
    TestAll();
    // добавьте сюда свои тесты
    return 0;
}
