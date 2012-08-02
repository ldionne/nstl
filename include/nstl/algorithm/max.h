/**
 * This file defines the @em max and @em max_comp algorithms.
 */

#ifndef NSTL_ALGORITHM_MAX_H
#define NSTL_ALGORITHM_MAX_H

#include <nstl/internal.h>


#define NSTL_MAX(ValueType) \
    NSTL_I_MAX(nstl_max(ValueType), ValueType)

#define NSTL_I_MAX(this_func, ValueType)                                       \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun max                                                                     \
static NSTL_INLINE ValueType this_func(ValueType a, ValueType b) {             \
    return nstl_lt(ValueType, ValueType)(a, b) ? b : a;                        \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_MAX_COMP(ValueType, Compare) \
    NSTL_I_MAX_COMP(nstl_max_comp(ValueType, Compare), ValueType, Compare)

#define NSTL_I_MAX_COMP(this_func, ValueType, Compare)                         \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun max_comp                                                                \
static NSTL_INLINE ValueType this_func                                         \
                                    (ValueType a, ValueType b, Compare comp) { \
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
