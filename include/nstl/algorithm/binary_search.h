/**
 * This file defines the @em binary_search and @em binary_search_comp
 * algorithms.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_ALGORITHM_BINARY_SEARCH_H
#define NSTL_ALGORITHM_BINARY_SEARCH_H

#include <nstl/internal.h>


#define NSTL_BINARY_SEARCH(FwdIter, ValueType)                                 \
NSTL_TYPE(nstl_binary_search(FwdIter),                                         \
                                                                               \
(defun binary_search                                                           \
/**                                                                            \
 * Return true if an element in the range [@p first, @p last) is equivalent   \
 * to @p value, and false otherwise.                                           \
 *                                                                             \
 * The comparison is performed using the @em nstl_lt operator. A value @em x   \
 * is considered equivalent to another value @em y when                        \
 * @code (!nstl_lt(a, b) && !nstl_lt(b, a)) @endcode . For the algorithm to    \
 * yield the expected result, the elements in the range must already be        \
 * ordered according to the same criterion.                                    \
 */                                                                            \
static NSTL_INLINE nstl_bool nstl_binary_search(FwdIter)                       \
                            (FwdIter first, FwdIter last, ValueType value) {   \
    FwdIter i;                                                                 \
    nstl_bool ret;                                                             \
    nstl_copy_ctor(FwdIter)(&i, nstl_lower_bound(FwdIter)                      \
                                                        (first, last, value)); \
    ret = nstl_ne(FwdIter, FwdIter)(i, last) &&                                \
          !nstl_lt(ValueType, ValueType)(value, nstl_deref(FwdIter)(i));       \
    nstl_dtor(FwdIter)(&i);                                                    \
    return ret;                                                                \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

#define NSTL_BINARY_SEARCH_COMP(FwdIter, ValueType, Compare)                   \
NSTL_TYPE(nstl_binary_search_comp(FwdIter, Compare),                           \
                                                                               \
(defun binary_search_comp                                                      \
/**                                                                            \
 * Return true if an element in the range [@p first, @p last) is equivalent   \
 * to @p value, and false otherwise.                                           \
 *                                                                             \
 * The comparison is performed using the @p comp comparator. A value @em x     \
 * is considered equivalent to another value @em y when                        \
 * @code (!comp(a, b) && !comp(b, a)) @endcode . For the algorithm to          \
 * yield the expected result, the elements in the range must already be        \
 * ordered according to the same criterion.                                    \
 */                                                                            \
static NSTL_INLINE nstl_bool nstl_binary_search_comp(FwdIter, Compare)         \
                (FwdIter first, FwdIter last, ValueType value, Compare comp) { \
    FwdIter i;                                                                 \
    nstl_bool ret;                                                             \
    nstl_copy_ctor(FwdIter)(&i, nstl_lower_bound_comp(FwdIter, Compare)        \
                                                (first, last, value, comp));   \
    ret = nstl_ne(FwdIter, FwdIter)(i, last) &&                                \
          !comp(value, nstl_deref(FwdIter)(i));                                \
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