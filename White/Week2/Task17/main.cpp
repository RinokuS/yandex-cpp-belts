#include <iostream>
#include <set>
#include <map>
using namespace std;

void read_command(map<string, set<string>>& syn_map){
    string command;
    cin >> command;

    if (command == "ADD"){
        string word1, word2;
        cin >> word1 >> word2;
        syn_map[word1].insert(word2);
        syn_map[word2].insert(word1);
    } else if (command == "COUNT"){
        string word;
        cin >> word;
        cout << syn_map[word].size() << endl;
    } else{
        string word1, word2;
        cin >> word1 >> word2;
        if (syn_map[word1].count(word2) != 0 || syn_map[word2].count(word1) != 0){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}

int main() {
    int comm_count;
    map<string, set<string>> syn_map;
    cin >> comm_count;

    for (int i = 0; i < comm_count; ++i) {
        read_command(syn_map);
    }
    return 0;
}
