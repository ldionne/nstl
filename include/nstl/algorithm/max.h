/**
 * This file defines the @em max and @em max_cmp algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_MAX_H
#define NSTL_ALGORITHM_MAX_H

#include <nstl/internal.h>


#define NSTL_MAX(ValueType)                                                    \
NSTL_TYPE(nstl_max(ValueType),                                                 \
                                                                               \
(defun max                                                                     \
static NSTL_INLINE ValueType nstl_max(ValueType)(ValueType a, ValueType b) {   \
    return nstl_lt(ValueType, ValueType)(a, b) ? b : a;                        \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_MAX_CMP(ValueType, BinaryPredicate)                               \
NSTL_TYPE(nstl_max_cmp(ValueType, BinaryPredicate),                            \
                                                                               \
(defun max_cmp                                                                 \
static NSTL_INLINE ValueType nstl_max_cmp(ValueType, BinaryPredicate)          \
                            (ValueType a, ValueType b, BinaryPredicate pred) { \
    return pred(a, b) ? b : a;                                                 \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'max(ValueType)',
    'max_cmp(ValueType, BinaryPredicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max (m a x)
#define nstl_max(ValueType) JOY_CAT3(nstl_mangled_max, _, ValueType)
#define NSTL_TOKEN_max_cmp (m a x _ c m p)
#define nstl_max_cmp(ValueType,  BinaryPredicate) JOY_CAT5(nstl_mangled_max_cmp, _, ValueType, _,  BinaryPredicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_H */
