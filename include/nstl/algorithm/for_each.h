/*!
 * This file defines the @em for_each algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_FOR_EACH_H
#define NSTL_ALGORITHM_FOR_EACH_H

#include <nstl/type.h>


#define NSTL_FOR_EACH(input_iter, function_type)                               \
NSTL_TYPE(                                                                     \
                                                                               \
(for_each (                                                                    \
/*!                                                                            \
 * Apply a function to each element in a range delimited by [@p first, @p last). \
 * The return value of the function, if any, is ignored.                       \
 *                                                                             \
 * @param f Unary function taking a pointer to an element in the range.        \
 *                                                                             \
 * @return The function @p f.                                                  \
 */                                                                            \
static inline function_type nstl_for_each(input_iter, function_type)           \
                            (input_iter first, input_iter last, function_type f) \
{                                                                              \
    for ( ; nstl_ne(input_iter, input_iter)(first, last);                      \
            nstl_inc(input_iter)(&first)) {                                    \
        f(nstl_deref(input_iter)(first));                                      \
    }                                                                          \
    return f;                                                                  \
}                                                                              \
))                                                                             \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_attributes(
    'for_each(input_iter, function_type)',

    implement=True, token=True,
))

]]] */
#define NSTL_TOKEN_for_each (f o r _ e a c h)
#define NSTL_INSTRUCTION_for_each(s, self, implementation) \
    NSTL_INSTRUCTION_implement(s, self, for_each, implementation)
#define nstl_for_each(input_iter,  function_type) JOY_CAT5(nstl_mangled_for_each, _, input_iter, _,  function_type)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FOR_EACH_H */
