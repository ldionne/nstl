/**
 * This file defines the @em copy_if algorithm.
 */

#ifndef NSTL_ALGORITHM_COPY_IF_H
#define NSTL_ALGORITHM_COPY_IF_H

#include <nstl/internal.h>


#define NSTL_COPY_IF(SinglePassReadableIterator,                               \
                     IncrementableWritableIterator, Predicate)                 \
    NSTL_I_COPY_IF(                                                            \
        nstl_copy_if(SinglePassReadableIterator,                               \
                     IncrementableWritableIterator, Predicate),                \
        SinglePassReadableIterator,                                            \
        IncrementableWritableIterator,                                         \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_COPY_IF(algo, Input, Output, Pred)                              \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun copy_if                                                                 \
static NSTL_INLINE Output algo(Input first_, Input last_,                      \
                               Output result_, Pred pred_) {                   \
    Input first;                                                               \
    Output result;                                                             \
    nstl_copy_ctor(Input)(&first, first_);                                     \
    nstl_copy_ctor(Output)(&result, result_);                                  \
                                                                               \
    for ( ; nstl_ne(Input, Input)(first, last_); nstl_inc(Input)(&first)) {    \
        nstl_deref_proxy(Input) in_proxy;                                      \
        nstl_ctor(nstl_deref_proxy(Input))(&in_proxy, first);                  \
        if (pred_(nstl_get(nstl_deref_proxy(Input))(in_proxy))) {              \
            nstl_deref_proxy(Output) out_proxy;                                \
            nstl_ctor(nstl_deref_proxy(Output))(&out_proxy, result);           \
                                                                               \
            nstl_put(nstl_deref_proxy(Output))(out_proxy,                      \
                                nstl_get(nstl_deref_proxy(Input))(in_proxy));  \
                                                                               \
            nstl_dtor(nstl_deref_proxy(Output))(&out_proxy);                   \
            nstl_inc(Output)(&result);                                         \
        }                                                                      \
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


/* [[[cog

import nstl
nstl.generate(cog,
    'copy_if(SinglePassReadableIterator, ' +
                                'IncrementableWritableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_copy_if (c o p y _ i f)
#define nstl_copy_if(SinglePassReadableIterator,  IncrementableWritableIterator,  Predicate) JOY_CAT7(nstl_mangled_copy_if, _, SinglePassReadableIterator, _,  IncrementableWritableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COPY_IF_H */
