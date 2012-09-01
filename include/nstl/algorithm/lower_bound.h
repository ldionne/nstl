/**
 * This file defines the @em lower_bound and @em lower_bound_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_LOWER_BOUND_H
#define NSTL_ALGORITHM_LOWER_BOUND_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_LOWER_BOUND(ForwardTraversalReadableIterator, T)                  \
    NSTL_I_LOWER_BOUND(                                                        \
        nstl_lower_bound(ForwardTraversalReadableIterator),                    \
        ForwardTraversalReadableIterator,                                      \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_LOWER_BOUND(algo, Iter, T)                                      \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun lower_bound                                                             \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        T,                                                                     \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    lower_bound_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last, T value) {                 \
    return nstl_helper(algo, impl)(first, last, value, nstl_lt(T, T));         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_LOWER_BOUND_COMP(ForwardTraversalReadableIterator, T, Compare)    \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_lower_bound_comp(ForwardTraversalReadableIterator, Compare),      \
        ForwardTraversalReadableIterator,                                      \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_LOWER_BOUND_COMP(algo, Iter, T, Comp) \
    NSTL_II_LOWER_BOUND_COMP(algo, Iter, T, Comp, nstl_ptrdiff_t)

#define NSTL_II_LOWER_BOUND_COMP(algo, Iter, T, Comp, Distance)                \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun lower_bound_comp                                                        \
NSTL_GETF(                                                                     \
    NSTL_I_DISTANCE(                                                           \
        nstl_helper(algo, distance),                                           \
        Iter                                                                   \
    ),                                                                         \
    distance                                                                   \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_ADVANCE_NAMED(                                                        \
        nstl_helper(algo, advance),                                            \
        (self_type Iter) (diff_traits (self_type Distance))                    \
        (traversal_category nstl_bidirectional_traversal_category)             \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
static Iter algo(Iter first_, Iter last_, T value_, Comp comp_) {              \
    Distance len = nstl_helper(algo, distance)(first_, last_);                 \
    Distance half;                                                             \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_gt(Distance, Distance)(len, 0)) {                              \
        nstl_bool is_lt;                                                       \
        Iter middle;                                                           \
        nstl_copy_ctor(Iter)(&middle, first);                                  \
                                                                               \
        half = nstl_div(Distance, Distance)(len, 2);                           \
        nstl_helper(algo, advance)(&middle, half);                             \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, middle);                 \
            is_lt = comp_(nstl_get(nstl_deref_proxy(Iter)(proxy)), value_);    \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        if (is_lt) {                                                           \
            Distance half_minus_one = nstl_sub(Distance, Distance)(half, 1);   \
            nstl_isub(Distance, Distance)(&len, half_minus_one);               \
            nstl_dtor(Distance)(&half_minus_one);                              \
            nstl_asg(Iter, Iter)(&first, middle);                              \
            nstl_inc(Iter)(&first);                                            \
        }                                                                      \
        else {                                                                 \
            nstl_asg(Distance, Distance)(&len, half);                          \
        }                                                                      \
        nstl_dtor(Distance)(&half);                                            \
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
    'lower_bound(ForwardTraversalReadableIterator)',
    'lower_bound_comp(ForwardTraversalReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_lower_bound (l o w e r _ b o u n d)
#define nstl_lower_bound(ForwardTraversalReadableIterator) JOY_CAT3(nstl_mangled_lower_bound, _, ForwardTraversalReadableIterator)
#define NSTL_TOKEN_lower_bound_comp (l o w e r _ b o u n d _ c o m p)
#define nstl_lower_bound_comp(ForwardTraversalReadableIterator,  Compare) JOY_CAT5(nstl_mangled_lower_bound_comp, _, ForwardTraversalReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_LOWER_BOUND_H */
