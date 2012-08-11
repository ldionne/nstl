/**
 * This file defines the @em find_mismatch and @em find_mismatch_comp
 * algorithms.
 *
 * @note These algorithms are equivalent to the @em mismatch algorithms of the
 *       C++ standard library.
 */

#ifndef NSTL_ALGORITHM_FIND_MISMATCH_H
#define NSTL_ALGORITHM_FIND_MISMATCH_H

#include <nstl/utility/pair.h>
#include <nstl/internal.h>


#define NSTL_FIND_MISMATCH(SinglePassReadableIterator,                         \
                           IncrementableReadableIterator, T)                   \
    NSTL_I_FIND_MISMATCH(                                                      \
        nstl_find_mismatch(SinglePassReadableIterator,                         \
                           IncrementableReadableIterator),                     \
        SinglePassReadableIterator,                                            \
        IncrementableReadableIterator,                                         \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_FIND_MISMATCH(algo, Iter1, Iter2, T)                            \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_mismatch                                                           \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_I_FIND_MISMATCH_COMP(                                                 \
        nstl_helper(algo, impl),                                               \
        Iter1,                                                                 \
        Iter2,                                                                 \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    find_mismatch_comp                                                         \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_pair(Iter1, Iter2) algo(Iter1 first1, Iter1 last1,     \
                                                Iter2 first2) {                \
    return nstl_helper(algo, impl)(first1, last1, first2, nstl_eq(T, T));      \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_FIND_MISMATCH_COMP(SinglePassReadableIterator,                    \
                                IncrementableReadableIterator, Compare)        \
    NSTL_I_FIND_MISMATCH_COMP(                                                 \
        nstl_find_mismatch_comp(SinglePassReadableIterator,                    \
                                IncrementableReadableIterator, Compare),       \
        SinglePassReadableIterator,                                            \
        IncrementableReadableIterator,                                         \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_FIND_MISMATCH_COMP(algo, Iter1, Iter2, Comp)                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_mismatch_comp                                                      \
static nstl_pair(Iter1, Iter2) algo(Iter1 first1_, Iter1 last1, Iter2 first2_, \
                                                                Comp comp) {   \
    Iter1 first1;                                                              \
    Iter2 first2;                                                              \
    nstl_pair(Iter1, Iter2) ret;                                               \
    nstl_copy_ctor(Iter1)(&first1, first1_);                                   \
    nstl_copy_ctor(Iter2)(&first2, first2_);                                   \
                                                                               \
    while (nstl_ne(Iter1, Iter1)(first1, last1)) {                             \
        nstl_bool both_equal;                                                  \
        {                                                                      \
            nstl_deref_proxy(Iter1) proxy1;                                    \
            nstl_deref_proxy(Iter2) proxy2;                                    \
            nstl_ctor(nstl_deref_proxy(Iter1))(&proxy1, first1);               \
            nstl_ctor(nstl_deref_proxy(Iter2))(&proxy2, first2);               \
                                                                               \
            both_equal = comp(nstl_get(nstl_deref_proxy(Iter1))(proxy1),       \
                              nstl_get(nstl_deref_proxy(Iter2))(proxy2));      \
                                                                               \
            nstl_dtor(nstl_deref_proxy(Iter2))(&proxy2);                       \
            nstl_dtor(nstl_deref_proxy(Iter1))(&proxy1);                       \
        }                                                                      \
        if (!both_equal)                                                       \
            break;                                                             \
        nstl_inc(Iter1)(&first1);                                              \
        nstl_inc(Iter2)(&first2);                                              \
    }                                                                          \
                                                                               \
    ret = nstl_make_pair(Iter1, Iter2)(first1, first2);                        \
    nstl_dtor(Iter2)(&first2);                                                 \
    nstl_dtor(Iter1)(&first1);                                                 \
    return ret;                                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'find_mismatch(SinglePassReadableIterator, ' +
                  'IncrementableReadableIterator)',
    'find_mismatch_comp(SinglePassReadableIterator, ' +
                       'IncrementableReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_mismatch (f i n d _ m i s m a t c h)
#define nstl_find_mismatch(SinglePassReadableIterator,  IncrementableReadableIterator) JOY_CAT5(nstl_mangled_find_mismatch, _, SinglePassReadableIterator, _,  IncrementableReadableIterator)
#define NSTL_TOKEN_find_mismatch_comp (f i n d _ m i s m a t c h _ c o m p)
#define nstl_find_mismatch_comp(SinglePassReadableIterator,  IncrementableReadableIterator,  Compare) JOY_CAT7(nstl_mangled_find_mismatch_comp, _, SinglePassReadableIterator, _,  IncrementableReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_MISMATCH_H */
