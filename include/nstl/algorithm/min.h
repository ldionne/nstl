/**
 * This file defines the @em min and @em min_comp algorithm.
 */

#ifndef NSTL_ALGORITHM_MIN_H
#define NSTL_ALGORITHM_MIN_H

#include <nstl/internal.h>


#define NSTL_MIN(ValueType)                                                    \
    NSTL_I_MIN(                                                                \
        nstl_min(ValueType),                                                   \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_MIN(algo, Value)                                                \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun min                                                                     \
static NSTL_INLINE Value algo(Value a, Value b) {                              \
    return nstl_lt(Value, Value)(b, a) ? b : a;                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_MIN_COMP(ValueType, Compare)                                      \
    NSTL_I_MIN_COMP(                                                           \
        nstl_min_comp(ValueType, Compare),                                     \
        ValueType,                                                             \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MIN_COMP(algo, Value, Comp)                                     \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun min_comp                                                                \
static NSTL_INLINE Value algo(Value a, Value b, Comp comp) {                   \
    return comp(b, a) ? b : a;                                                 \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'min(ValueType)',
    'min_comp(ValueType, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_min (m i n)
#define nstl_min(ValueType) JOY_CAT3(nstl_mangled_min, _, ValueType)
#define NSTL_TOKEN_min_comp (m i n _ c o m p)
#define nstl_min_comp(ValueType,  Compare) JOY_CAT5(nstl_mangled_min_comp, _, ValueType, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MIN_H */
