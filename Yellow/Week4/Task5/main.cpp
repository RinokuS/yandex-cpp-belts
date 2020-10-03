#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    string str;
    cin >> num;
    for (int i = 1; i <= num; ++i) {
        str += to_string(i);
    }

    sort(str.rbegin(), str.rend());
    do{
        for(const auto& x: str){
            cout << x << ' ';
        }
        cout << endl;
    } while(prev_permutation(str.begin(), str.end()));
    return 0;
}
