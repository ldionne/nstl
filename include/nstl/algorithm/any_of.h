/**
 * This file defines the @em any_of algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_ANY_OF_H
#define NSTL_ALGORITHM_ANY_OF_H

#include <nstl/internal.h>


#define NSTL_ANY_OF(InputIter, Predicate) \
    NSTL_I_ANY_OF(nstl_any_of(InputIter, Predicate), InputIter, Predicate)

#define NSTL_I_ANY_OF(this_func, InputIter, Predicate)                         \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun any_of                                                                  \
static NSTL_INLINE nstl_bool this_func                                         \
                        (InputIter first, InputIter last, Predicate pred) {    \
    for (; nstl_ne(InputIter, InputIter)(first, last);                         \
                                                nstl_inc(InputIter)(&first))   \
        if (pred(nstl_deref(InputIter)(first)))                                \
            return nstl_true;                                                  \
    return nstl_false;                                                         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'any_of(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_any_of (a n y _ o f)
#define nstl_any_of(InputIter,  Predicate) JOY_CAT5(nstl_mangled_any_of, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ANY_OF_H */
