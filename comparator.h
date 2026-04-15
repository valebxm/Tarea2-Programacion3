#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <functional>

namespace algorithms {
    namespace utility {

        template <template<typename> typename Compare = std::less>

        struct comparator {
            template <typename T>
            static bool compare(const T& a, const T& b) {
                return Compare<T>()(a, b);
            }
        };

    }
}

#endif
