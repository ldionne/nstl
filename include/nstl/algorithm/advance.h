/**
 * This file defines the @em advance algorithm.
 */

#ifndef NSTL_ALGORITHM_ADVANCE_H
#define NSTL_ALGORITHM_ADVANCE_H

#include <nstl/internal.h>


#define NSTL_ADVANCE(IncrementableIterator, Distance, is_bidirectional)        \
    NSTL_I_ADVANCE(                                                            \
        nstl_advance(IncrementableIterator, Distance),                         \
        IncrementableIterator,                                                 \
        Distance,                                                              \
        is_bidirectional                                                       \
    )                                                                          \
/**/

#define NSTL_I_ADVANCE(algo, Iter, Distance, is_bidirectional)                 \
    NSTL_STATIC_IF(is_bidirectional)(                                          \
        NSTL_I_ADVANCE_BIDIRECTIONAL, NSTL_I_ADVANCE_FORWARD                   \
    )(algo, Iter, Distance)                                                    \
/**/


#define NSTL_I_ADVANCE_FORWARD(algo, Iter, Distance)                           \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void algo(Iter *iter_, Distance n_) {                       \
    Distance n;                                                                \
    nstl_copy_ctor(Distance)(&n, n_);                                          \
                                                                               \
    while (n) {                                                                \
        nstl_dec(Distance)(&n);                                                \
        nstl_inc(Iter)(iter_);                                                 \
    }                                                                          \
                                                                               \
    nstl_dtor(Distance)(&n);                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_ADVANCE_BIDIRECTIONAL(algo, Iter, Distance)                     \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void algo(Iter *iter_, Distance n_) {                       \
    Distance n;                                                                \
    nstl_copy_ctor(Distance)(&n, n_);                                          \
                                                                               \
    if (nstl_gt(Distance, Distance)(n, 0))                                     \
        do {                                                                   \
            nstl_dec(Distance)(&n);                                            \
            nstl_inc(Iter)(iter_);                                             \
        } while (nstl_gt(Distance, Distance)(n, 0));                           \
    else                                                                       \
        while (nstl_lt(Distance, Distance)(n, 0)) {                            \
            nstl_inc(Distance)(&n);                                            \
            nstl_dec(Iter)(iter_);                                             \
        }                                                                      \
                                                                               \
    nstl_dtor(Distance)(&n);                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_ADVANCE_RANDOM_ACCESS(algo, Iter, Distance)                     \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void algo(Iter *iter_, Distance n_) {                       \
    nstl_iadd(Iter, Distance)(iter_, n_);                                      \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'advance(IncrementableIterator, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_advance (a d v a n c e)
#define nstl_advance(IncrementableIterator,  Distance) JOY_CAT5(nstl_mangled_advance, _, IncrementableIterator, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADVANCE_H */
