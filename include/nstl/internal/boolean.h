/**
 * Implementation of the C boolean type.
 *
 * @author Louis Dionne
 */

#if NSTL_I_INSTANTIATE_PRIMITIVE
    NSTL_INSTANTIATE(NSTL_BOOL)
    NSTL_INSTANTIATE(NSTL_PBOOL)
#else

#ifndef NSTL_INTERNAL_BOOLEAN_H
#define NSTL_INTERNAL_BOOLEAN_H

#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/pointer.h>
#include <nstl/internal/type.h>


#define NSTL_BOOLEAN(value_type)                                               \
NSTL_TYPE(value_type,                                                          \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(value_type))                            \
(inherit NSTL_COMPARISON_OPERATORS(value_type))                                \
(inherit NSTL_LOGICAL_OPERATORS(value_type))                                   \
(inherit NSTL_BITWISE_OPERATORS(value_type))                                   \
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
    enum nstl_bool {
        nstl_false = 0,
        nstl_true = 1
    };
    typedef enum nstl_bool nstl_bool;
#endif /* NSTL_CONFIG_BOOL_IS_AVAILABLE */

typedef nstl_bool *nstl_pbool;
#define NSTL_BOOL NSTL_BOOLEAN(nstl_bool)
#define NSTL_PBOOL NSTL_POINTER(nstl_bool, nstl_pbool)

#endif /* !NSTL_INTERNAL_BOOLEAN_H */
#endif /* NSTL_I_INSTANTIATE_PRIMITIVE */
