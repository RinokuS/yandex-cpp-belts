#include <iostream>
using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;

    if (n > b){
        n *= (100 - y) * 0.01;
    } else if (n > a){
        n *= (100 - x) * 0.01;
    }

    cout << n;
    return 0;
}
