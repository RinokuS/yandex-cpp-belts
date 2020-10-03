#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int GCD(const int& num, const int& den){
    int n, m, helper;
    if (num > den){
        n = num;
        m = den;
    } else if (num < den){
        n = den;
        m = num;
    } else{
        return num;
    }

    while (m != 0){
        helper = m;
        m = n % m;
        n = helper;
    }

    return n;
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator != 0){
            PosOrNeg(numerator, denominator);
            int gcd = GCD(abs(numerator), abs(denominator));

            this->numerator = numerator / gcd;
            this->denominator = denominator / gcd;
        } else{
            this->numerator = 0;
            this->denominator = 1;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator, denominator;

    void PosOrNeg(int& num, int& den) const{
        if ((num > 0 && den < 0) || (num < 0 && den < 0)){
            num = -num;
            den = -den;
        }
    }
};

bool operator==(const Rational& rat1, const Rational& rat2){
    double helper1 = rat1.Numerator() * 1.0;
    double helper2 = rat2.Numerator() * 1.0;

    return helper1 / rat1.Denominator() == helper2 / rat2.Denominator();
}

bool operator<(const Rational& rat1, const Rational& rat2){
    double helper1 = rat1.Numerator() * 1.0;
    double helper2 = rat2.Numerator() * 1.0;

    return helper1 / rat1.Denominator() < helper2 / rat2.Denominator();
}

Rational operator+(const Rational& rat1, const Rational& rat2){
    int nok = rat1.Denominator() * rat2.Denominator() / GCD(rat1.Denominator(), rat2.Denominator());
    return Rational(rat1.Numerator() * (nok / rat1.Denominator()) +
                    rat2.Numerator() * (nok / rat2.Denominator()), nok);
}

Rational operator-(const Rational& rat1, const Rational& rat2){
    int nok = rat1.Denominator() * rat2.Denominator() / GCD(rat1.Denominator(), rat2.Denominator());
    return Rational(rat1.Numerator() * (nok / rat1.Denominator()) -
                    rat2.Numerator() * (nok / rat2.Denominator()), nok);
}

Rational operator*(const Rational& rat1, const Rational& rat2){
    return Rational(rat1.Numerator() * rat2.Numerator(),
                    rat1.Denominator() * rat2.Denominator());
}

Rational operator/(const Rational& rat1, const Rational& rat2){
    return Rational(rat1.Numerator() * rat2.Denominator(),
                    rat1.Denominator() * rat2.Numerator());
}

istream& operator>>(istream& stream, Rational& rat){
    int n = rat.Numerator(), d = rat.Denominator();
    stream >> n;
    stream.ignore(1);
    stream >> d;
    rat = Rational(n, d);

    return stream;
}

ostream& operator<<(ostream& stream, const Rational& rat){
    stream << rat.Numerator() << '/' << rat.Denominator();

    return stream;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
