#include <cstddef>
#include <memory>
#include <new>
#include <utility>

template<typename T>
struct RawMemory{
    size_t cp = 0;
    T* buffer = nullptr;

    RawMemory() = default;
    RawMemory(const RawMemory&) = delete;
    RawMemory(size_t n){
        buffer = Allocate(n);
        cp = n;
    }
    RawMemory(RawMemory&& other) noexcept{
        Swap(other);
    }

    ~RawMemory(){
        Deallocate(buffer);
    }

    RawMemory& operator=(const RawMemory&) = delete;
    RawMemory& operator=(RawMemory&& other) noexcept{
        Swap(other);

        return *this;
    }

    T* operator+(size_t i) {
        return buffer + i;
    }
    const T* operator+(size_t i) const{
        return buffer + i;
    }

    T& operator[](size_t i) {
        return buffer[i];
    }
    const T& operator[](size_t i) const{
        return buffer[i];
    }

    void Swap(RawMemory& other) noexcept{
        std::swap(cp, other.cp);
        std::swap(buffer, other.buffer);
    }

    static T* Allocate(size_t n){
        return static_cast<T*>(operator new(n * sizeof(T)));
    }

    static void Deallocate(T* buf){
        operator delete(buf);
    }
};

template <typename T>
class Vector {
private:
    size_t count = 0;
    RawMemory<T> data;

    static void Construct(void* buf){
        new (buf) T;
    }
    static void Construct(void* buf, const T& elem){
        new (buf) T(elem);
    }

    static void Destroy(T* buf){
        buf->~T();
    }
public:
    Vector() = default;
    Vector(size_t n) : data(n){
        std::uninitialized_value_construct_n(data.buffer, n);
        count = n;
    }
    Vector(const Vector& other) : data(other.count){
        std::uninitialized_copy_n(
                other.data.buffer,
                other.count, data.buffer
                );
        count = other.count;
    }
    Vector(Vector&& other){
        Swap(other);
    }

    ~Vector(){
        std::destroy_n(data.buffer, count);
    }

    Vector& operator = (const Vector& other){
        if (data.cp < other.count){
            Vector<T> temp_vec(other);
            Swap(temp_vec);
        } else {
            for (int i = 0; i < count && i < other.count; ++i) {
                data[i] = other.data[i];
            }

            if (count > other.count){
                std::destroy_n(
                        data.buffer + other.count,
                        count - other.count
                );
            } else if (count < other.count){
                std::uninitialized_copy_n(
                        other.data.buffer + count,
                        other.count - count, data.buffer + count
                        );
            }
            count = other.count;
        }

        return *this;
    }
    Vector& operator = (Vector&& other) noexcept{
        Swap(other);

        return *this;
    }

    void Swap(Vector& other) noexcept{
        data.Swap(other.data);
        std::swap(count, other.count);
    }

    void Reserve(size_t n){
        if (n > data.cp){
            RawMemory<T> temp_data(n);

            std::uninitialized_move_n(
                    data.buffer, count,
                    temp_data.buffer
                    );
            std::destroy_n(data.buffer, count);

            data.Swap(temp_data);
        }
    }

    void Resize(size_t n){
        Reserve(n);

        if (count < n){
            std::uninitialized_value_construct_n(
                    data.buffer + count, n - count
                    );
        } else if (count > n){
            std::destroy_n(data.buffer + n, count - n);
        }

        count = n;
    }

    void PushBack(const T& elem){
        if (count == data.cp){
            Reserve(count == 0 ? 1 : 2 * count);
        }

        new(data + count) T(elem);
        count++;
    }
    void PushBack(T&& elem){
        if (count == data.cp){
            Reserve(count == 0 ? 1 : 2 * count);
        }

        new (data + count) T(std::move(elem));
        count++;
    }

    template <typename ... Args>
    T& EmplaceBack(Args&&... args){
        if (count == data.cp){
            Reserve(count == 0 ? 1 : 2 * count);
        }

        auto temp_elem = new (data + count) T(std::forward<Args>(args)...);
        count++;
        return *temp_elem;
    }

    void PopBack(){
        std::destroy_at(data + count-- - 1);
    }

    size_t Size() const noexcept{
        return count;
    }
    size_t Capacity() const noexcept{
        return data.cp;
    }

    const T& operator[](size_t i) const{
        return data[i];
    }
    T& operator[](size_t i){
        return data[i];
    }
};