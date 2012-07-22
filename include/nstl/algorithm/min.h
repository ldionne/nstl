/**
 * This file defines the @em min algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_MIN_H
#define NSTL_ALGORITHM_MIN_H

#include <nstl/internal.h>


#define NSTL_MIN(ValueType)                                                    \
NSTL_TYPE(nstl_min(ValueType),                                                 \
                                                                               \
(defun min                                                                     \
/**                                                                            \
 * Return the lesser of @p a and @p b.                                         \
 *                                                                             \
 * The comparison uses nstl_lt to determine which value is lesser.             \
 */                                                                            \
static NSTL_INLINE ValueType nstl_min(ValueType)(ValueType a, ValueType b) {   \
    return nstl_lt(ValueType, ValueType)(b, a) ? b : a;                        \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_MIN_CMP(ValueType, BinaryPredicate)                               \
NSTL_TYPE(nstl_min_cmp(ValueType, BinaryPredicate),                            \
                                                                               \
(defun min_cmp                                                                 \
/**                                                                            \
 * Return the lesser of @p a and @p b.                                         \
 *                                                                             \
 * The comparison uses @p pred to determine which value is lesser.             \
 *                                                                             \
 * @note In order for this algorithm to have the same result as the @em min    \
 *       algorithm, the @p pred predicate should act as a strict weak          \
 *       comparison predicate.                                                 \
 */                                                                            \
static NSTL_INLINE ValueType nstl_min_cmp(ValueType, BinaryPredicate)          \
                            (ValueType a, ValueType b, BinaryPredicate pred) { \
    return pred(b, a) ? b : a;                                                 \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'min(ValueType)',
    'min_cmp(ValueType, BinaryPredicate)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min (m i n)
#define nstl_min(ValueType) JOY_CAT3(nstl_mangled_min, _, ValueType)
#define NSTL_TOKEN_min_cmp (m i n _ c m p)
#define nstl_min_cmp(ValueType,  BinaryPredicate) JOY_CAT5(nstl_mangled_min_cmp, _, ValueType, _,  BinaryPredicate)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_H */