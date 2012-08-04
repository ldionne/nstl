/**
 * This file defines the @em find_if_not algorithm.
 */

#ifndef NSTL_ALGORITHM_FIND_IF_NOT_H
#define NSTL_ALGORITHM_FIND_IF_NOT_H

#include <nstl/internal.h>


#define NSTL_FIND_IF_NOT(SinglePassReadableIterator, Predicate)                \
    NSTL_I_FIND_IF_NOT(                                                        \
        nstl_find_if_not(SinglePassReadableIterator, Predicate),               \
        SinglePassReadableIterator,                                            \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_FIND_IF_NOT(algo, Iter, Pred)                                   \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun find_if_not                                                             \
static NSTL_INLINE Iter algo(Iter first_, Iter last, Pred pred) {              \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_ne(Iter, Iter)(first, last) && pred(nstl_deref(Iter)(first)))  \
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
    'find_if_not(SinglePassReadableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_if_not (f i n d _ i f _ n o t)
#define nstl_find_if_not(SinglePassReadableIterator,  Predicate) JOY_CAT5(nstl_mangled_find_if_not, _, SinglePassReadableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_IF_NOT_H */
