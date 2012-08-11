/**
 * This file defines the @em find_if algorithm.
 *
 * @author Alexandre Girard
 */

#ifndef NSTL_ALGORITHM_FIND_IF_H
#define NSTL_ALGORITHM_FIND_IF_H

#include <nstl/internal.h>


#define NSTL_FIND_IF(InputIter, Predicate)                                     \
    NSTL_I_FIND_IF(                                                            \
        nstl_find_if(InputIter, Predicate), InputIter, Predicate               \
        )                                                                      \
    /**/

#define NSTL_I_FIND_IF(this_func, InputIter, Predicate)                        \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun find_if                                                                 \
static NSTL_INLINE InputIter this_func                                         \
                        (InputIter first, InputIter last, Predicate pred) {    \
                                                                               \
    while (nstl_ne(InputIter, InputIter)(first, last)                          \
           && !(pred(nstl_deref(InputIter)(first))))                           \
        nstl_inc(InputIter)(&first);                                           \
                                                                               \
   return first;                                                               \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
                                                                               \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'find_if(InputIter, Predicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_find_if (f i n d _ i f)
#define nstl_find_if(InputIter,  Predicate) JOY_CAT5(nstl_mangled_find_if, _, InputIter, _,  Predicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FIND_IF_H */

