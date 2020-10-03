#include "stats.h"
#include <string>

Stats::Stats() {
    for(const auto& item: meths){
        methods_to_requests[item] = 0;
    }
    methods_to_requests["UNKNOWN"] = 0;
    for(const auto& item: uris){
        uri_to_requests[item] = 0;
    }
    uri_to_requests["unknown"] = 0;
}

void Stats::AddMethod(string_view method) {
    if (meths.count(method)){
        methods_to_requests[method]++;
    } else{
        methods_to_requests["UNKNOWN"]++;
    }
}

void Stats::AddUri(string_view uri) {
    if (uris.count(uri)){
        uri_to_requests[uri]++;
    } else{
        uri_to_requests["unknown"]++;
    }
}

const map<string_view, int> & Stats::GetMethodStats() const {
    return methods_to_requests;
}

const map<string_view, int> & Stats::GetUriStats() const {
    return uri_to_requests;
}

vector<string_view> SplitRequest(string_view line){
    vector<string_view> result;

    while(line[0] == ' '){
        line.remove_prefix(1);
    }

    while(true){
        size_t space = line.find(' ');
        result.push_back(line.substr(0, space));

        if (space == line.npos){
            break;
        } else{
            line.remove_prefix(space + 1);
        }
    }

    return result;
}

HttpRequest ParseRequest(string_view line){
    HttpRequest request;
    vector<string_view> parsed_request = SplitRequest(line);

    request.method = parsed_request[0];
    request.uri = parsed_request[1];
    request.protocol = parsed_request[2];

    return request;
}