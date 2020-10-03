#pragma once

#include <cstdlib>
#include <algorithm>
#include <iostream>


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
    SimpleVector(const SimpleVector &other) : capacity(other.capacity),
    size(other.size), data(new T[other.capacity]), end_(data + other.size) {
        std::copy(other.begin(), other.end(), begin());
    }

    ~SimpleVector(){
        delete[] data;
    }

    T& operator[](size_t index){
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return end_; }

    const T* begin() const { return data; }
    const T* end() const { return end_; }

    size_t Size() const{
        return size;
    }
    size_t Capacity() const{
        return capacity;
    }
    void PushBack(const T& value){
        if (data == nullptr){
            data = new T[1];
            capacity = 1;
        } else if (size == capacity){
            T* new_data = new T[2*capacity];

            for (auto i = 0; i != capacity; ++i) {
                new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
            capacity *= 2;
        }

        *(data + size) = value;

        size++;
        end_ = data + size;
    }

    SimpleVector& operator=(const SimpleVector& other){
        if (other.size <= capacity){
            std::copy(other.begin(), other.end(), begin());
            size = other.size;
        } else{
            SimpleVector<T> tmp(other);

            std::swap(tmp.data, data);
            std::swap(tmp.size, size);
            std::swap(tmp.capacity, capacity);
            std::swap(tmp.end_, end_);
        }

        return *this;
    }
private:
    T* data;
    T* end_;
    size_t capacity;
    size_t size;
};