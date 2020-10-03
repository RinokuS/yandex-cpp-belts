#pragma once

#include "http_request.h"

#include <string_view>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Stats {
public:
    Stats();

    void AddMethod(string_view method);
    void AddUri(string_view uri);
    const map<string_view, int>& GetMethodStats() const;
    const map<string_view, int>& GetUriStats() const;

private:
    const set<string_view> meths = {"GET", "POST", "PUT", "DELETE"};
    const set<string_view> uris = {"/", "/order", "/product", "/basket", "/help"};
    map<string_view, int> methods_to_requests;
    map<string_view, int> uri_to_requests;
};

vector<string_view> SplitRequest(string_view line);

HttpRequest ParseRequest(string_view line);