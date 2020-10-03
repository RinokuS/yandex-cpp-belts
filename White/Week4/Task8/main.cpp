#include <iostream>
using namespace std;

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

    int GCD(const int& num, const int& den) const{
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
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}