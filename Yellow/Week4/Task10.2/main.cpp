#include <iterator>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        const string& prefix){
    auto lb = lower_bound(range_begin, range_end, prefix);
    auto ub = upper_bound(range_begin, range_end, prefix);

    while (ub != range_end && string((*ub).begin(), (*ub).begin() + prefix.size()) == prefix){
        ub++;
    }

    if (lb == ub){
        if (lb == range_begin){
            return make_pair(range_begin, range_begin);
        } else{
            return make_pair(lb, lb);
        }
    } else{
        return make_pair(lb, ub);
    }
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
