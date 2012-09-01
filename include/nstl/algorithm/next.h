/**
 * This file defines the @em next and @em next_n algorithms.
 */

#ifndef NSTL_ALGORITHM_NEXT_H
#define NSTL_ALGORITHM_NEXT_H

#include <nstl/algorithm/advance.h>
#include <nstl/internal.h>


#define NSTL_NEXT(IncrementableIterator)                                       \
    NSTL_I_NEXT(                                                               \
        nstl_next(IncrementableIterator),                                      \
        IncrementableIterator                                                  \
    )                                                                          \
/**/

#define NSTL_I_NEXT(algo, Iter)                                                \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun next                                                                    \
static NSTL_INLINE Iter algo(Iter iter_) {                                     \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_inc(Iter)(&iter);                                                     \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_NEXT_N(IncrementableIterator, Distance)                           \
    NSTL_I_NEXT_N(                                                             \
        nstl_next_n(IncrementableIterator, Distance),                          \
        IncrementableIterator,                                                 \
        Distance                                                               \
    )                                                                          \
/**/

#define NSTL_I_NEXT_N(algo, Iter, Distance)                                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun next_n                                                                  \
NSTL_GETF(                                                                     \
    NSTL_ADVANCE_NAMED(                                                        \
        nstl_helper(algo, advance),                                            \
        (self_type Iter) (diff_traits (self_type Distance))                    \
        (traversal_category nstl_incrementable_traversal_tag)                  \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter iter_, Distance n_) {                        \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_helper(algo, advance)(&iter, n_);                                     \
    return iter;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'next(IncrementableIterator)',
    'next_n(IncrementableIterator, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_next (n e x t)
#define nstl_next(IncrementableIterator) JOY_CAT3(nstl_mangled_next, _, IncrementableIterator)
#define NSTL_TOKEN_next_n (n e x t _ n)
#define nstl_next_n(IncrementableIterator,  Distance) JOY_CAT5(nstl_mangled_next_n, _, IncrementableIterator, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_NEXT_H */
