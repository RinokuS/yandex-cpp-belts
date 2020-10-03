#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b;

    if (a >= b){
        c = a;
        d = b;
    } else{
        c = b;
        d = a;
    }

    while (c % d != 0){
        int help;
        help = d;
        d = c % d;
        c = help;
    }

    cout << d;
    return 0;
}
