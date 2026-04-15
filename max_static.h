#ifndef MAX_STATIC_H
#define MAX_STATIC_H

namespace compile_time {

    template <int A, int B>
    constexpr int max_static() {
        return (A > B) ? A : B;
    }

}

#endif
