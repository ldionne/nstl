/**
 * This file defines the @em equal_range and @em equal_range_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_EQUAL_RANGE_H
#define NSTL_ALGORITHM_EQUAL_RANGE_H

#include <nstl/algorithm/advance.h>
#include <nstl/algorithm/distance.h>
#include <nstl/algorithm/lower_bound.h>
#include <nstl/algorithm/upper_bound.h>
#include <nstl/internal.h>
#include <nstl/utility/pair.h>


#define NSTL_EQUAL_RANGE(ForwardTraversalReadableIterator, ValueType)          \
    NSTL_I_EQUAL_RANGE(                                                        \
        nstl_equal_range(ForwardTraversalReadableIterator),                    \
        ForwardTraversalReadableIterator,                                      \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_EQUAL_RANGE(algo, Iter, Value)                                  \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun equal_range                                                             \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(Value, Value);               \
NSTL_GETF(                                                                     \
    NSTL_I_EQUAL_RANGE_COMP(                                                   \
        nstl_helper(algo, impl),                                               \
        Iter,                                                                  \
        Value,                                                                 \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    equal_range_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_pair(Iter, Iter) algo(Iter first, Iter last,           \
                                                          Value value) {       \
    return nstl_helper(algo, impl)(first, last, value, nstl_lt(Value, Value)); \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_EQUAL_RANGE_COMP(ForwardTraversalReadableIterator, ValueType,     \
                                                                Compare)       \
    NSTL_I_EQUAL_RANGE_COMP(                                                   \
        nstl_equal_range_comp(ForwardTraversalReadableIterator, Compare),      \
        ForwardTraversalReadableIterator,                                      \
        ValueType,                                                             \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_EQUAL_RANGE_COMP(algo, Iter, Value, Comp)                       \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun equal_range_comp                                                        \
NSTL_GETF(                                                                     \
    NSTL_I_DISTANCE(                                                           \
        nstl_helper(algo, distance),                                           \
        Iter                                                                   \
    ),                                                                         \
    distance                                                                   \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_ADVANCE(                                                            \
        nstl_helper(algo, advance),                                            \
        Iter,                                                                  \
        nstl_ptrdiff_t,                                                        \
        /*is_bidirectionnal=*/ 0                                               \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_UPPER_BOUND_COMP(                                                   \
        nstl_helper(algo, upper_bound_comp),                                   \
        Iter,                                                                  \
        Value,                                                                 \
        Comp                                                                   \
    ),                                                                         \
    upper_bound_comp                                                           \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_helper(algo, lower_bound_comp),                                   \
        Iter,                                                                  \
        Value,                                                                 \
        Comp                                                                   \
    ),                                                                         \
    lower_bound_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE Value nstl_helper(algo, deref)(Iter it) {                   \
    nstl_deref_proxy(Iter) proxy;                                              \
    Value ret;                                                                 \
    nstl_ctor(nstl_deref_proxy(Iter))(&proxy, it);                             \
    ret = nstl_get(nstl_deref_proxy(Iter))(proxy);                             \
    nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                                 \
    return ret;                                                                \
}                                                                              \
                                                                               \
static nstl_pair(Iter, Iter) algo(Iter first_, Iter last, Value value,         \
                                                          Comp comp) {         \
    Iter first;                                                                \
    nstl_ptrdiff_t len = nstl_helper(algo, distance)(first_, last);            \
    nstl_ptrdiff_t half;                                                       \
    nstl_pair(Iter, Iter) ret;                                                 \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (len > 0) {                                                          \
        Iter middle;                                                           \
        Value at_middle;                                                       \
        nstl_copy_ctor(Iter)(&middle, first);                                  \
                                                                               \
        half = len / 2;                                                        \
        nstl_helper(algo, advance)(&middle, half);                             \
        /* Note: It is allright to cache the value like this since the comp is \
         *       already used like comp(Value, return_type_of_nstl_get) and    \
         *       comp(return_type_of_nstl_get, Value) in the StlPort           \
         *       implementation. We do not suffer a loss of generality by      \
         *       using the Value type to store the cached copy because both    \
         *       arguments of comp must be convertible to Value.               \
         */                                                                    \
        at_middle = nstl_helper(algo, deref)(middle);                          \
        if (comp(at_middle, value)) {                                          \
            nstl_asg(Iter, Iter)(&first, middle);                              \
            nstl_inc(Iter)(&first);                                            \
            len = len - half - 1;                                              \
        }                                                                      \
        else if (comp(value, at_middle)) {                                     \
            len = half;                                                        \
        }                                                                      \
        else {                                                                 \
            Iter left = nstl_helper(algo, lower_bound_comp)(first, middle,     \
                                                                value, comp);  \
            Iter right;                                                        \
                                                                               \
            /* This is an optimization that was originally present in the      \
             * StlPort stl:                                                    \
             * If lower_bound haven't found an equivalent value there is no    \
             * need to call upper_bound.                                       \
             *                                                                 \
             * However, I think that it is impossible to reach the code inside \
             * the if statement:                                               \
             * If we are in the current else branch of the if/else-if/else     \
             * construct above, it means that *middle is equivalent to value.  \
             * Since middle is also the past-the-end element of the range      \
             * passed to lower_bound, the result of calling lower_bound must   \
             * be either an iterator to a previous element equivalent to       \
             * value, or middle itself (if no element was found). In both      \
             * cases, *left __must__ be equivalent to value, and the branch    \
             * can't be reached.                                               \
             */                                                                \
            NSTL_STATIC_WHEN(NSTL_CONFIG_INTERNAL_DEBUG)(                      \
                if (comp(nstl_helper(algo, deref)(left), value)) {             \
                    nstl_assert_true(nstl_false);                              \
                    ret = nstl_make_pair(Iter, Iter)(left, left);              \
                    nstl_dtor(Iter)(&left);                                    \
                    nstl_dtor(Iter)(&middle);                                  \
                    nstl_dtor(Iter)(&first);                                   \
                    return ret;                                                \
                }                                                              \
            ) /* end NSTL_CONFIG_INTERNAL_DEBUG */                             \
                                                                               \
            nstl_helper(algo, advance)(&first, len);                           \
            right = nstl_helper(algo, upper_bound_comp)                        \
                                (nstl_inc(Iter)(&middle), first, value, comp); \
            ret = nstl_make_pair(Iter, Iter)(left, right);                     \
            nstl_dtor(Iter)(&right);                                           \
            nstl_dtor(Iter)(&left);                                            \
            nstl_dtor(Iter)(&middle);                                          \
            nstl_dtor(Iter)(&first);                                           \
            return ret;                                                        \
        }                                                                      \
        nstl_dtor(Iter)(&middle);                                              \
    }                                                                          \
    ret = nstl_make_pair(Iter, Iter)(first, first);                            \
    nstl_dtor(Iter)(&first);                                                   \
    return ret;                                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'equal_range(ForwardTraversalReadableIterator)',
    'equal_range_comp(ForwardTraversalReadableIterator, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_equal_range (e q u a l _ r a n g e)
#define nstl_equal_range(ForwardTraversalReadableIterator) JOY_CAT3(nstl_mangled_equal_range, _, ForwardTraversalReadableIterator)
#define NSTL_TOKEN_equal_range_comp (e q u a l _ r a n g e _ c o m p)
#define nstl_equal_range_comp(ForwardTraversalReadableIterator,  Compare) JOY_CAT5(nstl_mangled_equal_range_comp, _, ForwardTraversalReadableIterator, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_EQUAL_RANGE_H */
