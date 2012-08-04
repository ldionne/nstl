/**
 * This file defines the @em count algorithm.
 */

#ifndef NSTL_ALGORITHM_COUNT_H
#define NSTL_ALGORITHM_COUNT_H

#include <nstl/internal.h>


#define NSTL_COUNT(SinglePassReadableIterator, ValueType)                      \
    NSTL_I_COUNT(                                                              \
        nstl_count(SinglePassReadableIterator),                                \
        SinglePassReadableIterator,                                            \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_COUNT(algo, Iter, Value)                                        \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun count                                                                   \
static NSTL_INLINE nstl_ptrdiff_t algo(Iter first_, Iter last, Value value) {  \
    Iter first;                                                                \
    nstl_ptrdiff_t n = 0;                                                      \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last); nstl_inc(Iter)(&first))          \
        if (nstl_eq(Value, Value)(nstl_deref(Iter)(first), value))             \
            ++n;                                                               \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return n;                                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'count(SinglePassReadableIterator)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_count (c o u n t)
#define nstl_count(SinglePassReadableIterator) JOY_CAT3(nstl_mangled_count, _, SinglePassReadableIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COUNT_H */
