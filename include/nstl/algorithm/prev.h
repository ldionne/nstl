/**
 * This file defines the @em prev and @em prev_n algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_PREV_H
#define NSTL_ALGORITHM_PREV_H

#include <nstl/algorithm/advance.h>
#include <nstl/internal.h>


#define NSTL_PREV(BidirIter) \
    NSTL_I_PREV(nstl_prev(BidirIter), BidirIter)

#define NSTL_I_PREV(this_func, BidirIter)                                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun prev                                                                    \
static NSTL_INLINE BidirIter this_func(BidirIter iter) {                       \
    nstl_dec(BidirIter)(&iter);                                                \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_PREV_N(BidirIter, Distance) \
    NSTL_I_PREV_N(nstl_prev_n(BidirIter, Distance), BidirIter, Distance)

#define NSTL_I_PREV_N(this_func, BidirIter, Distance)                          \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun prev_n                                                                  \
NSTL_GETF(NSTL_I_ADVANCE(nstl_helper(this_func, advance), BidirIter,           \
                                Distance, /*is_bidirectionnal=*/ 1), advance)  \
                                                                               \
static NSTL_INLINE BidirIter this_func(BidirIter iter, Distance n) {           \
    nstl_helper(this_func, advance)(&iter, -n);                                \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'prev(BidirIter)',
    'prev_n(BidirIter, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_prev (p r e v)
#define nstl_prev(BidirIter) JOY_CAT3(nstl_mangled_prev, _, BidirIter)
#define NSTL_TOKEN_prev_n (p r e v _ n)
#define nstl_prev_n(BidirIter,  Distance) JOY_CAT5(nstl_mangled_prev_n, _, BidirIter, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_PREV_H */
