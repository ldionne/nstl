/**
 * This file defines the @em min_element algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_MIN_ELEMENT_H
#define NSTL_ALGORITHM_MIN_ELEMENT_H

#include <nstl/internal.h>


#define NSTL_MIN_ELEMENT(FwdIter, ValueType)                                   \
NSTL_TYPE(nstl_min_element(FwdIter),                                           \
                                                                               \
(defun min_element                                                             \
static NSTL_INLINE FwdIter nstl_min_element(FwdIter)(FwdIter first,            \
                                                            FwdIter last) {    \
    FwdIter result;                                                            \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return first;                                                          \
    nstl_copy_ctor(FwdIter)(&result, first);                                   \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&first), last))         \
        if (nstl_lt(ValueType, ValueType)(nstl_deref(FwdIter)(first),          \
                                          nstl_deref(FwdIter)(result)))        \
            nstl_asg(FwdIter, FwdIter)(&result, first);                        \
                                                                               \
    return result;                                                             \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_MIN_ELEMENT_CMP(FwdIter, ValueType, BinaryPredicate)              \
NSTL_TYPE(nstl_min_element_cmp(FwdIter, BinaryPredicate),                      \
                                                                               \
(defun min_element_cmp                                                         \
static NSTL_INLINE FwdIter nstl_min_element_cmp(FwdIter, BinaryPredicate)      \
                        (FwdIter first, FwdIter last, BinaryPredicate comp) {  \
    FwdIter result;                                                            \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return first;                                                          \
    nstl_copy_ctor(FwdIter)(&result, first);                                   \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&first), last))         \
        if (comp(nstl_deref(FwdIter)(first), nstl_deref(FwdIter)(result)))     \
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
    'min_element(FwdIter)',
    'min_element_cmp(FwdIter, BinaryPredicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min_element (m i n _ e l e m e n t)
#define nstl_min_element(FwdIter) JOY_CAT3(nstl_mangled_min_element, _, FwdIter)
#define NSTL_TOKEN_min_element_cmp (m i n _ e l e m e n t _ c m p)
#define nstl_min_element_cmp(FwdIter,  BinaryPredicate) JOY_CAT5(nstl_mangled_min_element_cmp, _, FwdIter, _,  BinaryPredicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_ELEMENT_H */
