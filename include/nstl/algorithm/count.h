/**
 * This file defines the @em count algorithm.
 */

#ifndef NSTL_ALGORITHM_COUNT_H
#define NSTL_ALGORITHM_COUNT_H

#include <nstl/internal.h>
#include <nstl/iterator/traits.h>


#define NSTL_COUNT(SinglePassReadableIteratorTraits, T)                        \
    NSTL_COUNT_NAMED(                                                          \
        nstl_count(NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits)),    \
        SinglePassReadableIteratorTraits,                                      \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_COUNT_NAMED(AlgorithmName, SinglePassReadableIteratorTraits, T)   \
    NSTL_I_COUNT(                                                              \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits),                \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_COUNT(algo, Iter, T)                                            \
NSTL_TYPE(algo,                                                                \
(defun count                                                                   \
                                                                               \
static NSTL_INLINE nstl_ptrdiff_t algo(Iter first_, Iter last_, T value_) {    \
    Iter first;                                                                \
    nstl_ptrdiff_t n = 0;                                                      \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last_); nstl_inc(Iter)(&first)) {       \
        nstl_bool must_count;                                                  \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            must_count = nstl_eq(T, T)                                         \
                            (nstl_get(nstl_deref_proxy(Iter))(proxy), value_); \
            nstl_dtor(nstl_deref_proxy(Iter)(&proxy));                         \
        }                                                                      \
        if (must_count)                                                        \
            ++n;                                                               \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return n;                                                                  \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'count(SinglePassReadableIterator)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_count (c o u n t)
#define nstl_count(SinglePassReadableIterator) JOY_CAT3(nstl_mangled_count, _, SinglePassReadableIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COUNT_H */
