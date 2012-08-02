/**
 * This file defines the @em min_element and @em nstl_min_element_comp
 * algorithms.
 */

#ifndef NSTL_ALGORITHM_MIN_ELEMENT_H
#define NSTL_ALGORITHM_MIN_ELEMENT_H

#include <nstl/internal.h>


#define NSTL_MIN_ELEMENT(FwdIter, ValueType) \
    NSTL_I_MIN_ELEMENT(nstl_min_element(FwdIter), FwdIter, ValueType)

#define NSTL_I_MIN_ELEMENT(this_func, FwdIter, ValueType)                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun min_element                                                             \
static NSTL_INLINE FwdIter this_func(FwdIter first, FwdIter last) {            \
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

#define NSTL_MIN_ELEMENT_COMP(FwdIter, ValueType, Compare)                     \
    NSTL_I_MIN_ELEMENT_COMP(                                                   \
        nstl_min_element_comp(FwdIter, Compare), FwdIter, ValueType, Compare   \
    )                                                                          \
/**/

#define NSTL_I_MIN_ELEMENT_COMP(this_func, FwdIter, ValueType, Compare)        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun min_element_comp                                                        \
static NSTL_INLINE FwdIter this_func                                           \
                                (FwdIter first, FwdIter last, Compare comp) {  \
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
    'min_element_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min_element (m i n _ e l e m e n t)
#define nstl_min_element(FwdIter) JOY_CAT3(nstl_mangled_min_element, _, FwdIter)
#define NSTL_TOKEN_min_element_comp (m i n _ e l e m e n t _ c o m p)
#define nstl_min_element_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_min_element_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_ELEMENT_H */
