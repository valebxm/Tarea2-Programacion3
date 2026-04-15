#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <initializer_list>
#include <stdexcept>
#include <cstddef>

template <typename T, std::size_t N>
class static_array {
    T data[N] = {};

public:
    static_array() = default;
    static_array(std::initializer_list<T> inicio) {
        if (inicio.size() > N)
            throw std::out_of_range("Muchos elementos en la lista de inicializadores");
        std::size_t i = 0;
        for (const auto& item : inicio)
            data[i++] = item;
    }

    T& operator[](std::size_t indice) {
        return data[indice];
    }

    const T& operator[](std::size_t indice) const {
        return data[indice];
    }

    constexpr std::size_t size() const {
        return N;
    }

    T* begin() {return data;}
    T* end() {return data + N;}

    const T* begin() const {return data;}
    const T* end() const {return data + N;}

    const T* begin2() const {return data;}
    const T* end2() const {return data + N;}
};

#endif
