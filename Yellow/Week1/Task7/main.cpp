#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include <set>
#include <utility>

using namespace std;

template <typename Key, typename Value> Value& GetRefStrict(map<Key, Value>& dict, Key key);

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& dict, Key key){
    if (dict.count(key) != 0){
        return dict[key];
    } else{
        throw runtime_error("Invalid key");
    }
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}
