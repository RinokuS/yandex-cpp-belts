#include <iostream>
#include <sstream>
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
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
