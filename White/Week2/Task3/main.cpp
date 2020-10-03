#include <iostream>
#include <vector>
using namespace std;

bool IsPalindrom(string x){
    for (int i = 0; i <= x.length() / 2; ++i) {
        if (x[i] != x[x.length() - 1 - i])
            return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> ans;
    for(auto x : words){
        if (IsPalindrom(x) && x.length() >= minLength)
            ans.push_back(x);
    }

    return ans;
}

int main() {
    //for(auto x: PalindromFilter({"abacaba", "aba"}, 2))
    //    cout << x << endl;
    return 0;
}
