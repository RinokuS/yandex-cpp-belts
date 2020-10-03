#include <utility>
#include <exception>

// Исключение этого типа должно генерироваться при обращении к "пустому" Optional в функции Value
struct BadOptionalAccess: public std::exception {
};

template <typename T>
class Optional {
private:
  // alignas нужен для правильного выравнивания блока памяти
  alignas(T) unsigned char data[sizeof(T)];
  bool defined = false;

public:
  Optional() = default;
  Optional(const T& elem){
      new (data) T(elem);
      defined = true;
  }
  Optional(T&& elem){
      new (data) T(std::move(elem));
      defined = true;
  }
  void Transport(const Optional& other){
      if (this->defined) {
          if (other.defined) {
              *this->Get() = *other.Get();
          } else {
              reinterpret_cast<T*>(this->data)->~T();
          }
      } else {
          if (other.defined)
              new (this->data) T(*other.Get());
      }

      this->defined = other.defined;
  }
  void Transport(Optional&& other){
      if (this->defined) {
          if (other.defined) {
              *this->Get() = std::move(*other.Get());
          } else {
              reinterpret_cast<T*>(this->data)->~T();
          }
      } else {
          if (other.defined)
              new (this->data) T(std::move(*other.Get()));
      }

      this->defined = other.defined;
  }
  Optional(const Optional& other){
    Transport(other);
  }
  Optional(Optional&& other){
      Transport(std::move(other));
  }

  Optional& operator=(const T& elem){
    if (this->defined){
        *reinterpret_cast<T*>(this->data) = elem;
    } else{
        new(data) T(elem);
    }

    this->defined = true;

    return *this;
  }
  Optional& operator=(T&& elem){
      if (this->defined){
          *reinterpret_cast<T*>(this->data) = std::move(elem);
      } else{
          new(data) T(std::move(elem));
      }

      this->defined = true;

      return *this;
  }
  Optional& operator=(const Optional& other){
      Transport(other);

      return *this;
  }
  Optional& operator=(Optional&& other){
      Transport(std::move(other));

      return *this;
  }

  bool HasValue() const{
      return defined;
  }

  T* Get(){
      return reinterpret_cast<T*>(&this->data);
  }
    const T* Get() const{
        return reinterpret_cast<const T*>(&this->data);
    }
  // Эти операторы не должны делать никаких проверок на пустоту.
  // Проверки остаются на совести программиста.
  T& operator*(){
      return *this->Get();
  }
  const T& operator*() const{
      return *this->Get();
  }
  T* operator->(){
      return this->Get();
  }
  const T* operator->() const{
      return this->Get();
  }

  // Генерирует исключение BadOptionalAccess, если объекта нет
  T& Value(){
      if (defined)
          return *reinterpret_cast<T*>(&this->data);
      throw BadOptionalAccess();
  }
  const T& Value() const{
      if (defined)
          return *reinterpret_cast<const T*>(&this->data);
      throw BadOptionalAccess();
  }

  void Reset(){
      if (defined)
          reinterpret_cast<T*>(data)->~T();
      defined = false;
  }

  ~Optional(){
      if (defined)
        reinterpret_cast<T*>(this->data)->~T();
  }
};
