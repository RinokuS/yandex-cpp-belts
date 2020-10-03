#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

void AllBuses(const map<string, vector<string>>& busesToStops){
    if (busesToStops.size() == 0){
        cout << "No buses" << endl;
    } else{
        for (const auto& [key, value]: busesToStops){
            cout << "Bus " << key << ":";
            for (const auto& x: value){
                cout << " " << x;
            }
            cout << endl;
        }
    }
}

void StopsForBus(map<string, vector<string>>& busesToStops, map<string, vector<string>>& stopsToBuses){
    string bus;
    cin >> bus;
    if (busesToStops.count(bus) == 0){
        cout << "No bus" << endl;
    } else{
        for (const auto& x: busesToStops[bus]){
            cout << "Stop " << x << ":";
            if (stopsToBuses[x].size() == 1) {
                cout << " no interchange" << endl;
            } else {
                for (const auto &y: stopsToBuses[x]) {
                    if (y != bus)
                        cout << " " << y;
                }
                cout << endl;
            }
        }
    }
}

void BusesForStop(map<string, vector<string>>& stopsToBuses){
    string stop;
    cin >> stop;
    if (stopsToBuses.count(stop) == 0){
        cout << "No stop" << endl;
    } else{
        for (const auto& x: stopsToBuses[stop]){
            cout << x << " ";
        }
        cout << endl;
    }
}

void NewBus(map<string, vector<string>>& busesToStops,map<string, vector<string>>& stopsToBuses){
    string bus;
    int stopCount;
    cin >> bus >> stopCount;
    vector<string> stops(stopCount);

    for(auto& x: stops) {
        cin >> x;
        stopsToBuses[x].push_back(bus); // заполняем словарь остановок с привязанными к ним списками автобусов
    }

    busesToStops[bus] = stops; // заполняем словарь автобусов с привязанными к ним списками станций
}

void CommandReader(map<string, vector<string>>& busesToStops,map<string, vector<string>>& stopsToBuses){
    string command;
    cin >> command;

    if (command == "ALL_BUSES"){
        AllBuses(busesToStops);
    } else if (command == "STOPS_FOR_BUS"){
        StopsForBus(busesToStops, stopsToBuses);
    } else if (command == "BUSES_FOR_STOP"){
        BusesForStop(stopsToBuses);
    } else{
        NewBus(busesToStops, stopsToBuses);
    }
}

int main() {
    int commCount;
    map<string, vector<string>> busesToStops, stopsToBuses;
    cin >> commCount;

    for (int i = 0; i < commCount; ++i) {
        CommandReader(busesToStops, stopsToBuses);
    }
    return 0;
}
