/**
 * This file defines the @em prev and @em prev_n algorithms.
 */

#ifndef NSTL_ALGORITHM_PREV_H
#define NSTL_ALGORITHM_PREV_H

#include <nstl/algorithm/advance.h>
#include <nstl/internal.h>


#define NSTL_PREV(BidirectionnalTraversalIterator)                             \
    NSTL_I_PREV(                                                               \
        nstl_prev(BidirectionnalTraversalIterator),                            \
        BidirectionnalTraversalIterator                                        \
    )                                                                          \
/**/

#define NSTL_I_PREV(algo, Iter)                                                \
NSTL_TYPE(Iter,                                                                \
                                                                               \
(defun prev                                                                    \
static NSTL_INLINE Iter algo(Iter iter_) {                                     \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_dec(Iter)(&iter);                                                     \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_PREV_N(BidirectionnalTraversalIterator, Distance)                 \
    NSTL_I_PREV_N(                                                             \
        nstl_prev_n(BidirectionnalTraversalIterator, Distance),                \
        BidirectionnalTraversalIterator,                                       \
        Distance                                                               \
    )                                                                          \
/**/

#define NSTL_I_PREV_N(algo, Iter, Distance)                                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun prev_n                                                                  \
NSTL_GETF(                                                                     \
    NSTL_I_ADVANCE(                                                            \
        nstl_helper(algo, advance),                                            \
        Iter,                                                                  \
        Distance,                                                              \
        /*is_bidirectionnal=*/ 1                                               \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter iter_, Distance n) {                         \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_helper(algo, advance)(&iter, -n);                                     \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'prev(BidirectionnalTraversalIterator)',
    'prev_n(BidirectionnalTraversalIterator, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_prev (p r e v)
#define nstl_prev(BidirectionnalTraversalIterator) JOY_CAT3(nstl_mangled_prev, _, BidirectionnalTraversalIterator)
#define NSTL_TOKEN_prev_n (p r e v _ n)
#define nstl_prev_n(BidirectionnalTraversalIterator,  Distance) JOY_CAT5(nstl_mangled_prev_n, _, BidirectionnalTraversalIterator, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_PREV_H */
