#include <map>
#include <iostream>
#include <string>
#include <vector>

// Serialization

template <typename T>
void Serialize(T pod, std::ostream& out);

void Serialize(const std::string& str, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out);

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);


template <typename T>
void Serialize(T pod, std::ostream& out){
    out.write(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void Serialize(const std::string& str, std::ostream& out){
    Serialize(str.size(), out);
    out.write(str.c_str(), str.size());
}

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out){
    Serialize(data.size(), out);
    for (const auto& item: data){
        Serialize(item, out);
    }
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out){
    Serialize(data.size(), out);
    for(const auto& [key,value]: data){
        Serialize(key, out);
        Serialize(value, out);
    }
}

// Deserialization

template <typename T>
void Deserialize(std::istream& in, T& pod);

void Deserialize(std::istream& in, std::string& str);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data);

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);


template <typename T>
void Deserialize(std::istream& in, T& pod){
    in.read(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void Deserialize(std::istream& in, std::string& str){
    auto string_size = str.size();
    Deserialize(in, string_size);
    str.resize(string_size);

    in.read(str.data(), string_size);
}

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data){
    auto vector_size = data.size();
    Deserialize(in, vector_size);
    data.resize(vector_size);

    for(auto& item: data){
        Deserialize(in, item);
    }
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data){
    auto map_size = data.size();
    Deserialize(in, map_size);
    data.clear();

    for (int i = 0; i < map_size; ++i) {
        T1 temp_key;
        T2 temp_val;

        Deserialize(in, temp_key);
        Deserialize(in, temp_val);

        data.insert({temp_key, temp_val});
    }
}
