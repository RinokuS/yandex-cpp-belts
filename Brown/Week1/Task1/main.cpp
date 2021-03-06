#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class PriorityCollection {
public:
    using Id = int;

    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object){
        Id id = objects.size();

        objects.push_back(Node{0, move(object)});
        sorted_nodes.insert(make_pair(0, id));

        return id;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end,
             IdOutputIt ids_begin){
        while (range_begin != range_end)
        {
            *ids_begin++ = Add(std::move(*range_begin++));
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const{
        return id < objects.size() && id >= 0 && objects[id].priority != -1;

    }

    // Получить объект по идентификатору
    const T& Get(Id id) const{
        return objects[id].element;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id){
        Id old_priority = objects[id].priority++;

        sorted_nodes.erase({old_priority, id});
        sorted_nodes.insert({objects[id].priority, id});
    }

    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const{
        auto iter = --sorted_nodes.end();

        return {objects[iter->second].element, iter->first};
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax(){
        auto iter = --sorted_nodes.end();
        auto& item = objects[iter->second];
        sorted_nodes.erase(iter);
        const int priority = item.priority;
        item.priority = -1;

        return {move(item.element), priority};
    }


private:
    struct Node{
        int priority;
        T element;

        bool operator<(const Node &other){
            return priority < other.priority;
        }
    };

    vector<Node> objects;
    set<pair<int, Id>> sorted_nodes;
};


class StringNonCopyable : public string {
public:
    using string::string;  // Позволяет использовать конструкторы строки
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
    PriorityCollection<StringNonCopyable> strings;
    const auto white_id = strings.Add("white");
    const auto yellow_id = strings.Add("yellow");
    const auto red_id = strings.Add("red");

    strings.Promote(yellow_id);
    for (int i = 0; i < 2; ++i) {
        strings.Promote(red_id);
    }
    strings.Promote(yellow_id);
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "yellow");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "white");
        ASSERT_EQUAL(item.second, 0);
    }
}

void TheBestTest(){
    PriorityCollection<StringNonCopyable> contain;

    vector<StringNonCopyable> words;
    words.push_back("red");
    words.push_back("blue");
    words.push_back("green");
    words.push_back("yellow");
    words.push_back("white");

    vector<PriorityCollection<StringNonCopyable>::Id> check(words.size());

    contain.Add(words.begin(),words.end(), check.begin());

    //Проверка добавления вектора
    ASSERT_EQUAL(contain.Get(check[0]),"red");
    ASSERT_EQUAL(contain.Get(check[4]),"white");

    //Проверка валидности
    PriorityCollection<StringNonCopyable> spy;
    auto bomb = spy.Add({"joke"});

    ASSERT(contain.IsValid(bomb));
    ASSERT(contain.IsValid(check[0]));
    contain.Promote(check[0]);				//red++
    contain.PopMax();                     //del red
    ASSERT(!contain.IsValid(check[0]));

    //Проверка GetMax()
    contain.Promote(check[4]);				//white++
    auto check_max = contain.GetMax();
    ASSERT_EQUAL(check_max.first,StringNonCopyable({"white"}));
    auto check_max_copy = contain.GetMax();
    ASSERT_EQUAL(check_max.first,check_max_copy.first);
    //Проверка извлечения максимума PopMax();

    ASSERT_EQUAL(check_max.first,"white");
    auto item = contain.PopMax();			//del white
    ASSERT_EQUAL(item.first,StringNonCopyable({"white"}));
    ASSERT_EQUAL(item.second,1);
    ASSERT(!contain.IsValid(check[4]));

    //проверка GetMax() по очередности добавления
    auto new_item = contain.Add({"new"});
    contain.Promote(check[3]);	// yellow++
    contain.Promote(new_item);
    contain.Promote(check[2]);	// green++
    auto x = contain.GetMax();
    ASSERT_EQUAL(x.second, 1);
    ASSERT_EQUAL(x.first, "new");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestNoCopy);
    RUN_TEST(tr, TheBestTest);
    return 0;
}
