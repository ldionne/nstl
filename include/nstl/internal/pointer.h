/**
 * Implementation of C pointer types.
 */

#ifndef NSTL_INTERNAL_POINTER_H
#define NSTL_INTERNAL_POINTER_H

#include <nstl/internal/integral.h>
#include <nstl/internal/operator.h>
#include <nstl/internal/type.h>


#define NSTL_POINTER(ValueType, Pointer)                                       \
NSTL_TYPE(Pointer,                                                             \
                                                                               \
(inherit NSTL_INITIALIZATION_OPERATORS(Pointer))                               \
(inherit NSTL_ARITHMETIC_OPERATORS(Pointer))                                   \
(inherit NSTL_COMPARISON_OPERATORS(Pointer))                                   \
(inherit NSTL_LOGICAL_OPERATORS(Pointer))                                      \
                                                                               \
(defun add                                                                     \
static NSTL_INLINE Pointer nstl_add(Pointer, nstl_ptrdiff_t)                   \
                                            (Pointer self, nstl_ptrdiff_t n) { \
    return self + n;                                                           \
}                                                                              \
)                                                                              \
(defun iadd                                                                    \
static NSTL_INLINE Pointer nstl_iadd(Pointer, nstl_ptrdiff_t)                  \
                                        (Pointer *self, nstl_ptrdiff_t n) {    \
    return (*self) += n;                                                       \
}                                                                              \
)                                                                              \
(defun sub                                                                     \
static NSTL_INLINE nstl_ptrdiff_t nstl_sub(Pointer, Pointer)                   \
                                                    (Pointer x, Pointer y) {   \
    return x - y;                                                              \
}                                                                              \
                                                                               \
static NSTL_INLINE Pointer nstl_sub(Pointer, nstl_ptrdiff_t)                   \
                                            (Pointer self, nstl_ptrdiff_t n) { \
    return self - n;                                                           \
}                                                                              \
)                                                                              \
(defun isub                                                                    \
static NSTL_INLINE Pointer nstl_isub(Pointer, nstl_ptrdiff_t)                  \
                                        (Pointer *self, nstl_ptrdiff_t n) {    \
    return (*self) -= n;                                                       \
}                                                                              \
)                                                                              \
                                                                               \
(defun deref                                                                   \
static NSTL_INLINE ValueType nstl_deref(Pointer)(Pointer self) {               \
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
nstl.generate(cog,
    'deref(Pointer)',

    token=True, mangle=True,
)

]]] */
#include <joy/cat.h>
#define NSTL_TOKEN_deref (d e r e f)
#define nstl_deref(Pointer) JOY_CAT3(nstl_mangled_deref, _, Pointer)
/* [[[end]]] */

#endif /* !NSTL_INTERNAL_POINTER_H */
