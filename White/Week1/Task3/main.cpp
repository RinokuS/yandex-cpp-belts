#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;

    double D = B * B - 4 * A * C;

    if (A == 0){
        if (B != 0){
            cout << -C/B << endl;
        }
    } else if (D == 0){
        cout << -B/(2*A) << endl;
    } else if (D > 0){
        double x1, x2;
        x1 = (-B - sqrt(D))/(2*A);
        x2 = (-B + sqrt(D))/(2*A);

        cout << x1 << " " << x2 << endl;
    }

    return 0;
}


