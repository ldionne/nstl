/**
 * This file defines the @em swap algorithm.
 */

#ifndef NSTL_ALGORITHM_SWAP_H
#define NSTL_ALGORITHM_SWAP_H

#include <nstl/internal.h>


#define NSTL_SWAP(T1, T2)                                                      \
    NSTL_I_SWAP(                                                               \
        nstl_swap(T1, T2),                                                     \
        T1,                                                                    \
        T2                                                                     \
    )                                                                          \
/**/

#define NSTL_I_SWAP(algo, T1, T2)                                              \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun swap                                                                    \
static NSTL_INLINE void algo(T1 *a_, T2 *b_) {                                 \
    T1 tmp;                                                                    \
    nstl_copy_ctor(T1)(&tmp, *a_);                                             \
    nstl_asg(T1, T2)(a_, *b_);                                                 \
    nstl_asg(T2, T1)(b_, tmp);                                                 \
    nstl_dtor(T1)(&tmp);                                                       \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'swap(T1, T2)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_swap (s w a p)
#define nstl_swap(T1,  T2) JOY_CAT5(nstl_mangled_swap, _, T1, _,  T2)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_SWAP_H */
