/**
 * This file defines the @em copy algorithm.
 */

#ifndef NSTL_ALGORITHM_COPY_H
#define NSTL_ALGORITHM_COPY_H

#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_COPY(SinglePassReadableIterator, IncrementableWritableIterator)   \
    NSTL_I_COPY(                                                               \
        nstl_copy(SinglePassReadableIterator, IncrementableWritableIterator),  \
        SinglePassReadableIterator,                                            \
        IncrementableWritableIterator                                          \
    )                                                                          \
/**/

#define NSTL_I_COPY(algo, Input, Output)                                       \
    NSTL_I_COPY_DEFAULT(algo, Input, Output)                                   \
/**/


#define NSTL_I_COPY_DEFAULT(algo, Input, Output)                               \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy                                                                    \
static NSTL_INLINE Output algo(Input first_, Input last_, Output result_) {    \
    Input first;                                                               \
    Output result;                                                             \
    nstl_copy_ctor(Input)(&first, first_);                                     \
    nstl_copy_ctor(Output)(&result, result_);                                  \
                                                                               \
    for ( ; nstl_ne(Input, Input)(first, last_); nstl_inc(Output)(&result),    \
                                                 nstl_inc(Input)(&first)) {    \
        nstl_deref_proxy(Input) in_proxy;                                      \
        nstl_deref_proxy(Output) out_proxy;                                    \
        nstl_ctor(nstl_deref_proxy(Input))(&in_proxy, first);                  \
        nstl_ctor(nstl_deref_proxy(Output))(&out_proxy, result);               \
                                                                               \
        nstl_put(nstl_deref_proxy(Output))(out_proxy,                          \
                                nstl_get(nstl_deref_proxy(Input))(in_proxy));  \
                                                                               \
        nstl_dtor(nstl_deref_proxy(Output))(&out_proxy);                       \
        nstl_dtor(nstl_deref_proxy(Input)(&in_proxy));                         \
    }                                                                          \
                                                                               \
    nstl_dtor(Input)(&first);                                                  \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_COPY_RANDOM_ACCESS(algo, Input, Output)                         \
    NSTL_II_COPY_RANDOM_ACCESS(algo, Input, Output, nstl_ptrdiff_t)            \
/**/

#define NSTL_II_COPY_RANDOM_ACCESS(algo, Input, Output, Distance)              \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy                                                                    \
NSTL_GETF(                                                                     \
    NSTL_DISTANCE_NAMED(                                                       \
        nstl_helper(algo, distance),                                           \
        (self_type Input) (diff_traits (self_type Distance))                   \
        (traversal_category nstl_random_access_traversal_tag)                  \
    ),                                                                         \
    distance                                                                   \
)                                                                              \
                                                                               \
static NSTL_INLINE Output algo(Input first_, Input last_, Output result_) {    \
    Distance n = nstl_helper(algo, distance)(first_, last_);                   \
    Input first;                                                               \
    Output result;                                                             \
    nstl_copy_ctor(Input)(&first, first_);                                     \
    nstl_copy_ctor(Output)(&result, result_);                                  \
                                                                               \
    for ( ; nstl_gt(Distance, Distance)(n, 0); nstl_dec(Distance)(&n)) {       \
        nstl_deref_proxy(Input) in_proxy;                                      \
        nstl_deref_proxy(Output) out_proxy;                                    \
        nstl_ctor(nstl_deref_proxy(Input))(&in_proxy, first);                  \
        nstl_ctor(nstl_deref_proxy(Output))(&out_proxy, result);               \
                                                                               \
        nstl_put(nstl_deref_proxy(Output))(out_proxy,                          \
                                nstl_get(nstl_deref_proxy(Input))(in_proxy));  \
                                                                               \
        nstl_dtor(nstl_deref_proxy(Output))(&out_proxy);                       \
        nstl_dtor(nstl_deref_proxy(Input)(&in_proxy));                         \
                                                                               \
        nstl_inc(Input)(&first);                                               \
        nstl_inc(Output)(&result);                                             \
    }                                                                          \
                                                                               \
    nstl_dtor(Input)(&first);                                                  \
    nstl_dtor(Distance)(&n);                                                   \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_COPY_TRIVIAL(algo, Input, Output)                               \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy                                                                    \
/* Note: Iterators should be pointers.                                         \
 *       If they are not, it won't compile anyway.                             \
 */                                                                            \
static NSTL_INLINE Output algo(Input first_, Input last_, Output result_) {    \
    nstl_size_t const n = (char const*)last_ - (char const*)first_;            \
    return n ? (Output)((char*)nstl_memmove(result_, first_, n) + n) :result_; \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_COPY_TRIVIAL_NO_OVERLAP(algo, Input, Output)                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy                                                                    \
static NSTL_INLINE Output algo(Input first_, Input last_, Output result_) {    \
    nstl_size_t const n = (char const*)last_ - (char const*)first_;            \
    return n ? (Output)((char*)nstl_memcpy(result_, first_, n) + n) : result_; \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'copy(SinglePassReadableIterator, IncrementableWritableIterator)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_copy (c o p y)
#define nstl_copy(SinglePassReadableIterator,  IncrementableWritableIterator) JOY_CAT5(nstl_mangled_copy, _, SinglePassReadableIterator, _,  IncrementableWritableIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COPY_H */
