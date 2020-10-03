#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void CommandReader(vector<vector<string>>& toDoList, int& currentMonth){
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string command;
    cin >> command;

    if (command == "NEXT"){
        currentMonth++;
        if (months[currentMonth % 12] < months[(currentMonth - 1) % 12]){
            for (int i = months[currentMonth % 12]; i < months[(currentMonth - 1) % 12]; ++i) {
                toDoList[months[currentMonth % 12] - 1].insert(end(toDoList[months[currentMonth % 12] - 1]),
                                                               begin(toDoList[i]), end(toDoList[i])); // добавление всех дел с лишних дней на последний.
            }
            toDoList.resize(months[currentMonth % 12]);
        } else{
            toDoList.resize(months[currentMonth % 12]);
        }
    } else{
        int day;
        cin >> day;
        if (command == "ADD"){
            string work;
            cin >> work;

            toDoList[day - 1].push_back(work);
        } else{
            cout << toDoList[day - 1].size() << " ";
            for (auto x: toDoList[day - 1])
                cout << x << " ";
            cout << endl;
        }
    }
}

int main() {
    int commCount;
    vector<vector<string>> toDoList(31, vector<string>(0));
    cin >> commCount;
    int currentMonth = 0;

    for (int i = 0; i < commCount; ++i) {
        CommandReader(toDoList, currentMonth);
    }
    return 0;
}