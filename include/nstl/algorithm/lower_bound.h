/**
 * This file defines the @em lower_bound and @em lower_bound_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_LOWER_BOUND_H
#define NSTL_ALGORITHM_LOWER_BOUND_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_LOWER_BOUND(FwdIter, ValueType) \
    NSTL_I_LOWER_BOUND(nstl_lower_bound(FwdIter), FwdIter, ValueType)

#define NSTL_I_LOWER_BOUND(this_func, FwdIter, ValueType)                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun lower_bound                                                             \
typedef nstl_bool (*nstl_helper(this_func, impl_comp))(ValueType, ValueType);  \
                                                                               \
NSTL_GETF(NSTL_I_LOWER_BOUND_COMP(nstl_helper(this_func, impl), FwdIter,       \
            ValueType, nstl_helper(this_func, impl_comp)), lower_bound_comp)   \
                                                                               \
static FwdIter this_func(FwdIter first, FwdIter last, ValueType value) {       \
    return nstl_helper(this_func, impl)                                        \
                        (first, last, value, nstl_lt(ValueType, ValueType));   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_LOWER_BOUND_COMP(FwdIter, ValueType, Compare)                     \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_lower_bound_comp(FwdIter, Compare), FwdIter, ValueType, Compare   \
    )                                                                          \
/**/

#define NSTL_I_LOWER_BOUND_COMP(this_func, FwdIter, ValueType, Compare)        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun lower_bound_comp                                                        \
NSTL_GETF(NSTL_I_DISTANCE(                                                     \
    nstl_helper(this_func, distance), FwdIter), distance)                      \
NSTL_GETF(NSTL_I_ADVANCE(                                                      \
    nstl_helper(this_func, advance), FwdIter, nstl_ptrdiff_t,                  \
                                        /*is_bidirectionnal=*/ 0), advance)    \
static FwdIter this_func                                                       \
            (FwdIter first_, FwdIter last, ValueType value, Compare comp) {    \
    nstl_ptrdiff_t len = nstl_helper(this_func, distance)(first_, last);       \
    nstl_ptrdiff_t half;                                                       \
    FwdIter first;                                                             \
    nstl_copy_ctor(FwdIter)(&first, first_);                                   \
                                                                               \
    while (len > 0) {                                                          \
        FwdIter middle;                                                        \
        nstl_copy_ctor(FwdIter)(&middle, first);                               \
        half = len / 2;                                                        \
        nstl_helper(this_func, advance)(&middle, half);                        \
        if (comp(nstl_deref(FwdIter)(middle), value)) {                        \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
        }                                                                      \
        else {                                                                 \
            len = half;                                                        \
        }                                                                      \
        nstl_dtor(FwdIter)(&middle);                                           \
    }                                                                          \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'lower_bound(FwdIter)',
    'lower_bound_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_lower_bound (l o w e r _ b o u n d)
#define nstl_lower_bound(FwdIter) JOY_CAT3(nstl_mangled_lower_bound, _, FwdIter)
#define NSTL_TOKEN_lower_bound_comp (l o w e r _ b o u n d _ c o m p)
#define nstl_lower_bound_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_lower_bound_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_LOWER_BOUND_H */
