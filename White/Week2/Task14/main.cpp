#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

void Read(map<vector<string>, int>& ourMap, int& helper){
    int count;
    cin >> count;
    vector<string> vec(count);

    for(auto& x: vec){
        cin >> x;
    }

    if (ourMap.count(vec) == 0){
        ourMap[vec] = helper++;
        cout << "New bus " << ourMap[vec] << endl;
    } else{
        cout << "Already exists for " << ourMap[vec] << endl;
    }
}

int main() {
    int count, helper;
    map<vector<string>, int> ourMap;
    cin >> count;
    helper = 1;

    for (int i = 0; i < count; ++i) {
        Read(ourMap, helper);
    }
    return 0;
}
