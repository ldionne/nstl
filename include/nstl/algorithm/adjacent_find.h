/**
 * This file defines the @em adjacent_find and @em adjacent_find_comp
 * algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_ADJACENT_FIND_H
#define NSTL_ALGORITHM_ADJACENT_FIND_H

#include <nstl/internal.h>


#define NSTL_ADJACENT_FIND(FwdIter, ValueType) \
    NSTL_I_ADJACENT_FIND(nstl_adjacent_find(FwdIter), FwdIter, ValueType)

#define NSTL_I_ADJACENT_FIND(this_func, FwdIter, ValueType)                    \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun adjacent_find                                                           \
static NSTL_INLINE FwdIter this_func(FwdIter first, FwdIter last) {            \
    FwdIter next;                                                              \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return last;                                                           \
    nstl_copy_ctor(FwdIter)(&next, first);                                     \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&next), last)) {        \
        if (nstl_eq(ValueType, ValueType)(nstl_deref(FwdIter)(first),          \
                                          nstl_deref(FwdIter)(next))) {        \
            nstl_dtor(FwdIter)(&next);                                         \
            return first;                                                      \
        }                                                                      \
                                                                               \
        nstl_asg(FwdIter, FwdIter)(&first, next);                              \
    }                                                                          \
    nstl_dtor(FwdIter)(&next);                                                 \
    return last;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_ADJACENT_FIND_COMP(FwdIter, ValueType, Compare)                   \
    NSTL_I_ADJACENT_FIND_COMP(                                                 \
        nstl_adjacent_find_comp(FwdIter, Compare), FwdIter, ValueType, Compare \
    )                                                                          \
/**/

#define NSTL_I_ADJACENT_FIND_COMP(this_func, FwdIter, ValueType, Compare)      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun adjacent_find_comp                                                      \
static NSTL_INLINE FwdIter this_func                                           \
                                (FwdIter first, FwdIter last, Compare comp) {  \
    FwdIter next;                                                              \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return last;                                                           \
    nstl_copy_ctor(FwdIter)(&next, first);                                     \
    while (nstl_ne(FwdIter, FwdIter)(nstl_inc(FwdIter)(&next), last)) {        \
        if (comp(nstl_deref(FwdIter)(first), nstl_deref(FwdIter)(next))) {     \
            nstl_dtor(FwdIter)(&next);                                         \
            return first;                                                      \
        }                                                                      \
                                                                               \
        nstl_asg(FwdIter, FwdIter)(&first, next);                              \
    }                                                                          \
    nstl_dtor(FwdIter)(&next);                                                 \
    return last;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'adjacent_find(FwdIter)',
    'adjacent_find_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_adjacent_find (a d j a c e n t _ f i n d)
#define nstl_adjacent_find(FwdIter) JOY_CAT3(nstl_mangled_adjacent_find, _, FwdIter)
#define NSTL_TOKEN_adjacent_find_comp (a d j a c e n t _ f i n d _ c o m p)
#define nstl_adjacent_find_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_adjacent_find_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_ADJACENT_FIND_H */
