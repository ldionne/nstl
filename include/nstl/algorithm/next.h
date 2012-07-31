/**
 * This file defines the @em next and @em next_n algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_NEXT_H
#define NSTL_ALGORITHM_NEXT_H

#include <nstl/algorithm/advance.h>
#include <nstl/internal.h>


#define NSTL_NEXT(InputIter) \
    NSTL_I_NEXT(nstl_next(InputIter), InputIter)

#define NSTL_I_NEXT(this_func, InputIter)                                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun next                                                                    \
static NSTL_INLINE InputIter this_func(InputIter iter) {                       \
    nstl_inc(InputIter)(&iter);                                                \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_NEXT_N(InputIter, Distance) \
    NSTL_I_NEXT_N(nstl_next_n(InputIter, Distance), InputIter, Distance)

#define NSTL_I_NEXT_N(this_func, InputIter, Distance)                          \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun next_n                                                                  \
NSTL_GETF(NSTL_I_ADVANCE(nstl_helper(this_func, advance), InputIter,           \
                                Distance, /*is_bidirectionnal=*/ 0), advance)  \
                                                                               \
static NSTL_INLINE InputIter this_func(InputIter iter, Distance n) {           \
    nstl_helper(this_func, advance)(&iter, n);                                 \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'next(InputIter)',
    'next_n(InputIter, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_next (n e x t)
#define nstl_next(InputIter) JOY_CAT3(nstl_mangled_next, _, InputIter)
#define NSTL_TOKEN_next_n (n e x t _ n)
#define nstl_next_n(InputIter,  Distance) JOY_CAT5(nstl_mangled_next_n, _, InputIter, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_NEXT_H */
