#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void PrintAll(){
    ifstream input("input.txt");
    double num;

    cout << fixed << setprecision(3);
    while(input >> num){
        cout << num << endl;
    }
}

int main() {
    PrintAll();
    return 0;
}
