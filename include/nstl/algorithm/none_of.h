/**
 * This file defines the @em none_of algorithm.
 */

#ifndef NSTL_ALGORITHM_NONE_OF_H
#define NSTL_ALGORITHM_NONE_OF_H

#include <nstl/internal.h>


#define NSTL_NONE_OF(SinglePassReadableIterator, Predicate)                    \
    NSTL_I_NONE_OF(                                                            \
        nstl_none_of(SinglePassReadableIterator, Predicate),                   \
        SinglePassReadableIterator,                                            \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_NONE_OF(algo, Iter, Pred)                                       \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun none_of                                                                 \
static NSTL_INLINE nstl_bool algo(Iter first_, Iter last, Pred pred) {         \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last); nstl_inc(Iter)(&first)) {        \
        nstl_bool one_is_true;                                                 \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            one_is_true = pred(nstl_get(nstl_deref_proxy(Iter))(proxy));       \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        if (one_is_true) {                                                     \
            nstl_dtor(Iter)(&first);                                           \
            return nstl_false;                                                 \
        }                                                                      \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return nstl_true;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'none_of(SinglePassReadableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_none_of (n o n e _ o f)
#define nstl_none_of(SinglePassReadableIterator,  Predicate) JOY_CAT5(nstl_mangled_none_of, _, SinglePassReadableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_NONE_OF_H */
