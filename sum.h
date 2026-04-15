#ifndef SUM_H
#define SUM_H

#include "concepts.h"
#include <iterator>

namespace core_numeric {

    template <Iterable C>
    requires Addable<typename C::value_type>
    auto sum(const C& contenedor) {
        using T = typename C::value_type;

        if constexpr (std::is_integral_v<T>) {
            T resultado{0};
            for (const auto& valor : contenedor)
                resultado = resultado + valor;
            return resultado;
        } else {
            T resultado{};
            for (const auto& valor : contenedor)
                resultado = resultado + valor;
            return resultado;
        }
    }

}

#endif
