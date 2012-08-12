/**
 * This file defines the @em upper_bound and @em upper_bound_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_UPPER_BOUND_H
#define NSTL_ALGORITHM_UPPER_BOUND_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_UPPER_BOUND(ForwardTraversalReadableIterator, T)                  \
    NSTL_I_UPPER_BOUND(                                                        \
        nstl_upper_bound(ForwardTraversalReadableIterator),                    \
        ForwardTraversalReadableIterator,                                      \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_UPPER_BOUND(algo, Iter, T)                                      \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun upper_bound                                                             \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_I_UPPER_BOUND_COMP(                                                   \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        T,                                                                     \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    upper_bound_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last, T value) {                 \
    return nstl_helper(algo, impl)(first, last, value, nstl_lt(T, T));         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_UPPER_BOUND_COMP(ForwardTraversalReadableIterator, T, Compare)    \
    NSTL_I_UPPER_BOUND_COMP(                                                   \
        nstl_upper_bound_comp(ForwardTraversalReadableIterator, Compare),      \
        ForwardTraversalReadableIterator,                                      \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_UPPER_BOUND_COMP(algo, Iter, T, Comp)                           \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun upper_bound_comp                                                        \
NSTL_GETF(                                                                     \
    NSTL_I_DISTANCE(                                                           \
        nstl_helper(algo, distance),                                           \
        Iter                                                                   \
    ),                                                                         \
    distance                                                                   \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_ADVANCE(                                                            \
        nstl_helper(algo, advance),                                            \
        Iter,                                                                  \
        nstl_ptrdiff_t,                                                        \
        /*is_bidirectionnal=*/ 0                                               \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
static Iter algo(Iter first_, Iter last_, T value_, Comp comp_) {              \
    nstl_ptrdiff_t len = nstl_helper(algo, distance)(first_, last_);           \
    nstl_ptrdiff_t half;                                                       \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (len > 0) {                                                          \
        nstl_bool is_gt;                                                       \
        Iter middle;                                                           \
        nstl_copy_ctor(Iter)(&middle, first);                                  \
                                                                               \
        half = len / 2;                                                        \
        nstl_helper(algo, advance)(&middle, half);                             \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, middle);                 \
            is_gt = comp_(value_, nstl_get(nstl_deref_proxy(Iter)(proxy)));    \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        if (is_gt) {                                                           \
            len = half;                                                        \
        }                                                                      \
        else {                                                                 \
            nstl_asg(Iter, Iter)(&first, middle);                              \
            nstl_inc(Iter)(&first);                                            \
            len = len - half - 1;                                              \
        }                                                                      \
        nstl_dtor(Iter)(&middle);                                              \
    }                                                                          \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'upper_bound(ForwardTraversalReadableIterator)',
    'upper_bound_comp(ForwardTraversalReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_upper_bound (u p p e r _ b o u n d)
#define nstl_upper_bound(ForwardTraversalReadableIterator) JOY_CAT3(nstl_mangled_upper_bound, _, ForwardTraversalReadableIterator)
#define NSTL_TOKEN_upper_bound_comp (u p p e r _ b o u n d _ c o m p)
#define nstl_upper_bound_comp(ForwardTraversalReadableIterator,  Compare) JOY_CAT5(nstl_mangled_upper_bound_comp, _, ForwardTraversalReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_UPPER_BOUND_H */
