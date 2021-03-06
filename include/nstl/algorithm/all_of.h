/**
 * This file defines the @em all_of algorithm.
 */

#ifndef NSTL_ALGORITHM_ALL_OF_H
#define NSTL_ALGORITHM_ALL_OF_H

#include <nstl/internal.h>
#include <nstl/iterator/traits.h>


#define NSTL_ALL_OF(SinglePassReadableIteratorTraits, Predicate)               \
    NSTL_I_ALL_OF(                                                             \
        SinglePassReadableIteratorTraits,                                      \
        NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits),                \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_ALL_OF(traits, Iter, Pred)                                      \
    NSTL_I_ADVANCE_NAMED(                                                      \
        nstl_all_of(Iter, Pred),                                               \
        traits,                                                                \
        Iter,                                                                  \
        Pred                                                                   \
    )                                                                          \
/**/

#define NSTL_ALL_OF_NAMED(AlgorithmName, SinglePassReadableIteratorTraits,     \
                                         Predicate)                            \
    NSTL_I_ALL_OF_NAMED(                                                       \
        AlgorithmName,                                                         \
        SinglePassReadableIteratorTraits,                                      \
        NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits),                \
        Predicate                                                              \
    )                                                                          \
/**/

#define NSTL_I_ALL_OF_NAMED(algo, traits, Iter, Pred)                          \
    NSTL_I_ALL_OF_DEFAULT(algo, Iter, Pred)                                    \
/**/


#define NSTL_I_ALL_OF_DEFAULT(algo, Iter, Pred)                                \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun all_of                                                                  \
static NSTL_INLINE nstl_bool algo(Iter first_, Iter last_, Pred pred_) {       \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last_); nstl_inc(Iter)(&first)) {       \
        nstl_bool all_are_true;                                                \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                  \
            all_are_true = pred_(nstl_get(nstl_deref_proxy(Iter))(proxy));     \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        if (!all_are_true) {                                                   \
            nstl_dtor(Iter)(&first);                                           \
            return nstl_false;                                                 \
        }                                                                      \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return nstl_true;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'all_of(SinglePassReadableIterator, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_all_of (a l l _ o f)
#define nstl_all_of(SinglePassReadableIterator,  Predicate) JOY_CAT5(nstl_mangled_all_of, _, SinglePassReadableIterator, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ALL_OF_H */
