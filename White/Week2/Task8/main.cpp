#include <iostream>
#include <vector>
using namespace std;

vector<int> ReadTemp(){
    int num;
    cin >> num;
    vector<int> v(num);

    for(auto& x: v){
        cin >> x;
    }
    return v;
}

int AverageTemp(vector<int> vec){
    int x = 0;
    for (auto i : vec){
        x += i;
    }
    
    return x / vec.size();
}

void Temperature(){
    vector<int> days = ReadTemp();
    vector<int> goodDays;
    int averageTemp = AverageTemp(days);
    int count = 0;

    for (int i = 0; i < days.size(); ++i) {
        if (days[i] > averageTemp){
            goodDays.push_back(i);
            count++;
        }
    }

    cout << count << endl;
    for(auto x: goodDays)
        cout << x << " ";
}

int main() {
    Temperature();
    return 0;
}
