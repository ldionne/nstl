/**
 * This file defines the @em upper_bound and @em upper_bound_comp algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_UPPER_BOUND_H
#define NSTL_ALGORITHM_UPPER_BOUND_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/internal.h>


#define NSTL_UPPER_BOUND(FwdIter, ValueType) \
    NSTL_I_UPPER_BOUND(nstl_upper_bound(FwdIter), FwdIter, ValueType)

#define NSTL_I_UPPER_BOUND(this_func, FwdIter, ValueType)                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun upper_bound                                                             \
NSTL_GETF(NSTL_I_DISTANCE(nstl_helper(this_func, distance), FwdIter),          \
                                                                    distance)  \
NSTL_GETF(NSTL_I_ADVANCE(nstl_helper(this_func, advance), FwdIter,             \
                                                    nstl_ptrdiff_t), advance)  \
/**                                                                            \
 * Return an iterator pointing to the first element in the sorted range        \
 * [@p first, @p last) which compares greater than @p value.                   \
 *                                                                             \
 * The comparison is done using the @em nstl_lt operator.                      \
 * For the algorithm to yield the expected result, the elements in the range   \
 * must already be sorted according to the same criterion.                     \
 *                                                                             \
 * Unlike @em nstl_lower_bound, this algorithm does not return an iterator     \
 * to the element if it compares equivalent to @p value, but only if it        \
 * compares strictly greater.                                                  \
 */                                                                            \
static FwdIter this_func(FwdIter first, FwdIter last, ValueType value) {       \
    nstl_ptrdiff_t len = nstl_helper(this_func, distance)(first, last);        \
    nstl_ptrdiff_t half;                                                       \
    while (len > 0) {                                                          \
        FwdIter middle;                                                        \
        nstl_copy_ctor(FwdIter)(&middle, first);                               \
        half = len >> 1; /* faster way of doing (len / 2) */                   \
        nstl_helper(this_func, advance)(&middle, half);                        \
        if (nstl_lt(ValueType, ValueType)                                      \
                                    (value, nstl_deref(FwdIter)(middle))) {    \
            len = half;                                                        \
        }                                                                      \
        else {                                                                 \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
        }                                                                      \
        nstl_dtor(FwdIter)(&middle);                                           \
    }                                                                          \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_UPPER_BOUND_COMP(FwdIter, ValueType, Compare)                     \
    NSTL_I_UPPER_BOUND_COMP(                                                   \
        nstl_upper_bound_comp(FwdIter, Compare), FwdIter, ValueType, Compare   \
    )                                                                          \
/**/

#define NSTL_I_UPPER_BOUND_COMP(this_func, FwdIter, ValueType, Compare)        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun upper_bound_comp                                                        \
NSTL_GETF(NSTL_I_DISTANCE(                                                     \
    nstl_helper(this_func, distance), FwdIter), distance)                      \
NSTL_GETF(NSTL_I_ADVANCE(                                                      \
    nstl_helper(this_func, advance), FwdIter, nstl_ptrdiff_t), advance)        \
/**                                                                            \
 * Return an iterator pointing to the first element in the sorted range        \
 * [@p first, @p last) which compares greater than @p value.                   \
 *                                                                             \
 * The comparison is done using the @p comp comparator.                        \
 * For the algorithm to yield the expected result, the elements in the range   \
 * must already be sorted according to the same criterion.                     \
 *                                                                             \
 * Unlike @em nstl_lower_bound, this algorithm does not return an iterator     \
 * to the element if it compares equivalent to @p value, but only if it        \
 * compares strictly greater.                                                  \
 */                                                                            \
static FwdIter this_func                                                       \
                (FwdIter first, FwdIter last, ValueType value, Compare comp) { \
    nstl_ptrdiff_t len = nstl_helper(this_func, distance)(first, last);        \
    nstl_ptrdiff_t half;                                                       \
    while (len > 0) {                                                          \
        FwdIter middle;                                                        \
        nstl_copy_ctor(FwdIter)(&middle, first);                               \
        half = len >> 1; /* faster way of doing (len / 2) */                   \
        nstl_helper(this_func, advance)(&middle, half);                        \
        if (comp(value, nstl_deref(FwdIter)(middle))) {                        \
            len = half;                                                        \
        }                                                                      \
        else {                                                                 \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
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
    'upper_bound(FwdIter)',
    'upper_bound_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_upper_bound (u p p e r _ b o u n d)
#define nstl_upper_bound(FwdIter) JOY_CAT3(nstl_mangled_upper_bound, _, FwdIter)
#define NSTL_TOKEN_upper_bound_comp (u p p e r _ b o u n d _ c o m p)
#define nstl_upper_bound_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_upper_bound_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_UPPER_BOUND_H */
