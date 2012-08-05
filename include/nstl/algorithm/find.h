/**
 * This file defines the @em find algorithm.
 */

#ifndef NSTL_ALGORITHM_FIND_H
#define NSTL_ALGORITHM_FIND_H

#include <nstl/internal.h>


#define NSTL_FIND(SinglePassReadableIterator, ValueType)                       \
    NSTL_I_FIND(                                                               \
        nstl_find(SinglePassReadableIterator, ValueType),                      \
        SinglePassReadableIterator,                                            \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_FIND(algo, Iter, Value)                                         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find                                                                    \
                                                                               \
static NSTL_INLINE Value nstl_helper(algo, deref)(Iter it) {                   \
    nstl_deref_proxy(Iter) proxy;                                              \
    Value ret;                                                                 \
    nstl_ctor(nstl_deref_proxy(Iter))(&proxy, it);                             \
    ret = nstl_get(nstl_deref_proxy(Iter))(proxy);                             \
    nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                                 \
    return ret;                                                                \
}                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first_, Iter last, Value value) {            \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_ne(Iter, Iter)(first, last) &&                                 \
           nstl_ne(Value, Value)(nstl_helper(algo, deref)(first), value))      \
        nstl_inc(Iter)(&first);                                                \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'find(SinglePassReadableIterator, ValueType)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find (f i n d)
#define nstl_find(SinglePassReadableIterator,  ValueType) JOY_CAT5(nstl_mangled_find, _, SinglePassReadableIterator, _,  ValueType)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_H */
