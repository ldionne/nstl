/**
 * This file defines the @em find algorithm.
 */

#ifndef NSTL_ALGORITHM_FIND_H
#define NSTL_ALGORITHM_FIND_H

#include <nstl/internal.h>


#define NSTL_FIND(SinglePassReadableIterator, T)                               \
    NSTL_I_FIND(                                                               \
        nstl_find(SinglePassReadableIterator),                                 \
        SinglePassReadableIterator,                                            \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_FIND(algo, Iter, T)                                             \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find                                                                    \
static NSTL_INLINE T nstl_helper(algo, deref)(Iter it) {                       \
    nstl_deref_proxy(Iter) proxy;                                              \
    T ret;                                                                     \
    nstl_ctor(nstl_deref_proxy(Iter))(&proxy, it);                             \
    ret = nstl_get(nstl_deref_proxy(Iter))(proxy);                             \
    nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                                 \
    return ret;                                                                \
}                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first_, Iter last, T value) {                \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_ne(Iter, Iter)(first, last) &&                                 \
           nstl_ne(T, T)(nstl_helper(algo, deref)(first), value))              \
        nstl_inc(Iter)(&first);                                                \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'find(SinglePassReadableIterator)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find (f i n d)
#define nstl_find(SinglePassReadableIterator) JOY_CAT3(nstl_mangled_find, _, SinglePassReadableIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_H */
