#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void PrintAll(){
    ifstream input("input.txt");
    string str;
    while(getline(input, str)){
        cout << str << endl;
    }
}

int main() {
    PrintAll();
    return 0;
}
