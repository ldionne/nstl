/**
 * This file defines the @em advance algorithm.
 */

#ifndef NSTL_ALGORITHM_ADVANCE_H
#define NSTL_ALGORITHM_ADVANCE_H

#include <nstl/internal.h>


#define NSTL_ADVANCE(InputIter, Distance, is_bidirectionnal)                   \
    NSTL_I_ADVANCE(nstl_advance(InputIter, Distance),                          \
        InputIter, Distance, is_bidirectionnal                                 \
    )                                                                          \
/**/

#define NSTL_I_ADVANCE(this_func, InputIter, Distance, is_bidirectionnal)      \
    NSTL_STATIC_IF(is_bidirectionnal)(                                         \
        NSTL_I_ADVANCE_BIDIRECTIONNAL, NSTL_I_ADVANCE_FORWARD                  \
    )(this_func, InputIter, Distance)                                          \
/**/

#define NSTL_I_ADVANCE_BIDIRECTIONNAL(this_func, InputIter, Distance)          \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void this_func(InputIter *iter, Distance n_) {              \
    Distance n;                                                                \
    nstl_copy_ctor(Distance)(&n, n_);                                          \
    if (nstl_gt(Distance, Distance)(n, 0))                                     \
        while (n) {                                                            \
            nstl_dec(Distance)(&n);                                            \
            nstl_inc(InputIter)(iter);                                         \
        }                                                                      \
    else                                                                       \
        while (n) {                                                            \
            nstl_inc(Distance)(&n);                                            \
            nstl_dec(InputIter)(iter);                                         \
        }                                                                      \
    nstl_dtor(Distance)(&n);                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_I_ADVANCE_FORWARD(this_func, InputIter, Distance)                 \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void this_func(InputIter *iter, Distance n_) {              \
    Distance n;                                                                \
    nstl_copy_ctor(Distance)(&n, n_);                                          \
    while (n) {                                                                \
        nstl_dec(Distance)(&n);                                                \
        nstl_inc(InputIter)(iter);                                             \
    }                                                                          \
    nstl_dtor(Distance)(&n);                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'advance(InputIter, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_advance (a d v a n c e)
#define nstl_advance(InputIter,  Distance) JOY_CAT5(nstl_mangled_advance, _, InputIter, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADVANCE_H */
