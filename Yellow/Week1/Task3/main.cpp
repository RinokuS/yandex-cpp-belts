#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    uint64_t count, R;
    uint64_t mass = 0;
    cin >> count >> R;

    for (uint64_t i = 0; i < count; ++i) {
        uint64_t W, H, D;
        cin >> W >> H >> D;

        mass += R * W * H * D;
    }

    cout << mass;
    return 0;
}
