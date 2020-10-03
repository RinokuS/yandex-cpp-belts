#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2){
        return;
    }
    size_t part_len = (range_end - range_begin) / 3;
    vector<typename RandomIt::value_type> vec(make_move_iterator(range_begin),
            make_move_iterator(range_end));

    MergeSort(move(vec.begin()), move(vec.begin() + part_len));
    MergeSort(move(vec.begin() + part_len), move(vec.begin() + 2*part_len));
    MergeSort(move(vec.begin() + 2*part_len), move(vec.end()));
    vector<typename RandomIt::value_type> tmp;

    merge(make_move_iterator(vec.begin()), make_move_iterator(vec.begin() + part_len),
          make_move_iterator(vec.begin() + part_len), make_move_iterator(vec.begin() + 2*part_len),
          back_inserter(tmp));

    merge(make_move_iterator(tmp.begin()), make_move_iterator(tmp.end()),
            make_move_iterator(vec.begin() + 2*part_len), make_move_iterator(vec.end()),
            range_begin);
}

void TestIntVector() {
    vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
    MergeSort(begin(numbers), end(numbers));
    ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestIntVector);
    return 0;
}