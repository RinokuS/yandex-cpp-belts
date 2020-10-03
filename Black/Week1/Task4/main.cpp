#include <iostream>
#include <cstdlib>

int main() {
    int64_t n, m;
    std::cin >> n >> m;
    bool is_sum_overflowed = false;

    if (n > 0 && m > 0){
        int64_t temp = INT64_MAX - n - m;
        is_sum_overflowed = temp < 0;
    } else if (n < 0 && m < 0){
        int64_t temp = INT64_MIN - n - m;
        is_sum_overflowed = temp > 0;
    }
    
    if (is_sum_overflowed){
        std::cout << "Overflow!";
    } else{
        std::cout << n + m;
    }
    return 0;
}
