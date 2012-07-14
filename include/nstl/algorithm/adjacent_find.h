/**
 * This file defines the @em adjacent_find algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_ADJACENT_FIND_H
#define NSTL_ALGORITHM_ADJACENT_FIND_H

#include <nstl/internal.h>


#define NSTL_ADJACENT_FIND(FwdIter, T)                                         \
NSTL_TYPE(                                                                     \
                                                                               \
(defun adjacent_find                                                           \
/**                                                                            \
 * Search the range [first, last) for the first occurrence of two consecutive  \
 * equal elements, and return an iterator to the first of these two elements.  \
 *                                                                             \
 * The comparison between the consecutive elements is performed by applying    \
 * the nstl_eq operator.                                                       \
 */                                                                            \
static NSTL_INLINE FwdIter nstl_adjacent_find(FwdIter, T)                      \
                                    (FwdIter first, FwdIter last) {            \
    FwdIter next;                                                              \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return last;                                                           \
    nstl_copy_ctor(FwdIter)(&next, first);                                     \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&next), last)) {        \
        if (nstl_eq(T, T)(nstl_deref(FwdIter)(first),                          \
                                                nstl_deref(FwdIter)(next)))    \
            return first;                                                      \
        nstl_asg(FwdIter, FwdIter)(&first, next);                              \
    }                                                                          \
    return last;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'adjacent_find(FwdIter, T)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_adjacent_find (a d j a c e n t _ f i n d)
#define nstl_adjacent_find(FwdIter,  T) JOY_CAT5(nstl_mangled_adjacent_find, _, FwdIter, _,  T)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADJACENT_FIND_H */
