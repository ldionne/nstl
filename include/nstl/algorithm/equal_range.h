/**
 * This file defines the @em equal_range and @em equal_range_comp algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_EQUAL_RANGE_H
#define NSTL_ALGORITHM_EQUAL_RANGE_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/algorithm/lower_bound.h>
#include <nstl/algorithm/upper_bound.h>
#include <nstl/internal.h>
#include <nstl/pair.h>


#define NSTL_EQUAL_RANGE(FwdIter, ValueType) \
    NSTL_I_EQUAL_RANGE(nstl_equal_range(FwdIter), FwdIter, ValueType)

#define NSTL_I_EQUAL_RANGE(this_func, FwdIter, ValueType)                      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun equal_range                                                             \
NSTL_GETF(NSTL_I_DISTANCE(nstl_helper(this_func, distance), FwdIter),          \
                                                                    distance)  \
NSTL_GETF(NSTL_I_ADVANCE(nstl_helper(this_func, advance), FwdIter,             \
                                                    nstl_ptrdiff_t), advance)  \
NSTL_GETF(NSTL_I_UPPER_BOUND(nstl_helper(this_func, upper_bound), FwdIter,     \
                                                    ValueType), upper_bound)   \
NSTL_GETF(NSTL_I_LOWER_BOUND(nstl_helper(this_func, lower_bound), FwdIter,     \
                                                    ValueType), lower_bound)   \
/**                                                                            \
 * Return the bounds of the largest subrange included in the range delimited   \
 * by [@p first, @p last) with values equivalent to @p value.                  \
 *                                                                             \
 * The comparison is performed using the @em nstl_lt operator. A value @em a   \
 * is considered to a value @em b when @code (!(a < b) && !(b < a)) @endcode . \
 * If @p value is not equivalent to any value in the range, the subrange       \
 * returned has a length of zero, with both iterators pointing to the nearest  \
 * value greater than @p value, if any, or to @p last, if @p value compares    \
 * greater than all the elements in the range.                                 \
 *                                                                             \
 * @note For the algorithm to yield the expected result, the elements in the   \
 *       range must already be ordered using the same criterion.               \
 */                                                                            \
