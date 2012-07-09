/*!
 * Implementation of C integral types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_INTEGRAL_H
#define NSTL_INTERNAL_INTEGRAL_H

#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


#define NSTL_INTEGRAL(T)                                                       \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(T))                                     \
(inherit NSTL_ARITHMETIC_OPERATORS(T))                                         \
(inherit NSTL_COMPARISON_OPERATORS(T))                                         \
(inherit NSTL_LOGICAL_OPERATORS(T))                                            \
(inherit NSTL_BITWISE_OPERATORS(T))                                            \
                                                                               \
)                                                                              \
/**/

typedef signed char nstl_schar;
#define NSTL_SCHAR NSTL_INTEGRAL(nstl_schar)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_SCHAR)

#define nstl_char char
#define NSTL_CHAR NSTL_INTEGRAL(nstl_char)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_CHAR)

typedef unsigned char nstl_uchar;
#define NSTL_UCHAR NSTL_INTEGRAL(nstl_uchar)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_UCHAR)

#define nstl_short short
#define NSTL_SHORT NSTL_INTEGRAL(nstl_short)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_SHORT)

typedef unsigned short nstl_ushort;
#define NSTL_USHORT NSTL_INTEGRAL(nstl_ushort)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_USHORT)

#define nstl_int int
#define NSTL_INT NSTL_INTEGRAL(nstl_int)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_INT)

typedef unsigned int nstl_uint;
#define NSTL_UINT NSTL_INTEGRAL(nstl_uint)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_UINT)

#define nstl_long long
#define NSTL_LONG NSTL_INTEGRAL(nstl_long)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_LONG)

typedef unsigned long nstl_ulong;
#define NSTL_ULONG NSTL_INTEGRAL(nstl_ulong)
NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_ULONG)

#if NSTL_CONFIG_LONG_LONG_AVAILABLE
    typedef long long nstl_long_long;
#   define NSTL_LONG_LONG NSTL_INTEGRAL(nstl_long_long)
    NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_LONG_LONG)

    typedef unsigned long long nstl_ulong_long;
#   define NSTL_ULONG_LONG NSTL_INTEGRAL(nstl_ulong_long)
    NSTL_I_INSTANTIATE_PRIMITIVE(NSTL_ULONG_LONG)
#endif /* NSTL_CONFIG_LONG_LONG_AVAILABLE */

#endif /* !NSTL_INTERNAL_INTEGRAL_H */
