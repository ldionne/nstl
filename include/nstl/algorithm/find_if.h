/**
 * This file defines the @em find_if algorithm.
 */

#ifndef NSTL_ALGORITHM_FIND_IF_H
#define NSTL_ALGORITHM_FIND_IF_H

#include <nstl/internal.h>


#define NSTL_FIND_IF(SinglePassReadableIterator, Predicate)                    \
    NSTL_I_FIND_IF(                                                            \
        nstl_find_if(SinglePassReadableIterator, Predicate),                   \
        SinglePassReadableIterator,                                            \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_FIND_IF(algo, Iter, Pred)                                       \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_if                                                                 \
static NSTL_INLINE Iter algo(Iter first_, Iter last_, Pred pred_) {            \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_ne(Iter, Iter)(first, last_)) {                                \
        nstl_bool found;                                                       \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            found = pred_(nstl_get(nstl_deref_proxy(Iter))(proxy));            \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        if (found)                                                             \
            return first;                                                      \
        else                                                                   \
            nstl_inc(Iter)(&first);                                            \
    }                                                                          \
   return first;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'find_if(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_if (f i n d _ i f)
#define nstl_find_if(InputIter,  Predicate) JOY_CAT5(nstl_mangled_find_if, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_IF_H */
