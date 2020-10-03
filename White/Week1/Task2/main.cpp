#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a, b, c;
    vector<string> vec;

    cin >> a >> b >> c;

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);

    cout << *min_element(vec.begin(), vec.end());
    return 0;
}
