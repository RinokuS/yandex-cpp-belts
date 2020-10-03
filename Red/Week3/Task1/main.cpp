#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate(){
        T* obj;

        if (o.empty()){
            obj = new T;
        } else{
            obj = o.front();
            o.pop();
        }

        v.insert(obj);
        return obj;
    }
    T* TryAllocate(){
        if (o.empty()){
            return nullptr;
        } else{
            T* obj = o.front();
            o.pop();

            v.insert(obj);
            return obj;
        }
    }

    void Deallocate(T* object){
        if (v.count(object)){
            o.push(object);
            v.erase(v.find(object));
        } else{
            throw invalid_argument("Invalid object");
        }
    }

    ~ObjectPool(){
        for(auto& item : v){
            delete item;
        }
        for(auto i = o.size(); i > 0; i--){
            delete o.front();
            o.pop();
        }
    }

private:
    set<T*> v;
    queue<T*> o;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
