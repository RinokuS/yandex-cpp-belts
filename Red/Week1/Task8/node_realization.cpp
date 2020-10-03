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
        return head->Data;
    }
    const T& Front() const{
        return (const_cast<Deque*>(this)->head)->Data;
    }

    T& Back(){
        return tail->Data;
    }
    const T& Back() const{
        return (const_cast<Deque*>(this)->tail)->Data;
    }

    void PushFront(T item){
        auto* new_node = new Node<T>(item);
        if (size != 0 && head){
            new_node->Next = head;
            head->Prev = new_node;

            head = new_node;
        } else{
            head = new_node;
            tail = new_node;
        }

        size++;
    }
    void PushBack(T item){
        auto* new_node = new Node<T>(item);
        if (size != 0 && tail){
            new_node->Prev = tail;
            tail->Next = new_node;

            tail = new_node;
        } else{
            head = new_node;
            tail = new_node;
        }

        size++;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

    T& at(size_t index){
        if (index < 0 || index >= size){
            throw out_of_range("Index is out of deque range!");
        }

        Node<T>* temp = head;
        for (size_t i=0; i<index; i++)
            temp=temp->Next;

        return temp->Data;
    }
};

int main() {

    return 0;
}

