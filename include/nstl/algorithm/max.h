/**
 * This file defines the @em max and @em max_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_MAX_H
#define NSTL_ALGORITHM_MAX_H

#include <nstl/internal.h>


#define NSTL_MAX(ValueType)                                                    \
    NSTL_I_MAX(                                                                \
        nstl_max(ValueType),                                                   \
        ValueType                                                              \
    )                                                                          \
/**/

#define NSTL_I_MAX(algo, Value)                                                \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun max                                                                     \
static NSTL_INLINE Value algo(Value a, Value b) {                              \
    return nstl_lt(Value, Value)(a, b) ? b : a;                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


#define NSTL_MAX_COMP(ValueType, Compare)                                      \
    NSTL_I_MAX_COMP(                                                           \
        nstl_max_comp(ValueType, Compare),                                     \
        ValueType,                                                             \
        Compare                                                                \
    )                                                                          \
/**/

#define NSTL_I_MAX_COMP(algo, Value, Comp)                                     \
NSTL_TYPE(algo,                                                                \
                                                                               \
(defun max_comp                                                                \
static NSTL_INLINE Value algo(Value a, Value b, Comp comp) {                   \
    return comp(a, b) ? b : a;                                                 \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/


/* [[[cog

import nstl
nstl.generate(cog,
    'max(ValueType)',
    'max_comp(ValueType, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_max (m a x)
#define nstl_max(ValueType) JOY_CAT3(nstl_mangled_max, _, ValueType)
#define NSTL_TOKEN_max_comp (m a x _ c o m p)
#define nstl_max_comp(ValueType,  Compare) JOY_CAT5(nstl_mangled_max_comp, _, ValueType, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_MAX_H */
