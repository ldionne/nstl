/**
 * This file defines the @em find_if_not algorithm.
 */

#ifndef NSTL_ALGORITHM_FIND_IF_NOT_H
#define NSTL_ALGORITHM_FIND_IF_NOT_H

#include <nstl/internal.h>


#define NSTL_FIND_IF_NOT(InputIter, Predicate)                                 \
    NSTL_I_FIND_IF_NOT(                                                        \
        nstl_find_if_not(InputIter, Predicate), InputIter, Predicate           \
    )                                                                          \
/**/

#define NSTL_I_FIND_IF_NOT(this_func, InputIter, Predicate)                    \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun find_if_not                                                             \
static NSTL_INLINE InputIter this_func                                         \
                        (InputIter first_, InputIter last, Predicate pred) {   \
    InputIter first;                                                           \
    nstl_copy_ctor(InputIter)(&first, first_);                                 \
    while (nstl_ne(InputIter, InputIter)(first, last) &&                       \
           pred(nstl_deref(InputIter)(first)))                                 \
        nstl_inc(InputIter)(&first);                                           \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'find_if_not(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_if_not (f i n d _ i f _ n o t)
#define nstl_find_if_not(InputIter,  Predicate) JOY_CAT5(nstl_mangled_find_if_not, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_IF_NOT_H */
