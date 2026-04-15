#ifndef MAX_H
#define MAX_H

#include "concepts.h"
#include <iterator>
#include <stdexcept>

namespace core_numeric {

    template <Iterable C>
    requires Comparable<typename C::value_type>
    auto max(const C& contenedor) {
        auto it = std::begin(contenedor);
        auto fin = std::end(contenedor);

        if (it == fin)
            throw std::invalid_argument("El contenedor esta vacio");
        using T = typename C::value_type;
        if constexpr (std::is_integral_v<T>) {
            T maximo = *it;
            ++it;
            for (; it != fin; ++it)
                if (maximo < *it) maximo = *it;
            return maximo;
        } else {
            T maximo = *it;
            ++it;
            for (; it != fin; ++it)
                if (maximo < *it) maximo = *it;
            return maximo;
        }
    }

}

#endif
