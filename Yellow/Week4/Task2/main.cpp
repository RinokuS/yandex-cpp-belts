#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
    auto elem = find_if(elements.begin(), elements.end(), [border](T x){return x > border;});
    vector<T> vec;

    for(auto x = elem; x != elements.end(); x++){
        vec.push_back(*x);
    }

    sort(vec.begin(), vec.end());
    return vec;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
