/**
 * This file defines the @em any_of algorithm.
 */

#ifndef NSTL_ALGORITHM_ANY_OF_H
#define NSTL_ALGORITHM_ANY_OF_H

#include <nstl/internal.h>


#define NSTL_ANY_OF(SinglePassReadableIterator, Predicate)                     \
    NSTL_I_ANY_OF(                                                             \
        nstl_any_of(SinglePassReadableIterator, Predicate),                    \
        SinglePassReadableIterator,                                            \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_ANY_OF(algo, Iter, Pred)                                        \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun any_of                                                                  \
static NSTL_INLINE nstl_bool algo(Iter first_, Iter last_, Pred pred_) {       \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last_); nstl_inc(Iter)(&first)) {       \
        nstl_bool one_is_true;                                                 \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            one_is_true = pred_(nstl_get(nstl_deref_proxy(Iter))(proxy));      \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        if (one_is_true) {                                                     \
            nstl_dtor(Iter)(&first);                                           \
            return nstl_true;                                                  \
        }                                                                      \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return nstl_false;                                                         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'any_of(SinglePassReadableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_any_of (a n y _ o f)
#define nstl_any_of(SinglePassReadableIterator,  Predicate) JOY_CAT5(nstl_mangled_any_of, _, SinglePassReadableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ANY_OF_H */
