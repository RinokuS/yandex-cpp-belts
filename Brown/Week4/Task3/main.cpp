#include "test_runner.h"

#include <cstddef>  // РЅСѓР¶РЅРѕ РґР»СЏ nullptr_t

using namespace std;

// Р РµР°Р»РёР·СѓР№С‚Рµ С€Р°Р±Р»РѕРЅ РєР»Р°СЃСЃР° UniquePtr
template <typename T>
class UniquePtr {
private:
    T* raw_pointer;
public:
    UniquePtr() : raw_pointer(nullptr){
    }
    UniquePtr(T *ptr) : raw_pointer(move(ptr)){
    }
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other){
        raw_pointer = nullptr;
        Swap(other);
    }
    UniquePtr& operator = (const UniquePtr&) = delete;
    UniquePtr& operator = (nullptr_t){
        delete raw_pointer;
        raw_pointer = nullptr;

        return *this;
    }
    UniquePtr& operator = (UniquePtr&& other) noexcept {
        delete raw_pointer;
        raw_pointer = nullptr;
        Swap(other);

        return *this;
    }
    ~UniquePtr(){
        delete raw_pointer;
    }

    T& operator * () const{
        return *raw_pointer;
    }

    T* operator -> () const{
        return raw_pointer;
    }

    T* Release(){
        T* temp = move(raw_pointer);
        raw_pointer = nullptr;
        return move(temp);
    }

    void Reset(T * ptr){
        delete raw_pointer;
        raw_pointer = move(ptr);
    }

    void Swap(UniquePtr& other){
        T* temp = move(raw_pointer);
        raw_pointer = other.Release();
        other.Reset(move(temp));
    }

    T* Get() const{
        return raw_pointer;
    }
};


struct Item {
    static int counter;
    int value;
    Item(int v = 0): value(v) {
        ++counter;
    }
    Item(const Item& other): value(other.value) {
        ++counter;
    }
    ~Item() {
        --counter;
    }
};

int Item::counter = 0;


void TestLifetime() {
    Item::counter = 0;
    {
        UniquePtr<Item> ptr(new Item);
        ASSERT_EQUAL(Item::counter, 1);

        ptr.Reset(new Item);
        ASSERT_EQUAL(Item::counter, 1);
    }
    ASSERT_EQUAL(Item::counter, 0);

    {
        UniquePtr<Item> ptr(new Item);
        ASSERT_EQUAL(Item::counter, 1);

        auto rawPtr = ptr.Release();
        ASSERT_EQUAL(Item::counter, 1);

        delete rawPtr;
        ASSERT_EQUAL(Item::counter, 0);
    }
    ASSERT_EQUAL(Item::counter, 0);
}

void TestGetters() {
    UniquePtr<Item> ptr(new Item(42));
    ASSERT_EQUAL(ptr.Get()->value, 42);
    ASSERT_EQUAL((*ptr).value, 42);
    ASSERT_EQUAL(ptr->value, 42);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestLifetime);
    RUN_TEST(tr, TestGetters);
}