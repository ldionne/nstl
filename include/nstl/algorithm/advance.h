/**
 * This file defines the @em advance algorithm.
 */

#ifndef NSTL_ALGORITHM_ADVANCE_H
#define NSTL_ALGORITHM_ADVANCE_H

#include <nstl/internal.h>
#include <nstl/iterator/traits.h>

#include <chaos/preprocessor/control/branch.h>


#define NSTL_ADVANCE(IncrementableIteratorTraits)                              \
    NSTL_I_ADVANCE(                                                            \
        IncrementableIteratorTraits,                                           \
        NSTL_TRAIT_SELF_TYPE(IncrementableIteratorTraits),                     \
        NSTL_TRAIT_DIFF_TYPE(IncrementableIteratorTraits)                      \
    )                                                                          \
/**/

#define NSTL_I_ADVANCE(IterTraits, Iter, Diff)                                 \
    NSTL_I_ADVANCE_NAMED(                                                      \
        nstl_advance(Iter, Diff),                                              \
        IterTraits,                                                            \
        Iter,                                                                  \
        Diff                                                                   \
    )                                                                          \
/**/

#define NSTL_ADVANCE_NAMED(AlgorithmName, IncrementableIteratorTraits)         \
    NSTL_I_ADVANCE_NAMED(                                                      \
        AlgorithmName,                                                         \
        IncrementableIteratorTraits,                                           \
        NSTL_TRAIT_SELF_TYPE(IncrementableIteratorTraits),                     \
        NSTL_TRAIT_DIFF_TYPE(IncrementableIteratorTraits)                      \
    )                                                                          \
/**/

#define NSTL_I_ADVANCE_NAMED(algo, IterTraits, Iter, Diff)                     \
    CHAOS_PP_BRANCH                                                            \
    (0xIF)(NSTL_IS_RANDOM_ACCESS_ITERATOR(IterTraits))(                        \
        NSTL_I_ADVANCE_RANDOM_ACCESS(algo, Iter, Diff)                         \
                                                                               \
    )(0xELIF)(NSTL_IS_BIDIRECTIONAL_ITERATOR(IterTraits))(                     \
        NSTL_I_ADVANCE_BIDIRECTIONAL(algo, Iter, Diff)                         \
                                                                               \
    )(0xELSE)(                                                                 \
        NSTL_I_ADVANCE_DEFAULT(algo, Iter, Diff)                               \
    )(0xENDIF)                                                                 \
/**/


#define NSTL_I_ADVANCE_DEFAULT(algo, Iter, Diff)                               \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void algo(Iter *iter_, Diff n_) {                           \
    Diff n;                                                                    \
    nstl_copy_ctor(Diff)(&n, n_);                                              \
                                                                               \
    while (nstl_ne(Diff, Diff)(n, 0)) {                                        \
        nstl_dec(Diff)(&n);                                                    \
        nstl_inc(Iter)(iter_);                                                 \
    }                                                                          \
                                                                               \
    nstl_dtor(Diff)(&n);                                                       \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_ADVANCE_BIDIRECTIONAL(algo, Iter, Diff)                         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void algo(Iter *iter_, Diff n_) {                           \
    Diff n;                                                                    \
    nstl_copy_ctor(Diff)(&n, n_);                                              \
                                                                               \
    if (nstl_lt(Diff, Diff)(0, n))                                             \
        do {                                                                   \
            nstl_dec(Diff)(&n);                                                \
            nstl_inc(Iter)(iter_);                                             \
        } while (nstl_ne(Diff, Diff)(n, 0));                                   \
    else                                                                       \
        while (nstl_ne(Diff, Diff)(n, 0)) {                                    \
            nstl_inc(Diff)(&n);                                                \
            nstl_dec(Iter)(iter_);                                             \
        }                                                                      \
                                                                               \
    nstl_dtor(Diff)(&n);                                                       \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_I_ADVANCE_RANDOM_ACCESS(algo, Iter, Diff)                         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun advance                                                                 \
static NSTL_INLINE void algo(Iter *iter_, Diff n_) {                           \
    nstl_iadd(Iter, Diff)(iter_, n_);                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'advance(IncrementableIterator, Distance)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_advance (a d v a n c e)
#define nstl_advance(IncrementableIterator,  Distance) JOY_CAT5(nstl_mangled_advance, _, IncrementableIterator, _,  Distance)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADVANCE_H */
