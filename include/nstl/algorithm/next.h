/**
 * This file defines the @em next and @em next_n algorithms.
 */

#ifndef NSTL_ALGORITHM_NEXT_H
#define NSTL_ALGORITHM_NEXT_H

#include <nstl/algorithm/advance.h>
#include <nstl/internal.h>
#include <nstl/iterator/traits.h>


#define NSTL_NEXT(IncrementableIteratorTraits)                                 \
    NSTL_NEXT_NAMED(                                                           \
        nstl_next(NSTL_TRAIT_SELF_TYPE(IncrementableIteratorTraits)),          \
        IncrementableIteratorTraits                                            \
    )                                                                          \
/**/

#define NSTL_NEXT_NAMED(AlgorithmName, IncrementableIteratorTraits)            \
    NSTL_I_NEXT(                                                               \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(IncrementableIteratorTraits)                      \
    )                                                                          \
/**/

#define NSTL_I_NEXT(algo, Iter)                                                \
NSTL_TYPE(algo,                                                                \
(defun next                                                                    \
                                                                               \
static NSTL_INLINE Iter algo(Iter iter_) {                                     \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_inc(Iter)(&iter);                                                     \
    return iter;                                                               \
}                                                                              \
                                                                               \
))                                                                             \
/**/


#define NSTL_NEXT_N(IncrementableIteratorTraits)                               \
    NSTL_NEXT_N_NAMED(                                                         \
        nstl_next_n(NSTL_TRAIT_SELF_TYPE(IncrementableIteratorTraits)),        \
        IncrementableIteratorTraits                                            \
    )                                                                          \
/**/

#define NSTL_NEXT_N_NAMED(AlgorithmName, IncrementableIteratorTraits)          \
    NSTL_I_NEXT_N(                                                             \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(IncrementableIteratorTraits),                     \
        NSTL_TRAIT_DIFF_TYPE(IncrementableIteratorTraits),                     \
        IncrementableIteratorTraits                                            \
    )                                                                          \
/**/

#define NSTL_I_NEXT_N(algo, Iter, Distance, Traits)                            \
NSTL_TYPE(algo,                                                                \
(defun next_n                                                                  \
                                                                               \
NSTL_GETF(NSTL_ADVANCE_NAMED(nstl_helper(algo, advance), Traits), advance)     \
                                                                               \
static NSTL_INLINE Iter algo(Iter iter_, Distance n_) {                        \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_helper(algo, advance)(&iter, n_);                                     \
    return iter;                                                               \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'next(IncrementableIterator)',
    'next_n(IncrementableIterator)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_next (n e x t)
#define nstl_next(IncrementableIterator) JOY_CAT3(nstl_mangled_next, _, IncrementableIterator)
#define NSTL_TOKEN_next_n (n e x t _ n)
#define nstl_next_n(IncrementableIterator) JOY_CAT3(nstl_mangled_next_n, _, IncrementableIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_NEXT_H */
