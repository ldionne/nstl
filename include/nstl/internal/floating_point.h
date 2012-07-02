/*!
 * Implementation of C floating point types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_FLOATING_POINT_H
#define NSTL_INTERNAL_FLOATING_POINT_H

#include <nstl/type.h>
#include <nstl/operator.h>


#define NSTL_FLOATING_POINT(T)                                                 \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_ARITHMETIC_OPERATORS(T))                                         \
(unsetf mod)                                                                   \
(unsetf imod)                                                                  \
                                                                               \
(inherit NSTL_COMPARISON_OPERATORS(T))                                         \
(inherit NSTL_LOGICAL_OPERATORS(T))                                            \
(inherit NSTL_ALLOCATION_OPERATORS(T))                                         \
                                                                               \
)                                                                              \
/**/

#endif /* !NSTL_INTERNAL_FLOATING_POINT_H */
