/**
 * This file defines the @em max and @em max_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_MAX_H
#define NSTL_ALGORITHM_MAX_H

#include <nstl/internal.h>


#define NSTL_MAX(ValueTraits)                                                  \
    NSTL_MAX_NAMED(                                                            \
        nstl_max(NSTL_TRAIT_SELF_TYPE(ValueTraits)),                           \
        ValueTraits                                                            \
    )                                                                          \
/**/

#define NSTL_MAX_NAMED(AlgorithmName, ValueTraits)                             \
    NSTL_I_MAX(                                                                \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(ValueTraits)                                      \
    )                                                                          \
/**/

#define NSTL_I_MAX(algo, T)                                                    \
NSTL_TYPE(algo,                                                                \
(defun max                                                                     \
                                                                               \
static NSTL_INLINE T algo(T a_, T b_) {                                        \
    T result;                                                                  \
    nstl_copy_ctor(T)(&result, nstl_lt(T, T)(a_, b_) ? b_ : a_);               \
    return result;                                                             \
}                                                                              \
                                                                               \
))                                                                             \
/**/


#define NSTL_MAX_COMP(ValueTraits, Compare)                                    \
    NSTL_MAX_COMP_NAMED(                                                       \
        nstl_max_comp(NSTL_TRAIT_SELF_TYPE(ValueTraits), Compare),             \
        ValueTraits,                                                           \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_MAX_COMP_NAMED(AlgorithmName, ValueTraits, Compare)               \
    NSTL_I_MAX_COMP(                                                           \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(ValueTraits),                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MAX_COMP(algo, T, Comp)                                         \
NSTL_TYPE(algo,                                                                \
(defun max_comp                                                                \
                                                                               \
static NSTL_INLINE T algo(T a_, T b_, Comp comp_) {                            \
    T result;                                                                  \
    nstl_copy_ctor(T)(&result, comp_(a_, b_) ? b_ : a_);                       \
    return result;                                                             \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'max(T)',
    'max_comp(T, Compare)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max (m a x)
#define nstl_max(T) JOY_CAT3(nstl_mangled_max, _, T)
#define NSTL_TOKEN_max_comp (m a x _ c o m p)
#define nstl_max_comp(T,  Compare) JOY_CAT5(nstl_mangled_max_comp, _, T, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_H */
