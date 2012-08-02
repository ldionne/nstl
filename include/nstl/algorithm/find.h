/**
 * This file defines the @em find algorithm.
 */

#ifndef NSTL_ALGORITHM_FIND_H
#define NSTL_ALGORITHM_FIND_H

#include <nstl/internal.h>


#define NSTL_FIND(InputIter, ValueType) \
    NSTL_I_FIND(nstl_find(InputIter, ValueType), InputIter, ValueType)

#define NSTL_I_FIND(this_func, InputIter, ValueType)                           \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun find                                                                    \
static NSTL_INLINE InputIter this_func                                         \
                    (InputIter first, InputIter last, ValueType const value) { \
    while (nstl_ne(InputIter, InputIter)(first, last) &&                       \
           nstl_ne(ValueType, ValueType)(nstl_deref(InputIter)(first), value)) \
        nstl_inc(InputIter)(&first);                                           \
    return first;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'find(InputIter, ValueType)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find (f i n d)
#define nstl_find(InputIter,  ValueType) JOY_CAT5(nstl_mangled_find, _, InputIter, _,  ValueType)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_H */
