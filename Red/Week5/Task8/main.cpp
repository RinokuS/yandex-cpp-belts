#include "test_runner.h"
#include <vector>
#include <future>
#include <algorithm>
#include <numeric>
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

template<typename Container>
int64_t SimpleSum(const Container& matrix)
{
    int64_t result = 0;

    for (const auto& line : matrix)
    {
        result += accumulate(line.begin(), line.end(), 0);
    }

    return result;
}

int64_t CalculateMatrixSum(const vector<vector<int>>& matrix) {
    int64_t result = 0;

    vector<future<int64_t>> futures;
    futures.reserve(4);

    for(auto page: Paginate(matrix, matrix.size() / 4 + matrix.size() % 4 )){
        futures.push_back(async([=]{
            return SimpleSum(page);
        }));
    }

    for(auto& fu: futures){
        result += fu.get();
    }

    return result;
}

void TestCalculateMatrixSum() {
    const vector<vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };
    ASSERT_EQUAL(CalculateMatrixSum(matrix), 136);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestCalculateMatrixSum);
}