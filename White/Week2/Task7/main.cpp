#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v){
    vector<int> x = v;
    for (int i = 0; i < x.size() / 2; ++i) {
        int helper = x[i];
        x[i] = x[x.size() - 1 - i];
        x[x.size() - 1 - i] = helper;
    }

    return x;
}

int main() {

    return 0;
}
