/**
 * This file defines the @em binary_search and @em binary_search_comp
 * algorithms.
 */

#ifndef NSTL_ALGORITHM_BINARY_SEARCH_H
#define NSTL_ALGORITHM_BINARY_SEARCH_H

#include <nstl/algorithm/lower_bound.h>
#include <nstl/internal.h>


#define NSTL_BINARY_SEARCH(FwdIter, ValueType) \
    NSTL_I_BINARY_SEARCH(nstl_binary_search(FwdIter), FwdIter, ValueType)

#define NSTL_I_BINARY_SEARCH(this_func, FwdIter, ValueType)                    \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun binary_search                                                           \
typedef nstl_bool (*nstl_helper(this_func, impl_pred))(ValueType, ValueType);  \
                                                                               \
NSTL_GETF(NSTL_I_BINARY_SEARCH_COMP(nstl_helper(this_func, impl),              \
FwdIter, ValueType, nstl_helper(this_func, impl_pred)), binary_search_comp)    \
                                                                               \
static NSTL_INLINE nstl_bool this_func                                         \
                            (FwdIter first, FwdIter last, ValueType value) {   \
    return nstl_helper(this_func, impl)                                        \
                        (first, last, value, nstl_lt(ValueType, ValueType));   \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_BINARY_SEARCH_COMP(FwdIter, ValueType, Compare)                   \
    NSTL_I_BINARY_SEARCH_COMP(                                                 \
        nstl_binary_search_comp(FwdIter, Compare), FwdIter, ValueType, Compare \
    )                                                                          \
/**/

#define NSTL_I_BINARY_SEARCH_COMP(this_func, FwdIter, ValueType, Compare)      \
NSTL_TYPE(this_func,                                                           \
                                                                               \
(defun binary_search_comp                                                      \
NSTL_GETF(NSTL_I_LOWER_BOUND_COMP(                                             \
    nstl_helper(this_func, lower_bound_comp), FwdIter, ValueType, Compare),    \
                                                            lower_bound_comp)  \
static NSTL_INLINE nstl_bool this_func                                         \
                (FwdIter first, FwdIter last, ValueType value, Compare comp) { \
    FwdIter i = nstl_helper(this_func, lower_bound_comp)                       \
                                                (first, last, value, comp);    \
    nstl_bool ret = nstl_ne(FwdIter, FwdIter)(i, last) &&                      \
                    !comp(value, nstl_deref(FwdIter)(i));                      \
    nstl_dtor(FwdIter)(&i);                                                    \
    return ret;                                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
nstl.generate(cog,
    'binary_search(FwdIter)',
    'binary_search_comp(FwdIter, Compare)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_binary_search (b i n a r y _ s e a r c h)
#define nstl_binary_search(FwdIter) JOY_CAT3(nstl_mangled_binary_search, _, FwdIter)
#define NSTL_TOKEN_binary_search_comp (b i n a r y _ s e a r c h _ c o m p)
#define nstl_binary_search_comp(FwdIter,  Compare) JOY_CAT5(nstl_mangled_binary_search_comp, _, FwdIter, _,  Compare)
/* [[[end]]] */

#endif /* !NSTL_ALGORITHM_BINARY_SEARCH_H */
