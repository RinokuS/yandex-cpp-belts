#include <iostream>
using namespace std;

bool IsPalindrom(string x){
    for (int i = 0; i <= x.length() / 2; ++i) {
        if (x[i] != x[x.length() - 1 - i])
            return false;
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    cout << IsPalindrom(str);
    return 0;
}
