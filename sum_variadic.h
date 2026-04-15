#ifndef SUM_VARIATIC_H
#define SUM_VARIATIC_H

namespace utils {
    namespace math {

        template <typename T>
        T sum_variadic(T valor) {
            return valor;
        }

        template <typename T, typename... Args>
        T sum_variadic(T primero, Args... args) {
            return (primero + ... + args);
        }
    }
}

#endif
