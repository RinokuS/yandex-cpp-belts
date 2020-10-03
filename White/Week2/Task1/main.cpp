#include <iostream>
using namespace std;

int Factorial(int a){
    int fac = 1;
    if (a <= 1)
        return 1;

    while(a != 0){
        fac *= a;
        a--;
    }

    return fac;
}

int main() {
    int a;
    cin >> a;

    cout << Factorial(a);
    return 0;
}

