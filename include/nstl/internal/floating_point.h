/**
 * Implementation of C floating point types.
 *
 * @author Louis Dionne
 */

#if NSTL_I_INSTANTIATE_PRIMITIVE
    NSTL_INSTANTIATE(NSTL_FLOAT)
    NSTL_INSTANTIATE(NSTL_DOUBLE)
    NSTL_INSTANTIATE(NSTL_LONG_DOUBLE)
#else

#ifndef NSTL_INTERNAL_FLOATING_POINT_H
#define NSTL_INTERNAL_FLOATING_POINT_H

#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


#define NSTL_FLOATING_POINT(T)                                                 \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(T))                                     \
(inherit NSTL_ARITHMETIC_OPERATORS(T))                                         \
(inherit NSTL_COMPARISON_OPERATORS(T))                                         \
(inherit NSTL_LOGICAL_OPERATORS(T))                                            \
(drop mod imod)                                                                \
                                                                               \
)                                                                              \
/**/

#define nstl_float float
#define NSTL_FLOAT NSTL_FLOATING_POINT(nstl_float)

#define nstl_double double
#define NSTL_DOUBLE NSTL_FLOATING_POINT(nstl_double)

typedef long double nstl_long_double;
#define NSTL_LONG_DOUBLE NSTL_FLOATING_POINT(nstl_long_double)

#endif /* !NSTL_INTERNAL_FLOATING_POINT_H */
#endif /* NSTL_I_INSTANTIATE_PRIMITIVE */
