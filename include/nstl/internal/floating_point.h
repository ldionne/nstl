/*!
 * Implementation of C floating point types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_FLOATING_POINT_H
#define NSTL_INTERNAL_FLOATING_POINT_H

#include <nstl/type.h>


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

#endif /* !NSTL_INTERNAL_FLOATING_POINT_H */
