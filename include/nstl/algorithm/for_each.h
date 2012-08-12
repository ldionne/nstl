/**
 * This file defines the @em for_each algorithm.
 */

#ifndef NSTL_ALGORITHM_FOR_EACH_H
#define NSTL_ALGORITHM_FOR_EACH_H

#include <nstl/internal.h>


#define NSTL_FOR_EACH(SinglePassReadableIterator, Function)                    \
    NSTL_I_FOR_EACH(                                                           \
        nstl_for_each(SinglePassReadableIterator, Function),                   \
        SinglePassReadableIterator,                                            \
        Function                                                               \
    )                                                                          \
/**/

#define NSTL_I_FOR_EACH(algo, Iter, Func)                                      \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun for_each                                                                \
static NSTL_INLINE Func algo(Iter first_, Iter last_, Func f_) {               \
    Iter first;                                                                \
    nstl_copy_ctor(Iter)(&first, first_);                                      \
                                                                               \
    for ( ; nstl_ne(Iter, Iter)(first, last_); nstl_inc(Iter)(&first)) {       \
        nstl_deref_proxy(Iter) proxy;                                          \
        nstl_ctor(nstl_deref_proxy(Iter))(&proxy, first);                      \
        f_(nstl_get(nstl_deref_proxy(Iter))(proxy));                           \
        nstl_dtor(nstl_deref_proxy(Iter))(&proxy);                             \
    }                                                                          \
                                                                               \
    nstl_dtor(Iter)(&first);                                                   \
    return f_;                                                                 \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'for_each(SinglePassReadableIterator, Function)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_for_each (f o r _ e a c h)
#define nstl_for_each(SinglePassReadableIterator,  Function) JOY_CAT5(nstl_mangled_for_each, _, SinglePassReadableIterator, _,  Function)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_FOR_EACH_H */
