/**
 * This file defines the @em swap algorithm.
 */

#ifndef NSTL_ALGORITHM_SWAP_H
#define NSTL_ALGORITHM_SWAP_H

#include <nstl/internal.h>


#define NSTL_SWAP(ValueType1, ValueType2)                                      \
    NSTL_I_SWAP(                                                               \
        nstl_swap(ValueType1, ValueType2),                                     \
        ValueType1,                                                            \
        ValueType2                                                             \
    )                                                                          \
/**/

#define NSTL_I_SWAP(algo, Value1, Value2)                                      \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun swap                                                                    \
static NSTL_INLINE void algo(Value1 *a, Value2 *b) {                           \
    Value1 tmp;                                                                \
    nstl_copy_ctor(Value1)(&tmp, *a);                                          \
    nstl_asg(Value1, Value2)(a, *b);                                           \
    nstl_asg(Value1, Value2)(b, tmp);                                          \
    nstl_dtor(Value1)(&tmp);                                                   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'swap(ValueType1, ValueType2)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_swap (s w a p)
#define nstl_swap(ValueType1,  ValueType2) JOY_CAT5(nstl_mangled_swap, _, ValueType1, _,  ValueType2)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_SWAP_H */
