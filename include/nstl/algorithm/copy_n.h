/**
 * This file defines the @em copy_n algorithm.
 */

#ifndef NSTL_ALGORITHM_COPY_N_H
#define NSTL_ALGORITHM_COPY_N_H

#include <nstl/algorithm/copy.h>
#include <nstl/algorithm/next.h>
#include <nstl/internal.h>


#define NSTL_COPY_N(SinglePassReadableIterator, Size,                          \
                    IncrementableWritableIterator)                             \
    NSTL_I_COPY_N(                                                             \
        nstl_copy_n(SinglePassReadableIterator, Size,                          \
                    IncrementableWritableIterator),                            \
        SinglePassReadableIterator,                                            \
        Size,                                                                  \
        IncrementableWritableIterator                                          \
    )                                                                          \
/**/

#define NSTL_I_COPY_N(algo, Input, Size, Output)                               \
    NSTL_I_COPY_N_DEFAULT(algo, Input, Size, Output)                           \
/**/


#define NSTL_I_COPY_N_DEFAULT(algo, Input, Size, Output)                       \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy_n                                                                  \
static NSTL_INLINE Output algo(Input first_, Size count_, Output result_) {    \
    Input first;                                                               \
    Output result;                                                             \
    Size count;                                                                \
    nstl_copy_ctor(Output)(&result, result_);                                  \
    if (nstl_le(Size, Size)(count_, 0))                                        \
        return result;                                                         \
                                                                               \
    nstl_copy_ctor(Input)(&first, first_);                                     \
    nstl_copy_ctor(Size)(&count, count_);                                      \
    while (nstl_true) {                                                        \
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
        nstl_dec(Size)(&count);                                                \
        nstl_inc(Output)(&result);                                             \
        /* Avoid incrementing first one time for nothing                       \
         * on the last iteration.                                              \
         */                                                                    \
        if (nstl_le(Size, Size)(count, 0))                                     \
            break;                                                             \
        else                                                                   \
            nstl_inc(Input)(&first);                                           \
    }                                                                          \
                                                                               \
    nstl_dtor(Size)(&count);                                                   \
    nstl_dtor(Input)(&first);                                                  \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_COPY_N_RANDOM_ACCESS(algo, Input, Size, Output)                 \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy_n                                                                  \
NSTL_GETF(                                                                     \
    NSTL_NEXT_N_NAMED(                                                         \
        nstl_helper(algo, next_n),                                             \
        (self_type Input) (diff_traits (self_type Size))                       \
        (traversal_category nstl_random_access_traversal_tag)                  \
    ),                                                                         \
    next_n                                                                     \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_COPY(                                                               \
        nstl_helper(algo, copy),                                               \
        Input,                                                                 \
        Output                                                                 \
    ),                                                                         \
    copy                                                                       \
)                                                                              \
                                                                               \
static NSTL_INLINE Output algo(Input first_, Size count_, Output result_) {    \
    Input last = nstl_helper(algo, next_n)(first_, count_);                    \
    Output result = nstl_helper(algo, copy)(first_, last, result_);            \
    nstl_dtor(Input)(&last);                                                   \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'copy_n(SinglePassReadableIterator, Size, IncrementableWritableIterator)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_copy_n (c o p y _ n)
#define nstl_copy_n(SinglePassReadableIterator,  Size,  IncrementableWritableIterator) JOY_CAT7(nstl_mangled_copy_n, _, SinglePassReadableIterator, _,  Size, _,  IncrementableWritableIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COPY_N_H */
