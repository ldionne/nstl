/*!
 * Implementation of C integral types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_INTEGRAL_H
#define NSTL_INTERNAL_INTEGRAL_H

#include <nstl/type.h>


#define NSTL_INTEGRAL(T)                                                       \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_ARITHMETIC_OPERATORS(T))                                         \
(inherit NSTL_COMPARISON_OPERATORS(T))                                         \
(inherit NSTL_LOGICAL_OPERATORS(T))                                            \
(inherit NSTL_BITWISE_OPERATORS(T))                                            \
(inherit NSTL_ALLOCATION_OPERATORS(T))                                         \
                                                                               \
)                                                                              \
/**/

#endif /* !NSTL_INTERNAL_INTEGRAL_H */
