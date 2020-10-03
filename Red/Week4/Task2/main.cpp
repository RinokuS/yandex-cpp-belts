#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) : size(a_size){
        if (a_size > N || a_size < 0){
            throw invalid_argument("Invalid array size");
        }
    }

    T& operator[](size_t index){
        if (index < size && index >= 0)
            return arr[index];
    }
    const T& operator[](size_t index) const{
        if (index < size && index >= 0)
            return arr[index];
    }

    typename array<T, N>::iterator begin(){
        return arr.begin();
    }
    typename array<T, N>::iterator end(){
        return arr.begin() + size;
    }
    typename array<T, N>::const_iterator begin() const{
        return arr.begin();
    }
    typename array<T, N>::const_iterator end() const{
        return arr.begin() + size;
    }

    size_t Size() const{
        return size;
    }
    size_t Capacity() const{
        return arr.size();
    }

    void PushBack(const T& value){
        if (size == arr.size()){
            throw overflow_error("Invalid array size");
        }
        if (size < arr.size())
            arr[size++] = value;
    }
    T PopBack(){
        if (size == 0){
            throw underflow_error("Array is empty");
        }
        if (size > 0)
            return arr[--size];
    }

private:
    array<T, N> arr;
    size_t size;
};
