/**
 * This file defines the @em max and @em max_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_MAX_H
#define NSTL_ALGORITHM_MAX_H

#include <nstl/internal.h>


#define NSTL_MAX(T)                                                            \
    NSTL_I_MAX(                                                                \
        nstl_max(T),                                                           \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_MAX(algo, T)                                                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun max                                                                     \
static NSTL_INLINE T algo(T a_, T b_) {                                        \
    T result;                                                                  \
    nstl_copy_ctor(T)(&result, nstl_lt(T, T)(a_, b_) ? b_ : a_);               \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_MAX_COMP(T, Compare)                                              \
    NSTL_I_MAX_COMP(                                                           \
        nstl_max_comp(T, Compare),                                             \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MAX_COMP(algo, T, Comp)                                         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun max_comp                                                                \
static NSTL_INLINE T algo(T a_, T b_, Comp comp_) {                            \
    T result;                                                                  \
    nstl_copy_ctor(T)(&result, comp_(a_, b_) ? b_ : a_);                       \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'max(T)',
    'max_comp(T, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max (m a x)
#define nstl_max(T) JOY_CAT3(nstl_mangled_max, _, T)
#define NSTL_TOKEN_max_comp (m a x _ c o m p)
#define nstl_max_comp(T,  Compare) JOY_CAT5(nstl_mangled_max_comp, _, T, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_H */
