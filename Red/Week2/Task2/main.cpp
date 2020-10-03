#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <sstream>

#include "profile.h"

using namespace std;

class Learner {
private:
    set<string> dict;

public:
    int Learn(const vector<string>& words) {
        int newWords = 0;
        for (const auto& word : words) {
            size_t last_size = dict.size();
            dict.insert(word);

            if (last_size < dict.size())
                newWords++;
        }
        return newWords;
    }

    vector<string> KnownWords() {
        vector<string> helper(dict.begin(), dict.end());

        return helper;
    }
};
