#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Incognizable{
    int x = 0, y = 0;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};

    return 0;
}
