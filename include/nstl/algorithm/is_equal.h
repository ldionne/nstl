/**
 * This file defines the @em is_equal and @em is_equal_comp algorithms.
 *
 * @note This algorithm is equivalent to the @em equal algorithm of the C++
 *       standard library.
 */

#ifndef NSTL_ALGORITHM_IS_EQUAL_H
#define NSTL_ALGORITHM_IS_EQUAL_H

#include <nstl/internal.h>


#define NSTL_IS_EQUAL(InputIter1, InputIter2, ValueType)                       \
    NSTL_I_IS_EQUAL(nstl_is_equal(InputIter1, InputIter2),                     \
        InputIter1, InputIter2, ValueType                                      \
    )                                                                          \
/**/

#define NSTL_I_IS_EQUAL(this_func, InputIter1, InputIter2, ValueType)          \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun is_equal                                                                \
static nstl_bool this_func                                                     \
                    (InputIter1 first1, InputIter1 last1, InputIter2 first2) { \
    for ( ; nstl_ne(InputIter1, InputIter1)(first1, last1);                    \
                nstl_inc(InputIter1)(&first1), nstl_inc(InputIter2)(&first2))  \
        if (!(nstl_eq(ValueType, ValueType)(nstl_deref(InputIter1)(first1),    \
                                            nstl_deref(InputIter2)(first2))))  \
            return nstl_false;                                                 \
    return nstl_true;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_IS_EQUAL_COMP(InputIter1, InputIter2, Compare)                    \
    NSTL_I_IS_EQUAL_COMP(nstl_is_equal_comp(InputIter1, InputIter2, Compare),  \
        InputIter1, InputIter2, Compare                                        \
    )                                                                          \
/**/

#define NSTL_I_IS_EQUAL_COMP(this_func, InputIter1, InputIter2, Compare)       \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun is_equal_comp                                                           \
static nstl_bool this_func(InputIter1 first1, InputIter1 last1,                \
                                            InputIter2 first2, Compare comp) { \
    for ( ; nstl_ne(InputIter1, InputIter1)(first1, last1);                    \
                nstl_inc(InputIter1)(&first1), nstl_inc(InputIter2)(&first2))  \
        if (!(comp(nstl_deref(InputIter1)(first1),                             \
                   nstl_deref(InputIter2)(first2))))                           \
            return nstl_false;                                                 \
    return nstl_true;                                                          \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'is_equal(InputIter1, InputIter2)',
    'is_equal_comp(InputIter1, InputIter2, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_is_equal (i s _ e q u a l)
#define nstl_is_equal(InputIter1,  InputIter2) JOY_CAT5(nstl_mangled_is_equal, _, InputIter1, _,  InputIter2)
#define NSTL_TOKEN_is_equal_comp (i s _ e q u a l _ c o m p)
#define nstl_is_equal_comp(InputIter1,  InputIter2,  Compare) JOY_CAT7(nstl_mangled_is_equal_comp, _, InputIter1, _,  InputIter2, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_IS_EQUAL_H */
