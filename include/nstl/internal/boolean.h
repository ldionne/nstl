/**
 * Implementation of the C boolean type.
 *
 * @author Louis Dionne
 */

#if NSTL_I_INSTANTIATE_PRIMITIVE
    NSTL_INSTANTIATE(NSTL_BOOL)
#else

#ifndef NSTL_INTERNAL_BOOLEAN_H
#define NSTL_INTERNAL_BOOLEAN_H

#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


#define NSTL_BOOLEAN(T)                                                        \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(T))                                     \
(inherit NSTL_COMPARISON_OPERATORS(T))                                         \
(inherit NSTL_LOGICAL_OPERATORS(T))                                            \
(inherit NSTL_BITWISE_OPERATORS(T))                                            \
(drop lshift rshift ilshift irshift)                                           \
                                                                               \
)                                                                              \
/**/

#if NSTL_CONFIG_BOOL_IS_AVAILABLE
#   include <stdbool.h>
#   define nstl_bool bool
#   define nstl_true true
#   define nstl_false false
#else
    typedef short nstl_bool;
#   define nstl_true 1
#   define nstl_false 0
#endif /* NSTL_CONFIG_BOOL_IS_AVAILABLE */

#define NSTL_BOOL NSTL_BOOLEAN(nstl_bool)

#endif /* !NSTL_INTERNAL_BOOLEAN_H */
#endif /* NSTL_I_INSTANTIATE_PRIMITIVE */
