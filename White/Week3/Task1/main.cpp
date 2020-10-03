#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(const vector<int>& vec){
    for(const auto& i: vec){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    vector<int> vec(num);

    for(auto& i: vec){
        cin >> i;
    }

    sort(begin(vec), end(vec), [](int i, int j) {return abs(i) < abs(j);});
    print_vector(vec);
    return 0;
}
