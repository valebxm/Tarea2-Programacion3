#ifndef APPLY_TO_ALL_H
#define APPLY_TO_ALL_H

#include <utility>

namespace meta {
    namespace utility {

        template <auto F, typename... Args>
        void apply_to_all(Args&&... args) {
            (F(std::forward<Args>(args)), ...);
        }

        template <typename F, typename... Args>
        void apply_to_all(F&& funcion, Args&&... args) {
            (funcion(std::forward<Args>(args)), ...);
        }

    }
}

#endif
