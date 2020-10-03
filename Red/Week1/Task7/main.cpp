#include "test_runner.h"

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Table{
public:
    Table(const size_t &rows, const size_t &columns){
        Resize(rows, columns);
    }

    vector<T>& operator[](const size_t &index){
        return table[index];
    }
    const vector<T>& operator[](const size_t &index) const{
        return table[index];
    }

    void Resize(const size_t &rows, const size_t &columns){
        table.resize(rows);

        for(auto& row: table){
            row.resize(columns);
        }
    }

    pair<size_t, size_t> Size() const{
        if (!table.empty() && !table[0].empty())
            return make_pair(table.size(), (*table.begin()).size());
        return make_pair(0, 0);
    }

private:
    vector<vector<T>> table;
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}