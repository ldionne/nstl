/**
 * This file defines the @em copy algorithm.
 */

#ifndef NSTL_ALGORITHM_COPY_H
#define NSTL_ALGORITHM_COPY_H

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
static NSTL_INLINE Output algo(Input first_, Input last, Output result_) {     \
    Input first;                                                               \
    Output result;                                                             \
    nstl_copy_ctor(Input)(&first, first_);                                     \
    nstl_copy_ctor(Output)(&result, result_);                                  \
                                                                               \
    for ( ; nstl_ne(Input, Input)(first, last); nstl_inc(Output)(&result),     \
                                                nstl_inc(Input)(&first)) {     \
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


#define NSTL_I_COPY_TRIVIAL(algo, Input, Output)                               \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy                                                                    \
/* Note: Iterators should be pointers.                                         \
 *       If they are not, it won't compile anyway.                             \
 */                                                                            \
static NSTL_INLINE Output algo(Input first, Input last, Output result) {       \
    nstl_size_t const n = last - first;                                        \
    nstl_memmove(result, first, n * sizeof(*result));                          \
    return result + n;                                                         \
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
