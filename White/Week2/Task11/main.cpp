#include <iostream>
#include <map>
using namespace std;

void FillMap(const string& x, map<char, int>& mapX){
    for(const auto& i: x){
        ++mapX[i];
    }
}

string AnagramCheck(const string& a, const string& b){
    map<char, int> mapA;
    map<char, int> mapB;

    FillMap(a, mapA);
    FillMap(b, mapB);

    if (mapA.size() != mapB.size()){
        return "NO";
    }
    for(const auto& item: mapA){
        if (mapA[item.first] != mapB[item.first]){
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int count;
    cin >> count;

    for (int i = 0; i < count; ++i) {
        string a, b;
        cin >> a >> b;

        cout << AnagramCheck(a, b) << endl;
    }
    return 0;
}
