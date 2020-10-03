#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void PrintAll(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    string str;
    while(getline(input, str)){
        output << str << endl;
    }
}

int main() {
    PrintAll();
    return 0;
}
