/**
 * This file defines the @em find_first_seq and @em find_first_seq_comp
 * algorithms.
 *
 * @note These algorithms are equivalent to the @em search algorithms of the
 *       C++ standard library.
 */

#ifndef NSTL_ALGORITHM_FIND_FIRST_SEQ_H
#define NSTL_ALGORITHM_FIND_FIRST_SEQ_H

#include <nstl/algorithm/find.h>
#include <nstl/internal.h>


#define NSTL_FIND_FIRST_SEQ(ForwardTraversalReadableIterator1,                 \
                            ForwardTraversalReadableIterator2, T)              \
    NSTL_I_FIND_FIRST_SEQ(                                                     \
        nstl_find_first_seq(ForwardTraversalReadableIterator1,                 \
                            ForwardTraversalReadableIterator2),                \
        ForwardTraversalReadableIterator1,                                     \
        ForwardTraversalReadableIterator2,                                     \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_FIND_FIRST_SEQ(algo, Iter1, Iter2, T)                           \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_first_seq                                                          \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_I_FIND_FIRST_SEQ_COMP(                                                \
        nstl_helper(algo, impl),                                               \
        Iter1,                                                                 \
        Iter2,                                                                 \
        nstl_helper(algo, impl_comp),                                          \
        T                                                                      \
    ),                                                                         \
    find_first_seq_comp                                                        \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter1 algo(Iter1 first1, Iter1 last1,                       \
                              Iter2 first2, Iter2 last2) {                     \
    return nstl_helper(algo, impl)(first1, last1,                              \
                                   first2, last2, nstl_eq(T, T));              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_FIND_FIRST_SEQ_COMP(ForwardTraversalReadableIterator1,            \
                                 ForwardTraversalReadableIterator2,            \
                                 Compare, T)                                   \
    NSTL_I_FIND_FIRST_SEQ_COMP(                                                \
        nstl_find_first_seq_comp(ForwardTraversalReadableIterator1,            \
                                 ForwardTraversalReadableIterator2, Compare),  \
        ForwardTraversalReadableIterator1,                                     \
        ForwardTraversalReadableIterator2,                                     \
        Compare,                                                               \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_FIND_FIRST_SEQ_COMP(algo, Iter1, Iter2, Comp, T)                \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_first_seq_comp                                                     \
NSTL_GETF(                                                                     \
    NSTL_I_FIND_COMP(                                                          \
        nstl_helper(algo, find_comp),                                          \
        Iter1,                                                                 \
        T,                                                                     \
        Comp                                                                   \
    ),                                                                         \
    find_comp                                                                  \
)                                                                              \
                                                                               \
static NSTL_INLINE T nstl_helper(algo, deref1)(Iter1 it_) {                    \
    nstl_deref_proxy(Iter1) proxy;                                             \
    T result;                                                                  \
    nstl_ctor(nstl_deref_proxy(Iter1))(&proxy, it_);                           \
    result = nstl_get(nstl_deref_proxy(Iter1))(proxy);                         \
    nstl_dtor(nstl_deref_proxy(Iter1))(&proxy);                                \
    return result;                                                             \
}                                                                              \
                                                                               \
static NSTL_INLINE T nstl_helper(algo, deref2)(Iter2 it_) {                    \
    nstl_deref_proxy(Iter2) proxy;                                             \
    T result;                                                                  \
    nstl_ctor(nstl_deref_proxy(Iter2))(&proxy, it_);                           \
    result = nstl_get(nstl_deref_proxy(Iter2))(proxy);                         \
    nstl_dtor(nstl_deref_proxy(Iter2))(&proxy);                                \
    return result;                                                             \
}                                                                              \
                                                                               \
static Iter1 algo(Iter1 first1_, Iter1 last1_,                                 \
                  Iter2 first2_, Iter2 last2_, Comp comp_) {                   \
    Iter1 first1;                                                              \
    Iter1 last1;                                                               \
    Iter2 seq_second;                                                          \
    Iter1 result;                                                              \
                                                                               \
    /* Check for empty ranges. */                                              \
    if (nstl_eq(Iter1, Iter1)(first1_, last1_) ||                              \
        nstl_eq(Iter2, Iter2)(first2_, last2_)) {                              \
        nstl_copy_ctor(Iter1)(&result, first1_);                               \
        return result;                                                         \
    }                                                                          \
                                                                               \
    nstl_copy_ctor(Iter1)(&first1, first1_);                                   \
    nstl_copy_ctor(Iter1)(&last1, last1_);                                     \
    nstl_copy_ctor(Iter2)(&seq_second, first2_);                               \
    nstl_inc(Iter2)(&seq_second);                                              \
                                                                               \
    /* Check for a subrange of length 1. */                                    \
    if (nstl_eq(Iter2, Iter2)(seq_second, last2_)) {                           \
        result = nstl_helper(algo, find_comp)(first1, last1,                   \
                                 nstl_helper(algo, deref2)(first2_), comp_);   \
        goto end;                                                              \
    }                                                                          \
                                                                               \
    /* General case. */                                                        \
    while (nstl_true) {                                                        \
        Iter2 seq_current;                                                     \
        Iter1 current;                                                         \
                                                                               \
        /* Find the beginning of the subrange in [first1, last1), if any. */   \
        nstl_asg(Iter1, Iter1)(&first1,                                        \
                               nstl_helper(algo, find_comp)(first1, last1,     \
                                nstl_helper(algo, deref2)(first2_), comp_));   \
        if (nstl_eq(Iter1, Iter1)(first1, last1)) {                            \
            nstl_copy_ctor(Iter1)(&result, last1);                             \
            goto end;                                                          \
        }                                                                      \
                                                                               \
        /* Check if the subrange in [first1, last1) has fewer elements than    \
         * [first2_, last2_), which we know to have a length of at least 2.    \
         */                                                                    \
        nstl_copy_ctor(Iter1)(&current, first1);                               \
        nstl_inc(Iter1)(&current);                                             \
        if (nstl_eq(Iter1, Iter1)(current, last1)) {                           \
            nstl_dtor(Iter1)(&current);                                        \
            nstl_copy_ctor(Iter1)(&result, last1);                             \
            goto end;                                                          \
        }                                                                      \
                                                                               \
        /* Try to match the subrange. */                                       \
        nstl_copy_ctor(Iter2)(&seq_current, seq_second);                       \
        while (comp_(nstl_helper(algo, deref1)(current),                       \
                     nstl_helper(algo, deref2)(seq_current))) {                \
                                                                               \
            nstl_inc(Iter2)(&seq_current);                                     \
            if (nstl_eq(Iter2, Iter2)(seq_current, last2_)) {                  \
                nstl_dtor(Iter2)(&seq_current);                                \
                nstl_dtor(Iter1)(&current);                                    \
                nstl_copy_ctor(Iter1)(&result, first1);                        \
                goto end;                                                      \
            }                                                                  \
                                                                               \
            nstl_inc(Iter1)(&current);                                         \
            if (nstl_eq(Iter1, Iter1)(current, last1)) {                       \
                nstl_dtor(Iter2)(&seq_current);                                \
                nstl_dtor(Iter1)(&current);                                    \
                nstl_copy_ctor(Iter1)(&result, last1);                         \
                goto end;                                                      \
            }                                                                  \
        }                                                                      \
        nstl_inc(Iter1)(&first1);                                              \
    }                                                                          \
                                                                               \
end:                                                                           \
    nstl_dtor(Iter2)(&seq_second);                                             \
    nstl_dtor(Iter1)(&last1);                                                  \
    nstl_dtor(Iter1)(&first1);                                                 \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'find_first_seq(ForwardTraversalReadableIterator1, ' +
                   'ForwardTraversalReadableIterator2)',
   'find_first_seq_comp(ForwardTraversalReadableIterator1, ' +
                       'ForwardTraversalReadableIterator2, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_first_seq (f i n d _ f i r s t _ s e q)
#define nstl_find_first_seq(ForwardTraversalReadableIterator1,  ForwardTraversalReadableIterator2) JOY_CAT5(nstl_mangled_find_first_seq, _, ForwardTraversalReadableIterator1, _,  ForwardTraversalReadableIterator2)
#define NSTL_TOKEN_find_first_seq_comp (f i n d _ f i r s t _ s e q _ c o m p)
#define nstl_find_first_seq_comp(ForwardTraversalReadableIterator1,  ForwardTraversalReadableIterator2,  Compare) JOY_CAT7(nstl_mangled_find_first_seq_comp, _, ForwardTraversalReadableIterator1, _,  ForwardTraversalReadableIterator2, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_FIRST_SEQ_H */
