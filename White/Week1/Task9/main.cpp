#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> vec;
    cin >> n;

    while (n != 0 && n != 1){
        vec.push_back(n % 2);
        n /= 2;
    }

    cout << n;
    for (int i = vec.size() - 1; i >= 0 ; --i) {
        cout << vec[i];
    }
    return 0;
}
