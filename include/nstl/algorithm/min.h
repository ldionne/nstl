/**
 * This file defines the @em min and @em min_comp algorithm.
 */

#ifndef NSTL_ALGORITHM_MIN_H
#define NSTL_ALGORITHM_MIN_H

#include <nstl/internal.h>


#define NSTL_MIN(T)                                                            \
    NSTL_I_MIN(                                                                \
        nstl_min(T),                                                           \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_MIN(algo, T)                                                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun min                                                                     \
static NSTL_INLINE T algo(T a, T b) {                                          \
    return nstl_lt(T, T)(b, a) ? b : a;                                        \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_MIN_COMP(T, Compare)                                              \
    NSTL_I_MIN_COMP(                                                           \
        nstl_min_comp(T, Compare),                                             \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MIN_COMP(algo, T, Comp)                                         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun min_comp                                                                \
static NSTL_INLINE T algo(T a, T b, Comp comp) {                               \
    return comp(b, a) ? b : a;                                                 \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'min(T)',
    'min_comp(T, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min (m i n)
#define nstl_min(T) JOY_CAT3(nstl_mangled_min, _, T)
#define NSTL_TOKEN_min_comp (m i n _ c o m p)
#define nstl_min_comp(T,  Compare) JOY_CAT5(nstl_mangled_min_comp, _, T, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_H */
