#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void PrintRow(const int& m, ifstream& input){
    int number;
    for (int i = 0; i < m; ++i) {
        input >> number;
        input.ignore(1);

        cout << setw(10) << number;
        if (i != m-1)
            cout << ' ';
    }
}

void ReadAll(){
    ifstream input("input.txt");
    int n, m;
    input >> n >> m;

    for (int i = 0; i < n; ++i) {
        PrintRow(m, input);

        if (i != n-1)
            cout << endl;
    }
}

int main() {
    ReadAll();
    return 0;
}
