/**
 * This file defines the @em count algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_COUNT_H
#define NSTL_ALGORITHM_COUNT_H

#include <nstl/internal.h>

#include <stddef.h>


#define NSTL_COUNT(InputIter, ValueType)                                       \
NSTL_TYPE(nstl_count(InputIter),                                               \
                                                                               \
(defun count                                                                   \
/**                                                                            \
 * Return the number of elements in the range delimited by [@p first, @p last) \
 * that compare equal to @p val.                                               \
 */                                                                            \
static NSTL_INLINE ptrdiff_t nstl_count(InputIter)                             \
                        (InputIter first, InputIter last, ValueType val) {     \
    ptrdiff_t n = 0;                                                           \
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
