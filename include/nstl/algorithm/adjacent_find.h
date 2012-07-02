/*!
 * This file defines the @em adjacent_find algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_ADJACENT_FIND_H
#define NSTL_ALGORITHM_ADJACENT_FIND_H

#include <nstl/type.h>
#include <nstl/operator.h>


#define NSTL_ADJACENT_FIND(ForwardIter, T)                                     \
NSTL_TYPE(                                                                     \
                                                                               \
(setf adjacent_find                                                            \
/*!                                                                            \
 * Search the range [first, last) for the first occurrence of two consecutive  \
 * equal elements, and return an iterator to the first of these two elements.  \
 *                                                                             \
 * The comparison between the consecutive elements is performed by applying    \
 * the nstl_eq operator.                                                       \
 */                                                                            \
static inline ForwardIter nstl_adjacent_find(ForwardIter, T)(ForwardIter first, \
                                                             ForwardIter last) \
{                                                                              \
    if (nstl_eq(ForwardIter, ForwardIter)(first, last))                        \
        return last;                                                           \
    ForwardIter next;                                                          \
    nstl_init_copy(&next, first);                                              \
    while (nstl_ne(ForwardIter, ForwardIter)(nstl_inc(ForwardIter)(&first),    \
                                             last)) {                          \
        if (nstl_eq(T, T)(nstl_deref(ForwardIter)(first),                      \
                          nstl_deref(ForwardIter)(next)))                      \
            return first;                                                      \
        first = next;                                                          \
    }                                                                          \
    return last;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    'adjacent_find(ForwardIter, T)',
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_adjacent_find (a d j a c e n t _ f i n d)
#define nstl_adjacent_find(ForwardIter,  T) JOY_CAT5(nstl_mangled_adjacent_find, _, ForwardIter, _,  T)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADJACENT_FIND_H */
