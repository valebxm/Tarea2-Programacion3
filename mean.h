#ifndef MEAN_H
#define MEAN_H

#include "concepts.h"
#include "sum.h"
#include <iterator>
#include <cstddef>

namespace core_numeric {

    template <Iterable C>
    requires Addable<typename C::value_type> && Divisible<typename C::value_type>
    auto mean(const C& contenedor) {
        using T = typename C::value_type;

        std::size_t n = 0;
        for ([[maybe_unused]] const auto& elem : contenedor) ++n;

        T total = sum(contenedor);
        return total / n;
    }

}

#endif
