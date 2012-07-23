/**
 * This file defines the @em count_if algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_COUNT_IF_H
#define NSTL_ALGORITHM_COUNT_IF_H

#include <nstl/internal.h>


#define NSTL_COUNT_IF(InputIter, Predicate) \
    NSTL_I_COUNT_IF(nstl_count_if(InputIter, Predicate), InputIter, Predicate)

#define NSTL_I_COUNT_IF(this_func, InputIter, Predicate)                       \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun count_if                                                                \
/**                                                                            \
 * Return the number of elements in the range delimited by [@p first, @p last) \
 * for which the predicate @p pred is true.                                    \
 *                                                                             \
 * @param pred Unary predicate taking an element in the range as argument      \
 *             and returning whether to cound the element.                     \
 */                                                                            \
static NSTL_INLINE nstl_ptrdiff_t this_func                                    \
                        (InputIter first, InputIter last, Predicate pred) {    \
    nstl_ptrdiff_t n = 0;                                                      \
    for ( ; nstl_ne(InputIter, InputIter)(first, last);                        \
                                                nstl_inc(InputIter)(&first)) { \
        if (pred(nstl_deref(InputIter)(first)))                                \
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
    'count_if(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_count_if (c o u n t _ i f)
#define nstl_count_if(InputIter,  Predicate) JOY_CAT5(nstl_mangled_count_if, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COUNT_IF_H */
