/**
 * This file defines the @em find_adjacent and @em find_adjacent_comp
 * algorithms.
 *
 * @note These algorithms are equivalent to the @em adjacent_find algorithms
 *       of the C++ standard library.
 */

#ifndef NSTL_ALGORITHM_FIND_ADJACENT_H
#define NSTL_ALGORITHM_FIND_ADJACENT_H

#include <nstl/internal.h>


#define NSTL_FIND_ADJACENT(ForwardTraversalReadableIterator, T)                \
    NSTL_I_FIND_ADJACENT(                                                      \
        nstl_find_adjacent(ForwardTraversalReadableIterator),                  \
        ForwardTraversalReadableIterator,                                      \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_FIND_ADJACENT(algo, Iter, T)                                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_adjacent                                                           \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_I_FIND_ADJACENT_COMP(                                                 \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    find_adjacent_comp                                                         \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last) {                          \
    return nstl_helper(algo, impl)(first, last, nstl_eq(T, T));                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_FIND_ADJACENT_COMP(ForwardTraversalReadableIterator, Compare)     \
    NSTL_I_FIND_ADJACENT_COMP(                                                 \
        nstl_find_adjacent_comp(ForwardTraversalReadableIterator, Compare),    \
        ForwardTraversalReadableIterator,                                      \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_FIND_ADJACENT_COMP(algo, Iter, Comp)                            \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_adjacent_comp                                                      \
static NSTL_INLINE Iter algo(Iter first_, Iter last, Comp comp) {              \
    Iter next;                                                                 \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    if (nstl_eq(Iter, Iter)(first, last))                                      \
        return first;                                                          \
    nstl_copy_ctor(Iter)(&next, first);                                        \
    while (nstl_ne(Iter, Iter)(nstl_inc(Iter)(&next), last)) {                 \
        nstl_bool are_same;                                                    \
        {                                                                      \
            nstl_deref_proxy(Iter) first_proxy;                                \
            nstl_deref_proxy(Iter) next_proxy;                                 \
            nstl_ctor(nstl_deref_proxy(Iter))(&first_proxy, first);            \
            nstl_ctor(nstl_deref_proxy(Iter))(&next_proxy, next);              \
                                                                               \
            are_same = comp(nstl_get(nstl_deref_proxy(Iter))(first_proxy),     \
                            nstl_get(nstl_deref_proxy(Iter))(next_proxy));     \
                                                                               \
            nstl_dtor(nstl_deref_proxy(Iter))(&next_proxy);                    \
            nstl_dtor(nstl_deref_proxy(Iter))(&first_proxy);                   \
        }                                                                      \
        if (are_same) {                                                        \
            nstl_dtor(Iter)(&next);                                            \
            return first;                                                      \
        }                                                                      \
        nstl_asg(Iter, Iter)(&first, next);                                    \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&next);                                                    \
    /* This is to return a copy of last without copy_ctor()ing. */             \
    nstl_asg(Iter, Iter)(&first, last);                                        \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'find_adjacent(ForwardTraversalReadableIterator)',
    'find_adjacent_comp(ForwardTraversalReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_adjacent (f i n d _ a d j a c e n t)
#define nstl_find_adjacent(ForwardTraversalReadableIterator) JOY_CAT3(nstl_mangled_find_adjacent, _, ForwardTraversalReadableIterator)
#define NSTL_TOKEN_find_adjacent_comp (f i n d _ a d j a c e n t _ c o m p)
#define nstl_find_adjacent_comp(ForwardTraversalReadableIterator,  Compare) JOY_CAT5(nstl_mangled_find_adjacent_comp, _, ForwardTraversalReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_ADJACENT_H */
