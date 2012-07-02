/*!
 * This file defines the @em find algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_FIND_H
#define NSTL_ALGORITHM_FIND_H

#include <nstl/type.h>


#define NSTL_FIND(InputIter, T)                                                \
NSTL_TYPE(                                                                     \
                                                                               \
(find (                                                                        \
/*!                                                                            \
 * Return an iterator to the first element in the range [first, last) that     \
 * compares equal to @p value, or @em last if not found.                       \
 */                                                                            \
static inline InputIter nstl_find(InputIter, T)(InputIter first, InputIter last, \
                                                                 T const value) \
{                                                                              \
    while (nstl_ne(InputIter, InputIter)(first, last) &&                       \
           nstl_ne(T, T)(nstl_deref(InputIter)(first), value))                 \
        nstl_inc(InputIter)(&first);                                           \
    return first;                                                              \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_attributes(
    'find(InputIter, T)',

    implement=True, token=True,
))

]]] */
#define NSTL_TOKEN_find (f i n d)
#define NSTL_INSTRUCTION_find(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, find, implementation)
#define nstl_find(InputIter,  T) JOY_CAT5(nstl_mangled_find, _, InputIter, _,  T)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_H */
