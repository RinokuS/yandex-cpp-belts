#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> vec;

    auto begin = s.begin();
    auto end = find(s.begin(), s.end(), ' ');

    while (begin != s.end()){
        vec.push_back(string(begin, end));
        if (end != s.end())
            end++;
        begin = end;
        end = find(end, s.end(), ' ');
    }

    return vec;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
