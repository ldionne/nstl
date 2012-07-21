/**
 * This file defines the @em swap algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_SWAP_H
#define NSTL_ALGORITHM_SWAP_H

#include <nstl/internal.h>


#define NSTL_SWAP(ValueType1, ValueType2)                                      \
NSTL_TYPE(nstl_swap(ValueType1, ValueType2),                                   \
                                                                               \
(defun swap                                                                    \
/**                                                                            \
 * Assign the content of @p a to @p b and the content of @p b to @p a.         \
 */                                                                            \
static NSTL_INLINE void nstl_swap(ValueType1, ValueType2)(ValueType1 *a,       \
                                                          ValueType2 *b) {     \
    ValueType1 tmp;                                                            \
    nstl_copy_ctor(ValueType1)(&tmp, *a);                                      \
    nstl_asg(ValueType1, ValueType2)(a, *b);                                   \
    nstl_asg(ValueType2, ValueType1)(b, tmp);                                  \
    nstl_dtor(ValueType1)(&tmp);                                               \
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
