/**
 * This file defines the @em swap utility function.
 */

#ifndef NSTL_UTILITY_SWAP_H
#define NSTL_UTILITY_SWAP_H

#include <nstl/internal.h>


#define NSTL_SWAP(ValueTraits)                                                 \
    NSTL_SWAP_NAMED(                                                           \
        nstl_swap(NSTL_TRAIT_SELF_TYPE(ValueTraits)),                          \
        ValueTraits                                                            \
    )                                                                          \
/**/

#define NSTL_SWAP_NAMED(AlgorithmName, ValueTraits)                            \
    NSTL_I_SWAP(                                                               \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(ValueTraits)                                      \
    )                                                                          \
/**/

#define NSTL_I_SWAP(algo, T)                                                   \
NSTL_TYPE(algo,                                                                \
(defun swap                                                                    \
                                                                               \
static NSTL_INLINE void algo(T *a_, T *b_) {                                   \
    T tmp;                                                                     \
    nstl_copy_ctor(T)(&tmp, *a_);                                              \
    nstl_asg(T, T)(a_, *b_);                                                   \
    nstl_asg(T, T)(b_, tmp);                                                   \
    nstl_dtor(T)(&tmp);                                                        \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'swap(T)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_swap (s w a p)
#define nstl_swap(T) JOY_CAT3(nstl_mangled_swap, _, T)
/* [[[end]]] */

#endif /* !NSTL_UTILITY_SWAP_H */
