/**
 * This file defines the @em max_element and @em max_element_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_MAX_ELEMENT_H
#define NSTL_ALGORITHM_MAX_ELEMENT_H

#include <nstl/internal.h>
#include <nstl/iterator/traits.h>


#define NSTL_MAX_ELEMENT(SinglePassReadableIteratorTraits)                     \
    NSTL_MAX_ELEMENT_NAMED(                                                    \
        nstl_max_element(                                                      \
                    NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits)),   \
        SinglePassReadableIteratorTraits                                       \
    )                                                                          \
/**/

#define NSTL_MAX_ELEMENT_NAMED(AlgorithmName,SinglePassReadableIteratorTraits) \
    NSTL_I_MAX_ELEMENT(                                                        \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits),                \
        NSTL_TRAIT_VALUE_TYPE(SinglePassReadableIteratorTraits),               \
        SinglePassReadableIteratorTraits                                       \
    )                                                                          \
/**/

#define NSTL_I_MAX_ELEMENT(algo, Iter, T, Traits)                              \
NSTL_TYPE(algo,                                                                \
(defun max_element                                                             \
                                                                               \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_MAX_ELEMENT_COMP_NAMED(                                               \
        nstl_helper(algo, impl),                                               \
        Traits,                                                                \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    max_element_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last) {                          \
    return nstl_helper(algo, impl)(first, last, nstl_lt(T, T));                \
}                                                                              \
                                                                               \
))                                                                             \
/**/


#define NSTL_MAX_ELEMENT_COMP(SinglePassReadableIteratorTraits, Compare)       \
    NSTL_MAX_ELEMENT_COMP_NAMED(                                               \
        nstl_max_element_comp(                                                 \
            NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits), Compare),  \
        SinglePassReadableIteratorTraits,                                      \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_MAX_ELEMENT_COMP_NAMED(AlgorithmName,                             \
                                    SinglePassReadableIteratorTraits, Compare) \
    NSTL_I_MAX_ELEMENT_COMP(                                                   \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(SinglePassReadableIteratorTraits),                \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MAX_ELEMENT_COMP(algo, Iter, Comp)                              \
NSTL_TYPE(algo,                                                                \
(defun max_element_comp                                                        \
                                                                               \
static NSTL_INLINE Iter algo(Iter first_, Iter last_, Comp comp_) {            \
    Iter first;                                                                \
    Iter result;                                                               \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
    if (nstl_eq(Iter, Iter)(first, last_))                                     \
        return first;                                                          \
                                                                               \
    nstl_copy_ctor(Iter)(&result, first);                                      \
    while (nstl_ne(Iter, Iter)(nstl_inc(Iter)(&first), last_)) {               \
        nstl_bool is_gt;                                                       \
        {                                                                      \
            nstl_deref_proxy(Iter) result_proxy;                               \
            nstl_deref_proxy(Iter) first_proxy;                                \
            nstl_ctor(nstl_deref_proxy(Iter))(&result_proxy, result);          \
            nstl_ctor(nstl_deref_proxy(Iter))(&first_proxy, first);            \
                                                                               \
            is_gt = comp_(nstl_get(nstl_deref_proxy(Iter))(result_proxy),      \
                          nstl_get(nstl_deref_proxy(Iter))(first_proxy));      \
                                                                               \
            nstl_dtor(nstl_deref_proxy(Iter))(&first_proxy);                   \
            nstl_dtor(nstl_deref_proxy(Iter))(&result_proxy);                  \
        }                                                                      \
        if (is_gt)                                                             \
            nstl_asg(Iter, Iter)(&result, first);                              \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return result;                                                             \
}                                                                              \
                                                                               \
))                                                                             \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'max_element(SinglePassReadableIterator)',
    'max_element_comp(SinglePassReadableIterator, Compare)',
    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max_element (m a x _ e l e m e n t)
#define nstl_max_element(SinglePassReadableIterator) JOY_CAT3(nstl_mangled_max_element, _, SinglePassReadableIterator)
#define NSTL_TOKEN_max_element_comp (m a x _ e l e m e n t _ c o m p)
#define nstl_max_element_comp(SinglePassReadableIterator,  Compare) JOY_CAT5(nstl_mangled_max_element_comp, _, SinglePassReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_ELEMENT_H */
