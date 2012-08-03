/**
 * This file defines the @em find_adjacent and @em find_adjacent_comp
 * algorithms.
 *
 * @note This algorithm is equivalent to the @em find_adjacent algorithm of
 *       the C++ standard library.
 */

#ifndef NSTL_ALGORITHM_FIND_ADJACENT_H
#define NSTL_ALGORITHM_FIND_ADJACENT_H

#include <nstl/internal.h>


#define NSTL_FIND_ADJACENT(FwdIter, ValueType) \
    NSTL_I_FIND_ADJACENT(nstl_find_adjacent(FwdIter), FwdIter, ValueType)

#define NSTL_I_FIND_ADJACENT(this_func, FwdIter, ValueType)                    \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun find_adjacent                                                           \
typedef nstl_bool (*nstl_helper(this_func, impl_comp))(ValueType, ValueType);  \
                                                                               \
NSTL_GETF(NSTL_I_FIND_ADJACENT_COMP(nstl_helper(this_func, impl), FwdIter,     \
            ValueType, nstl_helper(this_func, impl_comp)), find_adjacent_comp) \
                                                                               \
static NSTL_INLINE FwdIter this_func(FwdIter first, FwdIter last) {            \
    return nstl_helper(this_func, impl)                                        \
                                (first, last, nstl_eq(ValueType, ValueType));  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_FIND_ADJACENT_COMP(FwdIter, ValueType, Compare)                   \
    NSTL_I_FIND_ADJACENT_COMP(                                                 \
        nstl_find_adjacent_comp(FwdIter, Compare), FwdIter, ValueType, Compare \
    )                                                                          \
/**/

#define NSTL_I_FIND_ADJACENT_COMP(this_func, FwdIter, ValueType, Compare)      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun find_adjacent_comp                                                      \
static NSTL_INLINE FwdIter this_func                                           \
                                (FwdIter first_, FwdIter last, Compare comp) { \
    FwdIter next;                                                              \
    FwdIter first;                                                             \
    nstl_copy_ctor(FwdIter)(&first, first_);                                   \
    if (nstl_eq(FwdIter, FwdIter)(first, last))                                \
        return first;                                                          \
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
    nstl_asg(FwdIter, FwdIter)(&first, last);                                  \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'find_adjacent(FwdIter)',
    'find_adjacent_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_adjacent (f i n d _ a d j a c e n t)
#define nstl_find_adjacent(FwdIter) JOY_CAT3(nstl_mangled_find_adjacent, _, FwdIter)
#define NSTL_TOKEN_find_adjacent_comp (f i n d _ a d j a c e n t _ c o m p)
#define nstl_find_adjacent_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_find_adjacent_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_ADJACENT_H */
