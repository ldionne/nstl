/**
 * This file defines the @em adjacent_find algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_ADJACENT_FIND_H
#define NSTL_ALGORITHM_ADJACENT_FIND_H

#include <nstl/internal.h>


#define NSTL_ADJACENT_FIND(iterator_type, value_type)                          \
NSTL_TYPE(nstl_adjacent_find(iterator_type, value_type),                       \
                                                                               \
(defun adjacent_find                                                           \
/**                                                                            \
 * Search the range [@p first, @p last) for the first occurrence of two        \
 * consecutive equal elements, and return an iterator to the first of these    \
 * two elements.                                                               \
 *                                                                             \
 * The comparison between the consecutive elements is performed by applying    \
 * the @em nstl_eq operator.                                                   \
 */                                                                            \
static NSTL_INLINE iterator_type nstl_adjacent_find(iterator_type, value_type) \
                                (iterator_type first, iterator_type last) {    \
    iterator_type next;                                                        \
    if (nstl_eq(iterator_type, iterator_type)(first, last))                    \
        return last;                                                           \
    nstl_copy_ctor(iterator_type)(&next, first);                               \
    while (nstl_ne(iterator_type, iterator_type)                               \
                                    (nstl_inc(iterator_type)(&next), last)) {  \
                                                                               \
        if (nstl_eq(value_type, value_type)(nstl_deref(iterator_type)(first),  \
                                            nstl_deref(iterator_type)(next)))  \
            return first;                                                      \
                                                                               \
        nstl_asg(iterator_type, iterator_type)(&first, next);                  \
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
    'adjacent_find(iterator_type, value_type)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_adjacent_find (a d j a c e n t _ f i n d)
#define nstl_adjacent_find(iterator_type,  value_type) JOY_CAT5(nstl_mangled_adjacent_find, _, iterator_type, _,  value_type)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADJACENT_FIND_H */
