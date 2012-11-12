/**
 * This file defines the @em distance algorithm.
 */

#ifndef NSTL_ALGORITHM_DISTANCE_H
#define NSTL_ALGORITHM_DISTANCE_H

#include <nstl/internal.h>
#include <nstl/iterator/traits.h>

#include <chaos/preprocessor/control/if.h>


#define NSTL_DISTANCE(SinglePassIteratorTraits)                                \
    NSTL_DISTANCE_NAMED(                                                       \
        nstl_distance(NSTL_TRAIT_SELF_TYPE(SinglePassIteratorTraits)),         \
        SinglePassIteratorTraits                                               \
    )                                                                          \
/**/

#define NSTL_DISTANCE_NAMED(AlgorithmName, SinglePassIteratorTraits)           \
    CHAOS_PP_IF(NSTL_IS_RANDOM_ACCESS_ITERATOR(SinglePassIteratorTraits))(     \
        NSTL_I_DISTANCE_RANDOM_ACCESS, NSTL_I_DISTANCE_DEFAULT                 \
    )(AlgorithmName,                                                           \
      NSTL_TRAIT_SELF_TYPE(SinglePassIteratorTraits),                          \
      NSTL_TRAIT_DIFF_TYPE(SinglePassIteratorTraits))                          \
/**/

#define NSTL_I_DISTANCE_DEFAULT(algo, Iter, Distance)                          \
NSTL_TYPE(algo,                                                                \
(defun distance                                                                \
                                                                               \
static NSTL_INLINE Distance algo(Iter first_, Iter last_) {                    \
    Distance n;                                                                \
    Iter first;                                                                \
    nstl_copy_ctor(Distance)(&n, 0);                                           \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_ne(Iter, Iter)(first, last_)) {                                \
        nstl_inc(Iter)(&first);                                                \
        nstl_inc(Distance)(&n);                                                \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return n;                                                                  \
}                                                                              \
                                                                               \
))                                                                             \
/**/

#define NSTL_I_DISTANCE_RANDOM_ACCESS(algo, Iter, Distance)                    \
NSTL_TYPE(algo,                                                                \
(defun distance                                                                \
                                                                               \
static NSTL_INLINE Distance algo(Iter first_, Iter last_) {                    \
    return nstl_sub(Iter, Iter)(last_, first_);                                \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'distance(SinglePassIteratorTraits)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_distance (d i s t a n c e)
#define nstl_distance(SinglePassIteratorTraits) JOY_CAT3(nstl_mangled_distance, _, SinglePassIteratorTraits)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_DISTANCE_H */
