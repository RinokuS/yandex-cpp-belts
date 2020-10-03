#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int WorryCounter(const vector<bool>& vec){
    int counter = 0;
    for(auto x: vec) {
        if (x) {
            counter++;
        }
    }

    return counter;
}

void CommandReader(vector<bool>& vec){
    string command;
    cin >> command;
    if (command == "WORRY_COUNT"){
        cout << WorryCounter(vec) << endl;
    } else{
        int number;
        cin >> number;
        if (command == "WORRY")
            vec[number] = true;
        else if (command == "QUIET")
            vec[number] = false;
        else{
            vec.resize(vec.size() + number);
        }
    }
}

int main() {
    int comCount;
    vector<bool> vec(0, false);
    cin >> comCount;

    for (int i = 0; i < comCount; ++i) {
        CommandReader(vec);
    }
    return 0;
}
