#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

void Read(map<set<string>, int>& ourMap, int& helper){
    int count;
    cin >> count;
    set<string> set_;

    for (int i = 0; i < count; ++i) {
        string elem;
        cin >> elem;
        set_.insert(elem);
    }

    if (ourMap.count(set_) == 0){
        ourMap[set_] = helper++;
        cout << "New bus " << ourMap[set_] << endl;
    } else{
        cout << "Already exists for " << ourMap[set_] << endl;
    }
}

int main() {
    int count, helper;
    map<set<string>, int> ourMap;
    cin >> count;
    helper = 1;

    for (int i = 0; i < count; ++i) {
        Read(ourMap, helper);
    }
    return 0;
}
