/*!
 * Implementation of C pointer types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_POINTER_H
#define NSTL_INTERNAL_POINTER_H

#include <nstl/type.h>

#include <stddef.h>


#define NSTL_POINTER(ValueType, Pointer)                                       \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(Pointer))                               \
(inherit NSTL_ARITHMETIC_OPERATORS(Pointer))                                   \
(inherit NSTL_COMPARISON_OPERATORS(Pointer))                                   \
(inherit NSTL_LOGICAL_OPERATORS(Pointer))                                      \
                                                                               \
(setf add                                                                      \
static NSTL_INLINE Pointer nstl_add(Pointer, ptrdiff_t)                        \
                                                    (Pointer self, ptrdiff_t n) \
{                                                                              \
    return self + n;                                                           \
}                                                                              \
)                                                                              \
(setf iadd                                                                     \
static NSTL_INLINE Pointer nstl_iadd(Pointer, ptrdiff_t)                       \
                                                    (Pointer *self, ptrdiff_t n) \
{                                                                              \
    return (*self) += n;                                                       \
}                                                                              \
)                                                                              \
(setf sub                                                                      \
static NSTL_INLINE ptrdiff_t nstl_sub(Pointer, Pointer)(Pointer x, Pointer y)  \
{                                                                              \
    return x - y;                                                              \
}                                                                              \
                                                                               \
static NSTL_INLINE Pointer nstl_sub(Pointer, ptrdiff_t)                        \
                                                    (Pointer self, ptrdiff_t n) \
{                                                                              \
    return self - n;                                                           \
}                                                                              \
)                                                                              \
(setf isub                                                                     \
static NSTL_INLINE Pointer nstl_isub(Pointer, ptrdiff_t)                       \
                                                    (Pointer *self, ptrdiff_t n) \
{                                                                              \
    return (*self) -= n;                                                       \
}                                                                              \
)                                                                              \
                                                                               \
(setf deref                                                                    \
static NSTL_INLINE ValueType nstl_deref(Pointer)(Pointer self)                 \
{                                                                              \
    return *self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
(drop mul imul  div idiv  mod imod  prom inv)                                  \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate(
    'deref(Pointer)',

    token=True, mangle=True,
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_deref (d e r e f)
#define nstl_deref(Pointer) JOY_CAT3(nstl_mangled_deref, _, Pointer)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_POINTER_H */
