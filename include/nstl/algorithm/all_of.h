/**
 * This file defines the @em all_of algorithm.
 */

#ifndef NSTL_ALGORITHM_ALL_OF_H
#define NSTL_ALGORITHM_ALL_OF_H

#include <nstl/internal.h>


#define NSTL_ALL_OF(SinglePassReadableIterator, Predicate)                     \
    NSTL_I_ALL_OF(                                                             \
        nstl_all_of(SinglePassReadableIterator, Predicate),                    \
        SinglePassReadableIterator,                                            \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_ALL_OF(algo, Iter, Pred)                                        \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun all_of                                                                  \
static NSTL_INLINE nstl_bool algo(Iter first_, Iter last, Pred pred) {         \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last); nstl_inc(Iter)(&first))          \
        if (!pred(nstl_deref(Iter)(first))) {                                  \
            nstl_dtor(Iter)(&first);                                           \
            return nstl_false;                                                 \
        }                                                                      \
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
    'all_of(SinglePassReadableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_all_of (a l l _ o f)
#define nstl_all_of(SinglePassReadableIterator,  Predicate) JOY_CAT5(nstl_mangled_all_of, _, SinglePassReadableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ALL_OF_H */
