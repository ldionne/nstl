/**
 * This file defines the @em is_equal and @em is_equal_comp algorithms.
 *
 * @note This algorithm is equivalent to the @em equal algorithm of the C++
 *       standard library.
 */

#ifndef NSTL_ALGORITHM_IS_EQUAL_H
#define NSTL_ALGORITHM_IS_EQUAL_H

#include <nstl/internal.h>


#define NSTL_IS_EQUAL(SinglePassReadableIterator,                              \
                      IncrementableReadableIterator, ValueType)                \
    NSTL_I_IS_EQUAL(                                                           \
        nstl_is_equal(SinglePassReadableIterator,                              \
                      IncrementableReadableIterator),                          \
        SinglePassReadableIterator,                                            \
        IncrementableReadableIterator,                                         \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_IS_EQUAL(algo, Iter1, Iter2, Value)                             \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun is_equal                                                                \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(Value, Value);               \
NSTL_GETF(                                                                     \
    NSTL_I_IS_EQUAL_COMP(                                                      \
        nstl_helper(algo, impl),                                               \
        Iter1,                                                                 \
        Iter2,                                                                 \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    is_equal_comp                                                              \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_bool algo(Iter1 first1, Iter1 last1, Iter2 first2) {   \
    return nstl_helper(algo, impl)(first1, last1, first2,                      \
                                                    nstl_eq(Value, Value));    \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_IS_EQUAL_COMP(SinglePassReadableIterator,                         \
                           IncrementableReadableIterator, Compare)             \
    NSTL_I_IS_EQUAL_COMP(                                                      \
        nstl_is_equal_comp(SinglePassReadableIterator,                         \
                           IncrementableReadableIterator, Compare),            \
        SinglePassReadableIterator,                                            \
        IncrementableReadableIterator,                                         \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_IS_EQUAL_COMP(algo, Iter1, Iter2, Comp)                         \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun is_equal_comp                                                           \
static nstl_bool algo(Iter1 first1_, Iter1 last1, Iter2 first2_, Comp comp) {  \
    Iter1 first1;                                                              \
    Iter2 first2;                                                              \
    nstl_copy_ctor(Iter1)(&first1, first1_);                                   \
    nstl_copy_ctor(Iter2)(&first2, first2_);                                   \
                                                                               \
    for ( ; nstl_ne(Iter1, Iter1)(first1, last1); nstl_inc(Iter1)(&first1),    \
                                                  nstl_inc(Iter2)(&first2))    \
        if (!(comp(nstl_deref(Iter1)(first1), nstl_deref(Iter2)(first2)))) {   \
            nstl_dtor(Iter1)(&first1);                                         \
            nstl_dtor(Iter2)(&first2);                                         \
            return nstl_false;                                                 \
        }                                                                      \
                                                                               \
    nstl_dtor(Iter1)(&first1);                                                 \
    nstl_dtor(Iter2)(&first2);                                                 \
    return nstl_true;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'is_equal(SinglePassReadableIterator, IncrementableReadableIterator)',
    'is_equal_comp(SinglePassReadableIterator, ' +
                                    'IncrementableReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_is_equal (i s _ e q u a l)
#define nstl_is_equal(SinglePassReadableIterator,  IncrementableReadableIterator) JOY_CAT5(nstl_mangled_is_equal, _, SinglePassReadableIterator, _,  IncrementableReadableIterator)
#define NSTL_TOKEN_is_equal_comp (i s _ e q u a l _ c o m p)
#define nstl_is_equal_comp(SinglePassReadableIterator,  IncrementableReadableIterator,  Compare) JOY_CAT7(nstl_mangled_is_equal_comp, _, SinglePassReadableIterator, _,  IncrementableReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_IS_EQUAL_H */
