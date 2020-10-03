#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <set>
#include <vector>
#include <future>
#include <functional>

using namespace std;

template <typename Iterator>
class IteratorRange{
private:
    Iterator first, last;
    size_t page_size;
public:
    IteratorRange(Iterator f, Iterator l, size_t size) : first(f), last(l), page_size(size){}

    Iterator begin() const{
        return first;
    }

    Iterator end() const{
        return last;
    }

    size_t size() const{
        return page_size;
    }
};

template <typename Iterator>
class Paginator {
private:
    vector<IteratorRange<Iterator>> vec;
    size_t pages;
public:
    Paginator(const Iterator &begin, const Iterator &end, const size_t &page_size) : pages(0){
        auto page_start = begin;
        while (end - page_start >= page_size) {
            vec.push_back(IteratorRange(page_start, page_start + page_size, page_size));
            page_start = page_start + page_size;
            pages++;
        }
        if (end > page_start) {
            vec.push_back(IteratorRange(page_start, end, end - page_start));
            pages++;
        }
    }

    auto begin() const{
        return vec.begin();
    }

    auto end() const{
        return vec.end();
    }

    size_t size() const{
        return pages;
    }
};

template <typename C>
auto Paginate(C& c, const size_t &page_size) {
    Paginator paginator(c.begin(), c.end(), page_size);

    return paginator;
}


struct Stats {
    map<string, int> word_frequences;

    void operator +=(const Stats& other){
        for (const auto& pair_ : other.word_frequences)
        {
            word_frequences[pair_.first] += pair_.second;
        }
    }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
    string_view view = line;
    Stats result;

    size_t pos = view.find_first_not_of(' ');
    view.remove_prefix(pos);

    while (pos != string_view::npos)
    {
        pos = view.find_first_of(' ');

        auto key = std::string(view.substr(0, pos));

        if (key_words.count(key) > 0)
        {
            ++result.word_frequences[std::move(key)];
        }

        if (pos == string_view::npos)
            break;

        view.remove_prefix(pos);
        pos = view.find_first_not_of(' ');
        view.remove_prefix(pos);
    }

    return result;
}

Stats ExploreKeyWordsSingleThread(
        const set<string>& key_words, istream& input
) {
    Stats result;
    for (string line; getline(input, line); ) {
        result += ExploreLine(key_words, line);
    }
    return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
    Stats result;
    vector<future<Stats>> futures;
    size_t num_lines = 0;
    const auto threads_count = thread::hardware_concurrency();
    vector<stringstream> streams(threads_count);

    string line;

    while (getline(input, line))
    {
        streams[num_lines % threads_count] << line << '\n';
        ++num_lines;
    }

    futures.reserve(streams.size());

    for(auto& stream: streams){
        futures.push_back(
                async(ExploreKeyWordsSingleThread, ref(key_words), ref(stream))
                );
    }

    for (auto& fu: futures){
        result += fu.get();
    }

    return result;
}

void TestBasic() {
    const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

    stringstream ss;
    ss << "this new yangle service really rocks\n";
    ss << "It sucks when yangle isn't available\n";
    ss << "10 reasons why yangle is the best IT company\n";
    ss << "yangle rocks others suck\n";
    ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

    const auto stats = ExploreKeyWords(key_words, ss);
    const map<string, int> expected = {
            {"yangle", 6},
            {"rocks", 2},
            {"sucks", 1}
    };
    ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestBasic);
}