/**
 * This file defines the @em find and @em find_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_FIND_H
#define NSTL_ALGORITHM_FIND_H

#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_FIND(SinglePassReadableIterator, T)                               \
    NSTL_I_FIND(                                                               \
        nstl_find(SinglePassReadableIterator),                                 \
        SinglePassReadableIterator,                                            \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_FIND(algo, Iter, T)                                             \
    NSTL_I_FIND_DEFAULT(                                                       \
        algo,                                                                  \
        Iter,                                                                  \
        T                                                                      \
    )                                                                          \
/**/


#define NSTL_I_FIND_DEFAULT(algo, Iter, T)                                     \
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


#define NSTL_I_FIND_BYTE(algo, Iter, T)                                        \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find                                                                    \
static NSTL_INLINE Iter algo(Iter first_, Iter last_, T value_) {              \
    void *result = nstl_memchr(first_, value_, last_ - first_);                \
    return result != nstl_nullptr ? (Iter)result : last_;                      \
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
    NSTL_I_FIND_COMP_SINGLE_PASS(                                              \
        algo,                                                                  \
        Iter,                                                                  \
        T,                                                                     \
        Comp                                                                   \
    )                                                                          \
/**/


#define NSTL_I_FIND_COMP_SINGLE_PASS(algo, Iter, T, Comp)                      \
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


#define NSTL_I_FIND_COMP_RANDOM_ACCESS(algo, Iter, T, Comp) \
    NSTL_II_FIND_COMP_RANDOM_ACCESS(algo, Iter, T, Comp, nstl_ptrdiff_t)

#define NSTL_II_FIND_COMP_RANDOM_ACCESS(algo, Iter, T, Comp, Distance)         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_comp                                                               \
NSTL_GETF(                                                                     \
    NSTL_DISTANCE_NAMED(                                                       \
        nstl_helper(algo, distance),                                           \
        (self_type Iter) (diff_traits (self_type Distance))                    \
        (traversal_category nstl_random_access_traversal_tag)                  \
    ),                                                                         \
    distance                                                                   \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_bool nstl_helper(algo, make_comp)                      \
                                        (Iter first_, T value_, Comp comp_) {  \
    nstl_bool result;                                                          \
    nstl_deref_proxy(Iter) proxy;                                              \
    nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first_);                         \
    result = comp_(nstl_get(nstl_deref_proxy(Iter))(proxy), value_);           \
    nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                                 \
    return result;                                                             \
}                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first_, Iter last_, T value_, Comp comp_) {  \
    Iter first;                                                                \
    Distance trip_count = nstl_helper(algo, distance)(first_, last_);          \
    Distance remaining;                                                        \
    nstl_idiv(Distance, Distance)(&trip_count, 4);                             \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_gt(Distance, Distance)(trip_count, 0);                        \
            nstl_dec(Distance)(&trip_count)) {                                 \
        if (nstl_helper(algo, make_comp)(first, value_, comp_))                \
            goto end;                                                          \
        nstl_inc(Iter)(&first);                                                \
                                                                               \
        if (nstl_helper(algo, make_comp)(first, value_, comp_))                \
            goto end;                                                          \
        nstl_inc(Iter)(&first);                                                \
                                                                               \
        if (nstl_helper(algo, make_comp)(first, value_, comp_))                \
            goto end;                                                          \
        nstl_inc(Iter)(&first);                                                \
                                                                               \
        if (nstl_helper(algo, make_comp)(first, value_, comp_))                \
            goto end;                                                          \
        nstl_inc(Iter)(&first);                                                \
    }                                                                          \
                                                                               \
    remaining = nstl_helper(algo, distance)(first, last_);                     \
    switch (remaining) {                                                       \
        case 3:                                                                \
            if (nstl_helper(algo, make_comp)(first, value_, comp_))            \
                goto end_with_remaining;                                       \
            nstl_inc(Iter)(&first);                                            \
        case 2:                                                                \
            if (nstl_helper(algo, make_comp)(first, value_, comp_))            \
                goto end_with_remaining;                                       \
            nstl_inc(Iter)(&first);                                            \
        case 1:                                                                \
            if (nstl_helper(algo, make_comp)(first, value_, comp_))            \
                goto end_with_remaining;                                       \
        case 0:                                                                \
        default:                                                               \
            /* This is to avoid copy_ctor()ing last. */                        \
            nstl_asg(Iter, Iter)(&first, last_);                               \
            goto end_with_remaining;                                           \
    }                                                                          \
end_with_remaining:                                                            \
    nstl_dtor(Distance)(&remaining);                                           \
end:                                                                           \
    nstl_dtor(Distance)(&trip_count);                                          \
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
