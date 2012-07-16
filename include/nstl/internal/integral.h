/**
 * Implementation of C integral types.
 *
 * @author Louis Dionne
 */

#if NSTL_I_INSTANTIATE_PRIMITIVE
    NSTL_INSTANTIATE(NSTL_SCHAR)
    NSTL_INSTANTIATE(NSTL_CHAR)
    NSTL_INSTANTIATE(NSTL_UCHAR)
    NSTL_INSTANTIATE(NSTL_SHORT)
    NSTL_INSTANTIATE(NSTL_INT)
    NSTL_INSTANTIATE(NSTL_USHORT)
    NSTL_INSTANTIATE(NSTL_UINT)
    NSTL_INSTANTIATE(NSTL_LONG)
    NSTL_INSTANTIATE(NSTL_ULONG)

#   if NSTL_CONFIG_LONG_LONG_AVAILABLE
        NSTL_INSTANTIATE(NSTL_LONG_LONG)
        NSTL_INSTANTIATE(NSTL_ULONG_LONG)
#   endif

#else

#ifndef NSTL_INTERNAL_INTEGRAL_H
#define NSTL_INTERNAL_INTEGRAL_H

#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


#define NSTL_INTEGRAL(value_type)                                              \
NSTL_TYPE(value_type,                                                          \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(value_type))                            \
(inherit NSTL_ARITHMETIC_OPERATORS(value_type))                                \
(inherit NSTL_COMPARISON_OPERATORS(value_type))                                \
(inherit NSTL_LOGICAL_OPERATORS(value_type))                                   \
(inherit NSTL_BITWISE_OPERATORS(value_type))                                   \
                                                                               \
)                                                                              \
/**/

typedef signed char nstl_schar;
#define NSTL_SCHAR NSTL_INTEGRAL(nstl_schar)

#define nstl_char char
#define NSTL_CHAR NSTL_INTEGRAL(nstl_char)

typedef unsigned char nstl_uchar;
#define NSTL_UCHAR NSTL_INTEGRAL(nstl_uchar)

#define nstl_short short
#define NSTL_SHORT NSTL_INTEGRAL(nstl_short)

typedef unsigned short nstl_ushort;
#define NSTL_USHORT NSTL_INTEGRAL(nstl_ushort)

#define nstl_int int
#define NSTL_INT NSTL_INTEGRAL(nstl_int)

typedef unsigned int nstl_uint;
#define NSTL_UINT NSTL_INTEGRAL(nstl_uint)

#define nstl_long long
#define NSTL_LONG NSTL_INTEGRAL(nstl_long)

typedef unsigned long nstl_ulong;
#define NSTL_ULONG NSTL_INTEGRAL(nstl_ulong)

#if NSTL_CONFIG_LONG_LONG_AVAILABLE
    typedef long long nstl_long_long;
#   define NSTL_LONG_LONG NSTL_INTEGRAL(nstl_long_long)

    typedef unsigned long long nstl_ulong_long;
#   define NSTL_ULONG_LONG NSTL_INTEGRAL(nstl_ulong_long)
#endif /* NSTL_CONFIG_LONG_LONG_AVAILABLE */

#endif /* !NSTL_INTERNAL_INTEGRAL_H */
#endif /* NSTL_I_INSTANTIATE_PRIMITIVE */
