/*!
 * Implementation of C pointer types.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_INTERNAL_POINTER_H
#define NSTL_INTERNAL_POINTER_H

#include <nstl/type.h>
#include <nstl/operator.h>

#include <stddef.h>


#define NSTL_POINTER(ValueType, Pointer)                                       \
NSTL_TYPE(                                                                     \
                                                                               \
(inherit NSTL_ARITHMETIC_OPERATORS(Pointer))                                   \
(unsetf mul)                                                                   \
(unsetf imul)                                                                  \
(unsetf div)                                                                   \
(unsetf idiv)                                                                  \
(unsetf mod)                                                                   \
(unsetf imod)                                                                  \
(unsetf prom)                                                                  \
(unsetf inv)                                                                   \
(setf add                                                                      \
static inline Pointer nstl_add(Pointer, ptrdiff_t)(Pointer self, ptrdiff_t n)  \
{                                                                              \
    return self + n;                                                           \
}                                                                              \
)                                                                              \
(setf iadd                                                                     \
static inline Pointer nstl_iadd(Pointer, ptrdiff_t)(Pointer *self, ptrdiff_t n) \
{                                                                              \
    return (*self) += n;                                                       \
}                                                                              \
)                                                                              \
(setf sub                                                                      \
static inline ptrdiff_t nstl_sub(Pointer, Pointer)(Pointer x, Pointer y)       \
{                                                                              \
    return x - y;                                                              \
}                                                                              \
                                                                               \
static inline Pointer nstl_sub(Pointer, ptrdiff_t)(Pointer self, ptrdiff_t n)  \
{                                                                              \
    return self - n;                                                           \
}                                                                              \
)                                                                              \
(setf isub                                                                     \
static inline Pointer nstl_isub(Pointer, ptrdiff_t)(Pointer *self, ptrdiff_t n) \
{                                                                              \
    return (*self) -= n;                                                       \
}                                                                              \
)                                                                              \
                                                                               \
(inherit NSTL_COMPARISON_OPERATORS(Pointer))                                   \
(inherit NSTL_LOGICAL_OPERATORS(Pointer))                                      \
(inherit NSTL_ALLOCATION_OPERATORS(Pointer))                                   \
                                                                               \
(setf deref                                                                    \
static inline ValueType nstl_deref(Pointer)(Pointer self)                      \
{                                                                              \
    return *self;                                                              \
}                                                                              \
)                                                                              \
                                                                               \
)                                                                              \
/**/

/* [[[cog

import nstl
cog.outl(nstl.generate_mangled(
    'deref(Pointer)',
))

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_deref (d e r e f)
#define nstl_deref(Pointer) JOY_CAT3(nstl_mangled_deref, _, Pointer)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_POINTER_H */
