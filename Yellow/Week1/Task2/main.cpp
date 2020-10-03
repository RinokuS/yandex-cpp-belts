#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    int64_t count, aver = 0;
    cin >> count;
    vector<int64_t> vec(count);

    for(auto& i: vec){
        cin >> i;
        aver += i;
    }
    aver /= static_cast<int64_t>(vec.size());
    count = 0;

    for(const auto& i: vec){
        if (i > aver)
            count++;
    }
    cout << count << endl;

    for (int j = 0; j < vec.size(); ++j) {
        if (vec[j] > aver){
            cout << j << " ";
        }
    }
    return 0;
}
