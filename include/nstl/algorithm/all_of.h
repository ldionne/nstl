/**
 * This file defines the @em all_of algorithm.
 */

#ifndef NSTL_ALGORITHM_ALL_OF_H
#define NSTL_ALGORITHM_ALL_OF_H

#include <nstl/internal.h>


#define NSTL_ALL_OF(InputIter, Predicate) \
    NSTL_I_ALL_OF(nstl_all_of(InputIter, Predicate), InputIter, Predicate)

#define NSTL_I_ALL_OF(this_func, InputIter, Predicate)                         \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun all_of                                                                  \
static NSTL_INLINE nstl_bool this_func                                         \
                        (InputIter first, InputIter last, Predicate pred) {    \
    for ( ; nstl_ne(InputIter, InputIter)(first, last);                        \
                                                nstl_inc(InputIter)(&first))   \
        if (!pred(nstl_deref(InputIter)(first)))                               \
            return nstl_false;                                                 \
    return nstl_true;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'all_of(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_all_of (a l l _ o f)
#define nstl_all_of(InputIter,  Predicate) JOY_CAT5(nstl_mangled_all_of, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ALL_OF_H */
