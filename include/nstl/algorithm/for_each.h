/*!
 * This file defines the @em for_each algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_FOR_EACH_H
#define NSTL_ALGORITHM_FOR_EACH_H

#include <nstl/type.h>
#include <nstl/operator.h>


#define NSTL_FOR_EACH(InputIter, Function)                                     \
NSTL_TYPE(                                                                     \
                                                                               \
(setf for_each                                                                 \
/*!                                                                            \
 * Apply a function to each element in a range delimited by [@p first, @p last). \
 * The return value of the function, if any, is ignored.                       \
 *                                                                             \
 * @param f Unary function taking a pointer to an element in the range.        \
 *                                                                             \
 * @return The function @p f.                                                  \
 */                                                                            \
static inline Function nstl_for_each(InputIter, Function)(InputIter first,     \
                                                    InputIter last, Function f) \
{                                                                              \
    for ( ; nstl_ne(InputIter, InputIter)(first, last);                        \
            nstl_inc(InputIter)(&first)) {                                     \
        f(nstl_deref(InputIter)(first));                                       \
    }                                                                          \
    return f;                                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    'for_each(InputIter, Function)',
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_for_each (f o r _ e a c h)
#define nstl_for_each(InputIter,  Function) JOY_CAT5(nstl_mangled_for_each, _, InputIter, _,  Function)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FOR_EACH_H */
