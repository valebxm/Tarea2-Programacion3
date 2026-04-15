#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <concepts>
#include <iterator>
#include <cstddef>

template <typename C>
concept Iterable = requires(C c) {
    std::begin(c);
    std::end(c);
};

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template <typename T>
concept Divisible = requires(T a, std::size_t n) {
    { a / n } -> std::convertible_to<T>;
};

template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::same_as<bool>;
    { a > b } -> std::same_as<bool>;
} && Addable<T>;

#endif
