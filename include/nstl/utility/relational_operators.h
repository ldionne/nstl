/**
 * Implementation of relational operators.
 */

#ifndef NSTL_UTILITY_RELATIONAL_OPERATORS_H
#define NSTL_UTILITY_RELATIONAL_OPERATORS_H

#include <nstl/internal.h>


#define NSTL_RELATIONAL_OPERATORS(T)                                           \
NSTL_TYPE(nstl_relational_operators ## T,                                      \
                                                                               \
(defun ne                                                                      \
static NSTL_INLINE nstl_bool nstl_ne(T, T)(T a, T b) {                         \
    return !nstl_eq(T, T)(a, b);                                               \
}                                                                              \
)                                                                              \
                                                                               \
(defun gt                                                                      \
static NSTL_INLINE nstl_bool nstl_gt(T, T)(T a, T b) {                         \
    return nstl_lt(T, T)(b, a);                                                \
}                                                                              \
)                                                                              \
                                                                               \
(defun le                                                                      \
static NSTL_INLINE nstl_bool nstl_le(T, T)(T a, T b) {                         \
    return !nstl_lt(T, T)(b, a);                                               \
}                                                                              \
)                                                                              \
                                                                               \
(defun ge                                                                      \
static NSTL_INLINE nstl_bool nstl_ge(T, T)(T a, T b) {                         \
    return !nstl_lt(T, T)(a, b);                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#endif /* !NSTL_UTILITY_RELATIONAL_OPERATORS_H */
