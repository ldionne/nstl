/**
 * This file defines the @em count_if algorithm.
 */

#ifndef NSTL_ALGORITHM_COUNT_IF_H
#define NSTL_ALGORITHM_COUNT_IF_H

#include <nstl/internal.h>


#define NSTL_COUNT_IF(SinglePassReadableIterator, Predicate)                   \
    NSTL_I_COUNT_IF(                                                           \
        nstl_count_if(SinglePassReadableIterator, Predicate),                  \
        SinglePassReadableIterator,                                            \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_COUNT_IF(algo, Iter, Pred)                                      \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun count_if                                                                \
static NSTL_INLINE nstl_ptrdiff_t algo(Iter first_, Iter last_, Pred pred_) {  \
    Iter first;                                                                \
    nstl_ptrdiff_t n = 0;                                                      \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last_); nstl_inc(Iter)(&first)) {       \
        nstl_bool must_count;                                                  \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            must_count = pred_(nstl_get(nstl_deref_proxy(Iter))(proxy));       \
            nstl_dtor(nstl_deref_proxy(Iter)(&proxy));                         \
        }                                                                      \
        if (must_count)                                                        \
            ++n;                                                               \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return n;                                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'count_if(SinglePassReadableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_count_if (c o u n t _ i f)
#define nstl_count_if(SinglePassReadableIterator,  Predicate) JOY_CAT5(nstl_mangled_count_if, _, SinglePassReadableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COUNT_IF_H */
