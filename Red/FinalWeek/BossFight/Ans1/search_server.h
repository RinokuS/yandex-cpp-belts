#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

class InvertedIndex {
public:
    InvertedIndex() = default;

    explicit InvertedIndex(std::istream& document_input);
    const vector<pair<size_t, size_t>>& Lookup(const string& word) const;

    size_t GetDocsCount() const
    {
        return docs_count;
    }

private:
    unordered_map<string, vector<pair<size_t,size_t>>> index;
    size_t docs_count = 0;
};

class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
  InvertedIndex index;
};
