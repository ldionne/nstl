/**
 * This file defines the @em count algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_COUNT_H
#define NSTL_ALGORITHM_COUNT_H

#include <nstl/internal.h>


#define NSTL_COUNT(InputIter, ValueType) \
    NSTL_I_COUNT(nstl_count(InputIter), InputIter, ValueType)

#define NSTL_I_COUNT(this_func, InputIter, ValueType)                          \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun count                                                                   \
static NSTL_INLINE nstl_ptrdiff_t this_func                                    \
                        (InputIter first, InputIter last, ValueType val) {     \
    nstl_ptrdiff_t n = 0;                                                      \
    for ( ; nstl_ne(InputIter, InputIter)(first, last);                        \
                                                nstl_inc(InputIter)(&first)) { \
        if (nstl_eq(ValueType, ValueType)(nstl_deref(InputIter)(first), val))  \
            ++n;                                                               \
    }                                                                          \
    return n;                                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'count(InputIter)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_count (c o u n t)
#define nstl_count(InputIter) JOY_CAT3(nstl_mangled_count, _, InputIter)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COUNT_H */
