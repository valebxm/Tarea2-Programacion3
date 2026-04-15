#ifndef VARIADIC_H
#define VARIADIC_H

#include "concepts.h"
#include <cstddef>
#include <initializer_list>


namespace core_numeric {

    template <Addable T, Addable... Args>
    auto sum_variadic(T primero, Args... args) {
        return (primero + ... + args);
    }

    template <Addable T, Addable... Args>
    requires Divisible<T>
    auto mean_variadic(T primero, Args... args) {
        constexpr std::size_t n = 1 + sizeof...(args);
        auto total = sum_variadic(primero, args...);
        return total / n;
    }

    template <Addable T, Addable... Args>
    requires Divisible<T>
    auto variance_variadic(T primero, Args... args) {
        constexpr std::size_t n = 1 + sizeof...(args);
        auto promedio = mean_variadic(primero, args...);

        T suma_cuadrados{};
        auto acumular = [&](T val) {
            T d = val - promedio;
            suma_cuadrados = suma_cuadrados + (d * d);
        };

        acumular(primero);
        (acumular(args), ...);

        return suma_cuadrados / n;
    }

    template <Comparable T, Comparable... Args>
    auto max_variadic(T primero, Args... args) {
        T maximo = primero;

        if constexpr (std::is_integral_v<T>) {
            ([&](auto val) { if (maximo < val) maximo = val; }(args), ...);
        } else {
            ([&](auto val) { if (maximo < val) maximo = val; }(args), ...);
        }

        return maximo;
    }

}

#endif
