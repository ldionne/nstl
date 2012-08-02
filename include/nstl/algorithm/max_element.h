/**
 * This file defines the @em max_element and @em max_element_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_MAX_ELEMENT_H
#define NSTL_ALGORITHM_MAX_ELEMENT_H

#include <nstl/internal.h>


#define NSTL_MAX_ELEMENT(FwdIter, ValueType) \
    NSTL_I_MAX_ELEMENT(nstl_max_element(FwdIter), FwdIter, ValueType)

#define NSTL_I_MAX_ELEMENT(this_func, FwdIter, ValueType)                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun max_element                                                             \
static NSTL_INLINE FwdIter this_func(FwdIter first, FwdIter last) {            \
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

#define NSTL_MAX_ELEMENT_COMP(FwdIter, ValueType, Compare)                     \
    NSTL_I_MAX_ELEMENT_COMP(                                                   \
        nstl_max_element_comp(FwdIter, Compare), FwdIter, ValueType, Compare   \
    )                                                                          \
/**/

#define NSTL_I_MAX_ELEMENT_COMP(this_func, FwdIter, ValueType, Compare)        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun max_element_comp                                                        \
static NSTL_INLINE FwdIter this_func                                           \
                                (FwdIter first, FwdIter last, Compare comp) {  \
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
    'max_element_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max_element (m a x _ e l e m e n t)
#define nstl_max_element(FwdIter) JOY_CAT3(nstl_mangled_max_element, _, FwdIter)
#define NSTL_TOKEN_max_element_comp (m a x _ e l e m e n t _ c o m p)
#define nstl_max_element_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_max_element_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_ELEMENT_H */
