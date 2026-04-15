#ifndef DIMENSIONS_H
#define DIMENSIONS_H

namespace geometry {
    namespace meta {

        template <int... Dims>
        struct dimensions {
            static constexpr int total() {
                return (1 * ... * Dims);
            }
        };

        template <>
        struct dimensions<> {
            static constexpr int total() {
                return 0;
            }
        };

    }
}

#endif
