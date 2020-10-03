#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include <set>
#include <utility>

using namespace std;

template<typename V> vector<V> operator*(const vector<V>& vec1, const vector<V>& vec2);
template <typename First, typename Second> pair<First, Second> operator*
        (const pair<First, Second>& p1, const pair<First, Second>& p2);
template <typename Key, typename Value> map<Key, Value> operator*
        (const map<Key, Value>& dict1, const map<Key, Value>& dict2);
template <typename T> T Sqr(T t);

template <typename V>
vector<V> operator*(const vector<V>& vec1, const vector<V>& vec2){
    vector<V> ans;
    for (int i = 0; i < vec1.size(); ++i) {
        ans.push_back(vec1[i] * vec2[i]);
    }

    return ans;
}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2){
    pair<First, Second> ans;
    ans.first = p2.first * p1.first;
    ans.second = p1.second * p2.second;

    return ans;
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& dict1, const map<Key, Value>& dict2){
    map<Key, Value> ans;
    for(const auto& [key, value]: dict1){
        ans[key] = dict1.at(key) * dict2.at(key);
    }

    return ans;
}


template <typename T>
T Sqr(T t){
    return t * t;
}

int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