static nstl_pair(FwdIter, FwdIter) this_func                                   \
                            (FwdIter first, FwdIter last, ValueType value) {   \
    nstl_ptrdiff_t len = nstl_helper(this_func, distance)(first, last);        \
    nstl_ptrdiff_t half;                                                       \
    while (len > 0) {                                                          \
        FwdIter middle;                                                        \
        half = len >> 1; /* faster way of doing (len / 2) */                   \
        nstl_copy_ctor(FwdIter)(&middle, first);                               \
        nstl_helper(this_func, advance)(&middle, half);                        \
        if (nstl_lt(ValueType, ValueType)                                      \
                                    (nstl_deref(FwdIter)(middle), value)) {    \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
        }                                                                      \
        else if (nstl_lt(ValueType, ValueType)                                 \
                                    (value, nstl_deref(FwdIter)(middle))) {    \
            len = half;                                                        \
        }                                                                      \
        else {                                                                 \
            FwdIter left;                                                      \
            FwdIter right;                                                     \
            nstl_copy_ctor(FwdIter)(&left,                                     \
                nstl_helper(this_func, lower_bound)(first, middle, value));    \
            /* Optimization: If lower_bound haven't found an equivalent value  \
             *               there is no need to call upper_bound.             \
             */                                                                \
            if (nstl_lt(ValueType, ValueType)                                  \
                                        (nstl_deref(FwdIter)(left), value)) {  \
                return nstl_make_pair(FwdIter, FwdIter)(left, left);           \
            }                                                                  \
            nstl_helper(this_func, advance)(&first, len);                      \
            nstl_copy_ctor(FwdIter)(&right,                                    \
                            nstl_helper(this_func, upper_bound)                \
                                (nstl_inc(FwdIter)(&middle), first, value));   \
            return nstl_make_pair(FwdIter, FwdIter)(left, right);              \
        }                                                                      \
    }                                                                          \
    return nstl_make_pair(FwdIter, FwdIter)(first, first);                     \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_EQUAL_RANGE_COMP(FwdIter, ValueType, Compare)                     \
    NSTL_I_EQUAL_RANGE_COMP(                                                   \
        nstl_equal_range_comp(FwdIter, Compare), FwdIter, ValueType, Compare   \
    )                                                                          \
/**/

#define NSTL_I_EQUAL_RANGE_COMP(this_func, FwdIter, ValueType, Compare)        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun equal_range_comp                                                        \
NSTL_GETF(NSTL_I_DISTANCE(nstl_helper(this_func, distance), FwdIter),          \
                                                                    distance)  \
NSTL_GETF(NSTL_I_ADVANCE(nstl_helper(this_func, advance), FwdIter,             \
                                                    nstl_ptrdiff_t), advance)  \
NSTL_GETF(NSTL_I_UPPER_BOUND_COMP(nstl_helper(this_func, upper_bound_comp),    \
                            FwdIter, ValueType, Compare), upper_bound_comp)    \
NSTL_GETF(NSTL_I_LOWER_BOUND_COMP(nstl_helper(this_func, lower_bound_comp),    \
                            FwdIter, ValueType, Compare), lower_bound_comp)    \
/**                                                                            \
 * Return the bounds of the largest subrange included in the range delimited   \
 * by [@p first, @p last) with values equivalent to @p value.                  \
 *                                                                             \
 * The comparison is performed using the @p comp comparator. A value @em a is  \
 * considered to a value @em b when @code (!comp(a, b) && !comp(b, a))         \
 * @endcode . If @p value is not equivalent to any value in the range, the     \
 * subrange returned has a length of zero, with both iterators pointing to     \
 * the nearest value greater than @p value, if any, or to @p last, if          \
 * @p value compares greater than all the elements in the range.               \
 *                                                                             \
 * @note For the algorithm to yield the expected result, the elements in the   \
 *       range must already be ordered using the same criterion.               \
 */                                                                            \
static nstl_pair(FwdIter, FwdIter) this_func                                   \
                (FwdIter first, FwdIter last, ValueType value, Compare comp) { \
    nstl_ptrdiff_t len = nstl_helper(this_func, distance)(first, last);        \
    nstl_ptrdiff_t half;                                                       \
    while (len > 0) {                                                          \
        FwdIter middle;                                                        \
        half = len >> 1; /* faster way of doing (len / 2) */                   \
        nstl_copy_ctor(FwdIter)(&middle, first);                               \
        nstl_helper(this_func, advance)(&middle, half);                        \
        if (comp(nstl_deref(FwdIter)(middle), value)) {                        \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
        }                                                                      \
        else if (comp(value, nstl_deref(FwdIter)(middle))) {                   \
            len = half;                                                        \
        }                                                                      \
        else {                                                                 \
            FwdIter left;                                                      \
            FwdIter right;                                                     \
            nstl_copy_ctor(FwdIter)(&left,                                     \
                                    nstl_helper(this_func, lower_bound_comp)   \
                                                (first, middle, value, comp)); \
            /* Optimization: If lower_bound haven't found an equivalent value  \
             *               there is no need to call upper_bound.             \
             */                                                                \
            if (comp(nstl_deref(FwdIter)(left), value)) {                      \
                return nstl_make_pair(FwdIter, FwdIter)(left, left);           \
            }                                                                  \
            nstl_helper(this_func, advance)(&first, len);                      \
            nstl_copy_ctor(FwdIter)(&right,                                    \
                        nstl_helper(this_func, upper_bound_comp)               \
                            (nstl_inc(FwdIter)(&middle), first, value, comp)); \
            return nstl_make_pair(FwdIter, FwdIter)(left, right);              \
        }                                                                      \
    }                                                                          \
    return nstl_make_pair(FwdIter, FwdIter)(first, first);                     \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'equal_range(FwdIter)',
    'equal_range_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_equal_range (e q u a l _ r a n g e)
#define nstl_equal_range(FwdIter) JOY_CAT3(nstl_mangled_equal_range, _, FwdIter)
#define NSTL_TOKEN_equal_range_comp (e q u a l _ r a n g e _ c o m p)
#define nstl_equal_range_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_equal_range_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_EQUAL_RANGE_H */
