#ifndef ALL_TRUE_H
#define ALL_TRUE_H

namespace utils {
    namespace logic {

        template <typename... bools>
        bool all_true(bools... values) {
            return (... && values);
        }

    }
}

#endif
