#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if (range_end - range_begin < 3){
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    int middle = (range_end - range_begin) / 3;

    MergeSort(elements.begin(), elements.begin() + middle);
    MergeSort(elements.begin() + middle, elements.begin() + middle + middle);
    MergeSort(elements.begin() + middle + middle, elements.end());

    vector<typename RandomIt::value_type> helper;

    merge(elements.begin(), elements.begin() + middle, elements.begin() + middle,
            elements.begin() + middle + middle, back_inserter(helper));
    merge(helper.begin(), helper.end(), elements.begin() + middle + middle, elements.end(), range_begin);
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
