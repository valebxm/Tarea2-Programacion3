#ifndef TRANSFORM_REDUCE_H
#define TRANSFORM_REDUCE_H

#include "concepts.h"
#include "sum.h"

namespace core_numeric {

    template <Iterable C, typename F>
    requires Addable<typename C::value_type>
    auto transform_reduce(const C& contenedor, F funcion) {
        using T = typename C::value_type;
        T resultado{};
        for (const auto& valor : contenedor)
            resultado = resultado + funcion(valor);
        return resultado;
    }

}

#endif
