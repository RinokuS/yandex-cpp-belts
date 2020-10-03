#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
    for (int i = 0; i < v.size() / 2; ++i) {
        int helper = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = helper;
    }
}

int main() {
    //vector<int> v = {1, 2, 3, 4, 5, 6};
    //Reverse(v);
    //for(auto x : v)
        //cout << x << " ";
    return 0;
}
