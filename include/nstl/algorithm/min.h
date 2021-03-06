/**
 * This file defines the @em min and @em min_comp algorithm.
 */

#ifndef NSTL_ALGORITHM_MIN_H
#define NSTL_ALGORITHM_MIN_H

#include <nstl/internal.h>


#define NSTL_MIN(ValueTraits)                                                  \
    NSTL_MIN_NAMED(                                                            \
        nstl_min(NSTL_TRAIT_SELF_TYPE(ValueTraits)),                           \
        ValueTraits                                                            \
    )                                                                          \
/**/

#define NSTL_MIN_NAMED(AlgorithmName, ValueTraits)                             \
    NSTL_I_MIN(                                                                \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(ValueTraits)                                      \
    )                                                                          \
/**/

#define NSTL_I_MIN(algo, T)                                                    \
NSTL_TYPE(algo,                                                                \
(defun min                                                                     \
                                                                               \
static NSTL_INLINE T algo(T a_, T b_) {                                        \
    T result;                                                                  \
    nstl_copy_ctor(T)(&result, nstl_lt(T, T)(b_, a_) ? b_ : a_);               \
    return result;                                                             \
}                                                                              \
                                                                               \
))                                                                             \
/**/


#define NSTL_MIN_COMP(ValueTraits, Compare)                                    \
    NSTL_MIN_COMP_NAMED(                                                       \
        nstl_min_comp(NSTL_TRAIT_SELF_TYPE(ValueTraits), Compare),             \
        ValueTraits,                                                           \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_MIN_COMP_NAMED(AlgorithmName, ValueTraits, Compare)               \
    NSTL_I_MIN_COMP(                                                           \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(ValueTraits),                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MIN_COMP(algo, T, Comp)                                         \
NSTL_TYPE(algo,                                                                \
(defun min_comp                                                                \
                                                                               \
static NSTL_INLINE T algo(T a_, T b_, Comp comp_) {                            \
    T result;                                                                  \
    nstl_copy_ctor(T)(&result, comp_(b_, a_) ? b_ : a_);                       \
    return result;                                                             \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'min(T)',
    'min_comp(T, Compare)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min (m i n)
#define nstl_min(T) JOY_CAT3(nstl_mangled_min, _, T)
#define NSTL_TOKEN_min_comp (m i n _ c o m p)
#define nstl_min_comp(T,  Compare) JOY_CAT5(nstl_mangled_min_comp, _, T, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_H */
