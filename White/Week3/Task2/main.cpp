#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(const vector<string>& vec){
    for(const auto& i: vec){
        cout << i << " ";
    }
    cout << endl;
}

string to_lower(const string& x){
    string new_x;
    for (const auto& i: x)
        new_x += tolower(i);

    return new_x;
}

int main() {
    int num;
    cin >> num;
    vector<string> vec(num);

    for(auto& i: vec){
        cin >> i;
    }

    sort(begin(vec), end(vec), [](string i, string j) {
        string new_i = to_lower(i);
        string new_j = to_lower(j);

        return new_i < new_j;
    });
    print_vector(vec);
    return 0;
}
