/**
 * This file defines the @em advance algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_ADVANCE_H
#define NSTL_ALGORITHM_ADVANCE_H

#include <nstl/internal.h>


#define NSTL_ADVANCE(InputIter, Distance)                                      \
NSTL_TYPE(nstl_advance(InputIter, Distance),                                   \
                                                                               \
(defun advance                                                                 \
/**                                                                            \
 * Advance an iterator by @p n elements.                                       \
 */                                                                            \
static NSTL_INLINE void nstl_advance(InputIter, Distance)                      \
                                            (InputIter *iter, Distance n) {    \
    while (nstl_dec_(Distance)(&n))                                            \
        nstl_inc(InputIter)(iter);                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'advance(InputIter, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_advance (a d v a n c e)
#define nstl_advance(InputIter,  Distance) JOY_CAT5(nstl_mangled_advance, _, InputIter, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADVANCE_H */