#include "ini.h"

#include <sstream>

using namespace std;

namespace Ini{
    Section& Document::AddSection(string name) {
        return sections[move(name)];
    }

    const Section& Document::GetSection(const string &name) const {
        return sections.at(name);
    }

    size_t Document::SectionCount() const {
        return sections.size();
    }

    Document Load(istream& input){
        Document result;
        Section* lastAdded = nullptr;

        for(string line; getline(input, line);){
            if (line.empty())
                continue;
            stringstream ss(line);
            if(ss.peek() == '['){
                ss.ignore(1);
                string section;
                getline(ss, section, ']');
                lastAdded = &result.AddSection(section);
            } else{
                string key, value;
                getline(ss, key, '=');
                getline(ss, value);
                lastAdded->insert({key, value});
            }
        }

        return result;
    }
}
