/**
 * This file defines the @em none_of algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_NONE_OF_H
#define NSTL_ALGORITHM_NONE_OF_H

#include <nstl/internal.h>


#define NSTL_NONE_OF(InputIter, Predicate) \
    NSTL_I_NONE_OF(nstl_none_of(InputIter, Predicate), InputIter, Predicate)

#define NSTL_I_NONE_OF(this_func, InputIter, Predicate)                        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun none_of                                                                 \
static NSTL_INLINE nstl_bool this_func                                         \
                        (InputIter first, InputIter last, Predicate pred) {    \
    for (; nstl_ne(InputIter, InputIter)(first, last);                         \
                                                nstl_inc(InputIter)(&first))   \
        if (pred(nstl_deref(InputIter)(first)))                                \
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
    'none_of(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_none_of (n o n e _ o f)
#define nstl_none_of(InputIter,  Predicate) JOY_CAT5(nstl_mangled_none_of, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_NONE_OF_H */
