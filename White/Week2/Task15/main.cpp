#include <iostream>
#include <set>
using namespace std;

int main() {
    int count;
    set<string> s;
    cin >> count;

    for (int i = 0; i < count; ++i) {
        string element;
        cin >> element;
        s.insert(element);
    }

    cout << s.size() << endl;
    return 0;
}
