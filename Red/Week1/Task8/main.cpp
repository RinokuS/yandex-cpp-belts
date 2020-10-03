#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template <typename T>
class Node
{
public:
    T Data;
    Node<T>* Prev;
    Node<T>* Next;
    Node(const T&val): Data(val), Prev(nullptr), Next(nullptr) {}
};

template <typename T>
class Deque{
public:
    Deque() : size(0){}

    bool Empty() const{
        return size == 0;
    }

    size_t Size() const{
        return size;
    }

    T& operator[](size_t index){
        return at(index);
    }
    const T& operator[](size_t index) const{
        return const_cast<Deque*>(this)->at(index);
    }

    T& At(size_t index){
        return at(index);
    }
    const T& At(size_t index) const{
        return const_cast<Deque*>(this)->at(index);
    }

    T& Front(){
        return const_cast<T&>(static_cast<const Deque&>(*this).Front());
    }
    const T& Front() const{
        if (reversed_head.empty() && tail.empty()){
            throw out_of_range("Deque is empty!");
        } else if (reversed_head.empty()){
            const auto iter = tail.cbegin();
            return *iter;
        }
        return reversed_head.back();
    }

    T& Back(){
        return const_cast<T&>(static_cast<const Deque&>(*this).Back());
    }
    const T& Back() const{
        if (reversed_head.empty() && tail.empty()){
            throw out_of_range("Deque is empty!");
        } else if (tail.empty()){
            const auto iter = reversed_head.cbegin();
            return *iter;
        }
        return tail.back();
    }

    void PushFront(T item){
        reversed_head.push_back(item);
        size++;
    }
    void PushBack(T item){
        tail.push_back(item);
        size++;
    }

private:
    vector<T> reversed_head;
    vector<T> tail;
    size_t size;

    T& at(size_t index){
        if (index < 0 || index >= size){
            throw out_of_range("Index is out of deque range!");
        } else if (index < reversed_head.size()){
            return reversed_head[reversed_head.size() - 1 - index];
        } else{
            index -= reversed_head.size();
            return tail[index];
        }
    }
};

int main() {

    return 0;
}
