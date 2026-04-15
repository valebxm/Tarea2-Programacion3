#ifndef INVOKE_MULTIPLE_H
#define INVOKE_MULTIPLE_H

namespace functional {
    namespace meta {

        template <typename... funciones>
        void invoke_multiple(funciones&&... funcs) {
            (..., funcs());
        }

    }
}

#endif
