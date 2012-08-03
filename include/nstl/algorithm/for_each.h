/**
 * This file defines the @em for_each algorithm.
 */

#ifndef NSTL_ALGORITHM_FOR_EACH_H
#define NSTL_ALGORITHM_FOR_EACH_H

#include <nstl/internal.h>


#define NSTL_FOR_EACH(InputIter, Function) \
    NSTL_I_FOR_EACH(nstl_for_each(InputIter, Function), InputIter, Function)

#define NSTL_I_FOR_EACH(this_func, InputIter, Function)                        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun for_each                                                                \
static NSTL_INLINE Function this_func                                          \
                            (InputIter first_, InputIter last, Function f) {   \
    InputIter first;                                                           \
    nstl_copy_ctor(InputIter)(&first, first_);                                 \
    for ( ; nstl_ne(InputIter, InputIter)(first, last);                        \
                                                nstl_inc(InputIter)(&first))   \
        f(nstl_deref(InputIter)(first));                                       \
    nstl_dtor(InputIter)(&first);                                              \
    return f;                                                                  \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'for_each(InputIter, Function)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_for_each (f o r _ e a c h)
#define nstl_for_each(InputIter,  Function) JOY_CAT5(nstl_mangled_for_each, _, InputIter, _,  Function)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FOR_EACH_H */
