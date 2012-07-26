/**
 * This file defines the @em min and @em min_comp algorithm.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_MIN_H
#define NSTL_ALGORITHM_MIN_H

#include <nstl/internal.h>


#define NSTL_MIN(ValueType) \
    NSTL_I_MIN(nstl_min(ValueType), ValueType)

#define NSTL_I_MIN(this_func, ValueType)                                       \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun min                                                                     \
static NSTL_INLINE ValueType this_func(ValueType a, ValueType b) {             \
    return nstl_lt(ValueType, ValueType)(b, a) ? b : a;                        \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_MIN_COMP(ValueType, Compare) \
    NSTL_I_MIN_COMP(nstl_min_comp(ValueType, Compare), ValueType, Compare)

#define NSTL_I_MIN_COMP(this_func, ValueType, Compare)                         \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun min_comp                                                                \
static NSTL_INLINE ValueType this_func                                         \
                                    (ValueType a, ValueType b, Compare comp) { \
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
