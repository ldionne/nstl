/*!
 * This file defines the @em count_if algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_COUNT_IF_H
#define NSTL_ALGORITHM_COUNT_IF_H

#include <nstl/type.h>
#include <nstl/operator.h>

#include <stddef.h>


#define NSTL_COUNT_IF(InputIter, Predicate)                                    \
NSTL_TYPE(                                                                     \
                                                                               \
(setf count_if                                                                 \
/*!                                                                            \
 * Return the number of elements in the range delimited by [@p first, @p last) \
 * for which the predicate @p pred is true.                                    \
 *                                                                             \
 * @param pred Unary predicate taking an element in the range as argument      \
 *             and returning whether to cound the element.                     \
 */                                                                            \
static inline ptrdiff_t nstl_count_if(InputIter, Predicate)(InputIter first,   \
                                                InputIter last, Predicate pred) \
{                                                                              \
    ptrdiff_t n = 0;                                                           \
    for ( ; nstl_ne(InputIter, InputIter)(first, last);                        \
            nstl_inc(InputIter)(&first)) {                                     \
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
cog.outl(nstl.generate_mangled(
    'count_if(InputIter, Predicate)',
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_count_if (c o u n t _ i f)
#define nstl_count_if(InputIter,  Predicate) JOY_CAT5(nstl_mangled_count_if, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_COUNT_IF_H */
