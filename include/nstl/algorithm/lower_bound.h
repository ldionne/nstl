/**
 * This file defines the @em lower_bound and @em lower_bound_cmp algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_LOWER_BOUND_H
#define NSTL_ALGORITHM_LOWER_BOUND_H

#include <nstl/internal.h>


#define NSTL_LOWER_BOUND(FwdIter, ValueType)                                   \
NSTL_TYPE(nstl_lower_bound(FwdIter),                                           \
                                                                               \
(defun lower_bound                                                             \
/**                                                                            \
 * Return an iterator pointing to the first element in the sorted range        \
 * [@p first, @p last) which does not compare less than @p value.              \
 *                                                                             \
 * The comparison is done using the @em nstl_lt operator.                      \
 * For the algorithm to yield the expected result, the elements in the range   \
 * must already be ordered according to the same criterion.                    \
 *                                                                             \
 * Unlike @em nstl_upper_bound, this algorithm returns an iterator to the      \
 * element also if it compares qeuivalent to @p value and not only if it       \
 * compares greater.                                                           \
 */                                                                            \
static FwdIter nstl_lower_bound(FwdIter)                                       \
                            (FwdIter first, FwdIter last, ValueType value) {   \
                                                                               \
    ptrdiff_t len = nstl_distance(FwdIter)(first, last);                       \
    ptrdiff_t half;                                                            \
    FwdIter middle;                                                            \
    nstl_def_ctor(FwdIter)(&middle);                                           \
                                                                               \
    while (len > 0) {                                                          \
        half = len >> 1; /* faster way of doing (len / 2) */                   \
        nstl_asg(FwdIter, FwdIter)(&middle, first);                            \
        nstl_advance(FwdIter, ptrdiff_t)(&middle, half);                       \
        if (nstl_lt(ValueType, ValueType)                                      \
                                    (nstl_deref(FwdIter)(middle), value)) {    \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
        }                                                                      \
        else {                                                                 \
            len = half;                                                        \
        }                                                                      \
    }                                                                          \
    nstl_dtor(FwdIter)(&middle);                                               \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_LOWER_BOUND_CMP(FwdIter, ValueType, Compare)                      \
NSTL_TYPE(nstl_lower_bound_cmp(FwdIter, Compare),                              \
                                                                               \
(defun lower_bound_cmp                                                         \
/**                                                                            \
 * Return an iterator pointing to the first element in the sorted range        \
 * [@p first, @p last) which does not compare less than @p value.              \
 *                                                                             \
 * The comparison is done using the @p comp predicate.                         \
 * For the algorithm to yield the expected result, the elements in the range   \
 * must already be ordered according to the same criterion.                    \
 *                                                                             \
 * Unlike @em nstl_upper_bound, this algorithm returns an iterator to the      \
 * element also if it compares qeuivalent to @p value and not only if it       \
 * compares greater.                                                           \
 */                                                                            \
static FwdIter nstl_lower_bound_cmp(FwdIter, Compare)                          \
                (FwdIter first, FwdIter last, ValueType value, Compare comp) { \
                                                                               \
    ptrdiff_t len = nstl_distance(FwdIter)(first, last);                       \
    ptrdiff_t half;                                                            \
    FwdIter middle;                                                            \
    nstl_def_ctor(FwdIter)(&middle);                                           \
                                                                               \
    while (len > 0) {                                                          \
        half = len >> 1; /* faster way of doing (len / 2) */                   \
        nstl_asg(FwdIter, FwdIter)(&middle, first);                            \
        nstl_advance(FwdIter, ptrdiff_t)(&middle, half);                       \
        if (comp(nstl_deref(FwdIter)(middle), value)) {                        \
            nstl_asg(FwdIter, FwdIter)(&first, middle);                        \
            nstl_inc(FwdIter)(&first);                                         \
            len = len - half - 1;                                              \
        }                                                                      \
        else {                                                                 \
            len = half;                                                        \
        }                                                                      \
    }                                                                          \
    nstl_dtor(FwdIter)(&middle);                                               \
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
    'lower_bound_cmp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_lower_bound (l o w e r _ b o u n d)
#define nstl_lower_bound(FwdIter) JOY_CAT3(nstl_mangled_lower_bound, _, FwdIter)
#define NSTL_TOKEN_lower_bound_cmp (l o w e r _ b o u n d _ c m p)
#define nstl_lower_bound_cmp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_lower_bound_cmp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_LOWER_BOUND_H */
