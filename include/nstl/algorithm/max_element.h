/**
 * This file defines the @em max_element algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_MAX_ELEMENT_H
#define NSTL_ALGORITHM_MAX_ELEMENT_H

#include <nstl/internal.h>


#define NSTL_MAX_ELEMENT(FwdIter, ValueType)                                   \
NSTL_TYPE(nstl_max_element(FwdIter),                                           \
                                                                               \
(defun max_element                                                             \
/**                                                                            \
 * Return an iterator pointing to the element with the largest value in the    \
 * range [@p first, @p last).                                                  \
 *                                                                             \
 * The comparisons are performed using the @em nstl_lt operator. An element    \
 * is the largest if it does not compare less than any other element, but      \
 * it may compare equal.                                                       \
 */                                                                            \
static NSTL_INLINE FwdIter nstl_max_element(FwdIter)                           \
                                            (FwdIter first, FwdIter last) {    \
    FwdIter result;                                                            \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return first;                                                          \
    nstl_copy_ctor(FwdIter)(&result, first);                                   \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&first), last))         \
        if (nstl_lt(ValueType, ValueType)(nstl_deref(FwdIter)(result),         \
                                          nstl_deref(FwdIter)(first)))         \
            nstl_asg(FwdIter, FwdIter)(&result, first);                        \
                                                                               \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_MAX_ELEMENT_CMP(FwdIter, ValueType, BinaryPredicate)              \
NSTL_TYPE(nstl_max_element_cmp(FwdIter, BinaryPredicate),                      \
                                                                               \
(defun max_element_cmp                                                         \
/**                                                                            \
 * Return an iterator pointing to the element with the largest value in the    \
 * range [@p first, @p last).                                                  \
 *                                                                             \
 * The comparisons are performed using the @p comp binary predicate. An        \
 * element is the largest if it does not compare less than any other element,  \
 * but it may compare equal.                                                   \
 */                                                                            \
static NSTL_INLINE FwdIter nstl_max_element_cmp(FwdIter, BinaryPredicate)      \
                        (FwdIter first, FwdIter last, BinaryPredicate comp) {  \
    FwdIter result;                                                            \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return first;                                                          \
    nstl_copy_ctor(FwdIter)(&result, first);                                   \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&first), last))         \
        if (comp(nstl_deref(FwdIter)(result), nstl_deref(FwdIter)(first)))     \
            nstl_asg(FwdIter, FwdIter)(&result, first);                        \
                                                                               \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'max_element(FwdIter)',
    'max_element_cmp(FwdIter, BinaryPredicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max_element (m a x _ e l e m e n t)
#define nstl_max_element(FwdIter) JOY_CAT3(nstl_mangled_max_element, _, FwdIter)
#define NSTL_TOKEN_max_element_cmp (m a x _ e l e m e n t _ c m p)
#define nstl_max_element_cmp(FwdIter,  BinaryPredicate) JOY_CAT5(nstl_mangled_max_element_cmp, _, FwdIter, _,  BinaryPredicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_ELEMENT_H */
