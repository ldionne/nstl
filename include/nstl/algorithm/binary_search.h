/**
 * This file defines the @em binary_search and @em binary_search_comp
 * algorithms.
 */

#ifndef NSTL_ALGORITHM_BINARY_SEARCH_H
#define NSTL_ALGORITHM_BINARY_SEARCH_H

#include <nstl/algorithm/lower_bound.h>
#include <nstl/internal.h>
#include <nstl/iterator/traits.h>


#define NSTL_BINARY_SEARCH(ForwardTraversalReadableIteratorTraits, T)          \
    NSTL_I_BINARY_SEARCH(                                                      \
        ForwardTraversalReadableIteratorTraits,                                \
        NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_BINARY_SEARCH(traits, Iter, T)                                  \
    NSTL_I_BINARY_SEARCH_NAMED(                                                \
        nstl_binary_search(Iter),                                              \
        traits,                                                                \
        Iter,                                                                  \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_BINARY_SEARCH_NAMED(AlgorithmName,                                \
                                 ForwardTraversalReadableIteratorTraits, T)    \
    NSTL_I_BINARY_SEARCH_NAMED(                                                \
        AlgorithmName,                                                         \
        ForwardTraversalReadableIteratorTraits,                                \
        NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_BINARY_SEARCH_NAMED(algo, traits, Iter, T)                      \
    NSTL_I_BINARY_SEARCH_DEFAULT(algo, traits, Iter, T)                        \
/**/

#define NSTL_I_BINARY_SEARCH_DEFAULT(algo, traits, Iter, T)                    \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun binary_search                                                           \
typedef nstl_bool (*nstl_helper(algo, impl_pred))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_BINARY_SEARCH_COMP_NAMED(                                             \
        nstl_helper(algo, impl),                                               \
        traits,                                                                \
        T,                                                                     \
        nstl_helper(algo, impl_pred)                                           \
    ),                                                                         \
    binary_search_comp                                                         \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_bool algo(Iter first, Iter last, T value) {            \
    return nstl_helper(algo, impl)(first, last, value, nstl_lt(T, T));         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_BINARY_SEARCH_COMP(ForwardTraversalReadableIteratorTraits, T,     \
                                Compare)                                       \
    NSTL_I_BINARY_SEARCH_COMP(                                                 \
        ForwardTraversalReadableIteratorTraits,                                \
        NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_BINARY_SEARCH_COMP(traits, Iter, T, Compare)                    \
    NSTL_I_BINARY_SEARCH_COMP_NAMED(                                           \
        nstl_binary_search_comp(Iter, Compare),                                \
        traits,                                                                \
        Iter,                                                                  \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_BINARY_SEARCH_COMP_NAMED(AlgorithmName,                           \
                                      ForwardTraversalReadableIteratorTraits,  \
                                      T, Compare)                              \
    NSTL_I_BINARY_SEARCH_COMP_NAMED(                                           \
        AlgorithmName,                                                         \
        ForwardTraversalReadableIteratorTraits,                                \
        NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_BINARY_SEARCH_COMP_NAMED(algo, traits, Iter, T, Compare)        \
    NSTL_I_BINARY_SEARCH_COMP_DEFAULT(algo, Iter, T, Compare)                  \
/**/

#define NSTL_I_BINARY_SEARCH_COMP_DEFAULT(algo, Iter, T, Compare)              \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun binary_search_comp                                                      \
NSTL_GETF(                                                                     \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_helper(algo, lower_bound_comp),                                   \
        Iter,                                                                  \
        T,                                                                     \
        Compare                                                                \
    ),                                                                         \
    lower_bound_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_bool algo(Iter first_, Iter last_,                     \
                                  T value_, Compare comp_) {                   \
    Iter it = nstl_helper(algo, lower_bound_comp)(first_, last_,               \
                                                  value_, comp_);              \
    if (nstl_ne(Iter, Iter)(it, last_)) {                                      \
        nstl_bool ret;                                                         \
        {                                                                      \
            nstl_deref_proxy(Iter) proxy;                                      \
            nstl_ctor(nstl_deref_proxy(Iter))(&proxy, it);                     \
            ret = !comp_(value_, nstl_get(nstl_deref_proxy(Iter))(proxy));     \
            nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                         \
        }                                                                      \
        nstl_dtor(Iter)(&it);                                                  \
        return ret;                                                            \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&it);                                                      \
    return nstl_false;                                                         \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'binary_search(ForwardTraversalReadableIterator)',
    'binary_search_comp(ForwardTraversalReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_binary_search (b i n a r y _ s e a r c h)
#define nstl_binary_search(ForwardTraversalReadableIterator) JOY_CAT3(nstl_mangled_binary_search, _, ForwardTraversalReadableIterator)
#define NSTL_TOKEN_binary_search_comp (b i n a r y _ s e a r c h _ c o m p)
#define nstl_binary_search_comp(ForwardTraversalReadableIterator,  Compare) JOY_CAT5(nstl_mangled_binary_search_comp, _, ForwardTraversalReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_BINARY_SEARCH_H */
