/**
 * This file defines the @em distance algorithm.
 */

#ifndef NSTL_ALGORITHM_DISTANCE_H
#define NSTL_ALGORITHM_DISTANCE_H

#include <nstl/internal.h>


#define NSTL_DISTANCE(SinglePassIterator)                                      \
    NSTL_I_DISTANCE(                                                           \
        nstl_distance(SinglePassIterator),                                     \
        SinglePassIterator                                                     \
    )                                                                          \
/**/

#define NSTL_I_DISTANCE(algo, Iter)                                            \
    NSTL_I_DISTANCE_DEFAULT(algo, Iter, nstl_ptrdiff_t)                        \
/**/


#define NSTL_I_DISTANCE_DEFAULT(algo, Iter, Distance)                          \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun distance                                                                \
static NSTL_INLINE Distance algo(Iter first_, Iter last_) {                    \
    Distance n;                                                                \
    Iter first;                                                                \
    nstl_copy_ctor(Distance)(&n, 0);                                           \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_ne(Iter, Iter)(first, last_)) {                                \
        nstl_inc(Iter)(&first);                                                \
        nstl_inc(Distance)(&n);                                                \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return n;                                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_DISTANCE_RANDOM_ACCESS(algo, Iter, Distance)                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun distance                                                                \
static NSTL_INLINE Distance algo(Iter first_, Iter last_) {                    \
    return nstl_sub(Iter, Iter)(last_, first_);                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'distance(SinglePassIterator)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_distance (d i s t a n c e)
#define nstl_distance(SinglePassIterator) JOY_CAT3(nstl_mangled_distance, _, SinglePassIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_DISTANCE_H */
