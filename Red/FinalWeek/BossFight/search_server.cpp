#include "search_server.h"
#include "iterator_range.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

vector<string> SplitIntoWords(const string& line) {
    istringstream words_input(line);
    return {make_move_iterator(istream_iterator<string>(words_input)),
            make_move_iterator(istream_iterator<string>())};
}

SearchServer::SearchServer(istream& document_input) {
    UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {

    InvertedIndex new_index(document_input);
    swap(index, new_index);
}

void SearchServer::AddQueriesStream(
        istream& query_input, ostream& search_results_output
) {
    vector<size_t> ids_to_count;
    vector<int64_t> ids;

    for (string current_query; getline(query_input, current_query); ) {
        const auto words = SplitIntoWords(current_query);

        const size_t docs_count = index.GetDocsCount();
        ids_to_count.assign(docs_count, 0);
        ids.resize(docs_count);

        for (const auto& word : words)
        {
            for (const auto& [doc_id, hit_count] : index.Lookup(word))
            {
                ids_to_count[doc_id] += hit_count;
            }
        }

        iota(ids.begin(), ids.end(), 0);

        partial_sort(begin(ids), Head(ids, 5).end(), end(ids),
                          [&ids_to_count](int64_t lhs, int64_t rhs)
                          {
                              return pair(ids_to_count[lhs], -lhs) > pair(ids_to_count[rhs], -rhs);
                          });

        search_results_output << current_query << ':';

        for (size_t doc_id : Head(ids, 5))
        {
            const size_t hit_count = ids_to_count[doc_id];
            if (hit_count == 0)
            {
                break;
            }

            search_results_output << " {" << "docid: " << doc_id << ", " << "hitcount: " << hit_count << '}';
        }

        search_results_output << '\n';
    }
}

InvertedIndex::InvertedIndex(istream& document_input)
{
    index.reserve(15000);

    string line;
    while(std::getline(document_input, line))
    {
        ++docs_count;
        size_t id = docs_count - 1;

        for (const std::string& word : SplitIntoWords(line))
        {
            auto& id_to_count = index[word];
            if (!id_to_count.empty() && id_to_count.back().first == id) {
                ++id_to_count.back().second;
            }else {
                id_to_count.emplace_back(id, 1);
            }
        }
    }
}

const vector<pair<size_t, size_t>>& InvertedIndex::Lookup(const string& word) const
{
    static const vector<pair<size_t, size_t>> result;
    if (const auto it = index.find(word); it != index.end())
    {
        return it->second;
    }
    return result;
}
