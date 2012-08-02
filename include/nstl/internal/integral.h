/**
 * Implementation of C integral types.
 */

#if NSTL_I_INSTANTIATE_PRIMITIVE
    NSTL_INSTANTIATE(NSTL_SCHAR)
    NSTL_INSTANTIATE(NSTL_PSCHAR)

    NSTL_INSTANTIATE(NSTL_CHAR)
    NSTL_INSTANTIATE(NSTL_PCHAR)

    NSTL_INSTANTIATE(NSTL_UCHAR)
    NSTL_INSTANTIATE(NSTL_PUCHAR)

    NSTL_INSTANTIATE(NSTL_SHORT)
    NSTL_INSTANTIATE(NSTL_PSHORT)

    NSTL_INSTANTIATE(NSTL_INT)
    NSTL_INSTANTIATE(NSTL_PINT)

    NSTL_INSTANTIATE(NSTL_USHORT)
    NSTL_INSTANTIATE(NSTL_PUSHORT)

    NSTL_INSTANTIATE(NSTL_UINT)
    NSTL_INSTANTIATE(NSTL_PUINT)

    NSTL_INSTANTIATE(NSTL_LONG)
    NSTL_INSTANTIATE(NSTL_PLONG)

    NSTL_INSTANTIATE(NSTL_ULONG)
    NSTL_INSTANTIATE(NSTL_PULONG)

    NSTL_INSTANTIATE(NSTL_PTRDIFF_T)
    NSTL_INSTANTIATE(NSTL_PPTRDIFF_T)

    NSTL_INSTANTIATE(NSTL_SIZE_T)
    NSTL_INSTANTIATE(NSTL_PSIZE_T)

#   if NSTL_CONFIG_LONG_LONG_AVAILABLE
        NSTL_INSTANTIATE(NSTL_LONG_LONG)
        NSTL_INSTANTIATE(NSTL_PLONG_LONG)

        NSTL_INSTANTIATE(NSTL_ULONG_LONG)
        NSTL_INSTANTIATE(NSTL_PULONG_LONG)
#   endif

#else

#ifndef NSTL_INTERNAL_INTEGRAL_H
#define NSTL_INTERNAL_INTEGRAL_H

#include <nstl/internal/config.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/pointer.h>
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
typedef nstl_schar *nstl_pschar;
#define NSTL_SCHAR NSTL_INTEGRAL(nstl_schar)
#define NSTL_PSCHAR NSTL_POINTER(nstl_schar, nstl_pschar)

#define nstl_char char
typedef nstl_char *nstl_pchar;
#define NSTL_CHAR NSTL_INTEGRAL(nstl_char)
#define NSTL_PCHAR NSTL_POINTER(nstl_char, nstl_pchar)

typedef unsigned char nstl_uchar;
typedef nstl_uchar *nstl_puchar;
#define NSTL_UCHAR NSTL_INTEGRAL(nstl_uchar)
#define NSTL_PUCHAR NSTL_POINTER(nstl_uchar, nstl_puchar)

#define nstl_short short
typedef nstl_short *nstl_pshort;
#define NSTL_SHORT NSTL_INTEGRAL(nstl_short)
#define NSTL_PSHORT NSTL_POINTER(nstl_short, nstl_pshort)

typedef unsigned short nstl_ushort;
typedef nstl_ushort *nstl_pushort;
#define NSTL_USHORT NSTL_INTEGRAL(nstl_ushort)
#define NSTL_PUSHORT NSTL_POINTER(nstl_ushort, nstl_pushort)

#define nstl_int int
typedef nstl_int *nstl_pint;
#define NSTL_INT NSTL_INTEGRAL(nstl_int)
#define NSTL_PINT NSTL_POINTER(nstl_int, nstl_pint)

typedef unsigned int nstl_uint;
typedef nstl_uint *nstl_puint;
#define NSTL_UINT NSTL_INTEGRAL(nstl_uint)
#define NSTL_PUINT NSTL_POINTER(nstl_uint, nstl_puint)

#define nstl_long long
typedef nstl_long *nstl_plong;
#define NSTL_LONG NSTL_INTEGRAL(nstl_long)
#define NSTL_PLONG NSTL_POINTER(nstl_long, nstl_plong)

typedef unsigned long nstl_ulong;
typedef nstl_ulong *nstl_pulong;
#define NSTL_ULONG NSTL_INTEGRAL(nstl_ulong)
#define NSTL_PULONG NSTL_POINTER(nstl_ulong, nstl_pulong)

#include <stddef.h>
typedef ptrdiff_t nstl_ptrdiff_t;
typedef nstl_ptrdiff_t *nstl_pptrdiff_t;
#define NSTL_PTRDIFF_T NSTL_INTEGRAL(nstl_ptrdiff_t)
#define NSTL_PPTRDIFF_T NSTL_POINTER(nstl_ptrdiff_t, nstl_pptrdiff_t)

#include <stddef.h>
typedef size_t nstl_size_t;
typedef nstl_size_t *nstl_psize_t;
#define NSTL_SIZE_T NSTL_INTEGRAL(nstl_size_t)
#define NSTL_PSIZE_T NSTL_POINTER(nstl_size_t, nstl_psize_t)

#if NSTL_CONFIG_LONG_LONG_AVAILABLE
    typedef long long nstl_long_long;
    typedef nstl_long_long *nstl_plong_long;
#   define NSTL_LONG_LONG NSTL_INTEGRAL(nstl_long_long)
#   define NSTL_PLONG_LONG NSTL_POINTER(nstl_long_long, nstl_plong_long)

    typedef unsigned long long nstl_ulong_long;
    typedef nstl_ulong_long *nstl_pulong_long;
#   define NSTL_ULONG_LONG NSTL_INTEGRAL(nstl_ulong_long)
#   define NSTL_PULONG_LONG NSTL_POINTER(nstl_ulong_long, nstl_pulong_long)
#endif /* NSTL_CONFIG_LONG_LONG_AVAILABLE */

#endif /* !NSTL_INTERNAL_INTEGRAL_H */
#endif /* NSTL_I_INSTANTIATE_PRIMITIVE */
