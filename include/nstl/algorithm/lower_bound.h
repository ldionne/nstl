/**
 * This file defines the @em lower_bound and @em lower_bound_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_LOWER_BOUND_H
#define NSTL_ALGORITHM_LOWER_BOUND_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_LOWER_BOUND(ForwardTraversalReadableIterator, ValueType)          \
    NSTL_I_LOWER_BOUND(                                                        \
        nstl_lower_bound(ForwardTraversalReadableIterator),                    \
        ForwardTraversalReadableIterator,                                      \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_LOWER_BOUND(algo, Iter, Value)                                  \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun lower_bound                                                             \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(Value, Value);               \
NSTL_GETF(                                                                     \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        Value,                                                                 \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    lower_bound_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last, Value value) {             \
    return nstl_helper(algo, impl)(first, last, value, nstl_lt(Value, Value)); \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_LOWER_BOUND_COMP(ForwardTraversalReadableIterator, ValueType,     \
                                                                Compare)       \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_lower_bound_comp(ForwardTraversalReadableIterator, Compare),      \
        ForwardTraversalReadableIterator,                                      \
        ValueType,                                                             \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_LOWER_BOUND_COMP(algo, Iter, Value, Comp)                       \
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
    NSTL_I_ADVANCE(                                                            \
        nstl_helper(algo, advance),                                            \
        Iter,                                                                  \
        nstl_ptrdiff_t,                                                        \
        /*is_bidirectionnal=*/ 0                                               \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
static Iter algo(Iter first_, Iter last, Value value, Comp comp) {             \
    nstl_ptrdiff_t len = nstl_helper(algo, distance)(first_, last);            \
    nstl_ptrdiff_t half;                                                       \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (len > 0) {                                                          \
        Iter middle;                                                           \
        nstl_copy_ctor(Iter)(&middle, first);                                  \
        half = len / 2;                                                        \
        nstl_helper(algo, advance)(&middle, half);                             \
        if (comp(nstl_deref(Iter)(middle), value)) {                           \
            nstl_asg(Iter, Iter)(&first, middle);                              \
            nstl_inc(Iter)(&first);                                            \
            len = len - half - 1;                                              \
        }                                                                      \
        else {                                                                 \
            len = half;                                                        \
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
