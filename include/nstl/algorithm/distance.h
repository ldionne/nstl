/**
 * This file defines the @em distance algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_DISTANCE_H
#define NSTL_ALGORITHM_DISTANCE_H

#include <nstl/internal.h>


#define NSTL_DISTANCE(InputIter)                                               \
NSTL_TYPE(nstl_distance(InputIter),                                            \
                                                                               \
(defun distance                                                                \
/**                                                                            \
 * Return the number of elements between @p first and @p last.                 \
 */                                                                            \
static NSTL_INLINE nstl_ptrdiff_t nstl_distance(InputIter)                     \
                                        (InputIter first, InputIter last) {    \
    nstl_ptrdiff_t n = 0;                                                      \
    InputIter it;                                                              \
    nstl_copy_ctor(InputIter)(&it, first);                                     \
    while (nstl_ne(InputIter, InputIter)(it, last)) {                          \
        nstl_inc(InputIter)(&it);                                              \
        ++n;                                                                   \
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
    'distance(InputIter)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_distance (d i s t a n c e)
#define nstl_distance(InputIter) JOY_CAT3(nstl_mangled_distance, _, InputIter)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_DISTANCE_H */
