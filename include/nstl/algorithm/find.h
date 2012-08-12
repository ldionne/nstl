/**
 * This file defines the @em find and @em find_comp algorithms.
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
typedef nstl_bool (*nstl_helper(algo, impl_pred))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_I_FIND_COMP(                                                          \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        T,                                                                     \
        nstl_helper(algo, impl_pred)                                           \
    ),                                                                         \
    find_comp                                                                  \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last, T value) {                 \
    return nstl_helper(algo, impl)(first, last, value, nstl_eq(T, T));         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_FIND_COMP(SinglePassReadableIterator, T, Compare)                 \
    NSTL_I_FIND_COMP(                                                          \
        nstl_find_comp(SinglePassReadableIterator, Compare),                   \
        SinglePassReadableIterator,                                            \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_FIND_COMP(algo, Iter, T, Comp)                                  \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_comp                                                               \
static NSTL_INLINE Iter algo(Iter first_, Iter last_, T value_, Comp comp_) {  \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last_); nstl_inc(Iter)(&first)) {       \
        nstl_bool is_eq;                                                       \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            is_eq = comp_(nstl_get(nstl_deref_proxy(Iter))(proxy), value_);    \
            nstl_dtor(nstl_deref_proxy(Iter)(&proxy));                         \
        }                                                                      \
        if (is_eq)                                                             \
            break;                                                             \
    }                                                                          \
                                                                               \
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
    'find_comp(SinglePassReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find (f i n d)
#define nstl_find(SinglePassReadableIterator) JOY_CAT3(nstl_mangled_find, _, SinglePassReadableIterator)
#define NSTL_TOKEN_find_comp (f i n d _ c o m p)
#define nstl_find_comp(SinglePassReadableIterator,  Compare) JOY_CAT5(nstl_mangled_find_comp, _, SinglePassReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_H */
