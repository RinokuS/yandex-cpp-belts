

#include "database.h"

void Database::Add(const Date &date, const string &event) {
    if (!help_map.count(event) || !help_map[event].count(date)) {
        data_base[date].push_back(event);
        help_map[event].insert(date);
    }
}

vector<databasePairType> Database::FindIf(const predicateType& predicate) const {
    vector<databasePairType> entries;

    for (const auto &item: data_base) {
        for (const auto &event: item.second) {
            if (predicate(item.first, event)) {
                entries.emplace_back(databasePairType(item.first, event));
            }
        }
    }

    return entries;
}

int Database::RemoveIf(const predicateType& predicate) {
    int deletedEvCount = 0;
    vector<string> helper;

    for (auto iter = data_base.begin(); iter != data_base.end();){
        for(const auto& event: iter->second){
            if (predicate(iter->first, event)){
                deletedEvCount++;

                help_map[event].erase(iter->first);

                if (help_map[event].empty()) {
                    help_map.erase(event);
                }
            }
        }

        auto eraseStart = remove_if(iter->second.begin(), iter->second.end(),
                [&](const string& event){return predicate(iter->first, event);});

        iter->second.erase(eraseStart, iter->second.end());

        if (iter->second.empty()){
            iter = data_base.erase(iter);
        } else{
            iter++;
        }
    }

    return deletedEvCount;
}

databasePairType Database::Last(const Date &date) const {
    auto iter = data_base.upper_bound(date);

    if (iter != data_base.begin()) {
        iter = prev(iter);
        return make_pair(iter->first, iter->second.back());
    } else {
        throw invalid_argument("There is no last element in database :(");
    }
}

void Database::Print(ostream& os) const {
    for(const auto& [key, value]: data_base){
        for(const auto& event: value){
            os << key << ' ' << event << endl;
        }
    }
}

ostream &operator<<(ostream &os, const databasePairType& pair) {
    os << pair.first << ' ' << pair.second;
    return os;
}
