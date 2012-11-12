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
#include <nstl/iterator/traits.h>
#include <nstl/utility/pair.h>


#define NSTL_EQUAL_RANGE(ForwardTraversalReadableIteratorTraits, T)            \
    NSTL_EQUAL_RANGE_NAMED(                                                    \
        nstl_equal_range(                                                      \
                NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits)), \
        ForwardTraversalReadableIteratorTraits,                                \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_EQUAL_RANGE_NAMED(AlgorithmName,                                  \
                               ForwardTraversalReadableIteratorTraits, T)      \
    NSTL_I_EQUAL_RANGE(                                                        \
        AlgorithmName,                                                         \
        ForwardTraversalReadableIteratorTraits,                                \
        NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        T                                                                      \
    )                                                                          \
/**/

#define NSTL_I_EQUAL_RANGE(algo, Traits, Iter, T)                              \
NSTL_TYPE(algo,                                                                \
(defun equal_range                                                             \
                                                                               \
typedef nstl_bool (*nstl_helper(algo, impl_comp))(T, T);                       \
NSTL_GETF(                                                                     \
    NSTL_EQUAL_RANGE_NAMED_COMP(                                               \
        nstl_helper(algo, impl),                                               \
        Traits,                                                                \
        T,                                                                     \
        nstl_helper(algo, impl_comp)                                           \
    ),                                                                         \
    equal_range_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE nstl_pair(Iter, Iter) algo(Iter first, Iter last,T value) { \
    return nstl_helper(algo, impl)(first, last, value, nstl_lt(T, T));         \
}                                                                              \
                                                                               \
))                                                                             \
/**/


#define NSTL_EQUAL_RANGE_COMP(ForwardTraversalReadableIteratorTraits,          \
                              T, Compare)                                      \
    NSTL_EQUAL_RANGE_NAMED_COMP(                                               \
        nstl_equal_range_comp(                                                 \
            NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),      \
            Compare),                                                          \
        ForwardTraversalReadableIteratorTraits,                                \
        T,                                                                     \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_EQUAL_RANGE_NAMED_COMP(AlgorithmName,                             \
                                    ForwardTraversalReadableIteratorTraits,    \
                                    T, Compare)                                \
    NSTL_I_EQUAL_RANGE_COMP(                                                   \
        AlgorithmName,                                                         \
        NSTL_TRAIT_SELF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        T,                                                                     \
        Compare,                                                               \
        NSTL_TRAIT_DIFF_TYPE(ForwardTraversalReadableIteratorTraits),          \
        ForwardTraversalReadableIteratorTraits                                 \
    )                                                                          \
/**/

#define NSTL_I_EQUAL_RANGE_COMP(algo, Iter, T, Comp, Distance, Traits)         \
NSTL_TYPE(this_func,                                                           \
(defun equal_range_comp                                                        \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_DISTANCE_NAMED(                                                       \
        nstl_helper(algo, distance),                                           \
        Traits                                                                 \
    ),                                                                         \
    distance                                                                   \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_ADVANCE_NAMED(                                                        \
        nstl_helper(algo, advance),                                            \
        Traits                                                                 \
    ),                                                                         \
    advance                                                                    \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_UPPER_BOUND_COMP(                                                   \
        nstl_helper(algo, upper_bound_comp),                                   \
        Iter,                                                                  \
        T,                                                                     \
        Comp                                                                   \
    ),                                                                         \
    upper_bound_comp                                                           \
)                                                                              \
                                                                               \
NSTL_GETF(                                                                     \
    NSTL_I_LOWER_BOUND_COMP(                                                   \
        nstl_helper(algo, lower_bound_comp),                                   \
        Iter,                                                                  \
        T,                                                                     \
        Comp                                                                   \
    ),                                                                         \
    lower_bound_comp                                                           \
)                                                                              \
                                                                               \
static NSTL_INLINE T nstl_helper(algo, deref)(Iter it_) {                      \
    nstl_deref_proxy(Iter) proxy;                                              \
    T result;                                                                  \
    nstl_ctor(nstl_deref_proxy(Iter))(&proxy, it_);                            \
    result = nstl_get(nstl_deref_proxy(Iter))(proxy);                          \
    nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                                 \
    return result;                                                             \
}                                                                              \
                                                                               \
static nstl_pair(Iter, Iter) algo(Iter first_, Iter last_,                     \
                                  T value_, Comp comp_) {                      \
    Iter first;                                                                \
    Distance len = nstl_helper(algo, distance)(first_, last_);                 \
    Distance half;                                                             \
    nstl_pair(Iter, Iter) result;                                              \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    while (nstl_gt(Distance, Distance)(len, 0)) {                              \
        Iter middle;                                                           \
        T at_middle;                                                           \
        nstl_copy_ctor(Iter)(&middle, first);                                  \
                                                                               \
        half = nstl_div(Distance, Distance)(len, 2);                           \
        nstl_helper(algo, advance)(&middle, half);                             \
        /* Note: It is allright to cache the value like this since the comp is \
         *       already used like comp(Value, return_type_of_nstl_get) and    \
         *       comp(return_type_of_nstl_get, Value) in the StlPort           \
         *       implementation. We do not suffer a loss of generality by      \
         *       using the Value type to store the cached copy because both    \
         *       arguments of comp must be convertible to Value.               \
         */                                                                    \
        at_middle = nstl_helper(algo, deref)(middle);                          \
        if (comp_(at_middle, value_)) {                                        \
            Distance half_plus_one = nstl_add(Distance, Distance)(half, 1);    \
            nstl_isub(Distance, Distance)(&len, half_plus_one);                \
            nstl_dtor(Distance)(&half_plus_one);                               \
            nstl_asg(Iter, Iter)(&first, middle);                              \
            nstl_inc(Iter)(&first);                                            \
        }                                                                      \
        else if (comp_(value_, at_middle)) {                                   \
            nstl_asg(Distance, Distance)(&len, half);                          \
        }                                                                      \
        else {                                                                 \
            Iter left = nstl_helper(algo, lower_bound_comp)(first, middle,     \
                                                            value_, comp_);    \
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
                if (comp_(nstl_helper(algo, deref)(left), value_)) {           \
                    nstl_assert_true(nstl_false);                              \
                    result = nstl_make_pair(Iter, Iter)(left, left);           \
                    goto ret_from_inside_loop;                                 \
                }                                                              \
            ) /* end NSTL_CONFIG_INTERNAL_DEBUG */                             \
                                                                               \
            nstl_helper(algo, advance)(&first, len);                           \
            right = nstl_helper(algo, upper_bound_comp)                        \
                            (nstl_inc(Iter)(&middle), first, value_, comp_);   \
            result = nstl_make_pair(Iter, Iter)(left, right);                  \
            nstl_dtor(Iter)(&right);                                           \
                                                                               \
ret_from_inside_loop:                                                          \
            nstl_dtor(Iter)(&left);                                            \
            nstl_dtor(Distance)(&half);                                        \
            nstl_dtor(Iter)(&middle);                                          \
            nstl_dtor(Iter)(&first);                                           \
            return result;                                                     \
        }                                                                      \
        nstl_dtor(Distance)(&half);                                            \
        nstl_dtor(Iter)(&middle);                                              \
    }                                                                          \
    result = nstl_make_pair(Iter, Iter)(first, first);                         \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return result;                                                             \
}                                                                              \
                                                                               \
))                                                                             \
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
