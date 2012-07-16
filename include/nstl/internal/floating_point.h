/**
 * Implementation of C floating point types.
 *
 * @author Louis Dionne
 */

#if NSTL_I_INSTANTIATE_PRIMITIVE
    NSTL_INSTANTIATE(NSTL_FLOAT)
    NSTL_INSTANTIATE(NSTL_PFLOAT)

    NSTL_INSTANTIATE(NSTL_DOUBLE)
    NSTL_INSTANTIATE(NSTL_PDOUBLE)

    NSTL_INSTANTIATE(NSTL_LONG_DOUBLE)
    NSTL_INSTANTIATE(NSTL_PLONG_DOUBLE)
#else

#ifndef NSTL_INTERNAL_FLOATING_POINT_H
#define NSTL_INTERNAL_FLOATING_POINT_H

#include <nstl/internal/operator.h>
#include <nstl/internal/pointer.h>
#include <nstl/internal/type.h>


#define NSTL_FLOATING_POINT(value_type)                                        \
NSTL_TYPE(value_type,                                                          \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(value_type))                            \
(inherit NSTL_ARITHMETIC_OPERATORS(value_type))                                \
(inherit NSTL_COMPARISON_OPERATORS(value_type))                                \
(inherit NSTL_LOGICAL_OPERATORS(value_type))                                   \
(drop mod imod)                                                                \
                                                                               \
)                                                                              \
/**/

#define nstl_float float
typedef nstl_float *nstl_pfloat;
#define NSTL_FLOAT NSTL_FLOATING_POINT(nstl_float)
#define NSTL_PFLOAT NSTL_POINTER(nstl_float, nstl_pfloat)

#define nstl_double double
typedef nstl_double *nstl_pdouble;
#define NSTL_DOUBLE NSTL_FLOATING_POINT(nstl_double)
#define NSTL_PDOUBLE NSTL_POINTER(nstl_double, nstl_pdouble)

typedef long double nstl_long_double;
typedef nstl_long_double *nstl_plong_double;
#define NSTL_LONG_DOUBLE NSTL_FLOATING_POINT(nstl_long_double)
#define NSTL_PLONG_DOUBLE NSTL_POINTER(nstl_long_double, nstl_plong_double)

#endif /* !NSTL_INTERNAL_FLOATING_POINT_H */
#endif /* NSTL_I_INSTANTIATE_PRIMITIVE */
