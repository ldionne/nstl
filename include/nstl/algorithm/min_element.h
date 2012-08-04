/**
 * This file defines the @em min_element and @em nstl_min_element_comp
 * algorithms.
 */

#ifndef NSTL_ALGORITHM_MIN_ELEMENT_H
#define NSTL_ALGORITHM_MIN_ELEMENT_H

#include <nstl/internal.h>


#define NSTL_MIN_ELEMENT(SinglePassReadableIterator, ValueType)                \
    NSTL_I_MIN_ELEMENT(                                                        \
        nstl_min_element(SinglePassReadableIterator),                          \
        SinglePassReadableIterator,                                            \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_MIN_ELEMENT(algo, Iter, Value)                                  \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun min_element                                                             \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(Value, Value);               \
NSTL_GETF(                                                                     \
    NSTL_I_MIN_ELEMENT_COMP(                                                   \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        Value,                                                                 \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    min_element_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE Iter algo(Iter first, Iter last) {                          \
    return nstl_helper(algo, impl)(first, last, nstl_lt(Value, Value));        \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_MIN_ELEMENT_COMP(SinglePassReadableIterator, ValueType, Compare)  \
    NSTL_I_MIN_ELEMENT_COMP(                                                   \
        nstl_min_element_comp(SinglePassReadableIterator, Compare),            \
        SinglePassReadableIterator,                                            \
        ValueType,                                                             \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MIN_ELEMENT_COMP(algo, Iter, Value, Comp)                       \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun min_element_comp                                                        \
static NSTL_INLINE Iter algo(Iter first_, Iter last, Comp comp) {              \
    Iter first;                                                                \
    Iter result;                                                               \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    if (nstl_eq(Iter, Iter)(first, last))                                      \
        return first;                                                          \
    nstl_copy_ctor(Iter)(&result, first);                                      \
    while (nstl_ne(Iter, Iter)(nstl_inc(Iter)(&first), last))                  \
        if (comp(nstl_deref(Iter)(first), nstl_deref(Iter)(result)))           \
            nstl_asg(Iter, Iter)(&result, first);                              \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'min_element(SinglePassReadableIterator)',
    'min_element_comp(SinglePassReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min_element (m i n _ e l e m e n t)
#define nstl_min_element(SinglePassReadableIterator) JOY_CAT3(nstl_mangled_min_element, _, SinglePassReadableIterator)
#define NSTL_TOKEN_min_element_comp (m i n _ e l e m e n t _ c o m p)
#define nstl_min_element_comp(SinglePassReadableIterator,  Compare) JOY_CAT5(nstl_mangled_min_element_comp, _, SinglePassReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_ELEMENT_H */
