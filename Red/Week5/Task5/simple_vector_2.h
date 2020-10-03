#pragma once

#include <cstdint>
#include <algorithm>
#include <iostream>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
    SimpleVector() : size(0), capacity(0) {
        data = nullptr;
        end_ = nullptr;
    }
    explicit SimpleVector(size_t size) : capacity(size), size(size) {
        data = new T[size];
        end_ = data + size;
    }
    ~SimpleVector(){
        delete[] data;
    }

    T& operator[](size_t index){
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return end_; }

    size_t Size() const{
        return size;
    }
    size_t Capacity() const{
        return capacity;
    }

    void PushBack(T value){
        if (data == nullptr){
            data = new T[1];
            capacity = 1;
        } else if (size == capacity){
            T* new_data = new T[2*capacity];

            for (auto i = 0; i != capacity; ++i) {
                new_data[i] = move(data[i]);
            }

            delete[] data;

            data = move(new_data);
            capacity *= 2;
        }

        *(data + size) = move(value);

        size++;
        end_ = data + size;
    }
    // При необходимости перегрузите
    // существующие публичные методы

private:
    T* data;
    T* end_;
    size_t capacity;
    size_t size;
};
