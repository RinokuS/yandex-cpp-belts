#include <iostream>
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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
