#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, sp, place;
    list<int> all;
    vector<list<int>::iterator> vec(100000, all.end());

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> sp >> place;

        vec[sp] = all.insert(vec[place], sp);
    }

    for(const auto& x: all){
        cout << x << '\n';
    }
}
