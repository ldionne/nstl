/**
 * This file defines the @em prev and @em prev_n algorithms.
 */

#ifndef NSTL_ALGORITHM_PREV_H
#define NSTL_ALGORITHM_PREV_H

#include <nstl/algorithm/advance.h>
#include <nstl/internal.h>
#include <nstl/iterator/traits.h>


#define NSTL_PREV(BidirectionnalTraversalIteratorTraits)                       \
    NSTL_PREV_NAMED(                                                           \
       nstl_prev(NSTL_TRAIT_SELF_TYPE(BidirectionnalTraversalIteratorTraits)), \
        BidirectionnalTraversalIteratorTraits                                  \
    )                                                                          \
/**/

#define NSTL_PREV_NAMED(AlgorithmName, BidirectionnalTraversalIteratorTraits)  \
    NSTL_I_PREV(                                                               \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(BidirectionnalTraversalIteratorTraits)            \
    )                                                                          \
/**/

#define NSTL_I_PREV(algo, Iter)                                                \
NSTL_TYPE(Iter,                                                                \
(defun prev                                                                    \
                                                                               \
static NSTL_INLINE Iter algo(Iter iter_) {                                     \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_dec(Iter)(&iter);                                                     \
    return iter;                                                               \
}                                                                              \
                                                                               \
))                                                                             \
/**/


#define NSTL_PREV_N(BidirectionnalTraversalIteratorTraits)                     \
    NSTL_PREV_N_NAMED(                                                         \
        nstl_prev_n(                                                           \
                NSTL_TRAIT_SELF_TYPE(BidirectionnalTraversalIteratorTraits)),  \
        BidirectionnalTraversalIteratorTraits                                  \
    )                                                                          \
/**/

#define NSTL_PREV_N_NAMED(AlgorithmName,BidirectionnalTraversalIteratorTraits) \
    NSTL_I_PREV_N(                                                             \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(BidirectionnalTraversalIteratorTraits),           \
        NSTL_TRAIT_DIFF_TYPE(BidirectionnalTraversalIteratorTraits),           \
        BidirectionnalTraversalIteratorTraits                                  \
    )                                                                          \
/**/

#define NSTL_I_PREV_N(algo, Iter, Distance, Traits)                            \
NSTL_TYPE(algo,                                                                \
(defun prev_n                                                                  \
                                                                               \
NSTL_GETF(NSTL_ADVANCE_NAMED(nstl_helper(algo, advance), Traits), advance)     \
                                                                               \
static NSTL_INLINE Iter algo(Iter iter_, Distance n_) {                        \
    Iter iter;                                                                 \
    nstl_copy_ctor(Iter)(&iter, iter_);                                        \
    nstl_helper(algo, advance)(&iter, nstl_inv(Distance)(n_));                 \
    return iter;                                                               \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'prev(BidirectionnalTraversalIterator)',
    'prev_n(BidirectionnalTraversalIterator)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_prev (p r e v)
#define nstl_prev(BidirectionnalTraversalIterator) JOY_CAT3(nstl_mangled_prev, _, BidirectionnalTraversalIterator)
#define NSTL_TOKEN_prev_n (p r e v _ n)
#define nstl_prev_n(BidirectionnalTraversalIterator) JOY_CAT3(nstl_mangled_prev_n, _, BidirectionnalTraversalIterator)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_PREV_H */
