#include <iterator>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int num, num2, count;
    string oper;
    deque<string> dec;
    cin >> num >> count;
    dec.push_back(to_string(num));

    for (int i = 0; i < count; ++i) {
        cin >> oper >> num2;

        dec.push_front("(");
        dec.push_back(")");

        dec.push_back(" " + oper + " ");
        dec.push_back(to_string(num2));
    }

    for (const auto& x: dec){
        cout << x;
    }
    return 0;
}
